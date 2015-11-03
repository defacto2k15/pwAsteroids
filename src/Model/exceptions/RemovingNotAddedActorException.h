//
// Created by defacto on 24.10.15.
//

#ifndef PWASTEROIDS_NOTADDEDACTOREXCEPTION_H
#define PWASTEROIDS_NOTADDEDACTOREXCEPTION_H

#include <iostream>
#include <exception>
#include <stdexcept>
#include <string>

class RemovingNotAddedActorException : public std::runtime_error {
public:
	RemovingNotAddedActorException(std::string text);

	RemovingNotAddedActorException();
};


#endif //PWASTEROIDS_NOTADDEDACTOREXCEPTION_H
