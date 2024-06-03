#include <iostream>
#include "indexed_map.h"

int main()
{
    CustomMap<std::string, int> custom_map;
    
    custom_map.insert("one", 1);
    custom_map.insert("two", 2);
    custom_map.insert("three", 3);

    int value;
    if (custom_map.find("two", value)) {
        std::cout << "Found: " << value << std::endl;
    } else {
        std::cout << "Not found" << std::endl;
    }

    try {
        std::cout << "Key at index 1: " << custom_map.get_key_by_index(1) << std::endl;
        std::cout << "Value at index 1: " << custom_map.get_value_by_index(1) << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "Insertion order:" << std::endl;
    auto insertion_order = custom_map.get_insertion_order();
    for (const auto& pair : insertion_order) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
