//#include <pybind11/pybind11.h>
//#include <pybind11/stl.h>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <stdexcept>

//namespace py = pybind11;

template<typename KeyType, typename ValueType>
class CustomMap
{
public:

    void insert(const KeyType& key, const ValueType& value)
    {
        keys.push_back(key);
        values.push_back(value);
        size_t index = keys.size() - 1;
        map[key] = index;
    }

    bool find(const KeyType& key, ValueType& value) const
    {
        auto it = map.find(key);
        if (it != map.end()) {
            value = values[it->second];
            return true;
        }
        return false;
    }

    bool contains(const KeyType& key) const
    {
        return map.find(key) != map.end();
    }

    KeyType get_key_by_index(size_t index) const
    {
        if (index < keys.size()) {
            return keys[index];
        }
        throw std::out_of_range("Index out of range");
    }

    ValueType get_value_by_index(size_t index) const
    {
        if (index < values.size()) {
            return values[index];
        }
        throw std::out_of_range("Index out of range");
    }

    std::vector<std::pair<KeyType, ValueType>> get_insertion_order() const
    {
        std::vector<std::pair<KeyType, ValueType>> result;
        for (size_t i = 0; i < keys.size(); ++i) {
            result.emplace_back(keys[i], values[i]);
        }
        return result;
    }

    // Реализация оператора квадратных скобок
    ValueType& operator[](const KeyType& key) {
        auto it = map.find(key);
        if (it != map.end()) {
            return values[it->second];
        } else {
            keys.push_back(key);
            values.push_back(ValueType());
            size_t index = keys.size() - 1;
            self.map[key] = index;
            return values[index];
        }
    }

private:
    std::unordered_map <KeyType, size_t> map;
    std::vector <KeyType> keys;
    std::vector <ValueType> values;
};

/*
PYBIND11_MODULE(indexed_uomap, m)
{
    py::class_<CustomMap<std::string, int>>(m, "CustomMap")
        .def(py::init<>())
        .def("insert", &CustomMap<std::string, int>::insert)
        .def("find", &CustomMap<std::string, int>::find)
        .def("contains", &CustomMap<std::string, int>::contains)
        .def("get_key_by_index", &CustomMap<std::string, int>::get_key_by_index)
        .def("get_value_by_index", &CustomMap<std::string, int>::get_value_by_index)
        .def("get_insertion_order", &CustomMap<std::string, int>::get_insertion_order);
}
*/