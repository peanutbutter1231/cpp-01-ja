#include <iostream>

int main()
{
    char season = 'W';

    switch (season)
    {
    case 'S':
        std::cout << "Summer";
        break;
    case 'W':
        std::cout << "Winter";
        break;
    default:
        std::cout << "Invalid season";
    }
}
