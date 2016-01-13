//
// Created by defacto on 2016.01.11..
//

#ifndef PWASTEROIDS_IALLEGROEVENTLISTENER_H
#define PWASTEROIDS_IALLEGROEVENTLISTENER_H

class ViewManager;

class AbstractAllegroEventListener {
public:
    virtual void keyDown(int keynum ){
    };

    virtual void keyUp( int keynum ){
    };
    virtual void mouseKeyDown(int keynum ){
    };
    virtual void mouseKeyUp(int keynum){
    };
    virtual void timeEvent(){
    };

    virtual void charKeyDown(int unicode ){
    }
};

#endif //PWASTEROIDS_IALLEGROEVENTLISTENER_H
