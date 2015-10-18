//
// Created by defacto on 16.10.15.
//

#include <lib/gmock-1.7.0/gtest/include/gtest/gtest.h>
#include <PrimitiveTypes/ScaleToScreen.h>
#include <exceptions/BadScaleArgumentException.h>

TEST(ScaleTests, CanAddAndRetriveMembers ) {
	double x = 0.65;
	double y = 0.44;
	ScaleToScreen s(x, y);
	ASSERT_DOUBLE_EQ(x, s.getX());
	ASSERT_DOUBLE_EQ(y, s.getY());
}

TEST( ScaleTests, WhenGivingArgumentNotBetween0And1ExceptionsHappen ){
	ASSERT_THROW( ScaleToScreen(0.12, -1.2), BadScaleArgumentException );
}