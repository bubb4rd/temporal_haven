# Temporal Haven

Temporal Haven is a command-line text-based video game.

*Made for CSE 240 (Intro to Programming).*

# 📜 Setting

Temporal Haven is not just an ordinary city; it's a hub of temporal research and innovation, known for its cutting-edge laboratories and secretive government projects. The city is surrounded by lush landscapes and is built near the convergence point of several time anomalies. Discover the secrets behind the rise and continued reign of the government.

# 🏙 Locations

Temporal Haven includes several locations that are each important to the story. In these locations/cities you can interact with NPCs and obtain items crucial to completing the game.

# 🧍NPCs

There are many NPCs that the player can interact with, creating unique dialogue and end game states.

# 🔧 Items

There are three classes of each type of item (Common, Rare, Epic). Items can be obtained from following the story or having good relationships with NPCs. Items are crucial to the story.

# How to run

🚨 *This game must be compiled with CLANG!*

## Mac

Open terminal and cd to directory `temporal_haven` is located in.

```
temporal_haven % clang++ --std=c++11  adventure.cpp Player.cpp Item.cpp Backpack.cpp Location.cpp Locations.cpp Npc.cpp -o adventure
```

*(Or compile with C++ versions above 11)*

Followed by: `./adventure`. To compile the program.

## Windows

Open terminal and cd to directory `temporal_haven` is located in.

```
temporal_haven % clang++ --std=c++11  adventure.cpp Player.cpp Item.cpp Backpack.cpp Location.cpp Locations.cpp Npc.cpp -o adventure
```

*(Or compile with C++ versions above 11)*

Followed by: `adventure.exe`. To compile the program.

### Thank you

If you made it this far and actually played the game, thank you! It gave me a lot of frustration while creating it so I hope you got some enjoyment out of it. For queries email `bohubbard8@gmail.com`. Thank you once again 👍😁👍