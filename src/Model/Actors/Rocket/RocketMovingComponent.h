//
// Created by defacto on 26.10.15.
//

#ifndef PWASTEROIDS_ROCKETMOVINGCOMPONENT_H
#define PWASTEROIDS_ROCKETMOVINGCOMPONENT_H

#include <Model/components/PositionComponent.h>
#include <Model/modelInterfaces/IKeyboardStateProvider.h>
#include <Model/Services/IPhysicsService.h>
#include <Model/box2d/Box2DService.h>
#include <Model/components/DrawingComponent.h>
#include "RocketBox2dComponent.h"
#include "Model/modelInterfaces/Keys.h"
#include "IRocketConfigurableValues.h"
#include <exception>
#include <stdexcept>
#include <Model/python/PythonClassVisibilityModule.h>


class RocketMovingComponent : public Component {
	std::shared_ptr<RocketBox2dComponent> box2dComponent_;
	std::shared_ptr<IKeyboardStateProvider> keyboardStateProvider_;
	std::shared_ptr<DrawingComponent> rocketTailDrawing_;
	PythonClassVisibilityModule<RocketMovingComponent,  std::shared_ptr<IKeyboardStateProvider>, std::shared_ptr<PythonModule> > visibilityModule_;

public:
	RocketMovingComponent( std::shared_ptr<IKeyboardStateProvider> keyboardStateProvider, std::shared_ptr<PythonModule> pythonModule )
			: keyboardStateProvider_(keyboardStateProvider), visibilityModule_(pythonModule){
	}

	virtual void OnStart(IActor &actor);

	virtual void OnUpdate();

	void setRocketTail( std::shared_ptr<IActor> tailActor);

	int someStupidFunction( float arg ){ // todo remove
		std::cout << "Dano mi " << arg << std::endl;
		return arg + 33;
	}

	virtual void OnStop() override{};
private:

};
#endif //PWASTEROIDS_ROCKETMOVINGCOMPONENT_H
