//
// Created by defacto on 24.10.15.
//

#ifndef PWASTEROIDS_SERVICE_H
#define PWASTEROIDS_SERVICE_H

class IService {
public:
	virtual void OnStart(){};
	virtual void OnStop(){};
	virtual void OnUpdate(){};
	virtual ~IService(){};
};

#endif //PWASTEROIDS_SERVICE_H
