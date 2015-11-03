//
// Created by defacto on 26.10.15.
//


#include <lib/gmock-1.7.0/gtest/include/gtest/gtest.h>
#include <Component.h>
#include "ComponentTypeChecker.h"


class C1 : public Component{};
class C2 : public Component{};
class C3 : public C2{};

TEST(ComponentTypeInformationTest, WorksForTwoComponentsOfTheSameTypeWhenSecondIsCastedToBase){
	C3 *ptrToC3;
	ComponentTypeChecker checker(ptrToC3);

	C3 *anotherPtrToC3 = new C3;
	Component *ptrToC3AsComponent = anotherPtrToC3;

	ASSERT_TRUE(checker.wasCastSuccesfull(ptrToC3AsComponent));
}

TEST(ComponentTypeInformationTest, falseIfComponentsAreOfDiffrentType){
	C1 *ptrToC1 = new C1;
	C2 *ptrToC2;
	ComponentTypeChecker checker(ptrToC2);

	ASSERT_FALSE(checker.wasCastSuccesfull(ptrToC1));
}
