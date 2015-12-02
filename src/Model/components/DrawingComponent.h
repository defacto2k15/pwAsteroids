//
// Created by defacto on 28.11.15.
//

#ifndef PWASTEROIDS_DRAWINGCOMPONENT_H
#define PWASTEROIDS_DRAWINGCOMPONENT_H

#include <memory>
#include <Model/ModelDrawing/DrawingSystem.h>
#include <Model/Actors/IActor.h>
#include "PositionComponent.h"

class DrawingComponent : public Component{
	ScaleToScreen scaleToScreen_;
public:
	DrawingComponent(std::shared_ptr<DrawingSystem> drawingSystem, ImagePrimitiveType imageType, ScaleToScreen scaleToScreen)
			: drawingSystem_(drawingSystem), imageType_(imageType), scaleToScreen_(scaleToScreen){}

	virtual void OnStart(IActor &actor) override{
		positionComponent_ = actor.getOnlyComponent<PositionComponent>();
	};

	virtual void OnUpdate() override{
		drawingSystem_->drawImage(imageType_,
		                         positionComponent_->getPosition(), positionComponent_->getRotation(), scaleToScreen_);
	};

	void setVisibility(bool visibility ){
		isVisible_ = visibility;
	}

private:
	std::shared_ptr<DrawingSystem> drawingSystem_;
	std::shared_ptr<PositionComponent> positionComponent_;
	ImagePrimitiveType imageType_;
	bool isVisible_ = true;
};

#endif //PWASTEROIDS_DRAWINGCOMPONENT_H
