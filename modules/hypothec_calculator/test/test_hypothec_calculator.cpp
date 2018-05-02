#pragma once// Copyright 2018 Rodionov Fedor

#include <gtest/gtest.h>

#include <string>

#include "hypothec_calculator.h"

TEST_F(HypothecCalculator, Can_set_day_and_check_return_day) {
    // Arrange
    HypothecCalculator H;
    date data;
    data.day = 9;
    data.month = 5;
    data.year = 2018;

    // Act
    H.set_date_of_payment(data);

    // Assert
    EXPECT_EQ(H.return_final_date_of_payment().day, (data.day + 180) % 30 );
}

TEST_F(HypothecCalculator, Can_set_month_and_check_return_month) {
    // Arrange
    HypothecCalculator H;
    date data;
    data.day = 9;
    data.month = 10;
    data.year = 2018;

    // Act
    H.set_date_of_payment(data);

    // Assert
    EXPECT_EQ(H.return_final_date_of_payment().month, (data.month + 6) % 12 - 1);
}

TEST_F(HypothecCalculator, Can_set_year_and_check_return_year) {
    // Arrange
    HypothecCalculator H;
    date data;
    data.day = 9;
    data.month = 10;
    data.year = 2018;

    // Act
    H.set_date_of_payment(data);

    // Assert
    EXPECT_EQ(H.return_final_date_of_payment().year, 2019);
}

TEST_F(HypothecCalculator, Can_true_count_differentiated_payment_type) {
    // Arrange
    HypothecCalculator H;

    // Act
    H.set_payment_type(1);

    // Assert
    EXPECT_EQ(H.return_final_amount_of_payment(), 1029.17);
}

TEST_F(HypothecCalculator, Can_true_count_annuity_payment_type) {
    // Arrange
    HypothecCalculator H;

    // Act
    H.set_payment_type(2);

    // Assert
    EXPECT_EQ(H.return_final_amount_of_payment(), 1029.37);
}

TEST_F(HypothecCalculator, Cannt_set_minus_value_to_monthly_commissions) {
    // Arrange
    float value = -10;
    HypothecCalculator H;

    // Act & Assert
    ASSERT_ANY_THROW(H.set_monthly_commissions(value));
}

TEST_F(HypothecCalculator, Cannt_set_minus_value_to_first_commissions) {
    // Arrange
    float value = -10;
    HypothecCalculator H;

    // Act & Assert
    ASSERT_ANY_THROW(H.set_first_commissions(value));
}

TEST_F(HypothecCalculator, Cannt_create_object_with_minus_value) {
    // Arrange
    float value1 = -10;
    float value2 = -15;
    float value3 = -20;
    int value4 = -25;

    // Act & Assert
    ASSERT_ANY_THROW(HypothecCalculator H(value1, value2, value4, value3);
}

TEST_F(HypothecCalculator, Cannt_set_last year) {
    // Arrange
    HypothecCalculator H;
    date data;

    // Act
    data.day = 9;
    data.month = 10;
    data.year = 2018;

    //=Assert
    ASSERT_ANY_THROW(H.set_date_of_payment(data));
}