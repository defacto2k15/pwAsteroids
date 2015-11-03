//
// Created by defacto on 26.10.15.
//

#ifndef PWASTEROIDS_THEREISMORETHANONECOMPONENTOFGIVENTYPE_H
#define PWASTEROIDS_THEREISMORETHANONECOMPONENTOFGIVENTYPE_H


#include <iostream>
#include <exception>
#include <stdexcept>
#include <string>

class ThereIsNotOneComponentOfGivenType : public std::runtime_error {
public:
	ThereIsNotOneComponentOfGivenType(std::string text);

	ThereIsNotOneComponentOfGivenType(int numberOfComponents);

	ThereIsNotOneComponentOfGivenType();
};


#endif //PWASTEROIDS_THEREISMORETHANONECOMPONENTOFGIVENTYPE_H
