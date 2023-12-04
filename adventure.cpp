#include <iostream>
#include "Player.h"
#include "Locations.h"
#include <stdlib.h>
#include "Npc.h"
using namespace std;
float calculateGameStars(Player &player, bool winStatus)
{
    float gameStars = 0.0;
    int playerReputation = player.getReuputation();
    int playerItems = player.getBackpack().returnItemCount();
    // WEIGHT - REPUTATION
    if (playerReputation >= 65)
        gameStars += 2;
    else if (playerReputation >= 60)
        gameStars += 1.25;
    else if (playerReputation >= 50)
        gameStars += 1;
    else if (playerReputation < 50)
        gameStars += 0.5;
    if (playerItems >= 4)
        gameStars += 2;
    else if (playerItems >= 3)
        gameStars += 1.5;
    else if (playerItems > 2)
        gameStars += 1;
    else
        gameStars += 0.5;

    if (player.getBackpack().hasItem("Easter Egg"))
        gameStars += 1;
    if (winStatus)
        gameStars += 5;
    return gameStars;
}
void printLine(char c)
{
    string r = "";
    for (int i = 1; i <= 56; i++)
    {
        r += c;
    }
    cout << r << endl;
}
void printMenu()
{
    printLine('-');
    cout << "MAIN MENU" << endl;
    printLine('-');
    cout << "1. Explore." << endl;
    cout << "2. Player information" << endl;
    cout << "3. Display Locations." << endl;
    cout << "4. Quit." << endl;
    cout << "Please choose an option: " << endl;
    printLine('-');
}
void printTravelChoices()
{
    printLine('-');
    cout << "Where will you go?" << endl;
    cout << "1. Victorian District" << endl;
    cout << "2. Futuristic Zone" << endl;
    // cout << "###################" << endl;
    cout << "3. Back to menu" << endl;
    cout << "Please enter a choice" << endl;
    printLine('-');
}
int calculateRandomReputation(char encounter)
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
// struct Player {
//     string playerName;
//     int age;
//     Backpack playerBackpack;
//     Player(string pName, int a): playerName(pName), age(a), playerBackpack() {}
// };
// struct Item {
//     string itemName;
//     string itemRarity;

//     Item() : itemName(nullptr), itemRarity(nullptr) {}
// };
// struct Backpack {
//     Item slot1;
//     Item slot2;
//     Item slot3;
//     Item slot4;

//     Backpack() : slot1(), slot2(), slot3(), slot4() {}
// };
int main()
{
    string playerName;
    int choice, age, menuChoice, nestedChoice;
    bool quit = false, smith = false, hood = false, institute = false, grand_ball = false, gameOver = false, gameWin = false, oldLady = false;
    bool exploring = true, firstExploration = true;

    Location victorianDistrict("Victorian District", false, "PUBLIC");
    Location futuristicZone("Futuristic Zone", false, "PUBLIC");
    // Location ancientRuins("Ancient Ruins", false, "PUBLIC");
    Location grandBall("Victorian Grand Ball", false, "SECRET");
    Locations towns("towns");
    towns.addLocation(victorianDistrict);
    towns.addLocation(futuristicZone);
    // towns.addLocation(ancientRuins);
    towns.addLocation(grandBall);
    printLine('-');
    cout << "Welcome to Temporal Haven! Temporal Haven is not just an ordinary city; it's a hub of temporal research and innovation, known for its cutting-edge laboratories and secretive government projects. The city is surrounded by lush landscapes and is built near the convergence point of several time anomalies. Your actions affect how others interact with you!" << endl;
    printLine('-');
    cout << "Let's create your player!" << endl;
    cout << "What should we call you? ";
    cin >> playerName;
    cout << "How old are you, " << playerName << "? ";
    cin >> age;
    cout << "Welcome to Temporal Haven, " << playerName << "!" << endl;
    Player mainPlayer(playerName, age);
    Backpack backpack = mainPlayer.getBackpack();
    do
    {

        printMenu();
        cin >> menuChoice;
        if (firstExploration)
        {
            printLine('-');
            cout << "TIP: Press 'Enter' to continue after each line for dialogues and interactions." << endl;
            printLine('-');
        }
        switch (menuChoice)
        {
        case 1:
            exploring = true;
            while (exploring)
            {
                printTravelChoices();
                cin >> choice;
                if (firstExploration)
                    firstExploration = false;
                if (choice == 1)
                {
                    towns.changeVisitStatus(victorianDistrict);
                    towns.getLocation("Victorian District").setVisitStatus(true);
                    cout << playerName << ", welcome to the Victorian District!" << endl;
                    cout << "The Victorian District is filled with life! Walking through the streets you begin to notice how clean the area is." << endl;
                    cout << "Everywhere you look, a steam-powered machine is running things.\n"
                         << endl;
                    cout << "\"Hey there! You new in town?\", a burly man calls out from what looks like a blacksmith shop." << endl;
                    printLine('-');
                    cout << "1. Talk to the man" << endl;
                    cout << "2. Keep walking" << endl;
                    cout << "Pick an option" << endl;
                    printLine('-');
                    cin >> nestedChoice;
                    if (nestedChoice == 1)
                    {
                        if (smith)
                            cout << "You have already talked to the smith" << endl;
                        else if (!smith)
                        {

                            Npc doug("Doug", {"Pretty cool place, what kind of items do you have here?", "This place is kind of shoddy.", "Do you have any free stuff?"});
                            string dougName = doug.getName();
                            cout << playerName << " approaches the man." << endl;
                            cout << playerName << " appreciates the craftsmanship of the blacksmith." << endl;
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            cout << playerName << ": Maybe there are some cool items here" << endl;
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            int reaction = doug.interaction(mainPlayer, 'P');
                            if (reaction == 1 || reaction == 3)
                            {
                                cout << dougName << ": Looking for anything specific?" << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << playerName << ": Sorry sir, I don't have any money, just got into town." << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << dougName << ": No money! Well, do you have any cool items? (he grins)" << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << playerName << ": No sir" << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << dougName << ": Well, I have a couple of old knives in the back. I could lend you one but I expect you to give it back, sometime " << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << playerName << " takes the dagger that " << dougName << " is holding" << endl;
                                cout << playerName << ": Thank you" << endl;
                                Item dagger("Dagger", "Common");
                                mainPlayer.getBackpack().addItem(dagger);
                            }
                            else if (reaction == 2)
                            {
                                cout << "Blacksmith: Well if you don't appreciate it you can get the hell out!" << endl;
                            }
                            smith = true;
                        }
                    }
                    else if (nestedChoice == 2)
                    {
                        if (!hood)
                        {
                            cout << "Passing the smith shop, " << playerName << " notices someone looking at them from the alley." << endl;
                            cout << playerName << ": why a hood?" << endl;
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            cout << playerName << " approaches the person in the hood." << endl;
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            cout << "Hood: I've been waiting for you, " << playerName << "." << endl;
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            cout << playerName << ": How do you know my name?" << endl;
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            cout << "Hood: That doesn't matter" << endl;
                            cout << "The hood drops an envelope on the ground before running away" << endl;
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            cout << playerName << ": Wait up!" << endl;
                            cout << "The hood gets away from " << playerName << "." << endl;
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            cout << playerName << " opens the envelope, a sticky note reads:\n\"Grand Victorian Ball, Victorian Palace, tonight.\"" << endl;
                            cout << playerName << " stuffs the envelope in their backpack.\n"
                                 << endl;

                            int addReputation = calculateRandomReputation('P');
                            int newReputation = mainPlayer.getReuputation() + addReputation;
                            mainPlayer.setReputation(newReputation);

                            cout << "You gained " << addReputation << " reputation. (Current reputation: " << newReputation << ")" << endl;

                            Item envelope("Grand Ball Invitation", "Rare");
                            mainPlayer.getBackpack().addItem(envelope);
                            towns.setLocationType(grandBall, "PUBLIC");
                            cout << "********************************************************" << endl;
                            std::cout << "Area discovered: " << grandBall.getLocation() << std::endl;
                            cout << "********************************************************" << endl;
                            hood = true;
                        }
                        else if (hood && !mainPlayer.getBackpack().hasItem("Easter Egg"))
                        {
                            cout << playerName << " stumbles upon a box with their name on it." << endl;
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            cout << playerName << ": What the hell?" << endl;
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                            Item easterEgg("Easter Egg", "Legendary");
                            cout << playerName << " opens the box to reveal a Golden Egg! It's an Easter Egg :3 \nAwesome job if you found this! - Gamemaker. " << endl;
                            mainPlayer.getBackpack().addItem(easterEgg);
                        }

                        if (mainPlayer.getBackpack().hasItem("Grand Ball Invitation") && grand_ball == false)
                        {
                            int tempChoice;
                            printLine('-');
                            cout << "1. Attend the ball" << endl;
                            cout << "2. Continue exploring" << endl;
                            cout << "Please pick an option." << endl;
                            printLine('-');
                            cin >> tempChoice;
                            if (tempChoice == 1)
                            {
                                if (mainPlayer.getBackpack().hasItem("Temporal Watch"))
                                {
                                    cout << "The Temporal Watch buzzes. \'Press ENTER to read message.\'" << endl;
                                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                    printLine('~');
                                    cout << "DO NOT TRUST ANYONE AT THE BALL." << endl;
                                    printLine('~');
                                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                    cout << playerName << ": Don't trust anyone? Who is even sending me a message?" << endl;
                                }
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << "In the envelope is a drawing of the Victorian Palace and an arrow pointing north." << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << playerName << " starts to head towards the Palace." << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << playerName << " arrives at the gates of the palace before he is stopped by two guards." << endl;
                                cout << "The gates are more than triple the height of " << playerName << "." << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << "Guard: Invitation." << endl;
                                cout << playerName << " hands the guard their invitation." << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << "The gates begin to creak inwards slowly, as they open." << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << playerName << " is in awe of how big everything in the palace actually is." << endl;
                                cout << playerName << " walks over to a huge fountain in the middle of the walkway, surrounded by lanterns, illuminating the water." << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << "\"Psssst!\" " << playerName << " hears a whisper from the other side of the fountain." << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << playerName << " circles around to the other side of the fountain." << endl;
                                cout << "Hood: Hello again, " << playerName << "." << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << playerName << ": You again! (approaching the hooded person)" << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << "Hood: I see you got in here fine." << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << playerName << ": Who are you? How do you know my name? Why did you bring me here?" << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << "Hood: Slow down, I know you are confused but it will make sense if you just listen." << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << playerName << ": Ok, then we'll start with the hood, why?" << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << "Hood: I am hiding from the government. They, my dear acquaintance, are not as pristine as their polished marble halls suggest. They have their fingers in everything, including these watches they've been distributing. " << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                if (mainPlayer.getBackpack().hasItem("Temporal Watch"))
                                    cout << playerName << ": Watches? You mean this thing on my wrist? What's wrong with it? (raising an eyebrow)" << endl;
                                else
                                    cout << playerName << ": I've seen them around, what's wrong with them?" << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << "Hood: Those watches aren't just for telling time. They're trackers, surveillance devices. They know every step you take, every breath you make, they are building something evil behind the scenes. The government's eyes are always on you." << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << playerName << ":  Surveillance watches? That's a bit hard to swallow. Why would they be keeping tabs on us?" << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << "Hood: Knowledge is power, my friend. They want to control everything, and that includes knowing what everyone is up to. But there are whispers of resistance, those of us who refuse to be pawns in their game." << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << playerName << ": Don't call me your friend, I don't even know you." << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << playerName << ": Speaking of, how do you even know me?" << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << "The hood points to the Temporal Watch on their wrist." << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << "Hood: Everything is connected. Nothing is a coincidence in this world." << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << playerName << ": So why did you bring me here?" << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << "Hood: This is more than an extravagant ball. It's a gathering of like-minded individuals, a chance to share information, expose the truth, and perhaps, change the course of this shadowy game they're playing." << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << playerName << ": So, what's the plan? How does this ball fit into all of it?" << endl;
                                Item resistancePin("Resistance Pin", "Rare");
                                cout << "Hood: Take this, you will know the time to use it (throwing a suit pin)" << endl;
                                mainPlayer.getBackpack().addItem(resistancePin);
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << "Hood: Inside, you'll meet people who can open your eyes to the government's secrets. Keep your wits about you, and don't trust everyone. The dance floor isn't the only place where moves are being made." << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << "The hood retreats into the dark fields of the palace." << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << playerName << " enters the palace." << endl;
                                cout << "The Grand Victorian Ball unfolds before your eyes as you step through the ornate doors of the majestic ballroom. The air is filled with the enchanting melodies of a live orchestra, the shimmering light of crystal chandeliers casting an ethereal glow on the dancing couples." << endl;
                                towns.changeVisitStatus(grandBall);
                                cout << playerName << ": Quite the spectacle. I didn't expect all this color. (gazing the surroundings)" << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << "A woman in an extravagant dress approaches " << playerName << "." << endl;
                                cout << "Woman: Welcome to the heart of the Grand Victorian Ball, where secrets are shared beneath the guise of celebration." << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << playerName << ": Secrets? What are you talking about?" << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << "Woman: Oh, honey, this isn't just a gathering of nobles and dignitaries. It's a haven for those seeking the hidden truths behind the government's facade. We've hand-picked everyone here, surely there are no spies, unless... (investigating " << playerName << ")" << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << playerName << ": Any advice on how to navigate this sea of intrigue? (surveying the crowds of people)" << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << "Woman: Seek out those with unusual accessories, symbols, or peculiar mannerisms. They often hold the keys to the cryptic conversations that sway the tides of power (whispering)" << endl;
                                cout << "Woman: Oh. by the way, my name is Elizabeth (smiling)" << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << playerName << ": Got it. Unusual accessories, symbols, and peculiar mannerisms. I'll be on the lookout." << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << playerName << " notices masked figures engaged in hushed conversations, each word laden with hidden meaning. The atmosphere is electric with anticipation, and the walls seem to echo with the secrets of Temporal Haven." << endl;
                                cout << playerName << ": Time to unravel the mysteries of this Grand Victorian Ball." << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << "Elizabeth flags " << playerName << ", motioning him over to her in the corner." << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << playerName << " shuffles through crowds to get to the woman." << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << "Before " << playerName << " reaches Elizabeth, two men start forcefully escorting " << playerName << " to the corner." << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << playerName << ": Hey! What the hell is going on? (struggling)" << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << "The men drop " << playerName << " in front of Elizabeth, who is accompanied by a small man." << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << "The man tries calming " << playerName << " down." << endl;
                                cout << "Man: Calm down for a moment. We need to make sure you're not a spy." << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << playerName << ": Spy? I thought everyone here was 'hand-picked'." << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << "Elizabeth: Who are you really, and why are you here?" << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << playerName << ": What do you mean?" << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << "Elizabeth: Don't play dumb, we know you aren't from here." << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << playerName << ": I'm not your enemy, I promise. I just want to find out the truth behind the government and get in touch with the right people." << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << "Man: Well, you made it this far. What do you know, and why should we help you?" << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << playerName << ": I know that they should be stopped. And from what I hear, you guys need me more than you do." << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << "Elizabeth looks at the man for defense but he shrugs in agreement" << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << "Man: You are right kid, we are all over the place. But this organization is built on trust. So, you must see how it looks when someone none have us have ever seen shows up here." << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << "Man: Follow us (walking away)" << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << playerName << " and the resistance members stand in front of a brick wall." << endl;
                                cout << "The man pulls out a pin just like the one the hood gave " << playerName << ". He presses the pin." << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << "The brick wall pops back and slides into a pocket" << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << playerName << " begins to walk down the eerily lighted tunnel, observing how bleak the walls are." << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << playerName << " arrives at two giant doors, lit with torches on each side." << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << "Elizabeth: Use your pin (pointing)" << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << playerName << " clicks their pin." << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << "(crack) The doors start opening, letting out a very loud creaking noise." << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << "A man is standing on the inside, smiling, waiting for people to greet him" << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << "Elizabeth and man: Hello Lucius (in unison)" << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << "The man smiles, gesturing for them to come in." << endl;
                                cout << "The room is spacious, its walls lined with countless bookshelves filled with dusty tomes. The air is heavy with the scent of aged paper. In the center stands an intricately carved mahogany table, upon which rests a collection of classified documents." << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << playerName << ": This... this is incredible. How did you create such a hidden chamber beneath the ballroom?" << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << "Lucius: Centuries of resistance, my friend. We have been fighting the government's tyranny for generations, and this chamber has been our sanctuary." << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << "Lucius walks over to a hidden alcove and with a swift motion, reveals a hidden compartment. Inside, an array of futuristic devices catches " << playerName << "\'s eye." << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << playerName << ": What are these? They look far more advanced than anything the government possesses (in awe)" << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << "Lucius: Oh, you have just scratched the surface. These are modded Temporal Watches that remove the limiters set on them, they are truly amazing creations (grinning)" << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << "Lucius: Our cause requires us to push boundaries and use every advantage at our disposal. We need you, " << playerName << ". Someone like you has the power to bring this whole thing down." << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << playerName << ": I am ready to stand with you and fight for truth, justice, and the restoration of an uncorrupted timeline." << endl;
                                cout << "Lucius nods approvingly, his eyes filled with determination and hope." << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << "Lucius: Then let us commence the revolution. But remember, " << playerName << ", the future depends on our next move. We cannot afford to falter." << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << playerName << ": I agree. What should my next step be?" << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << "Lucius: You need to visit the square in the Futuristic Zone, and get in contact with the resistance group preaching there." << endl;
                            }
                            grand_ball = true;
                        }
                    }
                }
                else if (choice == 2)
                {
                    cout << "Welcome to the Futuristic Zone, a dazzling metropolis of advanced technology and limitless possibilities! As you step into this high-tech haven, neon lights flicker overhead, and sleek buildings reach for the sky. Hovering vehicles zip through the air, leaving trails of luminous streaks." << endl;
                    cout << "\"The key to time travel could be somewhere around here. I think I saw a sign for a research institute at the plaza\", " << playerName << " thinks." << endl;
                    towns.changeVisitStatus(futuristicZone);
                    printLine('-');
                    cout << "1. Search for the research institute" << endl;
                    cout << "2. Walk around" << endl;
                    cout << "Please pick an option." << endl;
                    printLine('-');
                    cin >> nestedChoice;
                    if (nestedChoice == 1)
                    {
                        // cout << "RESEARCH INSTITUTE" << endl;
                        cout << playerName << " walks through the streets of the futuristic zone, recognizing that some people have a special type of watch." << endl;
                        if (!oldLady)
                        {
                            cout << playerName << " stops an old lady on the street." << endl;
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            Npc streetLady("Old lady", {"Excuse me miss, what is that thing on your hand?", "What's that thing on your wrist, some avant-garde fashion disaster?", "Where can I get a watch like that?"});
                            int reaction = streetLady.interaction(mainPlayer, 'I');
                            if (reaction == 1 || reaction == 3)
                            {
                                cout << "Old lady: It's a Temporal Message Watch. You don't have one?" << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << playerName << ": No I'm not from this area. What does it do?" << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << "Old lady: You can talk to people from future or past versions of yourself, its super cool!" << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << playerName << ": Where do I get one?" << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << "Old lady: You can get one from the Temporal Research Institute, it's about a half-mile down this main street." << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << playerName << ": Thank you!" << endl;
                            }
                            else if (reaction == 2)
                            {
                                cout << "\"Wouldn't you like to know weather boy\", the lady snaps back." << endl;
                            }
                            oldLady = true;
                        }
                        if (!institute)
                        {
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            cout << playerName << " begins to search for the research institute." << endl;
                            cout << playerName << " sees advanced pieces of technology everywhere. Smart watches, holographs, even floating bikes." << endl;
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            cout << "At the end of the main street there is bleach-white building, ominously covering the sun, casting a huge shadow onto the street.\nThe words \'Temporal Research Institute\' loom over them." << endl;
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            cout << playerName << " walks into the building, greeted by two women at the front desk. Both grinning from ear to ear." << endl;
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            cout << "\"Hi! My name is Emily, how can I help you today?\", one of the front deskwomen asks." << endl;
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            cout << playerName << ": Hi, umm, I'm trying to get a Temporal Watch?" << endl;
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            cout << "Emily: Yes! You've come to the right place!" << endl;
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            cout << playerName << " notices the other front desk lady staring at them very creepily." << endl;
                            cout << "Emily: Can I get a name for our records?" << endl;
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            cout << playerName << ": Sure, its " << playerName << "." << endl;
                            cout << "Emily: Perfect, we are giving away TMW's for free this week! You're in luck!" << endl;
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            cout << playerName << " looks at her with confusion." << endl;
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            cout << playerName << ": How are you able to give stuff like this for free?" << endl;
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            cout << "Emily: Amazing question! The government is doing a program where they are trying to get this technology to those who wouldn't normally be able to aqcuire it." << endl;
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            cout << playerName << ": So, how can I get one?" << endl;
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            cout << "Emily: We'll have you fill out a form with some basic info for us, and then after that I'll send someone to get you, so we can get your deviced configured." << endl;
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            cout << "After filling out the form and a little bit of waiting, a man retrieves " << playerName << ", he has a well-sized black box in his hands.\nHe leads them to what looks like an office." << endl;
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            cout << "Institute Worker: Please take a seat." << endl;
                            cout << "The institute worker gestures towards a seat at the desk." << endl;
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            cout << playerName << " takes a seat.\nInstitute Worker: Now, this may sting a little or it could induce a headache. We have painkillers if it gets bad." << endl;
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            cout << playerName << " puts the watch on their wrist." << endl;
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            cout << "The man plugs the watch into his computer, \nInstitute Worker: I'm just going to log your baseline in case you have any troubles down the line." << endl;
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            cout << "Institute Worker: How do you feel?." << endl;
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            cout << playerName << ": Nothing out of the ordinary." << endl;
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            cout << "Institute Worker: Well, if you have any problems feel free to come back at any time." << endl;
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            cout << playerName << " leaves the research institute." << endl;
                            Item temporalWatch("Temporal Watch", "Epic");
                            mainPlayer.getBackpack().addItem(temporalWatch);
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            institute = true;
                        }
                    }
                    else if (nestedChoice == 2)
                    {
                        // cout << "GOVERNMENT SECRETS" << endl;
                        cout << playerName << " appreciates how cool the architecture is in the Futuristic Zone. They are also in awe of the flying cars and bikes people ride" << endl;
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        cout << playerName << " cautiously enters the dimly lit warehouse filled with a chaotic assembly of protesters. Banners and signs are plastered everywhere, bearing slogans of resistance against the oppressive government. The air is heavy with tension and the scent of smoke." << endl;
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        cout << "Protestors: (in unison) We will not take this anymore! Enough is enough!" << endl;
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        Npc protestorOne("Protestor 1", {"How do I join?", "You don't think you guys are making a difference, do you?", "What are you protesting?"});
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        int reaction = protestorOne.interaction(mainPlayer, 'P');
                        if (reaction == 1 || reaction == 3)
                        {
                            cout << "Protestor: The government is hiding terrible things from us. They have been in power for so long because of their manipulation!" << endl;
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            cout << playerName << ": Really? That's terrible." << endl;
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            cout << "Protestor: Exactly! You should think about joining. That woman up there is Alexandra, she can help you out." << endl;
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            cout << "A makeshift platform stands at the center, where a fierce resistance leader is passionately rallying the crowd." << endl;
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            cout << "Alexandra: My fellow brothers and sisters, we gather here today united against a common enemy - a government that manipulates time to control our destiny! We shall not stand idle while they tear our world apart!" << endl;
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            cout << "The crowd roars with a mix of passion and anger, their faces filled with determination." << endl;
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            cout << playerName << " pushes through the crowd, their eyes locked on Alexandra, sensing her strong presence and sharp mind. As her speech winds down, Alexandra notices" << playerName << " making their way closer." << endl;
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            cout << playerName << " approaches Alexandra after she finished her speech" << endl;
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            cout << playerName << ": I'm " << playerName << " and I stand with the resistance. The government's time manipulation must be stopped." << endl;
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            cout << "People begin murmuring behind Alexandra." << endl;
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            cout << "Alexandra: We don't just bring anyone in, kid." << endl;
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            if (mainPlayer.getBackpack().hasItem("Resistance Pin"))
                            {
                                cout << playerName << ": But I am with you (brandishing the resistance pin)" << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << "The murmurs behind Alexandra stop abruptly." << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << "Alexandra looks at the pin in silence before responding." << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << "\"TEMPORAL POLICE OPEN UP! \", can be heard outside the warehouse, accompanied by large amounts of banging" << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << "Protesters begin scrambling in every direction for cover." << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                int fightChoice;
                                printLine('-');
                                cout << "1. Fight back" << endl;
                                cout << "2. Hide" << endl;
                                cout << "Pick an option." << endl;
                                printLine('-');
                                cin >> fightChoice;
                                if (fightChoice == 1)
                                {
                                    cout << "Alexandra: Don't do it!" << endl;
                                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                    cout << playerName << " runs out at the police screaming, before realizing how outnumbered they are." << endl;
                                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                    cout << "Police man: Put your hands behind your back!" << endl;
                                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                    cout << "Reluctantly, " << playerName << " complies." << endl;
                                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                }
                                else if (fightChoice == 2)
                                {
                                    cout << playerName << " and Alexandra dash away, trying to hide under a desk." << endl;
                                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                    cout << "The police begin arresting people, whilst still looking around the warehouse." << endl;
                                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                    cout << playerName << " sees the shoes of police officers right next to the desk they are hiding under." << endl;
                                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                    cout << playerName << " beings praying they don't find them." << endl;
                                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                    cout << "Police man: Get out from under there!" << endl;
                                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                    cout << playerName << " and Alexandra give up and comply." << endl;
                                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                }
                                cout << "The police arrest " << playerName << ", Alexandra, and a couple of protestors" << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << "Police Captain: You're under arrest for crimes of racketeering. Put your hands behind your back." << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << playerName << " and Alexandra exchange a knowing glance, steeling themselves for what lies ahead. They put their hands behind their back." << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << "The police arrive at the Temporal State. It is a vast, ominous facility that exudes power and control. Officers in crisp uniforms patrol the halls, their expressions cold and unwavering." << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << playerName << " and Alexandra are brought into the huge and ominous building before being escorted down dimly lit corridor. The corridor is lined with prison cells, each holding individuals stripped of their freedom. The echoes of despair resonate through the concrete walls." << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << playerName << " and Alexandra are pushed into a small holding cell. The door slams shut behind them, echoing through the silent room." << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << "Alexandra: We can't stay here. We need to find a way out, get to the heart of this place—-the Time Room." << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << playerName << ": The Time Room, really? That can't be a real place." << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << "Alexandra: It's exactly what it sounds like. Lucius found the location of it last week, its here!" << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << playerName << ": Where even are we?" << endl;
                                cout << "Alexandra: It's called the Temporal State building, its where most of the government policymakers work. This is their main base, if they brought us here it must mean they know we are onto them." << endl;
                                cout << "Alexandra: We have one shot at exposing the truth and undoing this twisted government. Let's do this." << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                if (mainPlayer.getBackpack().hasItem("Temporal Watch"))
                                {
                                    cout << playerName << ": They didn't take my Temporal Watch, can we do something with it?" << endl;
                                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                    cout << "Alexandra: Maybe, I think I can tinker with it to get us out of here." << endl;
                                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                    cout << "Alexandra uses a pin to play with some switches inside of the watch" << endl;
                                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                    cout << "Alexandra holds the watch up to the door." << endl;
                                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                    cout << "(sizzling sound followed by a small pop) The door lock pops out." << endl;
                                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                }
                                else
                                {
                                    cout << "Alexandra takes off her boot, revealing a metal stick." << endl;
                                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                    cout << "Alexandra: Don't worry, I won't let it end like this." << endl;
                                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                    cout << "Alexandra fiddles with the look for a couple of minutes before getting it to unlock." << endl;
                                }
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << "Alexandra: Come on, lets get going!" << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << playerName << " and Alexandra begin running down the corridor, trying to make it as far as possible." << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << "Police man: Somebody stop them! (running after the two)" << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << "They arrive at a bright red door with a sign above it reading \'Chronos Nexus\'" << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << playerName << ": This has to be it." << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << playerName << " and Alexandra burst into the Time Room, a high-tech chamber filled with pulsating screens and swirling vortexes of temporal energy." << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << "Alexandra: I'm gonna send you through. Go stand in the tube!" << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << playerName << " jumps into the tube, hearing drilling and wirring sounds" << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << playerName << ": Hey, I don't think this is a good id--" << endl;
                                cout << playerName << " gets cut off before getting teleported." << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                if (mainPlayer.getBackpack().hasItem("Temporal Watch"))
                                {
                                    cout << playerName << " arrives in what looks like the Temporal State building, but way older." << playerName << " notices the Temporal Watch is smoking, most likely damaged and irrepairable. They sit in front of the \'Presidential Suite\'" << endl;
                                }
                                else
                                {
                                    cout << playerName << " arrives in what looks like the Temporal State building, but way older. They sit in front of the \'Presidential Suite\'" << endl;
                                }
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << playerName << ": I mean this is too obvious--right? (questioning)" << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << playerName << " enters the room." << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                if (mainPlayer.getBackpack().hasItem("Dagger"))
                                {
                                    cout << playerName << " assassinates the Temporal leader with their dagger, securing the future for the people, free from the infinite reign of the Temporal government." << endl;
                                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                    cout << playerName << "lives out the rest of their lifetime in that timeline, a hero." << endl;
                                    gameWin = true;
                                }
                                else
                                {
                                    cout << playerName << " tries to strangle the Temporal leader but he wakes up and stabs " << playerName << ". They did not have any weapons." << endl;
                                }

                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << "\n\nGAME OVER!" << endl;
                                exploring = false;
                                gameOver = true;
                            }
                            else
                            {
                                cout << playerName << ": What do I gotta do?" << endl;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << "Alexandra: You're just not ready yet." << endl;
                            }
                        }
                        else if (reaction == 2)
                        {
                            cout << "Protestor: Yes, we are making a difference! And people who criticize us like you are no better than them!" << endl;
                        }
                        else
                            cout << "Invalid option." << endl;
                    }
                    else
                        cout << "Invalid option" << endl;
                }
                else if (choice == 3)
                    exploring = false;
            }
            if (gameOver)
            {
                printLine('%');
                cout << "\nFinal stats: Game stars: " << calculateGameStars(mainPlayer, gameWin) << "/10" << endl;
                mainPlayer.toString();
                printLine('%');
                cout << "Thank you for playing!" << endl;
                return 0;
            }
            break;
        case 2:
            mainPlayer.toString();
            break;
        case 3:
            towns.displayLocations();
            break;
            ;
        case 4:
            cout << "Quitting..." << endl;
            return 0;
        default:
            cout << "Invalid option." << endl;
        }
    } while (!quit);
    return 0;
}