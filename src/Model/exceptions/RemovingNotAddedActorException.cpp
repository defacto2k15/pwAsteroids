//
// Created by defacto on 24.10.15.
//

#include "RemovingNotAddedActorException.h"

RemovingNotAddedActorException::RemovingNotAddedActorException(std::string text) : std::runtime_error(
		std::string("RemovingNotAddedActorException happened: ") + text) {
}

RemovingNotAddedActorException::RemovingNotAddedActorException() : RemovingNotAddedActorException("") { }