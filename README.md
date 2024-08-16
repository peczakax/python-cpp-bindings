# python-cpp-bindings

This code demonstrates the process of interfacing C++ code with Python. The tests are parameterized to allow a unified test code to validate both the Python and C++ implementations.

## Requirements

- `Visual Studio` or a compatible compiler (Note: Windows mingw compiler is not supported)
- `Python 3.12`
- `pytest` for running tests


## Key Components

- **CMake Configuration**

    `CMakeLists,txt` configuration file for building the C++ library.

- **C++ Code**

    `bindings_cpp11.cpp`: Contains the bindings between C++ and Python.

    `datetime_cpp11.cpp`and `datetime_cpp11.h`: C++ source and header files for datetime functionalities.

    `functions_cpp11.cpp` and `functions_cpp11.h`: C++ source and header files for various functions.

- **Python Scripts**

    `setup.py`: Python setup script for building the C++ extensions.

    `functions.py`: Python implementation of the functions.

    `test_functions.py`: Test suite for validating both Python and C++ implementations.

## Building the C++ Library

To build the C++ library, run the following command to generate the package:

    python setup.py build_ext --inplace

You can also use CMake to compile the library files:

    mkdir build
    cd build
    cmake ..
    cmake --build .

## Running Tests

To run the tests, use the following command:

    pytest
