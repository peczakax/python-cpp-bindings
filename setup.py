from setuptools import setup
import pybind11
from pybind11.setup_helpers import Pybind11Extension, build_ext

ext_modules = [Pybind11Extension(
    "cppfunctions",
    ["bindings_cpp11.cpp", "functions_cpp11.cpp", "datetime_cpp11.cpp"],
    include_dirs=[pybind11.get_include()],
    language="c++",
    cxx_std=11,
)]

setup(
    name="cppfunctions",
    version="0.1",
    author="Your Name",
    author_email="your.email@example.com",
    description="A Python package with C++ extension for date interval computations",
    ext_modules=ext_modules,
    cmdclass={"build_ext": build_ext},
    zip_safe=False,
)

ext_modules2 = [Pybind11Extension(
    "cppdatetime",
    ["datetime_cpp11.cpp"],
    include_dirs=[pybind11.get_include()],
    language="c++",
    cxx_std=11,
)]

setup(
    name="cppdatetime",
    version="0.1",
    author="Andrzej Pęczak",
    author_email="your.email@example.com",
    description="A Python package with C++ extension for date interval computations",
    ext_modules=ext_modules2,
    cmdclass={"build_ext": build_ext},
    zip_safe=False,
)