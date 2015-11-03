//
// Created by defacto on 24.10.15.
//

#ifndef PWASTEROIDS_ROOTSERVICECONTAINERTEST_H
#define PWASTEROIDS_ROOTSERVICECONTAINERTEST_H

#include <Services/IService.h>
#include <memory>
#include <vector>
#include <lib/gmock-1.7.0/gtest/include/gtest/gtest.h>
#include <mock/MockService.h>
#include <Services/RootServiceContainer.h>
#include <iostream>
class RootServiceContainerTest : public ::testing::Test {
public:
	std::vector<std::shared_ptr<MockIService>> mockServicesVec_;
	RootServiceContainer container;
	void SetUp(){
		for(int i = 0; i < 10; i++){
			mockServicesVec_.push_back(std::make_shared<MockIService>());
		}
	}

	std::vector<std::shared_ptr<IService>> getIServiceVector(){
		std::vector<std::shared_ptr<IService>> outVec(mockServicesVec_.size());
		std::copy(begin(mockServicesVec_), end(mockServicesVec_), begin(outVec));
		return outVec;
	}
};

TEST_F(RootServiceContainerTest, onSetupIsCalledCorrectly){
	container.addService(getIServiceVector());
	for(auto &oneService : mockServicesVec_){
		EXPECT_CALL(*oneService, OnStart()).Times(1);
	}
	container.OnStart();
}

TEST_F(RootServiceContainerTest, onUpdateCalledCorrectly){
	container.addService(getIServiceVector());
	for(auto &oneService : mockServicesVec_){
		EXPECT_CALL(*oneService, OnUpdate()).Times(1);
	}
	container.OnUpdate();
}

#endif //PWASTEROIDS_ROOTSERVICECONTAINERTEST_H
