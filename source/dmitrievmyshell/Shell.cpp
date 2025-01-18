#include "Shell.hpp"
#include "EmaSearch.hpp"
#include "Dedup.hpp"
#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>

void executeCommand(const std::string& command);

void Shell::run() {
    std::string input;
    while (true) {
        std::cout << "myshell> ";
        std::getline(std::cin, input);
        if (input == "exit") break;

        if (input.starts_with("ema-search-str")) {
            std::istringstream iss(input);
            std::string cmd, filename, substring;
            iss >> cmd >> filename >> substring;
            emaSearchStr(filename, substring);
        } else if (input.starts_with("dedup")) {
            std::istringstream iss(input);
            std::string cmd;
            int num;
            std::vector<int> nums;
            iss >> cmd;
            while (iss >> num) {
                nums.push_back(num);
            }
            dedup(nums);
        } else {
            executeCommand(input);
        }
    }
}

void executeCommand(const std::string& command) {
    struct timespec start, end;
    clock_gettime(CLOCK_REALTIME, &start);

    pid_t pid = fork();
    if (pid == 0) {
        std::vector<char*> args;
        std::istringstream iss(command);
        std::string token;
        while (iss >> token) {
            char* arg = new char[token.size() + 1];
            std::strcpy(arg, token.c_str());
            args.push_back(arg);
        }
        args.push_back(nullptr);
        execvp(args[0], args.data());
        perror("Ошибка запуска команды");
        exit(EXIT_FAILURE);
    } else {
        waitpid(pid, nullptr, 0);
        clock_gettime(CLOCK_REALTIME, &end);

        double elapsed = (end.tv_sec - start.tv_sec) +
                         (end.tv_nsec - start.tv_nsec) / 1e9;
        std::cout << "Время выполнения: " << elapsed << " секунд\n";
    }
}
