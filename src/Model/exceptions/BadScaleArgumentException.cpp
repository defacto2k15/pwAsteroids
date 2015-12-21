//
// Created by defacto on 16.10.15.
//

#include "BadScaleArgumentException.h"

BadScaleArgumentException::BadScaleArgumentException(std::string text) : std::runtime_error(
		std::string("BadScaleArgumentException happened: ") + text) {
}

BadScaleArgumentException::BadScaleArgumentException() : BadScaleArgumentException("") { }