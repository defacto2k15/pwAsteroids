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
#include "ImagePathsContainer.h"

class GameScreenEventInterpreter : public AbstractAllegroEventListener {
    AllegroToGameKeyMapper &keyMapper_;
    MousePositionFetcher &mousePositionFetcher_;
    ImagePathsContainer &imagePathsContainer_;
    GameScreen *gameScreen_;
    Game &game_;
    std::vector<ActorId> createdObjectsIds_;
public:
    GameScreenEventInterpreter(AllegroToGameKeyMapper &keyMapper, MousePositionFetcher &mousePositionFetcher,
                               GameScreen *gameScreen, ImagePathsContainer &imagePathsContainer, Game &game)
            : keyMapper_(keyMapper), mousePositionFetcher_(mousePositionFetcher),
                gameScreen_(gameScreen), imagePathsContainer_(imagePathsContainer), game_(game) {
    }


    virtual void timeEvent() override{
        for( auto key : keyMapper_.getPressedKeys()){
            game_.getInputStateGetter()->gameKeyIsPressed(key);
        }

        Point mousePos = mousePositionFetcher_.getMousePosition();
        game_.getInputStateGetter()->setMousePosition( mousePos.getX(), mousePos.getY());

        for( auto imagePrimitive : game_.getOutGameScreenModel()->getImagePrimitives()){
            if(std::find( begin(createdObjectsIds_), end(createdObjectsIds_), imagePrimitive) == end(createdObjectsIds_) ){
                gameScreen_->createImage(imagePrimitive.getActorId(),
                                                  imagePathsContainer_.getPath(imagePrimitive.getImageType()) );
            }
           updateDrawableObject( imagePrimitive );
        }

        for( auto textPrimitive : game_.getOutGameScreenModel()->getTextPrimitives()){
            if(std::find( begin(createdObjectsIds_), end(createdObjectsIds_), textPrimitive) == end(createdObjectsIds_) ){
                gameScreen_->createText(textPrimitive.getActorId(), textPrimitive.getTextToWrite() );
            }
            updateDrawableObject( textPrimitive );
        }
        /* TODO deleting */
    }
private:
    void updateDrawableObject(BaseDrawablePrimitive &primitive ){
        gameScreen_->updateObject( primitive.getActorId(), primitive.getPosition(), primitive.getRotation(), primitive.getScale());
    } TUTAJ kontynuluj jak wymyslisz co zrobic ze skala
};


#endif //PWASTEROIDS_GAMESCREENEVENTINTERPRETER_H
