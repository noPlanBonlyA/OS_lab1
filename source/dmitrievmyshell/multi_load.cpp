#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <chrono> // Для измерения времени

void cpu_task(int iterations) {
    double result = 0;
    for (int i = 0; i < iterations; i++) {
        result += std::sin(i) * std::cos(i);
    }
    std::cout << "CPU Task завершена. Результат: " << result << std::endl;
}

void io_task(const std::string& filename, int size_mb) {
    std::vector<char> buffer(1024 * 1024, 'A'); // 1 MB данных

    // Замер времени для записи
    auto write_start_time = std::chrono::high_resolution_clock::now();
    std::ofstream file_out(filename, std::ios::binary);
    for (int i = 0; i < size_mb; i++) {
        file_out.write(buffer.data(), buffer.size());
    }
    file_out.close();
    auto write_end_time = std::chrono::high_resolution_clock::now();

    // Замер времени для чтения
    auto read_start_time = std::chrono::high_resolution_clock::now();
    std::ifstream file_in(filename, std::ios::binary);
    while (file_in.read(buffer.data(), buffer.size())) {}
    file_in.close();
    auto read_end_time = std::chrono::high_resolution_clock::now();

    // Вывод времени выполнения IO задач
    std::chrono::duration<double> write_elapsed = write_end_time - write_start_time;
    std::chrono::duration<double> read_elapsed = read_end_time - read_start_time;
    std::cout << "Время записи: " << write_elapsed.count() << " секунд" << std::endl;
    std::cout << "Время чтения: " << read_elapsed.count() << " секунд" << std::endl;
    std::cout << "IO Task завершена" << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Использование: " << argv[0] << " <количество итераций CPU> <имя файла> <размер файла в МБ>" << std::endl;
        return 1;
    }

    int cpu_iterations = std::stoi(argv[1]); // Количество итераций для CPU задачи
    std::string filename = argv[2];         // Имя файла для IO задачи
    int size_mb = std::stoi(argv[3]);       // Размер файла в МБ для IO задачи

    // Измерение времени выполнения CPU задачи
    auto cpu_start_time = std::chrono::high_resolution_clock::now();
    cpu_task(cpu_iterations);
    auto cpu_end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> cpu_elapsed = cpu_end_time - cpu_start_time;
    std::cout << "Время выполнения CPU задачи: " << cpu_elapsed.count() << " секунд" << std::endl;

    // Измерение времени выполнения IO задачи
    auto io_start_time = std::chrono::high_resolution_clock::now();
    io_task(filename, size_mb);
    auto io_end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> io_elapsed = io_end_time - io_start_time;
    std::cout << "Время выполнения IO задачи: " << io_elapsed.count() << " секунд" << std::endl;

    // Общее время выполнения программы
    auto total_start_time = cpu_start_time; // CPU задача началась первой
    auto total_end_time = io_end_time;     // IO задача завершилась последней
    std::chrono::duration<double> total_elapsed = total_end_time - total_start_time;
    std::cout << "Общее время выполнения программы: " << total_elapsed.count() << " секунд" << std::endl;

    return 0;
}
