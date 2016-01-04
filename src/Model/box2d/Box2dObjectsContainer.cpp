//
// Created by defacto on 2015.12.26..
//

#include <Model/collisions/CollisionGroupsData.h>
#include "Box2dObjectsContainer.h"

Box2dObjectsContainer::Box2dObjectsContainer(ImageScalesContainer &imageScalesContainer, GameConfiguration &gameConfiguration )
        : imageScalesContainer_(imageScalesContainer), gameConfiguration_(gameConfiguration) {
}

std::shared_ptr<Box2dObject> Box2dObjectsContainer::getRocketObject() {
    return createObjectWithBoxShape(imageScalesContainer_.getRocketImageScale(), 120, CollisionGroupsData::getRocketData());
}

std::shared_ptr<Box2dObject> Box2dObjectsContainer::getAsteriodObject(double size) {
    // todo use size!!!!
    return createObjectWithBoxShape(imageScalesContainer_.getBasicAsteroidImageScale() * size, 120, CollisionGroupsData::getAsteroidData());
}

std::shared_ptr<Box2dObject> Box2dObjectsContainer::getProjectileObject() {
    return createObjectWithBoxShape(imageScalesContainer_.getProjectileImageScale(), 250, CollisionGroupsData::getProjectileData());
}

std::shared_ptr<Box2dObject> Box2dObjectsContainer::createObjectWithBoxShape(ScaleToScreen imageScale,
                                                                             double density,
                                                                             CollisionGroupsData collisionGroupData) {
    auto shape = std::make_shared<b2PolygonShape>();
    Point imageSizeInGameUnits = imageScale.scalePoint( gameConfiguration_.getBox2dScreenDimensions()  );
    shape->SetAsBox(imageSizeInGameUnits.getX()/2,imageSizeInGameUnits.getY()/2);

    polygonShapesVector_.push_back(shape);

    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(0,0 );
    bodyDef.angle = 0;

    b2FixtureDef fixtureDef;
    fixtureDef.shape =shape.get();
    fixtureDef.density = density;

    fixtureDef.filter.categoryBits = collisionGroupData.categoryBits_;
    fixtureDef.filter.maskBits = collisionGroupData.maskBits_;

    std::vector<b2FixtureDef> fixturesVec{fixtureDef};
    return std::make_shared<Box2dObject>(bodyDef, fixturesVec,
                                         imageSizeInGameUnits.getX()*imageSizeInGameUnits.getY()*density,
                                         imageSizeInGameUnits);
}