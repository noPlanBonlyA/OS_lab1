#include "EmaSearch.hpp"
#include <iostream>
#include <fstream>


void emaSearchStr(const std::string& filename, const std::string& substring) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Ошибка: не удалось открыть файл " << filename << "\n";
        return;
    }

    std::string line;
    size_t lineNum = 1;
    while (std::getline(file, line)) {
        if (line.find(substring) != std::string::npos) {
            std::cout << "Найдено на строке " << lineNum << ": " << line << "\n";
        }
        ++lineNum;
    }
    file.close();
}
