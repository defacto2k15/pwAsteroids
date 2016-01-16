//
// Created by defacto on 2016.01.16..
//

#include "TestValues.h"

Point TestValues::getScreenSize() {
    return Point(1024, 600);
}

std::map< ImagePrimitiveType, Point> TestValues::getImageSizesMap() {
    ImageDataContainer imageDataContainer;
    imageDataContainer.addData(ImagePrimitiveType::Asteroid , ImageData{ 60, 60,  "../res/asteroid3.bmp" });
    imageDataContainer.addData(ImagePrimitiveType::BorderIndicator , ImageData{15, 15, "../res/arrow.bmp"});
    imageDataContainer.addData(ImagePrimitiveType::Projectile , ImageData{15, 15, "../res/projectile.bmp"});
    imageDataContainer.addData(ImagePrimitiveType::Rocket , ImageData{60, 60, "../res/rocket2.bmp"});
    imageDataContainer.addData(ImagePrimitiveType::RocketTail , ImageData{60, 60, "../res/rockettail2.bmp"});
    imageDataContainer.addData(ImagePrimitiveType::Heart , ImageData{ 60, 60, "../res/rocket2.bmp"});
    imageDataContainer.addData(ImagePrimitiveType::SecondPlayerTarget , ImageData{ 60, 60, "../res/target.bmp"});
    return imageDataContainer.getImageSizesMap(0);
}