//
// Created by defacto on 2015.12.26..
//

#include <Model/collisions/CollisionGroupsData.h>
#include "Box2dObjectsContainer.h"
#include <lib/Box2D/Collision/Shapes/b2CircleShape.h>

Box2dObjectsContainer::Box2dObjectsContainer(ImageScalesContainer &imageScalesContainer, GameConfiguration &gameConfiguration )
        : imageScalesContainer_(imageScalesContainer), gameConfiguration_(gameConfiguration) {
}

std::shared_ptr<Box2dObject> Box2dObjectsContainer::getRocketObject() {
    return createObjectWithCircleShape(imageScalesContainer_.getImageScale(ImagePrimitiveType::Rocket), 1200, CollisionGroupsData::getRocketData());
}

std::shared_ptr<Box2dObject> Box2dObjectsContainer::getAsteriodObject(double size) {
    return createObjectWithBoxShape(imageScalesContainer_.getImageScale(ImagePrimitiveType::Asteroid)* size, 120, CollisionGroupsData::getAsteroidData());
}

std::shared_ptr<Box2dObject> Box2dObjectsContainer::getProjectileObject() {
    return createObjectWithBoxShape(imageScalesContainer_.getImageScale(ImagePrimitiveType::Projectile), 250, CollisionGroupsData::getProjectileData());
}

std::shared_ptr<Box2dObject> Box2dObjectsContainer::getPowerupObject() {
    return createObjectWithBoxShape(imageScalesContainer_.getImageScale(ImagePrimitiveType::TripleShootPowerup), 1, CollisionGroupsData::getPowerupData());
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
    bodyDef.userData = (void*)(int(density));

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

std::shared_ptr<Box2dObject> Box2dObjectsContainer::createObjectWithCircleShape(ScaleToScreen imageScale,
                                                                                double densityPerSquareUnit,
                                                                                CollisionGroupsData collisionGroupData) {
    auto shape = std::make_shared<b2CircleShape>();
    Point imageSizeInGameUnits = imageScale.scalePoint( gameConfiguration_.getBox2dScreenDimensions()  );
    shape->m_p.Set(0, 0); //position, relative to body position
    shape->m_radius = imageSizeInGameUnits.getX()/2;

    polygonShapesVector_.push_back(shape);

    double density = pow(imageSizeInGameUnits.getX()/2, 2) * 3.14f;

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
