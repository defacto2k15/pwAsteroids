//
// Created by defacto on 01.11.15.
//

#ifndef PWASTEROIDS_IPRIMITIVESTODRAWCONTAINER_H
#define PWASTEROIDS_IPRIMITIVESTODRAWCONTAINER_H

#include "ImagePrimitive.h"

class IPrimitivesToDrawContainer {
public:
	virtual void AddImage(ImagePrimitive image)=0;
	virtual ~IPrimitivesToDrawContainer(){};
};


#endif //PWASTEROIDS_IPRIMITIVESTODRAWCONTAINER_H
