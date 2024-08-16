#include <pybind11/pybind11.h>
#include <string>
#include <ctime>
#include "functions_cpp11.h"

namespace py = pybind11;

PYBIND11_MODULE(cppfunctions, m) {
    m.doc() = "Bindings for date interval functions";

    m.def("compute_days_interval", &compute_days_interval, "Compute days interval between two date strings",
          py::arg("date1_str"), py::arg("date2_str"));

    m.def("compute_months_interval", &compute_months_interval, "Compute months interval between two date strings",
          py::arg("date1_str"), py::arg("date2_str"));

    m.def("compute_days_interval_dt", &compute_days_interval_dt, "Compute days interval between two std::tm dates",
          py::arg("date1"), py::arg("date2"));

    m.def("compute_months_interval_dt", &compute_months_interval_dt, "Compute months interval between two std::tm dates",
          py::arg("date1"), py::arg("date2"));
}
