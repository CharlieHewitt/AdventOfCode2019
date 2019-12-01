#include <string>
#include <iostream>
#include <fstream>

int calculateFuel(int mass)
{
  return (mass / 3) - 2;
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