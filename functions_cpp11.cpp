#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <ctime>
#include <cmath>
#include <cassert>
#include "functions_cpp11.h"
#include "datetime_cpp11.h"

// Parse date string to datetime object
datetime parse_date(const std::string& date_str) {
    std::tm tm = {};
    std::istringstream ss(date_str);
    ss >> std::get_time(&tm, "%Y-%m-%d");
    if (ss.fail()) {
        throw std::runtime_error("Failed to parse date: " + date_str);
    }
    return datetime(tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
}

// Compute days interval between two date strings
int compute_days_interval(const std::string& date1_str, const std::string& date2_str) {
    datetime date1 = parse_date(date1_str);
    datetime date2 = parse_date(date2_str);
    std::time_t time1 = date1.to_time_t();
    std::time_t time2 = date2.to_time_t();
    return std::abs(std::difftime(time2, time1) / (60 * 60 * 24));
}

// Compute months interval between two date strings
int compute_months_interval(const std::string& date1_str, const std::string& date2_str) {
    datetime date1 = parse_date(date1_str);
    datetime date2 = parse_date(date2_str);
    int years_diff = date2.year - date1.year;
    int months_diff = date2.month - date1.month;
    return std::abs(years_diff * 12 + months_diff);
}

// Compute days interval between two datetime objects
int compute_days_interval_dt(const datetime& date1, const datetime& date2) {
    std::tm tm1 = {};
    tm1.tm_year = date1.year - 1900;
    tm1.tm_mon = date1.month - 1;
    tm1.tm_mday = date1.day;

    std::tm tm2 = {};
    tm2.tm_year = date2.year - 1900;
    tm2.tm_mon = date2.month - 1;
    tm2.tm_mday = date2.day;

    std::time_t time1 = std::mktime(&tm1);
    std::time_t time2 = std::mktime(&tm2);
    return std::abs(std::difftime(time2, time1) / (60 * 60 * 24));
}

// Compute months interval between two datetime objects
int compute_months_interval_dt(const datetime& date1, const datetime& date2) {
    int years_diff = date2.year - date1.year;
    int months_diff = date2.month - date1.month;
    return std::abs(years_diff * 12 + months_diff);
}

// Main function to test the implementation
int main() {
    // Test compute_days_interval
    assert(compute_days_interval("2023-01-01", "2023-01-10") == 9);
    assert(compute_days_interval("2023-01-10", "2023-01-01") == 9);
    assert(compute_days_interval("2023-01-01", "2023-01-01") == 0);
    assert(compute_days_interval("2022-12-31", "2023-01-01") == 1);

    // Test compute_days_interval_dt
    datetime date1 = parse_date("2023-01-01");
    datetime date2 = parse_date("2023-01-10");
    assert(compute_days_interval_dt(date1, date2) == 9);
    date1 = parse_date("2023-01-10");
    date2 = parse_date("2023-01-01");
    assert(compute_days_interval_dt(date1, date2) == 9);

    // Test compute_months_interval
    assert(compute_months_interval("2023-01-01", "2023-02-01") == 1);
    assert(compute_months_interval("2023-01-01", "2023-04-01") == 3);
    assert(compute_months_interval("2023-01-01", "2023-01-01") == 0);
    assert(compute_months_interval("2022-01-01", "2023-01-01") == 12);

    // Test compute_months_interval_dt
    date1 = parse_date("2023-01-01");
    date2 = parse_date("2023-02-01");
    assert(compute_months_interval_dt(date1, date2) == 1);
    date1 = parse_date("2023-01-01");
    date2 = parse_date("2023-04-01");
    assert(compute_months_interval_dt(date1, date2) == 3);

    std::string date_str = "2023-10-05";
    datetime date = parse_date(date_str);
    std::cout << "Year: " << date.year << ", Month: " << date.month << ", Day: " << date.day << std::endl;

    std::cout << "All tests passed!" << std::endl;
    return 0;
}