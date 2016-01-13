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
    ResolutionsContainer(std::vector< std::pair<int, int>>  resolutions );

    std::vector< std::string > getResoutionsAsText();

    std::pair<int, int> getResolutionForText(std::string str);;

private:
    std::string createResolutionString(std::pair<int, int> pair);
};


#endif //PWASTEROIDS_RESOLUTIONSCONTAINER_H
