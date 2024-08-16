#include "datetime_cpp11.h"

datetime::datetime(int year, int month, int day, int hour, int minute, int second, int microsecond, std::string tzinfo, int fold)
    : year(year), month(month), day(day), hour(hour), minute(minute), second(second), microsecond(microsecond), tzinfo(tzinfo), fold(fold) {
    if (year < 1 || year > 9999) {
        throw std::out_of_range("Year out of range");
    }
    // Additional validation can be added here
}

void datetime::set_state(const std::string& state, int month) {
    if (state.length() != 10 || !(1 <= state[2] && state[2] <= 12)) {
        throw std::invalid_argument("Invalid state");
    }
    // Decode state and set member variables
    // This is a placeholder for actual state decoding logic
    this->year = std::stoi(state.substr(0, 4));
    this->month = month;
    this->day = std::stoi(state.substr(8, 2));
}

std::tuple<std::string, std::string> datetime::reduce() const {
    return std::make_tuple("datetime", "state");
}

std::time_t datetime::to_time_t() const {
    std::tm tm = {};
    tm.tm_year = year - 1900;
    tm.tm_mon = month - 1;
    tm.tm_mday = day;
    return std::mktime(&tm);
}


PYBIND11_MODULE(cppdatetime, m) {
    py::class_<datetime>(m, "datetime")
        .def(py::init<int, int, int, int, int, int, int, std::string, int>(),
             py::arg("year"), py::arg("month") = 1, py::arg("day") = 1, py::arg("hour") = 0, py::arg("minute") = 0, py::arg("second") = 0, py::arg("microsecond") = 0, py::arg("tzinfo") = "", py::arg("fold") = 0)
        .def("set_state", &datetime::set_state)
        .def("reduce", &datetime::reduce)
        .def_readwrite("year", &datetime::year)
        .def_readwrite("month", &datetime::month)
        .def_readwrite("day", &datetime::day)
        .def_readwrite("hour", &datetime::hour)
        .def_readwrite("minute", &datetime::minute)
        .def_readwrite("second", &datetime::second)
        .def_readwrite("microsecond", &datetime::microsecond)
        .def_readwrite("tzinfo", &datetime::tzinfo)
        .def_readwrite("fold", &datetime::fold);
}