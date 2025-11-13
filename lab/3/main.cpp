#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

/**
 * Simple Room class
 * Each room has a name and connections to other rooms
 */
class Room
{
public:
    string name;
    map<string, string> exits; // direction -> room name

    Room() {}
    Room(string n) : name(n) {}
};

/**
 * Game class - handles all game logic
 */
class Game
{
private:
    map<string, Room> rooms; // room name -> Room object
    string currentRoom;
    string monsterRoom;
    string princessRoom;
    bool hasPrincess;
    bool gameOver;

public:
    Game() : hasPrincess(false), gameOver(false)
    {
        srand(time(0)); // Initialize random seed for different results each game
    }

    /**
     * Load map from file
     * File format:
     * room_name
     * direction room_name
     * direction room_name
     * (blank line separates rooms)
     */
    bool loadMap(string filename)
    {
        ifstream file(filename);
        if (!file)
        {
            cout << "Error: Cannot open file " << filename << endl;
            return false;
        }

        string line;
        string roomName = "";

        while (getline(file, line))
        {
            // Skip empty lines between room definitions
            if (line.empty())
            {
                roomName = "";
                continue;
            }

            // First line is room name
            if (roomName.empty())
            {
                roomName = line;
                rooms[roomName] = Room(roomName);
            }
            else
            {
                // Following lines are exits: "direction target_room"
                size_t space = line.find(' ');
                if (space != string::npos)
                {
                    string direction = line.substr(0, space);
                    string target = line.substr(space + 1);
                    rooms[roomName].exits[direction] = target;
                }
            }
        }

        file.close();

        if (rooms.empty())
        {
            cout << "Error: No rooms loaded from file!" << endl;
            return false;
        }

        // Set starting room (first room in map)
        currentRoom = rooms.begin()->first;

        // Randomly select monster and princess rooms (excluding the starting room)
        vector<string> availableRooms;
        for (auto &pair : rooms)
            if (pair.first != currentRoom)
                availableRooms.push_back(pair.first);

        if (availableRooms.size() < 2)
        {
            cout << "Error: Need at least 3 rooms!" << endl;
            return false;
        }

        // Random selection: pick two different rooms
        int idx1 = rand() % availableRooms.size();
        int idx2;
        do
        {
            idx2 = rand() % availableRooms.size();
        } while (idx2 == idx1); // Ensure monster and princess are in different rooms

        monsterRoom = availableRooms[idx1];
        princessRoom = availableRooms[idx2];

        cout << "\n[Random locations set: Monster and Princess are hiding...]" << endl;
        cout << "DEBUG: Monster is in " << monsterRoom << endl;
        cout << "DEBUG: Princess is in " << princessRoom << endl;
        return true;
    }

    /**
     * Display current room information
     */
    void showRoom()
    {
        Room &room = rooms[currentRoom];
        cout << "\nWelcome to the " << room.name << ". ";

        int numExits = room.exits.size();
        if (numExits == 0)
            cout << "There are no exits." << endl;
        else if (numExits == 1)
            cout << "There is 1 exit: " << room.exits.begin()->first << "." << endl;
        else
        {
            cout << "There are " << numExits << " exits: ";
            int count = 0;
            for (auto &exit : room.exits)
            {
                if (count > 0)
                    cout << (count == numExits - 1 ? " and " : ", ");
                cout << exit.first;
                count++;
            }
            cout << "." << endl;
        }
    }

    /**
     * Move to another room
     */
    void move(string direction)
    {
        Room &room = rooms[currentRoom];

        if (room.exits.find(direction) == room.exits.end())
        {
            cout << "You can't go that way!" << endl;
            return;
        }

        currentRoom = room.exits[direction];

        // Check for monster
        if (currentRoom == monsterRoom)
        {
            cout << "\n*** OH NO! ***" << endl;
            cout << "A monster appears and attacks you!" << endl;
            cout << "*** GAME OVER ***" << endl;
            gameOver = true;
            return;
        }

        // Check for princess
        if (currentRoom == princessRoom && !hasPrincess)
        {
            cout << "\n*** CONGRATULATIONS! ***" << endl;
            cout << "You found the princess!" << endl;
            cout << "Princess: \"Thank you! Please take me back to the "
                 << rooms.begin()->first << "!\"" << endl;
            hasPrincess = true;
        }

        showRoom();

        // Check for victory
        if (hasPrincess && currentRoom == rooms.begin()->first)
        {
            cout << "\n*** VICTORY! ***" << endl;
            cout << "You rescued the princess and escaped!" << endl;
            gameOver = true;
        }
    }

    /**
     * Main game loop
     */
    void play()
    {
        cout << "=== CASTLE ADVENTURE ===" << endl;
        cout << "Find the princess and bring her back to escape!" << endl;
        cout << "Beware of the monster!" << endl;

        showRoom();

        while (!gameOver)
        {
            cout << "\nEnter your command: ";
            string command;
            cin >> command;

            if (command == "go")
            {
                string direction;
                cin >> direction;
                move(direction);
            }
            else if (command == "quit")
            {
                cout << "Thanks for playing!" << endl;
                break;
            }
            else
                cout << "Unknown command. Use 'go <direction>' or 'quit'." << endl;
        }
    }
};

/**
 * Main function
 */
int main(int argc, char *argv[])
{
    string mapFile = "map1.txt"; // Default map

    // Check if user provided a map file
    if (argc > 1)
    {
        mapFile = argv[1];
    }
    else
    {
        cout << "Enter map file name (or press Enter for default 'map1.txt'): ";
        string input;
        getline(cin, input);
        if (!input.empty())
            mapFile = input;
    }

    Game game;
    if (!game.loadMap(mapFile))
        return 1;
    game.play();
    return 0;
}