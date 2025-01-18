#include "Dedup.hpp"
#include <iostream>
#include <set>

void dedup(const std::vector<int>& input) {

    std::set<int> unique(input.begin(), input.end());
    std::cout << "Уникальные элементы: ";
    for (const auto& elem : unique) {
        std::cout << elem << " ";
    }
    std::cout << "\n";
    
}
