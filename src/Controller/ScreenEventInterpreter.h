//
// Created by defacto on 2016.01.13..
//

#ifndef PWASTEROIDS_SCREENEVENTINTERPRETER_H
#define PWASTEROIDS_SCREENEVENTINTERPRETER_H


#include "AbstractAllegroEventListener.h"
#include <string>

class ViewManager;

class ScreenEventInterpreter : public AbstractAllegroEventListener{
protected:
    ViewManager *viewManager_;
public:
    virtual std::string getScreenName()=0;

    virtual void setViewManager(ViewManager *manager);
};


#endif //PWASTEROIDS_SCREENEVENTINTERPRETER_H
