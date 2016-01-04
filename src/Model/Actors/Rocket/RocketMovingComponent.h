//
// Created by defacto on 26.10.15.
//

#ifndef PWASTEROIDS_ROCKETMOVINGCOMPONENT_H
#define PWASTEROIDS_ROCKETMOVINGCOMPONENT_H

#include <Model/components/PositionComponent.h>
#include <Model/modelInterfaces/IInputStateProvider.h>

#include <Model/Services/IPhysicsService.h>
#include <Model/box2d/Box2DService.h>
#include <Model/components/DrawingComponent.h>
#include "Box2dComponent.h"
#include "Model/modelInterfaces/Keys.h"
#include <exception>
#include <stdexcept>
#include <Model/python/PythonClassVisibilityModule.h>
#include <Model/configuration/GameConfiguration.h>


class RocketMovingComponent : public Component {
	std::shared_ptr<Box2dComponent> box2dComponent_;
	std::shared_ptr<IInputStateProvider> inputStateProvider_;
	std::shared_ptr<DrawingComponent> rocketTailDrawing_;
	GameConfiguration &gameConfiguration_;
	std::shared_ptr<PositionComponent> rocketPositionComponent_;
	PythonClassVisibilityModule<RocketMovingComponent,  std::shared_ptr<IInputStateProvider>,
			std::shared_ptr<PythonModule>, GameConfiguration &> visibilityModule_;

public:
	RocketMovingComponent(std::shared_ptr<IInputStateProvider> inputStateProvider,
						  std::shared_ptr<PythonModule> pythonModule, GameConfiguration &gameConfiguration );

	virtual void OnStart(IActor &actor);

	virtual void OnUpdate();

	void setRocketTail( std::shared_ptr<IActor> tailActor);

	int someStupidFunction( float arg ){ // todo remove
		std::cout << "Dano mi " << arg << std::endl;
		return arg + 33;
	}

	virtual void OnStop() override{};
private:
	void accelerate();

};
#endif //PWASTEROIDS_ROCKETMOVINGCOMPONENT_H
