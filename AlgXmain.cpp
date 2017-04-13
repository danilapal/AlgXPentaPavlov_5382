#include "algoritnmx.h"

#include <iostream>
#include <string>
#include <vector>

void handle_solution(const std::vector<std::vector<std::string>>& solution)
{
    for(const auto& row : solution) {
        for(const auto& el : row)
            std::cout << el << " ";
        std::cout << std::endl;
    }

    std::cout << "===========================" << std::endl;
}

int main()
{

    AlgorithmX alg_x;
    alg_x.search("input.txt", handle_solution);
    std::cout<<"END";
    return 0;
}

