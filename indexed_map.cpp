
#include <iostream>
#include <map>
#include <vector>
#include <functional>

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

    void print_insertion_order() const
    {
        for (size_t i = 0; i < keys.size(); ++i)
        {
            std::cout << keys[i] << ": " << values[i] << std::endl;
        }
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

    std::map<size_t, size_t, Comparator> map{ Comparator(keys) };
    std::vector<KeyType> keys;
    std::vector<ValueType> values;
};

int main()
{
    CustomMap<std::string, int> custom_map;
    custom_map.insert("one", 1);
    custom_map.insert("two", 2);
    custom_map.insert("three", 3);

    int value;
    if (custom_map.find("two", value))
    {
        std::cout << "Found: " << value << std::endl;
    }

    custom_map.print_insertion_order();

    return 0;
}
