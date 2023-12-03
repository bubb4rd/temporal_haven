#include <string>
#include <vector>
#include "Player.h"
class Npc {
    private:
        std::string npcName;
        std::vector<std::string> npcPrompts;
        bool npcMet;
    public:
        Npc(std::string name, std::vector<std::string> prompts);
        int interaction(Player& player, char level);
        std::string getName();
        void displayChoices();
        bool getMetStatus();
        void setMetStatus(bool status);
        int processChoice(Player& player, int choice, char level);
};