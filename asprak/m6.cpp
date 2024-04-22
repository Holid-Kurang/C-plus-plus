#include <iostream>
using namespace std;

struct Dungeon {
    string roomName;
    Player player = NULL;
    Monster monster = NULL;
    Item item = NULL;
    Dungeon* prev = NULL;
    Dungeon* nextStage[3] = {NULL,NULL,NULL};
};

struct Player {
    string name;
    int hp;
    int atk;
    int def;
    Item inventory[3] = {NULL,NULL,NULL};
};

struct Monster{
    string type;
    int hp;
    int atk;
    int def;
};

struct Item{
    string name;
    int specialHp;
    int specialAtk;
    int specialDef;
};


int main(){

}