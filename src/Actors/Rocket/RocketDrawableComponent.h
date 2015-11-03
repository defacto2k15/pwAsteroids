//
// Created by defacto on 26.10.15.
//

#ifndef PWASTEROIDS_ROCKETDRAWABLECOMPONENT_H
#define PWASTEROIDS_ROCKETDRAWABLECOMPONENT_H


#include <components/PositionComponent.h>
#include <ModelDrawing/DrawingSystem.h>
#include "ModelDrawing/ImagePrimitiveType.h"
class RocketDrawableComponent : public Component{

public:
	RocketDrawableComponent(DrawingSystem &drawingSystem ) : drawingSystem_(drawingSystem){}

	virtual void OnStart(IActor &actor) override{
		positionComponent_ = actor.getOnlyComponent<PositionComponent>();
	};

	virtual void OnUpdate() override{
		drawingSystem_.drawImage(ImagePrimitiveType::Rocket,
		                         positionComponent_->getPosition(), positionComponent_->getRotation());
	};

private:
	DrawingSystem &drawingSystem_;
	std::shared_ptr<PositionComponent> positionComponent_;
};


#endif //PWASTEROIDS_ROCKETDRAWABLECOMPONENT_H
