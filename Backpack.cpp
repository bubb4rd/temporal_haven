#include "Backpack.h"

Backpack::Backpack() {
}
int Backpack::firstAvailableSpace() {
    for (int i = 0; i < backpack.size(); i++) {
        if (backpack[i].getName() == "N/A") return i;
    }
    return -1;
}
void Backpack::addItem(Item item) {
    int insertIndex = firstAvailableSpace();

    if (insertIndex == -1) {
        cout << "Inventory is full!" << endl;
    } else {  
    backpack[insertIndex] = item;
    std::cout << "Item obtained: " << item.getName() << " | " << item.getRarity() << std::endl;
    }
}
bool Backpack::hasItem(std::string item) {
    for (int i = 0; i < backpack.size(); i++) {
        if (backpack[i].getName() == item) return true;
    }
    return false;
}
void Backpack::removeItem(Item item) {
    for (int i = 0; i < backpack.size(); i++) {
        if (backpack[i].getName() == item.getName()) {
            backpack[i].setName("N/A");
            backpack[i].setRarity("N/A");
        }
    }
}
void Backpack::toString() {
    std::cout << "Backpack" << std::endl;
    if (backpack.size() == 0) std::cout << "No items" << std::endl;
    for (Item i : backpack) {
        i.toString();
    }
}