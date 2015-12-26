//
// Created by defacto on 2015.12.26..
//

#ifndef PWASTEROIDS_BOX2DDEFINITIONSCONTAINER_H
#define PWASTEROIDS_BOX2DDEFINITIONSCONTAINER_H

#include <vector>
#include <Model/help/DegreesCalculations.h>
#include "Box2dObject.h"

class Box2dObjectsContainer {
    std::vector<std::shared_ptr<b2PolygonShape>> polygonShapesVector_;
public:
    std::shared_ptr<Box2dObject> getRocketObject(){
        auto rocketShape = std::make_shared<b2PolygonShape>();
        polygonShapesVector_.push_back(rocketShape);

        rocketShape->SetAsBox(1, 1);
      	b2BodyDef bodyDef;
        bodyDef.type = b2_dynamicBody;
        bodyDef.position.Set(0,0 );
        bodyDef.angle = 0;

        b2FixtureDef fixtureDef;
        fixtureDef.shape = rocketShape.get();
        fixtureDef.density = 1;

        std::vector<b2FixtureDef> fixturesVec{fixtureDef};
        return std::make_shared<Box2dObject>(bodyDef, fixturesVec);
    }
};


#endif //PWASTEROIDS_BOX2DDEFINITIONSCONTAINER_H
