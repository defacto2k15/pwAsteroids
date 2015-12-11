//
// Created by defacto on 10.12.15.
//

#ifndef PWASTEROIDS_IINPYTHONMODULE_H
#define PWASTEROIDS_IINPYTHONMODULE_H

#include <string>

class IInPythonModule {
public:
	virtual void addCommand( std::string commandText)=0;
};
#endif //PWASTEROIDS_IINPYTHONMODULE_H
