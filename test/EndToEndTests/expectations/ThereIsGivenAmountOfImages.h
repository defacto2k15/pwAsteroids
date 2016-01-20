//
// Created by root on 2016.01.20..
//

#ifndef PWASTEROIDS_THEREISGIVENAMOUNTOFIMAGES_H
#define PWASTEROIDS_THEREISGIVENAMOUNTOFIMAGES_H


#include "IEndToEndExpectation.h"
#include "InputVariableLambdaExpectation.h"

class ThereIsGivenAmountOfImages  :public IEndToEndExpectation{
    ImagePrimitiveType expectedType_;
    int expectedCount_;
    int lastRealCount_;
    std::shared_ptr<Game> game_;
public:
    ThereIsGivenAmountOfImages(const ImagePrimitiveType &expectedType_, int expectedCount_) :
                                                     expectedType_(expectedType_), expectedCount_(expectedCount_) {
    }

    virtual std::string getExpectationDescription(){
        return std::string("We expect that there will be ") + std::to_string(expectedCount_)
               + std::string(" Images of type ") + std::to_string(int(expectedType_));
    }


    virtual bool checkExpectation() override{
        auto primitives = game_->getOutGameScreenModel()->getImagePrimitives();
        lastRealCount_ = std::count_if(begin(primitives), end(primitives), [&](ImagePrimitive &primitive){
            return primitive.getImageType() == expectedType_;
        });
        return lastRealCount_ == expectedCount_;
    }

    virtual std::string getFailureMessage(){
        return std::string("But there was ") + std::to_string(lastRealCount_);
    }


    virtual void beforeFirstUpdate(std::shared_ptr<Game> game) override{
        game_ = game;
    }
};


#endif //PWASTEROIDS_THEREISGIVENAMOUNTOFIMAGES_H
