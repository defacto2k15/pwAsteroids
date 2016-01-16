//
// Created by defacto on 2016.01.16..
//

#ifndef PWASTEROIDS_TESTVALUES_H
#define PWASTEROIDS_TESTVALUES_H

#include <map>
#include <Model/PrimitiveTypes/Point.h>
#include <Model/ModelDrawing/ImagePrimitiveType.h>
#include <View/ImageData.h>
#include <Controller/ImageDataContainer.h>

class TestValues {
public:
    static Point getScreenSize();

    static std::map< ImagePrimitiveType, Point> getImageSizesMap();;
};


#endif //PWASTEROIDS_TESTVALUES_H
