//
// Created by defacto on 14.10.15.
//

#include <lib/gmock-1.7.0/gtest/include/gtest/gtest.h>
#include <mock/MockComponent.h>
#include <memory>
#include <ComponentsContainer.h>
#include <help/StdContainers.h>
#include <ComponentTypeChecker.h>
#include "exceptions/ThereIsNotOneComponentOfGivenType.h"

class  ComponentsContainerTest : public ::testing::Test
{
public:
	ComponentsContainer container;

	template<typename T>
	void addComponents( std::vector<T> vector ){
		for( T& oneElement :vector ){
			container.addComponent(oneElement);
		}
	}

	template<typename T1, typename T2>
	void assertContainsComponents(std::vector<T1> vectorToBeLookingInto, std::vector<T2> elementsWeAreSearching){
		for( T1& oneElement :  elementsWeAreSearching){
			ASSERT_TRUE(contains(vectorToBeLookingInto, oneElement));
		}
	}
};
TEST_F(ComponentsContainerTest, CanRetriveComponentsOfTheSameType ){
	std::vector<std::shared_ptr<MockComponent> > inVec{
			std::make_shared<MockComponent>(),
			std::make_shared<MockComponent>(),
			std::make_shared<MockComponent>()
	};

	addComponents(inVec);

	std::vector<std::shared_ptr<MockComponent> > components = container.getComponents< MockComponent >();

	ASSERT_EQ(unsigned(3), components.size() ) << "there were not as many retrived components as it was passed " ;
	assertContainsComponents(components, inVec);
}

class ComponentClass1 : public Component{};
class ComponentClass2 : public Component{};
class ComponentClass3 : public Component{};

TEST_F( ComponentsContainerTest, CanRetriveComponentByTypeAmongOtherTypedComponents){
	std::vector<std::shared_ptr<Component> > inVec{
		std::make_shared<ComponentClass1>(),
		std::make_shared<ComponentClass2>(),
		std::make_shared<ComponentClass3>(),
	};

	auto componentWeWillBeLookingFor = std::make_shared<ComponentClass3>();
	inVec.push_back(componentWeWillBeLookingFor);

	addComponents(inVec);

	auto outVec = container.getComponents<ComponentClass3>();
	ASSERT_EQ(unsigned(2), outVec.size());
	ASSERT_TRUE(contains(outVec, componentWeWillBeLookingFor));
}

TEST_F( ComponentsContainerTest, WhenNoComponentsOfGivenTypesArePresentWillReturnEmptyVector){
	std::vector<std::shared_ptr<MockComponent> > inVec{
		std::make_shared<MockComponent>(),
		std::make_shared<MockComponent>(),
		std::make_shared<MockComponent>()
	};

	addComponents(inVec);

	std::vector<std::shared_ptr<MockComponent> > components = container.getComponents< MockComponent >();
	ASSERT_TRUE(container.getComponents<ComponentClass1>().empty());
}

TEST_F( ComponentsContainerTest, GetAllComponentsWorksAsIntended ){
	std::vector<std::shared_ptr<Component> > inVec{
		std::make_shared<ComponentClass1>(),
		std::make_shared<ComponentClass2>(),
		std::make_shared<ComponentClass3>(),
	    std::make_shared<MockComponent>()
	};

	addComponents(inVec);

	auto outVec = container.getAllComponents();
	ASSERT_EQ(unsigned(4), outVec.size());
	assertContainsComponents(outVec, inVec);
}

TEST_F( ComponentsContainerTest, GetsCorrectComponentsUsingComponentsTypeChecker ){
	std::vector<std::shared_ptr<Component> > inVec{
			std::make_shared<ComponentClass1>(),
			std::make_shared<ComponentClass2>(),
			std::make_shared<ComponentClass3>(),
	};

	std::shared_ptr<Component> componentWeWillCheck = std::make_shared<MockComponent>();
	inVec.push_back(componentWeWillCheck);

	addComponents(inVec);
    MockComponent *m;
	ComponentTypeChecker checker = ComponentTypeChecker(m);
	auto outVec = container.getComponents(checker);

	ASSERT_TRUE(contains(outVec, componentWeWillCheck));
	ASSERT_EQ(1, outVec.size());
}

TEST_F(ComponentsContainerTest, getOneComponentWorksAsIntended ){
	std::vector<std::shared_ptr<Component> > inVec{
			std::make_shared<ComponentClass1>(),
			std::make_shared<ComponentClass2>(),
			std::make_shared<ComponentClass3>(),
			std::make_shared<ComponentClass3>(),
			std::make_shared<ComponentClass3>(),
	};
	auto componentWeAreLookingFor = std::make_shared<MockComponent>();
	inVec.push_back(componentWeAreLookingFor);
	addComponents(inVec);

	auto component = container.getOnlyComponent( ComponentTypeChecker::create<MockComponent>());
	ASSERT_EQ(component, componentWeAreLookingFor);
}

TEST_F(ComponentsContainerTest, getOnlyComponentThrowsIfThereIsMoreThanOneComponentOfGivenType ){

	std::vector<std::shared_ptr<Component> > inVec{
			std::make_shared<ComponentClass1>(),
			std::make_shared<ComponentClass2>(),
			std::make_shared<ComponentClass3>(),
			std::make_shared<ComponentClass3>(),
	};

	ASSERT_THROW(container.getOnlyComponent(ComponentTypeChecker::create<ComponentClass3>()),
	                ThereIsNotOneComponentOfGivenType);
}