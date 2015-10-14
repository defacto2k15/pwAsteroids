//
// Created by defacto on 14.10.15.
//
#ifndef PWASTEROIDS_STDCONTAINERS_H
#define PWASTEROIDS_STDCONTAINERS_H
#include <algorithm>

template<typename ContainerType>
bool contains(ContainerType container , decltype(*(container.begin())) item ){
	return std::find(std::begin(container), container.end(), item) != container.end();
};
#endif //PWASTEROIDS_STDCONTAINERS_H
