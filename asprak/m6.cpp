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
    bool dead = false;
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
    bool dead = false;
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
    int nextStage[2] = { -1, -1 };

    bool isStageEmpty() {
        return player[0].isPlayerEmpty() && player[1].isPlayerEmpty();
    }
};

Stage* createDungeon() {
    Stage* stage = new Stage[7];
    stage[0].roomName = "000";
    stage[0].nextStage[0] = 1;

    stage[1].roomName = "111";
    stage[1].nextStage[0] = 2;
    stage[1].prevStage = 0;

    stage[2].roomName = "222";
    stage[2].nextStage[0] = 4;
    stage[2].nextStage[1] = 5;

    stage[4].roomName = "444";
    stage[4].nextStage[0] = 3;
    stage[4].prevStage = 2;

    stage[3].roomName = "333";
    stage[3].prevStage = 4;

    stage[5].roomName = "555";
    stage[5].nextStage[0] = 6;
    stage[5].prevStage = 2;

    stage[6].roomName = "666";
    stage[6].prevStage = 5;

    Monster phoneix = { true,"Phoneix", 750, 75, 10 };
    Monster beastBear = { true,"Beast Bear", 1250, 40, 30 };
    Monster leviathan = { true,"Leviathan", 1750, 120, 20 };

    stage[1].monster = &beastBear;
    stage[4].monster = &phoneix;
    stage[6].monster = &leviathan;

    Item obatKuat = { "Obat Kuat", "Increase attack by 5005", 0, 5005 };
    Item obatSehat = { "Obat Sehat", "Increase HP by 5005", 5005, 0 };
    stage[3].item = &obatKuat;
    stage[4].item = &obatSehat;

    player[0].name = "Holil";
    player[0].hp = 1000;
    player[0].atk = 90;
    player[0].def = 10;
    player[1].name = "Gilang";
    player[1].hp = 1000;
    player[1].atk = 80;
    player[1].def = 15;

    stage[0].player[0] = player[0];
    stage[0].player[1] = player[1];

    return stage;
}
void beastBearModel() {
    cout << "   ..------~~~--.__" << endl;
    cout << "  /               c~\\" << endl;
    cout << "  /             \\__ `\\" << endl;
    cout << "  |  /~~--__/  /'\\ ~~'" << endl;
    cout << " /'/'\\ |    | |`\\ \\_" << endl;
    cout << "`-))  `-))  `-)) `-))" << endl;
}
void phoneixModel() {
    cout << "    ///,        ////" << endl;
    cout << "    \\ `/,      /` .>." << endl;
    cout << "     \\  /,   _/` /." << endl;
    cout << "      \\_ `/_/`  /." << endl;
    cout << "       \\__/_  .<" << endl;
    cout << "       /<<<<\\_\\_" << endl;
    cout << "      /,)^>>_._\\\\" << endl;
    cout << "      (/   \\\\ /\\\\\\" << endl;
    cout << "           //  ```` " << endl;
    cout << "          ((``" << endl;
}
void levithanModel() {
    cout << "       ,_____\\.--.,.--./" << endl;
    cout << "    ((__@@/  /         \\" << endl;
    cout << "   (.`\\@@/  / (|)' '(|) \\" << endl;
    cout << "  *'@@  /|''\\--,:___:,--/" << endl;
    cout << "/ @,--~/|(~~`\\_ V   V _/" << endl;
    cout << "|\"---< | \\    \\\\ ___ //" << endl;
    cout << "|>----<\\ @)    `;~~~;`" << endl;
    cout << "\\(>-----<\\@\")" << endl;
}

void displayMap(Stage* stage) {
    system("cls");
    char condition[7];
    for (int i = 0; i < 7; i++) {
        if (i == 6 && stage[i].isStageEmpty()) {
            condition[i] = '@';
        }
        else if (stage[i].isStageEmpty()) {
            condition[i] = '#';
        }
        else {
            condition[i] = '^';
        }
    }
    cout << "           (" << condition[0] << ")" << endl;
    cout << "            |" << endl;
    cout << "            |" << endl;
    cout << "           (" << condition[1] << ")" << endl;
    cout << "            |" << endl;
    cout << "            |" << endl;
    cout << "           (" << condition[2] << ")" << endl;
    cout << "           /  \\_" << endl;
    cout << "          /     \\_" << endl;
    cout << "         /       (" << condition[5] << ")" << endl;
    cout << "(" << condition[3] << ")----(" << condition[4] << ")        |" << endl;
    cout << "                 /" << endl;
    cout << "                |" << endl;
    cout << "                 \\" << endl;
    cout << "                 (" << condition[6] << ")" << endl;
}

void display(Stage stage) {
    cout << "Room Name: " << stage.roomName << endl;
    cout << "Player 1: " << stage.player[0].name << endl;
    cout << "Player 2: " << stage.player[1].name << endl;
    cout << "Monster: " << stage.monster->type << endl;
    cout << "Item: " << stage.item->name << endl;
}
int main() {
    Stage* dungeon = createDungeon();
    while (true){
        displayMap(&dungeon[0]);
        
        cout<<endl;system("pause");
    }
    
    displayMap(&dungeon[0]);

    // phoneixModel();
    // beastBearModel();
    // levithanModel();
}