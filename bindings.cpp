
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "indexed_map.h"

namespace py = pybind11;


PYBIND11_MODULE(indexed_map, m)
{
    py::class_<CustomMap<std::string, int>>(m, "IndexedMap")
        .def(py::init<>())
        .def("insert", &CustomMap<std::string, int>::insert)
        .def("find", [](const CustomMap<std::string, int>& self, const std::string& key)
        {
            int value;
            bool found = self.find(key, value);
            return std::make_pair(found, value);
        })
        .def("contains", &CustomMap<std::string, int>::contains)
        .def("get_key_by_index", &CustomMap<std::string, int>::get_key_by_index)
        .def("get_value_by_index", &CustomMap<std::string, int>::get_value_by_index)
        .def("get_insertion_order", &CustomMap<std::string, int>::get_insertion_order)
        .def("__contains__", &CustomMap<std::string, int>::__contains__)
        .def("__iter__", &CustomMap<std::string, int>::_keys);
}
