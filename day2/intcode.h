#include <string>
#include <iostream>
#include <fstream>
#include <vector>

void readFromFile(std::string fileName, std::vector<int> *vec)
{
    std::ifstream ifs(fileName);
    std::string line;

    //int total = 0;
    while (!ifs.eof() && getline(ifs, line, ','))
    {
        vec->push_back(std::stoi(line));
    }
    ifs.close();
}

void outToFile(std::string fileName, std::vector<int> vec)
{
    std::ofstream ofs(fileName);
    int index = 0;

    while (index < (int)vec.size())
    {
        ofs << vec.at(index);

        if (index % 4 == 3)
        {
            ofs << std::endl;
        }
        else
        {
            ofs << ',';
        }
        index++;
    }
    ofs.close();
}
bool performInstruction(std::vector<int> *program, int opCodeIndex)
{
    int opCode = program->at(opCodeIndex);

    if (opCode == 99)
    {
        std::cout << "halting" << std::endl;
        return true;
    }

    int var1 = program->at(opCodeIndex + 1);
    int var2 = program->at(opCodeIndex + 2);
    int target = program->at(opCodeIndex + 3);

    // get operands
    var1 = program->at(var1);
    var2 = program->at(var2);

    std::cout << "opcode=" << opCode << std::endl;

    if (opCode == 1)
    {
        program->at(target) = var1 + var2;
        std::cout << var1 << " + " << var2 << " = " << program->at(target) << std::endl;
    }
    else if (opCode == 2)
    {
        program->at(target) = var1 * var2;
        std::cout << var1 << " * " << var2 << " = " << program->at(target) << std::endl;
    }

    return false;
}

void runProgram(std::vector<int> *program)
{
    bool halted = false;
    int opCodeIndex = 0;
    while (!halted)
    {
        halted = performInstruction(program, opCodeIndex);
        std::cout << (halted ? "halted" : "executing") << std::endl;
        opCodeIndex += 4;
    }

    std::cout << program->at(0) << std::endl;
}
