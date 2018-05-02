// Copyright 2018 Rodionov Fedor
#include "hypothec_calculator.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

HypothecCalculator::HypothecCalculator()
{
	apartments_cost = 1000000;
	an_initial_fee = 0;
	credit_term_in_month = 60;
	interest_rate_in_month = 12.5;
	first_commissions = 0;
	monthly_commissions = 0;
	differentiated_payment_type = false;
	annuity_payment_type = true;
	start_of_payments.day = 9;
	start_of_payments.month = 5;
	start_of_payments.year = 2018;
}

HypothecCalculator::HypothecCalculator(float _app_costs, float _an_initial_fee, int _credit_term_in_month, float _interest_rate_in_month)
{
	if ((_app_costs <= 0) || (_an_initial_fee <= 0) || (_credit_term_in_month <= 0) || (_interest_rate_in_month <= 0)) throw std::string("Can't be lower then zero");
	apartments_cost = _app_costs;
	an_initial_fee = _an_initial_fee;
	credit_term_in_month = _credit_term_in_month;
	interest_rate_in_month = _interest_rate_in_month;
	first_commissions = 0;
	monthly_commissions = 0;
	annuity_payment_type = true;
	start_of_payments.day = 9;
	start_of_payments.month = 5;
	start_of_payments.year = 2018;
}

void HypothecCalculator::set_first_commissions(float _first_commissions)
{
	if ((_first_commissions <= 0)) throw std::string("Can't be lower then zero");
	first_commissions = _first_commissions;
}

void HypothecCalculator::set_monthly_commissions(float _monthly_commissions)
{
	if ((_monthly_commissions <= 0)) throw std::string("Can't be lower then zero");
	monthly_commissions = _monthly_commissions;
}

void HypothecCalculator::set_payment_type(int type)
{
	if (type % 2 == 0)
	{
		differentiated_payment_type = false;
		annuity_payment_type = true;
	}
	else
	{
		differentiated_payment_type = true;
		annuity_payment_type = false;
	}
}

void HypothecCalculator::set_date_of_payment(date _start_of_payments)
{
	start_of_payments.day = _start_of_payments.day;
	start_of_payments.month = _start_of_payments.month;
	start_of_payments.year = _start_of_payments.year;
}

float HypothecCalculator::return_final_amount_of_payment()
{
	float loan_debt = apartments_cost;
	float debt_per_month_main;
	float debt_per_month_extra;
	float debt_per_month_extra_sum = 0;
	float accrued_interest_in_the_period;

	if (differentiated_payment_type)
	{
		debt_per_month_main = apartments_cost / credit_term_in_month;
		for (int i = 0; i < credit_term_in_month; i++)
		{
			accrued_interest_in_the_period = loan_debt * interest_rate_in_month / (credit_term_in_month * 100);
			debt_per_month_extra = debt_per_month_main + debt_per_month_main* accrued_interest_in_the_period / 100;
			loan_debt = apartments_cost - debt_per_month_extra;
			debt_per_month_extra_sum += debt_per_month_extra;
		}
		return debt_per_month_extra_sum;
	}

	else
	{
		return debt_per_month_extra_sum;
	}
}

float HypothecCalculator::final_interest_charges()
{
	return 0;
}

date HypothecCalculator::return_final_date_of_payment()
{
	final_date_of_payment.day = (start_of_payments.day + credit_term_in_month * 30) % 30;
	final_date_of_payment.month = (start_of_payments.month + credit_term_in_month) % 12;
	final_date_of_payment.year = (start_of_payments.year + credit_term_in_month / 12);
	return final_date_of_payment;
}