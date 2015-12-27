//
// Created by defacto on 09.11.15.
//

#ifndef PWASTEROIDS_BOX2DCOMPONENT_H
#define PWASTEROIDS_BOX2DCOMPONENT_H

#include <Model/configuration/ActorsConfiguration.h>
#include <Model/components/Component.h>
#include <Model/box2d/Box2DService.h>
#include <Box2D/Collision/Shapes/b2PolygonShape.h>
#include <Box2D/Dynamics/b2Fixture.h>
#include <Model/components/PositionComponent.h>
#include "IRocketConfigurableValues.h"
#include <cmath>
#include <Model/help/DegreesCalculations.h>
#include <Model/box2d/IBox2dComponent.h>
#include <Model/components/IPositionSettingComponent.h>


class Box2dComponent : public Component{
	std::shared_ptr<Box2DService> box2dService_;
	std::shared_ptr<Box2dObject> box2dObject_;
	std::shared_ptr<PositionComponent> positionComponent_;
	std::shared_ptr<ActorsConfiguration> configurableValues_;

public:
	Box2dComponent(std::shared_ptr<Box2DService> box2dService,
				   std::shared_ptr<ActorsConfiguration> configurableValues,
				   std::shared_ptr<Box2dObject> rocketBox2dObject);

	virtual void OnStart(IActor &actor);

	virtual void OnUpdate();

	virtual void OnStop();

	void applyForce(Point forceVector);

	void applyTorque(double torque);

	void setPosition( double x, double y) ;

	void setRotation( double rotation) ;

	void applyLineralImpulse( Point vec);

	void applyAngularImpulse( double value);

	void SetLineralVelocity(Point speedVector );

	void SetAngularVelocity(double velocity);
private:
	void setTransformation( double x, double y, double rotation );
};


#endif //PWASTEROIDS_BOX2DCOMPONENT_H
