//
// Created by defacto on 16.10.15.
//

#ifndef PWASTEROIDS_FOREVERYLOOP_H
#define PWASTEROIDS_FOREVERYLOOP_H


#include "WhenCheckExpectations.h"

namespace when{
	class ForEveryLoop : public WhenCheckExpectations {

	public:
		virtual bool CheckExpectations();
	};
}


#endif //PWASTEROIDS_FOREVERYLOOP_H
