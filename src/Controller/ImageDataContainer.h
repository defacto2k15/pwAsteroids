//
// Created by defacto on 2016.01.11..
//

#ifndef PWASTEROIDS_IMAGEPATHSCONTAINER_H
#define PWASTEROIDS_IMAGEPATHSCONTAINER_H

#include <map>
#include <Model/ModelDrawing/ImagePrimitiveType.h>
#include <Model/help/StdContainers.h>
#include <stdexcept>
#include <View/ImageData.h>
#include <Model/PrimitiveTypes/Point.h>

class ImageDataContainer {
    std::map<ImagePrimitiveType, ImageData > pathsMap_;
public:
    void addData(ImagePrimitiveType type, ImageData data){
        pathsMap_[type] = data;
    }

    ImageData getData(ImagePrimitiveType type){
        if( pathsMap_.count(type) == 0){
            throw std::runtime_error("There is no path for primitive type of type "+std::to_string(type));
        }
        return  pathsMap_[type];
    }

    std::map< ImagePrimitiveType, Point> getImageSizesMap(){
        std::map<ImagePrimitiveType , Point> outMap;
        for( auto &pair : pathsMap_ ){
            Point size = Point( pair.second.xSize, pair.second.ySize);
            outMap[pair.first] = size;
        }
        return outMap;
    };
};


#endif //PWASTEROIDS_IMAGEPATHSCONTAINER_H
