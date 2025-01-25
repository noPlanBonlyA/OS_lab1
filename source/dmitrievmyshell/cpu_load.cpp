#include <iostream>
#include <cmath>
#include <chrono>

void cpu_task(int iterations) {
    double result = 0;
    for (int i = 0; i < iterations; i++) {
        result += std::sin(i) * std::cos(i);
    }
    std::cout << "CPU Task завершена. Результат: " << result << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Использование: " << argv[0] << " <количество итераций>" << std::endl;
        return 1;
    }

    int iterations = std::stoi(argv[1]);

    auto start = std::chrono::high_resolution_clock::now();
    cpu_task(iterations);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Время выполнения: " << elapsed.count() << " секунд" << std::endl;

    return 0;
}
