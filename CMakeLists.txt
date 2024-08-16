cmake_minimum_required(VERSION 3.14)

# Define the project name and version
project(MyProject VERSION 1.0 LANGUAGES CXX)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find the pybind11 package
find_package(pybind11 REQUIRED)

# Add the source files
set(SOURCES
	functions_cpp11.cpp
    datetime_cpp11.cpp
	bindings_cpp11.cpp
)

# Add the library
pybind11_add_module(functions ${SOURCES})

# Link the necessary libraries
target_link_libraries(functions PRIVATE pybind11::module)