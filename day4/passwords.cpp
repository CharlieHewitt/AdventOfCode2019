#include <iostream>
#include <string>
#include <map>

const int lowerRange = 382345;
const int upperRange = 843167;

/* 
    Brute Forcing due to lack of time, can be improved ...
*/

bool containsDouble(std::string pass)
{
    int digits[10] = {0};

    for (int i = 0; i < pass.length(); i++)
    {
        char digit = pass.at(i);
        digits[digit - 48]++;
    }

    for (int i = 0; i < 10; i++)
    {
        if (digits[i] == 2)
        {
            return true;
        }
    }
    return false;
}

bool ascending(std::string pass)
{
    int i = 0;
    int curr, next;

    while (i < pass.length() - 1)
    {
        curr = static_cast<int>(pass.at(i));
        next = static_cast<int>(pass.at(i + 1));

        //std::cout << curr << " " << next << std::endl;
        if (curr > next)
        {
            return false;
        }
        i++;
    }
    return true;
}

bool validPassword(std::string pass)
{
    return containsDouble(pass) && ascending(pass) && (pass.length() == 6);
}

void calculateValidPasswords()
{
    int count = 0;
    int current = lowerRange;

    while (current < upperRange)
    {
        if (validPassword(std::to_string(current)))
        {
            std::cout << current << " " << count << std::endl;
            count++;
        }
        current++;
    }

    std::cout << "Valid count: " << count << std::endl;
}

int main()
{
    //std::cout << containsDouble("11233") << std::endl;
    calculateValidPasswords();
}