//
// Created by defacto on 01.12.15.
//

#ifndef PWASTEROIDS_OUTGAMESCREENMODELSCALER_H
#define PWASTEROIDS_OUTGAMESCREENMODELSCALER_H


#include <memory>
#include <Model/configuration/IScreenScallingConfiguration.h>
#include <Model/configuration/ActorsConfiguration.h>
#include "IOutGameScreenModel.h"

class OutGameScreenModelScaler : public IOutGameScreenModel {
	std::shared_ptr<IOutGameScreenModel> originalOutGameScreenModel_;
	ActorsConfiguration &configuration_;
public:
	OutGameScreenModelScaler(std::shared_ptr<IOutGameScreenModel> originalOutGameScreenModel,
	                         ActorsConfiguration &configuration) :
			originalOutGameScreenModel_(originalOutGameScreenModel), configuration_(configuration){
	}

	virtual std::vector<ImagePrimitive> getImagePrimitives();


	virtual std::vector<TextPrimitive> getTextPrimitives() override;

	virtual void OnUpdate();


	virtual void AddPrimitive(std::shared_ptr<IDrawablePrimitive> primitive) override;

	virtual std::vector<ActorId> getRemovedActorsIds() override;

	virtual void AddRemovedPrimitiveId(ActorId id) override;

private:
	Point calculateNewPosition(Point oldPosition);
};


#endif //PWASTEROIDS_OUTGAMESCREENMODELSCALER_H
