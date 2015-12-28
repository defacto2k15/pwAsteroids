//
// Created by defacto on 09.11.15.
//

#include <Model/configuration/ActorsConfiguration.h>
#include "Box2dComponent.h"


Box2dComponent::Box2dComponent(std::shared_ptr<Box2DService> box2dService,
							   ActorsConfiguration &configurableValues,
							   std::shared_ptr<Box2dObject> rocketBox2dObject)
		: box2dService_(box2dService), configurableValues_(configurableValues), box2dObject_(rocketBox2dObject) {
}

void  Box2dComponent::OnStart(IActor &actor) {
	positionComponent_ = actor.getOnlyComponent<PositionComponent>();
	box2dService_->addObject(box2dObject_);

	positionComponent_->setPosition(configurableValues_.getInitialPosition());
	positionComponent_->setRotation(configurableValues_.getInitialRotation());

	b2Vec2 position( configurableValues_.getInitialPosition().getX(), configurableValues_.getInitialPosition().getY() );
	box2dObject_->getBody()->SetTransform(position, DegreesCalculations::degreesToRadians(configurableValues_.getInitialRotation() ));

}

void  Box2dComponent::OnUpdate() {
	auto rocketPositionInVec2d = box2dObject_->getBody()->GetPosition();
	auto rocketRotationInRadians = box2dObject_->getBody()->GetAngle();

	positionComponent_->setPosition(Point(rocketPositionInVec2d.x, rocketPositionInVec2d.y));
	positionComponent_->setRotation(DegreesCalculations::radiansToDegrees(rocketRotationInRadians));
}

void  Box2dComponent::OnStop() {
	box2dService_->removeObject(box2dObject_);
}

void Box2dComponent::setPosition(double x, double y) {
	setTransformation(x, y, box2dObject_->getBody()->GetAngle());
}

void Box2dComponent::setRotation(double rotation) {
	auto currentPosition = box2dObject_->getBody()->GetPosition();
	setTransformation(currentPosition.x, currentPosition.y, DegreesCalculations::degreesToRadians(rotation));
}

void Box2dComponent::setTransformation(double x, double y, double rotationInRadians) {
	box2dObject_->getBody()->SetTransform(b2Vec2(x, y), rotationInRadians);
}

void Box2dComponent::applyForce(Point forceVector) {
	b2Vec2 accVec =  b2Vec2(forceVector.getX(), forceVector.getY());
	box2dObject_->getBody()->ApplyForce(accVec,
										box2dObject_->getBody()->GetWorldCenter(), true);
}

void Box2dComponent::applyTorque(double torque) {
	box2dObject_->getBody()->ApplyTorque(torque, true);
}

void Box2dComponent::applyLineralImpulse(Point vecAsPoint) {
	b2Vec2 vec(vecAsPoint.getX(), vecAsPoint.getY());
	box2dObject_->getBody()->ApplyLinearImpulse(vec, box2dObject_->getBody()->GetWorldCenter(), true);
}

void Box2dComponent::applyAngularImpulse(double value) {
	box2dObject_->getBody()->ApplyAngularImpulse(value, true);
}

void Box2dComponent::SetLineralVelocity(Point speedVector ) {
	b2Vec2 vec( speedVector.getX(), speedVector.getY());
	box2dObject_->getBody()->SetLinearVelocity(vec);
}

void Box2dComponent::SetAngularVelocity(double velocity) {
	box2dObject_->getBody()->SetAngularVelocity(velocity);
}

Point Box2dComponent::getLineralVelocity() {
	Point returnValue( box2dObject_->getBody()->GetLinearVelocity().x,
					   box2dObject_->getBody()->GetLinearVelocity().y);
	return returnValue;
}