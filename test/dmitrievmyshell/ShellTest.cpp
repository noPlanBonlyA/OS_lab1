#include <gtest/gtest.h>
#include <sstream>
#include "../../source/dmitrievmyshell/Shell.hpp"

TEST(ShellTest, HandleBasicCommands) {
    Shell shell;
    // В данном случае ты можешь имитировать выполнение команд внутри оболочки
    EXPECT_NO_THROW(shell.run()); // Smoke test
}
