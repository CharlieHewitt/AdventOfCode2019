#include "intcode.h"

int main()
{
    std::vector<int> program;
    readFromFile("input.txt", &program);
    std::cout << "reading" << std::endl;
    runProgram(&program);
    outToFile("output.txt", program);
}