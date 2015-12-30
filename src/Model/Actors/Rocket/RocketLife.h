//
// Created by defacto on 2015.12.29..
//

#ifndef PWASTEROIDS_ROCKETLIFECOMPONENT_H
#define PWASTEROIDS_ROCKETLIFECOMPONENT_H

#include <memory>
#include <Model/configuration/ActorsConfiguration.h>
#include <Model/modelInterfaces/IOutGameScreenModel.h>
#include <stdexcept>

class RocketLife {
    unsigned int life_;
    ActorsConfiguration &actorsConfiguration_;
public:
    RocketLife( ActorsConfiguration &actorsConfiguration)
            : life_( actorsConfiguration.getInitialRocketLife()), actorsConfiguration_(actorsConfiguration){
    }

    void decreaseLife(){
        if( life_ == 0){
            throw std::runtime_error("There is arleady 0 life_ left");
        }
        --life_;
    }

    void increaseLife(){
        life_;
    }

    void resetLife(){
        life_ = actorsConfiguration_.getInitialRocketLife();
    }

    unsigned int getLife(){
        return life_;
    }
};


#endif //PWASTEROIDS_ROCKETLIFECOMPONENT_H
