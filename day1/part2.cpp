#include <string>
#include <iostream>
#include <fstream>

int calculateFuel(int mass)
{
    int totalFuel = 0;
    while (mass > 0)
    {
        mass = (mass / 3) - 2;

        if (mass > 0)
        {
            totalFuel += mass;
        }

        //std::cout << mass << std::endl;
    }

    return totalFuel;
}

void readFromFile(std::string fileName)
{
    std::ifstream ifs(fileName);
    std::string line;

    int total = 0;
    while (!ifs.eof() && getline(ifs, line))
    {
        total += calculateFuel(std::stoi(line));
    }
    ifs.close();

    std::cout << "Total is: " << total << std::endl;
}

int main()
{
    readFromFile("input.txt");
}