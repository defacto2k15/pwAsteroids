//
// Created by defacto on 28.11.15.
//

#ifndef PWASTEROIDS_DRAWINGCOMPONENT_H
#define PWASTEROIDS_DRAWINGCOMPONENT_H


#include <Model/ModelDrawing/DrawingSystem.h>
#include <Model/Actors/IActor.h>
#include "PositionComponent.h"

class DrawingComponent : public Component{
public:
	DrawingComponent(DrawingSystem &drawingSystem, ImagePrimitiveType imageType)
			: drawingSystem_(drawingSystem), imageType_(imageType){}

	virtual void OnStart(IActor &actor) override{
		positionComponent_ = actor.getOnlyComponent<PositionComponent>();
	};

	virtual void OnUpdate() override{
		drawingSystem_.drawImage(imageType_,
		                         positionComponent_->getPosition(), positionComponent_->getRotation());
	};

	void setVisibility(bool visibility ){
		isVisible_ = visibility;
	}

private:
	DrawingSystem &drawingSystem_;
	std::shared_ptr<PositionComponent> positionComponent_;
	ImagePrimitiveType imageType_;
	bool isVisible_ = true;
};

#endif //PWASTEROIDS_DRAWINGCOMPONENT_H
