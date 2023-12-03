#include "Backpack.h"


#pragma once

class Player {
    private:
        std::string playerName;
        int age;
        int reputation;
        Backpack playerBackpack;
    public:
        Player(std::string playerName, int age);
        std::string getName();
        int getAge();
        int getReuputation();
        int calculateRandomReputation(char encounter);
        void setReputation(int rep);
        Backpack& getBackpack();
        void toString();
    
};