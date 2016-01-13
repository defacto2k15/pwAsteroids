//
// Created by defacto on 2016.01.13..
//

#ifndef PWASTEROIDS_RESOLUTIONSCONTAINER_H
#define PWASTEROIDS_RESOLUTIONSCONTAINER_H

#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <assert.h>

class ResolutionsContainer {
    std::vector< std::pair<int, int>>  resolutions_;
public:
    ResolutionsContainer(std::vector< std::pair<int, int>>  resolutions ) : resolutions_(resolutions){
    }

    std::vector< std::string > getResoutionsAsText(){
        std::vector<std::string> outVec;
        for( auto pair : resolutions_){
            outVec.push_back( createResolutionString( pair ));
        }
        return outVec;
    }

    std::pair<int, int> getResolutionForText(std::string str){
        auto it = std::find_if(begin(resolutions_), end(resolutions_),
                               [str](auto pair)->{ return createResolutionString(pair) == str;});
        assert(it != resolutions_.end());
        return *it;
    };

private:
    std::string createResolutionString( std::pair<int, int> pair){
        std::stringstream ss;
        ss << pair.first << " x " << pair.second;
        return ss.str();
    }
};


#endif //PWASTEROIDS_RESOLUTIONSCONTAINER_H
