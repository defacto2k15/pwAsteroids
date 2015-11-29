//
// Created by defacto on 14.10.15.
//
#ifndef PWASTEROIDS_STDCONTAINERS_H
#define PWASTEROIDS_STDCONTAINERS_H
#include <algorithm>

template<typename ContainerType>
bool contains(ContainerType &container , decltype(*(container.begin())) item ){
	return std::find(std::begin(container), container.end(), item) != container.end();
};

template< typename ContainerType>
bool removeItem(ContainerType &container, decltype(*(container.begin())) item ){
	if( contains(container, item) == false){
		return false;
	}
	container.erase(std::remove(container.begin(), container.end(), item), container.end()) ;
	return true;
}
#endif //PWASTEROIDS_STDCONTAINERS_H
