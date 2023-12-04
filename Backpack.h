#include "Item.h"
#include <array>
#pragma once
class Backpack {
    public:
        Backpack();
        int firstAvailableSpace();
        void addItem(Item item);
        int returnItemCount();
        bool hasItem(std::string item);
        void removeItem(Item item);
        void toString();
    private:
        std::array<Item, 5> backpack;
        std::string backpackName;
};