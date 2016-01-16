//
// Created by defacto on 10.12.15.
//

#ifndef PWASTEROIDS_OUTPYTHONCOLLECTOREXPECTATION_H
#define PWASTEROIDS_OUTPYTHONCOLLECTOREXPECTATION_H


#include "IEndToEndExpectation.h"
#include "LambdaExpectation.h"
#include <string>

class OutPythonCollectorExpectation : public InputVariableLambdaExpectation< std::string >{
public:
	OutPythonCollectorExpectation( std::function<LastCheck( std::string)> checkingFunction) : InputVariableLambdaExpectation(checkingFunction){
	}

	virtual bool checkExpectation(){
		auto output = game_->getOutPythonModule().getOutput(); // TOOD clean

		lastCheck_ = checkingFunction_(output);
		lastLoopCount_++;
		return lastCheck_.wasCheckOk;
	}

};


#endif //PWASTEROIDS_OUTPYTHONCOLLECTOREXPECTATION_H
