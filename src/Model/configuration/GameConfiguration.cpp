//
// Created by defacto on 27.11.15.
//

#include <Model/configuration/GameConfiguration.h>



GameConfiguration* GameConfiguration::onlyInstancePointer;

GameConfiguration & configurationGettingFunction(){
   return *GameConfiguration::onlyInstancePointer;
}