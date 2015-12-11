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
	DrawingComponent(std::shared_ptr<DrawingSystem> drawingSystem, ImagePrimitiveType imageType, ScaleToScreen scaleToScreen);

	virtual void OnStart(IActor &actor);;

	virtual void OnUpdate();;

	void setVisibility(bool visibility );

private:
	std::shared_ptr<DrawingSystem> drawingSystem_;
	std::shared_ptr<PositionComponent> positionComponent_;
	ImagePrimitiveType imageType_;
	bool isVisible_ = true;
	ActorId actorId_;
};

#endif //PWASTEROIDS_DRAWINGCOMPONENT_H
