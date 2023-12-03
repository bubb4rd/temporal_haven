#include "Item.h"

    Item::Item() : itemName("N/A"), itemRarity("N/A") {}
    Item::Item(std::string item, std::string rarity) : itemName(item), itemRarity(rarity) {}

    std::string Item::getName() {
        return itemName;
    }
    std::string Item::getRarity() {
        return itemRarity;
    }
    void Item::setName(std::string n) {
        itemName = n;
    }
    void Item::setRarity(std::string r) {
        itemRarity = r;
    }
    void Item::toString() {
        cout << "Name: " << itemName << " | Rarity: " << itemRarity << endl;
    }