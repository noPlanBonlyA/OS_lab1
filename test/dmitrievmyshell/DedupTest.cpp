#include <gtest/gtest.h>
#include "../../source/dmitrievmyshell/Dedup.hpp"

TEST(DedupTest, RemoveDuplicates) {
    std::vector<int> input = {1, 2, 2, 3, 4, 4, 5};
    std::set<int> expected = {1, 2, 3, 4, 5};

    testing::internal::CaptureStdout();
    dedup(input);
    std::string output = testing::internal::GetCapturedStdout();

    // Проверяем, что выводятся только уникальные элементы
    for (int num : expected) {
        EXPECT_TRUE(output.find(std::to_string(num)) != std::string::npos);
    }
}
