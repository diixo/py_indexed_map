
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <map>
#include <vector>
#include <functional>
#include <algorithm>
#include <stdexcept>
#include <string>

namespace py = pybind11;

template<typename KeyType, typename ValueType>
class CustomMap
{
public:

    void insert(const KeyType& key, const ValueType& value)
    {
        keys.push_back(key);
        values.push_back(value);
        size_t index = keys.size() - 1;
        map[index] = index;
    }

    bool find(const KeyType& key, ValueType& value) const
    {
        auto it = std::find(keys.begin(), keys.end(), key);
        if (it != keys.end()) {
            size_t index = std::distance(keys.begin(), it);
            value = values[index];
            return true;
        }
        return false;
    }

    bool contains(const KeyType& key) const {
        ValueType value;
        return find(key, value);
    }

    KeyType get_key_by_index(size_t index) const {
        if (index < keys.size()) {
            return keys[index];
        }
        throw std::out_of_range("Index out of range");
    }

    ValueType get_value_by_index(size_t index) const {
        if (index < values.size()) {
            return values[index];
        }
        throw std::out_of_range("Index out of range");
    }

    std::vector<std::pair<KeyType, ValueType>> get_insertion_order() const {
        std::vector<std::pair<KeyType, ValueType>> result;
        for (size_t i = 0; i < keys.size(); ++i) {
            result.emplace_back(keys[i], values[i]);
        }
        return result;
    }

    bool __contains__(const KeyType& key) const {
        return contains(key);
    }


    py::iterable _keys() const {
        return py::cast(keys);
    }


private:
    struct Comparator
    {
        const std::vector<KeyType>& keys;
        Comparator(const std::vector<KeyType>& keys)
        : keys(keys)
        {}

        bool operator()(const size_t lhs, const size_t rhs) const
        {
            return keys[lhs] < keys[rhs];
        }
    };

    std::map <size_t, size_t, Comparator> map{ Comparator(keys) };
    std::vector <KeyType> keys;
    std::vector <ValueType> values;
};


