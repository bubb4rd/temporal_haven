#include <iostream>
using namespace std;
#pragma once
class Item {
    public:
        Item();
        Item(string item, string rarity);
        string getName();
        string getRarity();
        void setName(std::string n);
        void setRarity(std::string r);
        void toString();
        
    private:
        string itemName;
        string itemRarity;
};