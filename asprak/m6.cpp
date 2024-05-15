#include <iostream>
using namespace std;

struct Item {
    string name;
    int specialHp;
    int specialAtk;
    int specialDef;
};

struct Player {
    bool dead=false;
    string name;
    int hp;
    int atk;
    int def;
    Item inventory[3];
} player[4];

struct Monster {
    bool dead=false;
    string type;
    int hp;
    int atk;
    int def;
};

struct Stage {
    string roomName;
    Player player[4];
    Monster monster;
    Item item;
    int prevStage;
    int nextStage[2];
};
Stage stage[7];

void createDungeon() {
    stage[0].
}

int main() {

}