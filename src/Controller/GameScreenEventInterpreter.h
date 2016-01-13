//
// Created by defacto on 2016.01.11..
//

#ifndef PWASTEROIDS_GAMESCREENEVENTINTERPRETER_H
#define PWASTEROIDS_GAMESCREENEVENTINTERPRETER_H


#include <View/GameScreen.h>
#include "AbstractAllegroEventListener.h"
#include "KeyStateFetcher.h"
#include "MousePositionFetcher.h"
#include "AllegroToGameKeyMapper.h"
#include "ImageDataContainer.h"
#include "ScreenSize.h"

class GameScreenEventInterpreter : public AbstractAllegroEventListener {
    AllegroToGameKeyMapper &keyMapper_;
    MousePositionFetcher &mousePositionFetcher_;
    ImageDataContainer &imageDataContainer_;
    ScreenSize &screenSize_;
    GameScreen *gameScreen_;
    Game &game_;
    std::vector<ActorId> createdObjectsIds_;
public:
    GameScreenEventInterpreter(AllegroToGameKeyMapper &keyMapper, MousePositionFetcher &mousePositionFetcher,
                               GameScreen *gameScreen, ImageDataContainer &imageDataContainer, Game &game, ScreenSize &screenSize)
            : keyMapper_(keyMapper), mousePositionFetcher_(mousePositionFetcher),
                gameScreen_(gameScreen), imageDataContainer_(imageDataContainer), game_(game), screenSize_(screenSize) {
    }


    virtual void timeEvent() override{
        for( auto key : keyMapper_.getPressedKeys()){
            std::cout << "pressed is " << int(key) << std::endl;
            game_.getInputStateGetter()->gameKeyIsPressed(key);
        }

        Point mousePos = mousePositionFetcher_.getMousePosition();
        game_.getInputStateGetter()->setMousePosition( mousePos.getX(), mousePos.getY());

        for( auto imagePrimitive : game_.getOutGameScreenModel()->getImagePrimitives()){
            if(std::find( begin(createdObjectsIds_), end(createdObjectsIds_), imagePrimitive.getActorId()) == end(createdObjectsIds_) ){
                gameScreen_->createImage(imagePrimitive.getActorId(),
                                                  imageDataContainer_.getData(imagePrimitive.getImageType()).path );
                createdObjectsIds_.push_back(imagePrimitive.getActorId());
            }
            Size expectedSize = imagePrimitive.getScale().scalePoint( screenSize_.getSize());
            double zoom = double(expectedSize.getX()) /double(imageDataContainer_.getData(imagePrimitive.getImageType()).xSize);
            zoom = zoom / 4;
           updateDrawableObject( imagePrimitive, zoom );
        }

        for( auto textPrimitive : game_.getOutGameScreenModel()->getTextPrimitives()){
            if(std::find( begin(createdObjectsIds_), end(createdObjectsIds_), textPrimitive.getActorId()) == end(createdObjectsIds_) ){
                gameScreen_->createText(textPrimitive.getActorId(), textPrimitive.getTextToWrite() );
                createdObjectsIds_.push_back(textPrimitive.getActorId());
            }
            updateDrawableObject( textPrimitive, 1 );
        }
        for( auto actorId : game_.getOutGameScreenModel()->getRemovedActorsIds()){
            /* TODO deleting */
            gameScreen_->updateObject(actorId, Point(-100, -100), 0, 0);
        }

        gameScreen_->refreshScreen();
        game_.update();

    }
private:
    void updateDrawableObject(BaseDrawablePrimitive &primitive, double zoom ){

        gameScreen_->updateObject( primitive.getActorId(), primitive.getPosition(), primitive.getRotation(), zoom) ;
    }
};


#endif //PWASTEROIDS_GAMESCREENEVENTINTERPRETER_H
