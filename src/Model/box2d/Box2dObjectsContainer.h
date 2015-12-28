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

class Box2dObjectsContainer { // TODO clean this class!
    std::vector<std::shared_ptr<b2PolygonShape>> polygonShapesVector_;
    ImageScalesContainer &imageScalesContainer_;
    ActorsConfiguration &actorsConfiguration_;

public:
    Box2dObjectsContainer( ImageScalesContainer &imageScalesContainer, ActorsConfiguration &actorsConfiguration ) :
            imageScalesContainer_(imageScalesContainer), actorsConfiguration_(actorsConfiguration){
    }

    std::shared_ptr<Box2dObject> getRocketObject(){
        return createObjectWithBoxShape(imageScalesContainer_.getRocketImageScale(), 120);
    }


    std::shared_ptr<Box2dObject> getAsteriodObject(double size){
        return createObjectWithBoxShape(imageScalesContainer_.getBasicAsteroidImageScale(), 120);
    }

    std::shared_ptr<Box2dObject> getProjectileObject(){
        return createObjectWithBoxShape(imageScalesContainer_.getProjectileImageScale(), 120);
    }


private:
    std::shared_ptr<Box2dObject> createObjectWithBoxShape(ScaleToScreen imageScale, double densityPerSquareUnit ){
        auto shape = std::make_shared<b2PolygonShape>();
        Point imageSizeInGameUnits = imageScale.scalePoint( actorsConfiguration_.getBox2dScreenDimensions()  );
        shape->SetAsBox(imageSizeInGameUnits.getX()/2,imageSizeInGameUnits.getY()/2);

        polygonShapesVector_.push_back(shape);

        b2BodyDef bodyDef;
        bodyDef.type = b2_dynamicBody;
        bodyDef.position.Set(0,0 );
        bodyDef.angle = 0;

        b2FixtureDef fixtureDef;
        fixtureDef.shape =shape.get();
        fixtureDef.density = imageSizeInGameUnits.getX()*imageSizeInGameUnits.getY()*densityPerSquareUnit;

        std::vector<b2FixtureDef> fixturesVec{fixtureDef};
        return std::make_shared<Box2dObject>(bodyDef, fixturesVec);
    }
};


#endif //PWASTEROIDS_BOX2DDEFINITIONSCONTAINER_H
