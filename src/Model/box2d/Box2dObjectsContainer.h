//
// Created by defacto on 2015.12.26..
//

#ifndef PWASTEROIDS_BOX2DDEFINITIONSCONTAINER_H
#define PWASTEROIDS_BOX2DDEFINITIONSCONTAINER_H

#include <vector>
#include <Model/help/DegreesCalculations.h>
#include <Model/ModelDrawing/ImageScalesContainer.h>
#include <Model/configuration/ActorsConfiguration.h>
#include "Box2dObject.h"

class Box2dObjectsContainer {
    std::vector<std::shared_ptr<b2PolygonShape>> polygonShapesVector_;
    ImageScalesContainer &imageScalesContainer_;
    std::shared_ptr<ActorsConfiguration> actorsConfiguration_;
    std::vector< std::shared_ptr<std::array<b2Vec2, 4>>> collisionBoxArrays_;

    double x = 0.25;
    double y = 0.3;

public:
    Box2dObjectsContainer( ImageScalesContainer &imageScalesContainer, std::shared_ptr<ActorsConfiguration> actorsConfiguration ) :
            imageScalesContainer_(imageScalesContainer), actorsConfiguration_(actorsConfiguration){
    }

    std::shared_ptr<Box2dObject> getRocketObject(){
        ScaleToScreen rocketImageScale = imageScalesContainer_.getRocketImageScale();
        std::shared_ptr<std::array<b2Vec2, 4>> collisionBox = std::make_shared<std::array<b2Vec2, 4>>();
//        collisionBox->at(0).Set(-1* rocketImageScale.getX()/2, rocketImageScale.getY()/2);
//        collisionBox->at(1).Set(-1* rocketImageScale.getX()/2, -rocketImageScale.getY()/2);
//        collisionBox->at(2).Set(1* rocketImageScale.getX()/2, -rocketImageScale.getY()/2);
//        collisionBox->at(3).Set(1* rocketImageScale.getX()/2, rocketImageScale.getY()/2);

//        collisionBox->at(0).Set(-x, y);
//        collisionBox->at(1).Set(-x, -y);
//        collisionBox->at(2).Set(x, -y);
//        collisionBox->at(3).Set(x, y);
        collisionBoxArrays_.push_back(collisionBox);

        auto rocketShape = std::make_shared<b2PolygonShape>();
        Point pr = rocketImageScale.scalePoint( actorsConfiguration_->getBox2dScreenDimensions()  );
        rocketShape->SetAsBox(x,y);
        //rocketShape->Set(collisionBox->data(), 4);
        polygonShapesVector_.push_back(rocketShape);

      	b2BodyDef bodyDef;
        bodyDef.type = b2_dynamicBody;
        bodyDef.position.Set(0,0 );
        bodyDef.angle = 0;

        b2FixtureDef fixtureDef;
        fixtureDef.shape = rocketShape.get();
        fixtureDef.density = 14;

        std::vector<b2FixtureDef> fixturesVec{fixtureDef};
        return std::make_shared<Box2dObject>(bodyDef, fixturesVec);
    }


    std::shared_ptr<Box2dObject> getAsteriodObject(double size){
        ScaleToScreen asteroidImageScale = imageScalesContainer_.getBasicAsteroidImageScale();
        asteroidImageScale = asteroidImageScale * size;
        std::shared_ptr<std::array<b2Vec2, 4>> collisionBox = std::make_shared<std::array<b2Vec2, 4>>();
//        collisionBox->at(0).Set(-1* asteroidImageScale.getX()/2, asteroidImageScale.getY()/2);
//        collisionBox->at(1).Set(-1* asteroidImageScale.getX()/2, -asteroidImageScale.getY()/2);
//        collisionBox->at(2).Set(1* asteroidImageScale.getX()/2, -asteroidImageScale.getY()/2);
//        collisionBox->at(3).Set(1* asteroidImageScale.getX()/2, asteroidImageScale.getY()/2);

        collisionBox->at(0).Set(-x, y);
        collisionBox->at(1).Set(-x, -y);
        collisionBox->at(2).Set(x, -y);
        collisionBox->at(3).Set(x, y);

        collisionBoxArrays_.push_back(collisionBox);

        auto asteroidShape = std::make_shared<b2PolygonShape>();
        //asteroidShape->Set(collisionBox->data(), 4);
        asteroidShape->SetAsBox(x, y);
        polygonShapesVector_.push_back(asteroidShape);

        b2BodyDef bodyDef;
        bodyDef.type = b2_dynamicBody;
        bodyDef.position.Set(0,0 );
        bodyDef.angle = 0;

        b2FixtureDef fixtureDef;
        fixtureDef.shape =asteroidShape.get();
        fixtureDef.density = 1;

        std::vector<b2FixtureDef> fixturesVec{fixtureDef};
        return std::make_shared<Box2dObject>(bodyDef, fixturesVec);
}
};


#endif //PWASTEROIDS_BOX2DDEFINITIONSCONTAINER_H
