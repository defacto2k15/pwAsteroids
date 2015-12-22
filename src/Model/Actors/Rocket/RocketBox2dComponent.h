//
// Created by defacto on 09.11.15.
//

#ifndef PWASTEROIDS_ROCKETBOX2DCOMPONENT_H
#define PWASTEROIDS_ROCKETBOX2DCOMPONENT_H


#include <Model/components/Component.h>
#include <Model/box2d/Box2DService.h>
#include <Box2D/Collision/Shapes/b2PolygonShape.h>
#include <Box2D/Dynamics/b2Fixture.h>
#include <Model/components/PositionComponent.h>
#include "IRocketConfigurableValues.h"
#include <cmath>
#include <Model/help/DegreesCalculations.h>
#include <Model/box2d/IBox2dComponent.h>

class RocketBox2dComponent : public IBox2dComponent{
	std::shared_ptr<Box2DService> box2dService_;
	std::shared_ptr<Box2dObject> rocketBox2dObject_;
	std::shared_ptr<PositionComponent> rocketPositionComponent_;
	std::shared_ptr<IRocketConfigurableValues> configurableValues_;
	b2PolygonShape polygonShape_;

public:
	RocketBox2dComponent( std::shared_ptr<Box2DService> box2dService , std::shared_ptr<IRocketConfigurableValues> configurableValues);

	virtual void OnStart(IActor &actor);

	virtual void OnUpdate();

	virtual void OnStop();

	void accelerate();

	void turnLeft();

	void turnRight();

	void setPosition( double x, double y) override;

	void setRotation( double rotation) override;
private:
	void setTransformation( double x, double y, double rotation );
};


#endif //PWASTEROIDS_ROCKETBOX2DCOMPONENT_H
