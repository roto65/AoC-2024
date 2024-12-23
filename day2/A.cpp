#include <bits/stdc++.h>

#include "../shared.hpp"

// #define DEBUG 

std::vector<int> splitNums(std::string s) {
    std::vector<std::string> tmp = split(s, ' ');
    std::vector<int> nums;

    for (std::string numStr : tmp) {
        nums.push_back(stoi(numStr));
    }

    return nums;
}

bool checkAsc(std::vector<int> nums) {
    for (int i = 0; i < nums.size() - 1; i++) {
        int delta = nums.at(i + 1) - nums.at(i);
        if (delta < 1 || delta > 3) return false;
    }
    return true;
}

bool checkDesc(std::vector<int> nums) {
    for (int i = nums.size() - 1; i > 0; i--) {
        int delta = nums.at(i - 1) - nums.at(i);
        if (delta < 1 || delta > 3) return false;
    }
    return true;
}

int main(void) {
    std::vector<std::string> data = readFile("input.txt");

    std::vector<std::vector<int>> lines;

    for (std::string str : data) {
        lines.push_back(splitNums(str));
    }

    long long sum = 0;

    for (std::vector<int> line : lines) {
        if (checkAsc(line)) {
            sum++;

            #ifdef DEBUG
                std::cout << "Asc:  ";
                for (int n : line) {
                    std::cout << n << " ";
                }
                std::cout << std::endl;
            #endif
        } else if (checkDesc(line)) {
            sum++;

            #ifdef DEBUG
                std::cout << "Desc: ";
                for (int n : line) {
                    std::cout << n << " ";
                }
                std::cout << std::endl;
            #endif
        }
    }

    std::cout << sum << std::endl;

    return 0;
}

// Solution: 224