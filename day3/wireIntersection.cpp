#include "wires.h"

void readFromFile(std::string fileName, std::vector<std::vector<std::string>> *vec)
{
    std::ifstream ifs(fileName);
    std::string line;

    while (!ifs.eof() && getline(ifs, line))
    {
        std::vector<std::string> directions;
        std::string direction;
        int index = line.find_first_of(',');
        while (index > -1)
        {
            direction = line.substr(0, index);
            line = line.substr(index + 1, (line.length() - (index + 1)));
            directions.push_back(direction);
            index = line.find_first_of(',');
        }
        directions.push_back(line);
        vec->push_back(directions);
    }

    ifs.close();
}

Coordinates calculateCoordinates(std::string coordString, Coordinates currentCoordinates, bool *dir, int *distance)
{
    char direction = coordString.at(0);
    *distance = std::stoi(coordString.substr(1, coordString.length() - 1));

    Coordinates newCoord;

    switch (direction)
    {
    case 'R':
        newCoord.x = currentCoordinates.x + *distance;
        newCoord.y = currentCoordinates.y;
        *dir = false;
        break;

    case 'L':
        newCoord.x = currentCoordinates.x - *distance;
        newCoord.y = currentCoordinates.y;
        *dir = false;
        break;

    case 'U':
        newCoord.x = currentCoordinates.x;
        newCoord.y = currentCoordinates.y + *distance;
        *dir = true;
        break;

    case 'D':
        newCoord.x = currentCoordinates.x;
        newCoord.y = currentCoordinates.y - *distance;
        *dir = true;
        break;
    }
    return newCoord;
}

bool intersection(Coordinates p1, Coordinates p2, bool dir1, Coordinates p3, Coordinates p4, bool dir2, Coordinates *intersect)
{
    // currently requiring intersections to have a 90º angle
    if (dir1 == dir2)
    {
        return false;
    }

    // p1->p2 in x, p3->p4 in y
    if (dir1 == 0 && p3.x > std::min(p1.x, p2.x) && p3.x < std::max(p1.x, p2.x) && p1.y > std::min(p3.y, p4.y) && p1.y < std::max(p3.y, p4.y))
    {
        intersect->x = p3.x;
        intersect->y = p1.y;

        return true;
    }
    // p1->p2 in y, p3->p4 in y
    else if (dir1 == 1 && p3.y > std::min(p1.y, p2.y) && p3.y < std::max(p1.y, p2.y) && p1.x > std::min(p3.y, p4.y) && p1.x < std::max(p3.y, p4.y))
    {
        intersect->x = p1.x;
        intersect->y = p3.y;

        return true;
    }

    return false;
}

int foundTotal(Coordinates p1, Coordinates p3, Coordinates intersect, bool dir1, int runningTotal)
{
    // Total = currentTotal + Distance(intersect, p1) + Distance(intersect,p3)
    if (dir1 == 0)
    {
        runningTotal += std::max((intersect.x - p1.x), (p1.x - intersect.x));
        runningTotal += std::max((intersect.y - p3.y), (p3.y - intersect.y));
    }
    else
    {
        runningTotal += std::max((intersect.y - p1.y), (p1.y - intersect.y));
        runningTotal += std::max((intersect.x - p3.x), (p3.x - intersect.x));
    }

    return runningTotal;
}

int main()
{
    std::vector<std::vector<std::string>> stringCoords;
    readFromFile("input.txt", &stringCoords);

    // part 1
    Coordinates p1(0, 0), p2(0, 0), p3(0, 0), p4(0, 0), intersect(0, 0);
    bool dir1, dir2 = true;

    // part 2
    int distance = 0;
    int runningTotal = 0;

    for (auto it = stringCoords[0].begin(); it != stringCoords[0].end(); it++)
    {
        p2 = calculateCoordinates(*it, p1, &dir1, &distance);
        for (auto it1 = stringCoords[1].begin(); it1 != stringCoords[1].end(); it1++)
        {
            p4 = calculateCoordinates(*it1, p3, &dir2, &distance);
            bool found = intersection(p1, p2, dir1, p3, p4, dir2, &intersect);

            if (found)
            {
                int steps = foundTotal(p1, p3, intersect, dir1, runningTotal);
                std::cout
                    << "found intersection in " << steps << " steps at"
                    << "(" << intersect.x << "," << intersect.y;
                std::cout << ") Manhattan distance = " << (intersect.x + intersect.y) << std::endl;
            }
            runningTotal += distance;
            p3 = p4;
        }
        // if wire 1 were to go past first step distance would fail ...  but not an issue with input, would just need to have 2 distance vars and add after.
        p1 = p2;
    }
}
