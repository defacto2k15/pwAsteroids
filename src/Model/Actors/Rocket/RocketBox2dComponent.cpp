//
// Created by defacto on 09.11.15.
//

#include "RocketBox2dComponent.h"


RocketBox2dComponent::RocketBox2dComponent( std::shared_ptr<Box2DService> box2dService , std::shared_ptr<IRocketConfigurableValues> configurableValues)
		: box2dService_(box2dService), configurableValues_(configurableValues) {

	polygonShape_.SetAsBox(2,2);

	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set( configurableValues->getInitialPosition().getX(), configurableValues->getInitialPosition().getY() );
	bodyDef.angle = DegreesCalculations::degreesToRadians( configurableValues->getInitialRotation() );

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &polygonShape_;
	fixtureDef.density = 1;

	std::vector<b2FixtureDef> fixturesVec{fixtureDef};
	rocketBox2dObject_ = std::make_shared<Box2dObject>(bodyDef, fixturesVec);
}

void  RocketBox2dComponent::OnStart(IActor &actor) {
	rocketPositionComponent_ = actor.getOnlyComponent<PositionComponent>();
	box2dService_->addObject(rocketBox2dObject_);

	rocketPositionComponent_->setPosition(configurableValues_->getInitialPosition());
	rocketPositionComponent_->setRotation(configurableValues_->getInitialRotation());

}

void  RocketBox2dComponent::OnUpdate() {
	auto rocketPositionInVec2d = rocketBox2dObject_->getBody()->GetPosition();
	auto rocketRotationInRadians = rocketBox2dObject_->getBody()->GetAngle();

	rocketPositionComponent_->setPosition( Point(rocketPositionInVec2d.x, rocketPositionInVec2d.y));
	rocketPositionComponent_->setRotation( DegreesCalculations::radiansToDegrees(rocketRotationInRadians));
}

void  RocketBox2dComponent::OnStop() {
	box2dService_->removeObject(rocketBox2dObject_);
}

void RocketBox2dComponent::accelerate() { // LOL allways force to the same angle!
	b2Vec2 accVec =  b2Vec2((-1)*(configurableValues_->getRocketAccelerationRate() * sin( DegreesCalculations::degreesToRadians(rocketPositionComponent_->getRotation()))),
	                        configurableValues_->getRocketAccelerationRate() * cos( DegreesCalculations::degreesToRadians(rocketPositionComponent_->getRotation())));
	rocketBox2dObject_->getBody()->ApplyForce(accVec,
	                                          rocketBox2dObject_->getBody()->GetWorldCenter(), true);
}

void RocketBox2dComponent::turnLeft() {
	// Moze wygaszajmy obroty jak nikt nic nie klika?
	//std::cout << "AV: "<<rocketBox2dObject_->getBody()->GetAngularVelocity() << std::endl;
	rocketBox2dObject_->getBody()->ApplyTorque(-configurableValues_->getRocketTurnRate(), true);
}

void RocketBox2dComponent::turnRight() {
	rocketBox2dObject_->getBody()->ApplyTorque(configurableValues_->getRocketTurnRate(), true);
}