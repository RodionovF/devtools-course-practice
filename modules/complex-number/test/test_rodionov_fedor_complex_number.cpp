// Copyright 2018 Rodionov Fedor

#include <gtest/gtest.h>

#include "include/complex_number.h"
#include "test_rodionov_fedor_complex_number.h"

TEST(Rodionov_Fedor_ComplexNumberTest, degree_of_i) {
	// Arrange
	ComplexNumber z1(0.0, 1.0);

	// Act
	ComplexNumber z=z1 * z1 * z1 * z1;

	// Assert
	EXPECT_EQ(1, z.getRe());
}

TEST(Rodionov_Fedor_ComplexNumberTest, find_argument) {
	// Arrange
	ComplexNumber z1(5.0, 5.0);
	double tg_fi = 1;
	// Act
	double z = z1.getRe()/z1.getIm();
	
	// Assert
	EXPECT_EQ(tg_fi,z);
}

TEST(Rodionov_Fedor_ComplexNumberTest, both_side_multiplay) {
	// Arrange
	ComplexNumber z1(5.0, 5.0);
	ComplexNumber z2(3.0, 3.0);
	// Act
	ComplexNumber z = z1 * z2;
	ComplexNumber z_ = z2 * z1;

	// Assert
	EXPECT_TRUE(z == z_);
}

TEST(Rodionov_Fedor_ComplexNumberTest, conjugate_argument) {
	// Arrange
	ComplexNumber z1(5.0, 5.0);
	ComplexNumber z2(5.0, -5.0);
	// Act
	double z = std::atan(z1.getRe() / z1.getIm());
	double z_ = -std::atan(z2.getRe() / z2.getIm());
	// Assert
	EXPECT_EQ(z, z_);
}

TEST(Rodionov_Fedor_ComplexNumberTest, square_of_degree_module_complex_number) {
	// Arrange
	ComplexNumber z1(1.0 , 3.0);
	// Act
	double z = std::pow(z1.getRe(),2)+ std::pow(z1.getIm(),2);
	// Assert
	EXPECT_EQ(10, z);
}