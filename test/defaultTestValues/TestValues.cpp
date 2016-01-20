//
// Created by defacto on 2016.01.16..
//

#include "TestValues.h"

Point TestValues::getScreenSize() {
    return Point(1024, 600);
}

std::map< ImagePrimitiveType, Point> TestValues::getImageSizesMap() {
    ImageDataContainer imageDataContainer;
    imageDataContainer.addData(ImagePrimitiveType::Asteroid , ImageData{ 240, 240,  "../res/asteroid3.bmp" });
    imageDataContainer.addData(ImagePrimitiveType::BorderIndicator , ImageData{60, 60, "../res/arrow.bmp"});
    imageDataContainer.addData(ImagePrimitiveType::Projectile , ImageData{60, 60, "../res/projectile.bmp"});
    imageDataContainer.addData(ImagePrimitiveType::Rocket , ImageData{160, 240, "../res/rX.bmp"});
    imageDataContainer.addData(ImagePrimitiveType::RocketTail , ImageData{240, 240, "../res/rockettail2.bmp"});
    imageDataContainer.addData(ImagePrimitiveType::Heart , ImageData{ 240, 240, "../res/rocket2.bmp"});
    imageDataContainer.addData(ImagePrimitiveType::SecondPlayerTarget , ImageData{ 240, 240, "../res/target.bmp"});
    imageDataContainer.addData(ImagePrimitiveType::NotVisibleElement, ImageData{ 240, 240, "../res/target.bmp"});
    imageDataContainer.addData(ImagePrimitiveType::TripleShootPowerup, ImageData{ 240, 240, "../res/target.bmp"});
    imageDataContainer.addData(ImagePrimitiveType::HealthPowerup, ImageData{ 240, 240, "../res/rX.bmp"});
    imageDataContainer.addData(ImagePrimitiveType::ExplosionCloud , ImageData{ 240, 240,  "../res/asteroid3.bmp" });
    return imageDataContainer.getImageSizesMap(1);
}