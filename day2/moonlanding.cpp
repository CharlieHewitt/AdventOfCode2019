#include "intcode.h"

void bruteForce()
{

    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            std::vector<int> program;
            readFromFile("input.txt", &program);
            program.at(1) = i;
            program.at(2) = j;
            runProgram(&program);

            // moon landing date
            if (program.at(0) == 19690720)
            {
                std::cout << "(" << i << "," << j << ")";
                return;
            }
            //outToFile("output.txt", program);
        }
    }
}

int main()
{
    bruteForce();
}
