//
// Created by defacto on 09.11.15.
//

#ifndef PWASTEROIDS_LAMBDAEXPECTATION_H
#define PWASTEROIDS_LAMBDAEXPECTATION_H

#include <string>
#include <memory>
#include "IEndToEndExpectation.h"
#include "src/Model/Observer/IObserver.h"
#include "InputVariableLambdaExpectation.h"


class LambdaExpectation : public InputVariableLambdaExpectation<std::shared_ptr<Game>> {

public:
	LambdaExpectation( std::function<LastCheck (std::shared_ptr<Game> g)> function );

	virtual bool checkExpectation();

};


#endif //PWASTEROIDS_LAMBDAEXPECTATION_H
