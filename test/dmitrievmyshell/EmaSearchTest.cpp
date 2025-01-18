#include <gtest/gtest.h>
#include <fstream>
#include "../../source/dmitrievmyshell/EmaSearch.hpp"

TEST(EmaSearchTest, FindSubstring) {
    // Создаём временный файл
    std::ofstream file("testfile.txt");
    file << "hello world\n";
    file << "this is a test\n";
    file << "hello again\n";
    file.close();

    testing::internal::CaptureStdout();
    emaSearchStr("testfile.txt", "hello");
    std::string output = testing::internal::GetCapturedStdout();

    // Проверяем вывод
    EXPECT_TRUE(output.find("Найдено на строке 1") != std::string::npos);
    EXPECT_TRUE(output.find("Найдено на строке 3") != std::string::npos);
}

TEST(EmaSearchTest, FileNotFound) {
    testing::internal::CaptureStderr();
    emaSearchStr("nonexistent.txt", "test");
    std::string error = testing::internal::GetCapturedStderr();

    // Проверяем, что выводится сообщение об ошибке
    EXPECT_TRUE(error.find("Ошибка: не удалось открыть файл") != std::string::npos);
}
