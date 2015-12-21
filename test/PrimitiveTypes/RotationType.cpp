//
// Created by defacto on 28.11.15.
//

#include <lib/gmock-1.7.0/gtest/include/gtest/gtest.h>
#include <Model/PrimitiveTypes/Rotation.h>

TEST( RotationTests, ImplicitConversionToAndFromDoubleWorks ){
	double rotInDegrees = 243.45f;
	Rotation r = rotInDegrees;
	double  secondConversion = r;
	ASSERT_DOUBLE_EQ(rotInDegrees, secondConversion);
}

TEST( RotationTests, turncationFromPositiveNumbersWorksAsExpected ){
	double smallRot = 45.9f;
	double  rotInDegrees = smallRot + 360.0f + 360.0f;
	Rotation r = rotInDegrees;
	double outRotation = r;
	ASSERT_DOUBLE_EQ(smallRot, outRotation);
}

TEST( RotationTests, turncationFromNegativeNumbersWorksAsExpected ){
	double smallRot = 45.9f;
	double  rotInDegrees = smallRot - 360.0f - 360.0f;
	Rotation r = rotInDegrees;
	double outRotation = r;
	ASSERT_DOUBLE_EQ( smallRot, outRotation);
}

TEST( RotationTests, plusEqualsWorks ){
	double rot1 = 56.4f;
	double  rot2 = 44.9f;

	Rotation r = rot1;
	r+=rot2;
	r+=360.0f;
	double outRotation = r;
	ASSERT_DOUBLE_EQ( rot1+rot2, outRotation);
}