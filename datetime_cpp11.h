#ifndef DATETIME_H
#define DATETIME_H

#include <pybind11/pybind11.h>

#include <stdexcept>
#include <string>
#include <tuple>
#include <ctime>

namespace py = pybind11;

class datetime {
public:
    int year, month, day, hour, minute, second, microsecond, fold;
    std::string tzinfo;

    // Constructor
    datetime(int year, int month = 1, int day = 1, int hour = 0, int minute = 0, int second = 0, int microsecond = 0, std::string tzinfo = "", int fold = 0);

    // Method to set state (similar to __setstate__ in Python)
    void set_state(const std::string& state, int month);

    // Method to handle errors (similar to __reduce__ in Python)
    std::tuple<std::string, std::string> reduce() const;

    std::time_t to_time_t() const;
};



#endif // DATETIME_H