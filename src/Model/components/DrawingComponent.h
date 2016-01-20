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
	DrawingComponent(IDrawingSystem &drawingSystem, ImagePrimitiveType imageType, ScaleToScreen scaleToScreen);

	virtual void OnStart(IActor &actor);;

	virtual void OnUpdate();;

	virtual void OnStop() override{
		drawingSystem_.addRemovedActorId(actorId_);
	}

	void setVisibility(bool visibility );

    void setSize(double newSize){
        size_ = newSize;
    }

    void setOpacity( double newOpacity){
        opacity_ = newOpacity;
    }
private:
	IDrawingSystem &drawingSystem_;
	std::shared_ptr<PositionComponent> positionComponent_;
	ImagePrimitiveType imageType_;
	bool isVisible_ = true;
	ActorId actorId_;
    double size_ = 1;
    double opacity_ = 1;
};

#endif //PWASTEROIDS_DRAWINGCOMPONENT_H
