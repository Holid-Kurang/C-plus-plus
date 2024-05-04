#include <iostream>
using namespace std;

struct Item {
    string name;
    int specialHp;
    int specialAtk;
    int specialDef;
};

struct Player {
    string name;
    int hp;
    int atk;
    int def;
    Item inventory[3];
} player[4];

struct Monster {
    string type;
    int hp;
    int atk;
    int def;
};

struct Dungeon {
    string roomName;
    Player player[4];
    Monster monster;
    Item item;
    Dungeon* prev = NULL;
    Dungeon* nextStage[3] = { NULL,NULL,NULL };
};

void createDungeon() {

}

int main() {
    // cout << createDungeon() << endl;
    Monster monster;
    cout<<monster.atk;
}