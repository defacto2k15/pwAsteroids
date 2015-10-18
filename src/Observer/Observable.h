//
// Created by defacto on 16.10.15.
//

#ifndef PWASTEROIDS_OBSERVABLE_H
#define PWASTEROIDS_OBSERVABLE_H

#include <vector>
class IObserver;

class Observable {
	std::vector<IObserver*> observers_;
public:
	void addObserver( IObserver* newObserver );

	void removeObserver( IObserver* observerToRemove );

	void notifyObservers();
private:
	void assertObserverIsNotArleadyAdded(IObserver *pObserver);

	void assertObserverWasAdded(IObserver *pObserver);
};


#endif //PWASTEROIDS_OBSERVABLE_H
