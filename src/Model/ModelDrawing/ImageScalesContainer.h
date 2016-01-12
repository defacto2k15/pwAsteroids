//
// Created by defacto on 2015.12.27..
//

#ifndef PWASTEROIDS_IMAGESCALESCONTAINER_H
#define PWASTEROIDS_IMAGESCALESCONTAINER_H


#include <Model/PrimitiveTypes/ScaleToScreen.h>
#include <Model/configuration/GameConfiguration.h>
#include "ImagePrimitiveType.h"

class ImageScalesContainer {
    GameConfiguration &gameConfiguration_;
    std::map<ImagePrimitiveType, Point> imagePrimitivesSizeMap_;
public:
    ImageScalesContainer(GameConfiguration &gameConfiguration_,
                         const std::map<ImagePrimitiveType, Point> &imagePrimitivesSizeMap_) : gameConfiguration_(
            gameConfiguration_), imagePrimitivesSizeMap_(imagePrimitivesSizeMap_) { }

    ScaleToScreen getImageScale( ImagePrimitiveType type){
        assert(imagePrimitivesSizeMap_.count(type) > 0);
        Point sizeInPixels = imagePrimitivesSizeMap_[type];
        ScaleToScreen out = ScaleToScreen( sizeInPixels / gameConfiguration_.getScreenSizeInPixels());
        std::cout << "Scale is " << out.getX() << "  " << out.getY() << std::endl;
        return out;
    }

    Point getScreenSize(){
        return gameConfiguration_.getScreenSizeInPixels();
    }

};


#endif //PWASTEROIDS_IMAGESCALESCONTAINER_H
