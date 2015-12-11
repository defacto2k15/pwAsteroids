//
// Created by defacto on 10.12.15.
//

#ifndef PWASTEROIDS_IOUTPYTHONMODULE_H
#define PWASTEROIDS_IOUTPYTHONMODULE_H
#include <string>

class IOutPythonModule {
public:
	virtual std::string getOutput()=0;
};


#endif //PWASTEROIDS_IOUTPYTHONMODULE_H
