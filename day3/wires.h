#include <iostream>
#include <vector>
#include <fstream>
#include <string>

class Coordinates
{
public:
    Coordinates(int _x, int _y)
    {
        x = _x;
        y = _y;
    }
    Coordinates()
    {
        x = 0;
        y = 0;
    }

public:
    int x;
    int y;
};
