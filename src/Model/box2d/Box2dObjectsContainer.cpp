//
// Created by defacto on 2015.12.26..
//

#include "Box2dObjectsContainer.h"

Box2dObjectsContainer::Box2dObjectsContainer(ImageScalesContainer &imageScalesContainer, ActorsConfiguration &actorsConfiguration )
        : imageScalesContainer_(imageScalesContainer), actorsConfiguration_(actorsConfiguration) {
}

std::shared_ptr<Box2dObject> Box2dObjectsContainer::getRocketObject() {
    return createObjectWithBoxShape(imageScalesContainer_.getRocketImageScale(), 120);
}

std::shared_ptr<Box2dObject> Box2dObjectsContainer::getAsteriodObject(double size) {
    return createObjectWithBoxShape(imageScalesContainer_.getBasicAsteroidImageScale(), 120);
}

std::shared_ptr<Box2dObject> Box2dObjectsContainer::getProjectileObject() {
    return createObjectWithBoxShape(imageScalesContainer_.getProjectileImageScale(), 120);
}

std::shared_ptr<Box2dObject> Box2dObjectsContainer::createObjectWithBoxShape(ScaleToScreen imageScale, double densityPerSquareUnit ) {
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