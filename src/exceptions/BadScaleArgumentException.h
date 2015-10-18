//
// Created by defacto on 16.10.15.
//

#ifndef PWASTEROIDS_BADSCALEARGUMENTEXCEPTION_H
#define PWASTEROIDS_BADSCALEARGUMENTEXCEPTION_H

#include <iostream>
#include <exception>
#include <stdexcept>
#include <string>

class BadScaleArgumentException : public std::runtime_error {
public:
	BadScaleArgumentException(std::string text);

	BadScaleArgumentException();
};

#endif //PWASTEROIDS_BADSCALEARGUMENTEXCEPTION_H
