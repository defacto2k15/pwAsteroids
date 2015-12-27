//
// Created by defacto on 2015.12.26..
//

#ifndef PWASTEROIDS_ONSTARTLAMBDACOMPONENT_H
#define PWASTEROIDS_ONSTARTLAMBDACOMPONENT_H


#include "Component.h"
#include <functional>

class OnStartLambdaComponent : public Component{
    std::function< void(IActor &)> function_;
public:
    OnStartLambdaComponent(const std::function<void(IActor &)> &function_) : function_(function_) { }

    void OnStart( IActor &actor) override{
        function_(actor);
    }
};


#endif //PWASTEROIDS_ONSTARTLAMBDACOMPONENT_H
