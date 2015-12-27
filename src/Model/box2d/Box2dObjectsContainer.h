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
    ActorsConfiguration &actorsConfiguration_;
    std::vector< std::shared_ptr<std::array<b2Vec2, 4>>> collisionBoxArrays_;

    double x = 0.25;
    double y = 0.3;

public:
    Box2dObjectsContainer( ImageScalesContainer &imageScalesContainer, ActorsConfiguration &actorsConfiguration ) :
            imageScalesContainer_(imageScalesContainer), actorsConfiguration_(actorsConfiguration){
    }

    std::shared_ptr<Box2dObject> getRocketObject(){
        ScaleToScreen rocketImageScale = imageScalesContainer_.getRocketImageScale();

        auto rocketShape = std::make_shared<b2PolygonShape>();
        Point imageSizeInGameUnits = rocketImageScale.scalePoint( actorsConfiguration_.getBox2dScreenDimensions()  );
        rocketShape->SetAsBox(imageSizeInGameUnits.getX()/2,imageSizeInGameUnits.getY()/2);
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

        auto asteroidShape = std::make_shared<b2PolygonShape>();
        Point imageSizeInGameUnits = asteroidImageScale.scalePoint( actorsConfiguration_.getBox2dScreenDimensions()  );
        asteroidShape->SetAsBox(imageSizeInGameUnits.getX()/2,imageSizeInGameUnits.getY()/2);

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
