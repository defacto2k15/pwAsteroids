//
// Created by defacto on 2015.12.20..
//

#ifndef PWASTEROIDS_BOOSTHELP_H
#define PWASTEROIDS_BOOSTHELP_H

#include <memory>
#include <boost/smart_ptr/shared_ptr.hpp>

template<typename T>
boost::shared_ptr<T> make_boost_shared_ptr(std::shared_ptr<T>& ptr)
{
    return boost::shared_ptr<T>(ptr.get(), [ptr](T*) mutable {ptr.reset();});
}

template<typename T>
std::shared_ptr<T> make_std_shared_ptr(boost::shared_ptr<T>& ptr)
{
    return std::shared_ptr<T>(ptr.get(), [ptr](T*) mutable {ptr.reset();});
}


#endif //PWASTEROIDS_BOOSTHELP_H
