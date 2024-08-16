#ifndef FUNCTIONS_CPP11_H
#define FUNCTIONS_CPP11_H

#include <string>
#include <ctime>

#include "datetime_cpp11.h"


// Helper function to parse date string
datetime parse_date(const std::string& date_str);

// Compute days interval between two date strings
int compute_days_interval(const std::string& date1_str, const std::string& date2_str);

// Compute months interval between two date strings
int compute_months_interval(const std::string& date1_str, const std::string& date2_str);

// Compute days interval between two datetime dates
int compute_days_interval_dt(const datetime& date1, const datetime& date2);

// Compute months interval between two datetime dates
int compute_months_interval_dt(const datetime& date1, const datetime& date2);

#endif // FUNCTIONS_CPP11_H