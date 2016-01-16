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
    void addData(ImagePrimitiveType type, ImageData data);

    ImageData getData(ImagePrimitiveType type);

    std::map<ImagePrimitiveType, Point> getImageSizesMap(double scalingFactor);;
};


#endif //PWASTEROIDS_IMAGEPATHSCONTAINER_H
