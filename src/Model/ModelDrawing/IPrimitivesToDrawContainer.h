//
// Created by defacto on 01.11.15.
//

#ifndef PWASTEROIDS_IPRIMITIVESTODRAWCONTAINER_H
#define PWASTEROIDS_IPRIMITIVESTODRAWCONTAINER_H

#include "ImagePrimitive.h"
#include "TextPrimitive.h"
#include <memory>

class IPrimitivesToDrawContainer {
public:
	virtual void AddPrimitive( std::shared_ptr<IDrawablePrimitive> primitive)=0;
	virtual void AddRemovedPrimitiveId( ActorId id)=0;
	virtual ~IPrimitivesToDrawContainer(){};
};


#endif //PWASTEROIDS_IPRIMITIVESTODRAWCONTAINER_H
