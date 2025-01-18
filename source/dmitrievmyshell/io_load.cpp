#include <iostream>
#include <fstream>
#include <vector>
#include <chrono> // Для измерения времени

void io_task(const std::string& filename, int size_mb) {
    std::vector<char> buffer(1024 * 1024, 'A'); // 1 MB данных

    // Запись данных
    std::ofstream file_out(filename, std::ios::binary);
    for (int i = 0; i < size_mb; i++) {
        file_out.write(buffer.data(), buffer.size());
    }
    file_out.close();

    // Чтение данных
    std::ifstream file_in(filename, std::ios::binary);
    while (file_in.read(buffer.data(), buffer.size())) {}
    file_in.close();

    std::cout << "IO Task завершена" << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Использование: " << argv[0] << " <имя файла> <размер файла в МБ>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    int size_mb = std::stoi(argv[2]);

    // Измерение времени выполнения
    auto start_time = std::chrono::high_resolution_clock::now();
    io_task(filename, size_mb);
    auto end_time = std::chrono::high_resolution_clock::now();

    // Расчёт и вывод времени выполнения
    std::chrono::duration<double> elapsed = end_time - start_time;
    std::cout << "Время выполнения: " << elapsed.count() << " секунд" << std::endl;

    return 0;
}
