#include "Player.h"
#include <string>

Player::Player(string pName, int a) : playerName(pName), age(a), playerBackpack(), reputation(50) {}
string Player::getName()
{
    return playerName;
}
int Player::getAge()
{
    return age;
}
int Player::getReuputation()
{
    return reputation;
}
int Player::calculateRandomReputation(char encounter)
{
    int randomReputation = 0;
    if (encounter == 'P')
        randomReputation = rand() % 5 + 1;
    else if (encounter == 'F')
        randomReputation = rand() % 15 + 1;
    else if (encounter == 'I')
        randomReputation = rand() % 3 + 1;
    return randomReputation;
}
void Player::setReputation(int rep)
{
    reputation = rep;
}
Backpack& Player::getBackpack() {
    return playerBackpack;
}
void Player::toString()
{
    std::cout << "\n--------------------------------------------------------" << endl;
    std::cout << "PLAYER INFORMATION" << endl;
    std::cout << "--------------------------------------------------------" << endl;
    std::cout << "Name: " << playerName << endl;
    std::cout << "Age: " << age << endl;
    std::cout << "Reputation: " << reputation << endl;
    playerBackpack.toString();
    std::cout << "--------------------------------------------------------" << endl;
}
