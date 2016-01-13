//
// Created by defacto on 2016.01.11..
//

#include "ImageDataContainer.h"

void ImageDataContainer::addData(ImagePrimitiveType type, ImageData data) {
    pathsMap_[type] = data;
}

ImageData ImageDataContainer::getData(ImagePrimitiveType type) {
    if( pathsMap_.count(type) == 0){
        throw std::runtime_error("There is no path for primitive type of type "+std::to_string(type));
    }
    return  pathsMap_[type];
}

std::map< ImagePrimitiveType, Point> ImageDataContainer::getImageSizesMap() {
    std::map<ImagePrimitiveType , Point> outMap;
    for( auto &pair : pathsMap_ ){
        Point size = Point( pair.second.xSize, pair.second.ySize);
        outMap[pair.first] = size;
    }
    return outMap;
}