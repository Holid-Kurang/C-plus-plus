#include <iostream>
using namespace std;

struct Item {
    string name;
    string efek;
    int specialHp;
    int specialAtk;

    bool isItemEmpty() {
        return name == "";
    } 
};

struct Player {
    bool dead=false;
    string name;
    int hp;
    int atk;
    int def;
    Item item[2];

    bool isPlayerEmpty() {
        return name == "";
    }
    bool isDead() {
        return dead;
    }
}player[2];

struct Monster {
    bool dead=false;
    string type;
    int hp;
    int atk;
    int def;
    
    bool isMonsterEmpty() {
        return type == "";
    }
    bool isDead() {
        return dead;
    }
};

struct Stage {
    string roomName;
    Player player[2];
    Monster* monster;
    Item* item;
    int prevStage = -1;
    int nextStage[2] = {-1, -1};

    bool isStageEmpty() {
        return player[0].isPlayerEmpty() && player[1].isPlayerEmpty();
    }
};

Stage* createDungeon() {
    Stage* stage = new Stage[7];
    stage[0].nextStage[0] = 1;

    stage[1].nextStage[0] = 2;
    stage[1].prevStage = 0;
    
    stage[2].nextStage[0] = 4;
    stage[2].nextStage[1]= 5;

    stage[4].nextStage[0] = 3;
    stage[4].prevStage = 2;

    stage[3].prevStage = 4;

    stage[5].nextStage[0] = 6;
    stage[5].prevStage = 2;

    Monster slime = {true,"Slime", 10, 5, 2};
    Monster goblin = {true,"Goblin", 20, 10, 5};
    Monster medusa = {true,"Medusa", 300, 15, 10};

    stage[1].monster = &slime;
    stage[4].monster = &goblin;
    stage[6].monster = &medusa;

    Item obatkuat = {"Obat Kuat", "Increase attack by 999", 0, 999};
    Item obatsehat = {"Obat Sehat", "Increase HP by 999", 999, 0};
    stage[3].item = &obatkuat;
    stage[4].item = &obatsehat;

    player[0].name = "Holil";
    player[0].hp = 100;
    player[0].atk = 25;
    player[0].def = 5;
    player[1].name = "Gilang";
    player[1].hp = 100;
    player[1].atk = 20;
    player[1].def = 5;

    stage[6].player[0] = player[0];
    stage[6].player[1] = player[1];

    
    return stage;
}

void displayMap(Stage* stage) {
    system("cls");
    char condition[7];
    for (int i = 0; i < 7; i++) {
        if (i == 6 && stage[i].isStageEmpty()){
            condition[i] = '@';
        }else if (stage[i].isStageEmpty()) {
            condition[i] = '#';
        }else{
            condition[i] = '^';
        }
    }
    cout<<"           ("<<condition[0]<<")"<<endl;
    cout<<"            |"<<endl;
    cout<<"            |"<<endl;
    cout<<"           ("<<condition[1]<<")"<<endl;
    cout<<"            |"<<endl;
    cout<<"            |"<<endl;
    cout<<"           ("<<condition[2]<<")"<<endl;
    cout<<"           /  \\_"<<endl;
    cout<<"          /     \\_"<<endl;
    cout<<"         /       ("<<condition[5]<<")"<<endl;
    cout<<"("<<condition[3]<<")----("<<condition[4]<<")        |"<<endl;
    cout<<"                 /"<<endl;
    cout<<"                |"<<endl;
    cout<<"                 \\"<<endl;
    cout<<"                 ("<<condition[6]<<")"<<endl;
}
int main() {
    Stage* dungeon = createDungeon();
    
    displayMap(&dungeon[0]);
}