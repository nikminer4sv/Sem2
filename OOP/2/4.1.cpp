#include <iostream>
#include "Header-files/4.1_Header.h"

int main()
{
    Position playerPosition = Position(4, 5);
    char *playerName = new char[255], *playerColor = new char[255];

    std::cout << "Enter the player name: " << std::endl;
    std::cin.getline(playerName, 255);

    std::cout << "Enter the player color: " << std::endl;
    std::cin.getline(playerColor, 255);

    Player player = Player(playerPosition, playerName, playerColor);

    std::cout << player;
    
    delete[] playerName;
    delete[] playerColor;

    return 0;
}