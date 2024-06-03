from setuptools import setup, Extension
import pybind11

ext_modules = [
    Extension(
        'indexed_map',
        ['bindings.cpp'],
        include_dirs=[pybind11.get_include()],
        language='c++'
    ),
]

setup(
    name='indexed_map',
    version='1.0',
    ext_modules=ext_modules,
)
