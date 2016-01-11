//
// Created by defacto on 2016.01.11..
//

#ifndef PWASTEROIDS_IMAGEPATHSCONTAINER_H
#define PWASTEROIDS_IMAGEPATHSCONTAINER_H

#include <map>
#include <Model/ModelDrawing/ImagePrimitiveType.h>
#include <Model/help/StdContainers.h>
#include <stdexcept>

class ImagePathsContainer {
    std::map<ImagePrimitiveType, std::string > pathsMap_;
public:
    void addPath(ImagePrimitiveType type, std::string path){
        pathsMap_[path] = type;
    }

    std::string getPath(ImagePrimitiveType type){
        if( pathsMap_.count(type) == 0){
            throw std::runtime_error("There is no path for primitive type of type "+std::to_string(type));
        }
        return  pathsMap_[type];
    }
};


#endif //PWASTEROIDS_IMAGEPATHSCONTAINER_H
