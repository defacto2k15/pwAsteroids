//
// Created by defacto on 2016.01.11..
//

#include "GameScreenEventInterpreter.h"
#include "View/ViewManager.h"

std::string GameScreenEventInterpreter::getScreenName() {
    return "GameScreen";
}

GameScreenEventInterpreter::GameScreenEventInterpreter(AllegroToGameKeyMapper &keyMapper, MousePositionFetcher &mousePositionFetcher,
                                                       GameScreen *gameScreen, ImageDataContainer &imageDataContainer,
                                                       Game &game, ScreenSize &screenSize, SoundModule &soundModule)
        : keyMapper_(keyMapper), mousePositionFetcher_(mousePositionFetcher), gameScreen_(gameScreen),
          imageDataContainer_(imageDataContainer), game_(game), screenSize_(screenSize) , soundModule_(soundModule){
}

void GameScreenEventInterpreter::keyDown(int keynum) {
    if( keynum == ALLEGRO_KEY_ESCAPE ){
        viewManager_->changeActiveScreen("MenuScreen");
    } else if( keynum == ALLEGRO_KEY_TILDE ){
        viewManager_->changeActiveScreen("ConsoleScreen");
    }
}

void GameScreenEventInterpreter::timeEvent() {
    for( auto key : keyMapper_.getPressedKeys()){
        game_.getInputStateGetter()->gameKeyIsPressed(key);
    }

    Point mousePos = mousePositionFetcher_.getMousePosition();
    game_.getInputStateGetter()->setMousePosition( mousePos.getX(), mousePos.getY());

    for( auto imagePrimitive : game_.getOutGameScreenModel()->getImagePrimitives()) {
        if (imagePrimitive.getImageType() == ImagePrimitiveType::NotVisibleElement) {
            if (std::find(begin(createdObjectsIds_), end(createdObjectsIds_), imagePrimitive.getActorId()) !=
                end(createdObjectsIds_)) {
                updateDrawableObject(imagePrimitive, 0);
            }
        } else {
            if (std::find(begin(createdObjectsIds_), end(createdObjectsIds_), imagePrimitive.getActorId()) ==
                end(createdObjectsIds_)) {
                gameScreen_->createImage(imagePrimitive.getActorId(),
                                         imageDataContainer_.getData(imagePrimitive.getImageType()).path);
                createdObjectsIds_.push_back(imagePrimitive.getActorId());
            }
            Size expectedSize = imagePrimitive.getScale().scalePoint(screenSize_.getSize());
            double zoom = double(expectedSize.getX()) /
                          double(imageDataContainer_.getData(imagePrimitive.getImageType()).xSize);
            //zoom = zoom / 4;

            updateDrawableObject(imagePrimitive, zoom);
        }
    }

    for( auto textPrimitive : game_.getOutGameScreenModel()->getTextPrimitives()){
        if(std::find( begin(createdObjectsIds_), end(createdObjectsIds_), textPrimitive.getActorId()) == end(createdObjectsIds_) ){
            gameScreen_->createText(textPrimitive.getActorId(), textPrimitive.getTextToWrite() );
            createdObjectsIds_.push_back(textPrimitive.getActorId());
        }
        updateDrawableObject(textPrimitive, 1);
    }
    for( auto actorId : game_.getOutGameScreenModel()->getRemovedActorsIds()){
		gameScreen_->deleteObject(actorId);
    }
    for( MusicInstance oneInstance : game_.getOutGameMusicModel()->getMusicInstances()){
        switch (oneInstance.getElement()){
            case MusicElements::AsteroidCollisionSound:
                soundModule_.playSample("AsteroidCollision", oneInstance.getVolume() * 0.5f, true);
                break;
            case MusicElements::RocketDestructionSound:
                soundModule_.playSample("RocketFailure", oneInstance.getVolume() * 0.5f, true);
                break;
            case ShootSound:
                soundModule_.playSample("Blaster Imperial", oneInstance.getVolume() * 0.5f, true);
                break;
            case SecondPlayerAsteroidShoot:
                soundModule_.playSample("SecondPlayerShoot", oneInstance.getVolume() * 0.5f, true);
                break;
            case PowerupGainSound:
                soundModule_.playSample("PowerupGainSound", oneInstance.getVolume() * 0.5f, true);
                break;
        }
    }

    gameScreen_->refreshScreen();
    game_.update();

}

void GameScreenEventInterpreter::updateDrawableObject(BaseDrawablePrimitive &primitive, double zoom) {
    gameScreen_->updateObject( primitive.getActorId(), primitive.getPosition(), primitive.getRotation(), float(zoom)) ;
}