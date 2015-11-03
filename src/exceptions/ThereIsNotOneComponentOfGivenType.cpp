//
// Created by defacto on 26.10.15.
//

#include "ThereIsNotOneComponentOfGivenType.h"

ThereIsNotOneComponentOfGivenType::ThereIsNotOneComponentOfGivenType(std::string text) : std::runtime_error(
		std::string("ThereIsNotOneComponentOfGivenType happened: ") + text) {
}

ThereIsNotOneComponentOfGivenType::ThereIsNotOneComponentOfGivenType(int numberOfComponents)
		: ThereIsNotOneComponentOfGivenType(
		"There was " +std::to_string(numberOfComponents)+" elements.") {
}

ThereIsNotOneComponentOfGivenType::ThereIsNotOneComponentOfGivenType() : ThereIsNotOneComponentOfGivenType("") { }