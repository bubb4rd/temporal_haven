#include "Npc.h"

Npc::Npc(std::string name, std::vector<std::string> prompts) : npcName(name), npcPrompts(prompts), npcMet(false) {}

int Npc::interaction(Player& player, char level) {
    int choice, response;
    displayChoices();
    cin >> choice;
    response = processChoice(player, choice, level);
    return response;
}
std::string Npc::getName() {
    return npcName;
}
void Npc::displayChoices() {
    cout << "--------------------------------------------------------" << endl;
    for (int i = 0; i < npcPrompts.size(); i++) {
        cout << i + 1 << ". " << npcPrompts[i] << endl;
    }
    cout << "Make a decision." << endl;
    cout << "--------------------------------------------------------" << endl;
}

bool Npc::getMetStatus() {
    return npcMet;
}
void Npc::setMetStatus(bool status) {
    npcMet = status;
}
int Npc::processChoice(Player& player, int choice, char level) {
    if (choice == 1) {
        int rep = player.calculateRandomReputation(level);
        int newReputation = player.getReuputation() + rep;
        player.setReputation(newReputation);
        cout << "You gained " << rep << " reputation. (Current reputation: " << newReputation << ")" << endl;
    } else if (choice == 2) {
        int rep = player.calculateRandomReputation(level);
        int newReputation = player.getReuputation() - rep;
        player.setReputation(newReputation);
        cout << "You lost " << rep << " reputation. (Current reputation: " << newReputation << ")" << endl;
    } else if (choice != 3) cout << "Invalid option." << endl;

    return choice;
}