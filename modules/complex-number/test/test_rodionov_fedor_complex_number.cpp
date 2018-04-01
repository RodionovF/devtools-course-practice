// Copyright 2018 Rodionov Fedor

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Rodionov_Fedor_ComplexNumberTest, degree_of_i) {
	// Arrange
	ComplexNumber z1(0.0, 1.0);

	// Act
	ComplexNumber z=z1*z1*z1*z1;

	// Assert
	EXPECT_EQ(1, z.getRe());
}