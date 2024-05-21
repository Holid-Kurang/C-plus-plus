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
    string name;
    int hp;
    int atk;
    int def;
    Item* item = nullptr;

    bool isPlayerEmpty() {
        return name == "";
    }
    bool isDead() {
        return hp < 0;
    }
};

struct Monster {
    string type;
    int hp;
    int atk;
    int def;

    bool isMonsterEmpty() {
        return type == "";
    }
    bool isDead() {
        return hp < 0;
    }
};

struct Room {
    string roomName;
    Player currentPlayer[2];
    Monster* monster = nullptr;
    Item* item = nullptr;
    int prevRoom = -1;
    int nextRoom[2] = { -1, -1 };

    bool isPlayerExist() {
        return !currentPlayer[0].isPlayerEmpty() || !currentPlayer[1].isPlayerEmpty();
    }
    bool isMonsterExist() {
        return monster != nullptr;
    }
    bool isItemExist() {
        return item != nullptr;
    }
};

Room* createDungeon() {
    Room* room = new Room[7];
    room[0].roomName = "000";
    room[0].nextRoom[0] = 1;

    room[1].roomName = "Eldoria Forest";
    room[1].nextRoom[0] = 2;
    room[1].prevRoom = 0;

    room[2].roomName = "222";
    room[2].nextRoom[0] = 4;
    room[2].nextRoom[1] = 5;
    room[2].prevRoom = 1;

    room[4].roomName = "Skyreach Isle";
    room[4].nextRoom[0] = 3;
    room[4].prevRoom = 2;

    room[3].roomName = "333";
    room[3].prevRoom = 4;

    room[5].roomName = "555";
    room[5].nextRoom[0] = 6;
    room[5].prevRoom = 2;

    room[6].roomName = "Abyssia Ocean";
    room[6].prevRoom = 5;

    Monster beastBear = {"Beast Bear", 1250, 100, 30 };
    Monster phoneix = {"Phoneix", 950, 140, 10 };
    Monster leviathan = {"Leviathan", 5000, 300, 50 };

    room[1].monster = new Monster(beastBear);
    room[4].monster = new Monster(phoneix);
    room[6].monster = new Monster(leviathan);

    Item obatKuat = { "Obat Kuat", "Increase attack by 6999", 0, 6999 };
    Item obatSehat = { "Obat Sehat", "Increase HP by 6999", 6999, 0 };
    room[3].item = new Item(obatSehat);
    room[4].item = new Item(obatKuat);

    Player player[2];
    player[0].name = "Holil";
    player[0].hp = 1000;
    player[0].atk = 150;
    player[0].def = 30;
    player[1].name = "Gilang";
    player[1].hp = 1000;
    player[1].atk = 100;
    player[1].def = 75;

    room[0].currentPlayer[0] = player[0];
    room[0].currentPlayer[1] = player[1];

    return room;
}

void centerText(string mess) {
    cout << "| |";
    bool front = true;
    for (int i = mess.size(); i < 45; i++) {
        if (front) {
            mess = " " + mess;
        }
        else {
            mess = mess + " ";
        }
        front = !front;
    }
    cout << mess << "| |" << endl;
}
void alignXText(string mess1, string mess2){
    cout<<"| |"<<mess1;
    for (int i = mess1.size()+mess2.size(); i < 45; i++){
        cout<<" ";
    }
    cout<<mess2<<"| |"<<endl;
}

void bar() {
    cout << "|+|=============================================|+|" << endl;
}

void beastBearModel() {
    bar();
    cout << "                                " << endl;
    cout << "                                " << endl;
    cout << "\t\t   ..------~~~--.__           " << endl;
    cout << "\t\t  /               c~\\        " << endl;
    cout << "\t\t  /             \\__ `\\      " << endl;
    cout << "\t\t  |  /~~--__/  /'\\ ~~'       " << endl;
    cout << "\t\t /'/'\\ |    | |`\\ \\_       " << endl;
    cout << "\t\t`-))  `-))  `-)) `-))         " << endl;
    cout << "                                " << endl;
    cout << "                                " << endl;
    bar();centerText("Beast Bear");bar();
}

void phoneixModel() {
    bar();
    cout << "\t\t    ///,        ////" << endl;
    cout << "\t\t    \\ `/,      /` .>." << endl;
    cout << "\t\t     \\  /,   _/` /." << endl;
    cout << "\t\t      \\_ `/_/`  /." << endl;
    cout << "\t\t       \\__/_  .<" << endl;
    cout << "\t\t       /<<<<\\_\\_" << endl;
    cout << "\t\t      /,)^>>_._\\\\" << endl;
    cout << "\t\t      (/   \\\\ /\\\\\\" << endl;
    cout << "\t\t           //  ```` " << endl;
    cout << "\t\t          ((``" << endl;
    bar();centerText("Phoenix");bar();
}

void levithanModel() {
    bar();
    cout << endl;
    cout << "\t\t         ,--._______,-." << endl;
    cout << "\t\t       ,_____\\.--.,.--./" << endl;
    cout << "\t\t    ((__@@/  /         \\" << endl;
    cout << "\t\t   (.`\\@@/  / (|)' '(|) \\" << endl;
    cout << "\t\t  *'@@  /|''\\--,:___:,--/" << endl;
    cout << "\t\t/ @,--~/|(~~`\\_ V   V _/" << endl;
    cout << "\t\t|\"---< | \\    \\\\ ___ //" << endl;
    cout << "\t\t|>----<\\ @)    `;~~~;`" << endl;
    cout << "\t\t\\(>-----<\\@\")" << endl;
    bar();centerText("Leviathan");bar();
}

string intToString(int n) {
    if (n == 0) {
        return "0";
    }
    bool isNegative = false;
    if (n < 0) {
        isNegative = true;
        n = -n;
    }
    string result;
    while (n > 0) {
        char digit = '0' + (n % 10);
        result = digit + result;
        n /= 10;
    }
    if (isNegative) {
        result = "-" + result;
    }
    return result;
}

int currentRoom(Room* room) {
    for (int i = 0; i < 7; i++) {
        if (room[i].isPlayerExist()) {
            return i;
        }
    }
    return -1;
}

int countNextRoom(int nextRoom[]) {
    int count = 0;
    for (int i = 0; i < 2; i++) {
        if (nextRoom[i] != -1) {
            count++;
        }
    }
    return count;
}

void gotoNextRoom(Room room[], int currentRoom, int nextRoom) {
    room[nextRoom].currentPlayer[0] = room[currentRoom].currentPlayer[0];
    room[nextRoom].currentPlayer[1] = room[currentRoom].currentPlayer[1];
    room[currentRoom].currentPlayer[0] = Player();
    room[currentRoom].currentPlayer[1] = Player();
}

void goBack(Room room[], int currentRoom) {
    int prevRoom = room[currentRoom].prevRoom;
    room[prevRoom].currentPlayer[0] = room[currentRoom].currentPlayer[0];
    room[prevRoom].currentPlayer[1] = room[currentRoom].currentPlayer[1];
    room[currentRoom].currentPlayer[0] = Player();
    room[currentRoom].currentPlayer[1] = Player();
}

void displayMap(Room* room) {
    system("cls");
    char condition[7];
    for (int i = 0; i < 7; i++) {
        if (i == 6 && !room[i].isPlayerExist()) {
            condition[i] = '@';
        }
        else if (!room[i].isPlayerExist()) {
            condition[i] = '#';
        }
        else {
            condition[i] = '!';
        }
    }bar(); centerText(room[currentRoom(room)].roomName);bar();
    cout << "\t\t           (" << condition[0] << ")" << endl;
    cout << "\t\t            |" << endl;
    cout << "\t\t            |" << endl;
    cout << "\t\t           (" << condition[1] << ")" << endl;
    cout << "\t\t            |" << endl;
    cout << "\t\t            |" << endl;
    cout << "\t\t           (" << condition[2] << ")" << endl;
    cout << "\t\t           /  \\_" << endl;
    cout << "\t\t          /     \\_" << endl;
    cout << "\t\t         /       (" << condition[5] << ")" << endl;
    cout << "\t\t(" << condition[3] << ")----(" << condition[4] << ")        |" << endl;
    cout << "\t\t                 /" << endl;
    cout << "\t\t                |" << endl;
    cout << "\t\t                 \\" << endl;
    cout << "\t\t                 (" << condition[6] << ")" << endl;
}

bool fight(Player *player, Monster &monster) {
    int countPlayer1Turn = 1, countPlayer2turn = 1, monsterTurn = 1;
    bool player1Turn=true;
    int hpMonster = monster.hp;
    string choice;
    while (true){
        system("cls");
        centerText("There's a monster in this room");
        if(monster.type == "Beast Bear"){
            beastBearModel();
        }else if(monster.type == "Phoneix"){
            phoneixModel();
        }else if(monster.type == "Leviathan"){
            levithanModel();
        }
        centerText(intToString(hpMonster)+"/"+intToString(monster.hp));
        centerText("Atk : "+intToString(monster.atk));
        centerText("Def : "+intToString(monster.def));
        centerText("Turn : "+intToString(monsterTurn));
        bar();
        if(player1Turn){
            alignXText(player[0].name+" : "+intToString(player[0].hp)+"<==", intToString(player[1].hp)+" : "+player[1].name);
        }else{
            alignXText(player[0].name+" : "+intToString(player[0].hp), "==>"+intToString(player[1].hp)+" : "+player[1].name);
        }
        alignXText("Atk : "+intToString(player[0].atk), intToString(player[1].atk)+" : Atk");
        alignXText("Def : "+intToString(player[0].def), intToString(player[1].def)+" : Def");
        alignXText("Turn : "+intToString(countPlayer1Turn), intToString(countPlayer2turn)+" : Turn");
        bar();
        cout<<"1. attack"<<endl;
        cout<<"2. heal"<<endl;
        cout<<"3. use item"<<endl;
        cout<<">>>>> "; getline(cin, choice);
        while(choice != "1" && choice != "2" && choice != "3"){
            cout<<"Invalid choice"<<endl;
            cout<<">>>>> "; getline(cin, choice);
        }
        if(player1Turn){
            if(countPlayer1Turn % 3 == 0){ // skill player 1
                system("cls");
                bar();centerText("Holil use his skill to critical attack");bar();
                monster.hp -= player[0].atk * 2; 
                system("pause");
            }else{
                if(choice == "1"){
                    monster.hp -= (player[0].atk - monster.def);
                }else if (choice == "2"){
                    player[0].hp += 50;
                }else{
                    if(player[0].item != nullptr){
                        player[0].atk += player[0].item->specialAtk;
                        player[0].hp += player[0].item->specialHp;
                        player[0].item = nullptr;
                        delete player[0].item;
                    }else{
                        cout<<"No item to use"<<endl; system("pause"); 
                        continue;
                    }
                }
            }
            countPlayer1Turn++;
        }else{
            if(countPlayer2turn % 3 == 0){ // skill player 2
                system("cls");
                bar();centerText("Gilang use his skill to block any attack");bar();
                system("pause");
                countPlayer2turn++;
                monsterTurn++; player1Turn = !player1Turn;
                continue;
            }else{
                if(choice == "1"){
                    monster.hp -= (player[1].atk - monster.def);
                }else if (choice == "2"){
                    player[1].hp += 50;
                }else{
                    if(player[1].item != nullptr){
                        player[1].atk += player[1].item->specialAtk;
                        player[1].hp += player[1].item->specialHp;
                        player[1].item = nullptr;
                        delete player[1].item;
                    }else{
                        cout<<"No item to use"<<endl; system("pause"); 
                        continue;
                    }
                }
            }
            countPlayer2turn++;
        }
        
        if(monster.isDead()){
            system("cls");
            bar();centerText(monster.type+" is dead");bar();
            system("pause");
            break;
        }
        if(monsterTurn % 5 == 0){ // skill monster
            system("cls");
            bar();centerText(monster.type+" use his skill to wide attack");bar();
            player[0].hp -= (monster.atk); 
            player[1].hp -= (monster.atk); 
            system("pause");
        }else{
            system("cls");
            if(player1Turn){
                bar();centerText(monster.type+" use his attack to holil");bar();
                player[0].hp -= (monster.atk - player[0].def); 
            }else{
                bar();centerText(monster.type+" use his attack to gilang");bar();
                player[1].hp -= (monster.atk - player[1].def); 
            }
            system("pause");
        }
        if(player[0].isDead() || player[1].isDead()){
            system("cls");
            bar();centerText("One of you is dead");
            centerText("LOSE");bar();
            system("pause");
            break;
        }
        player1Turn = !player1Turn;
        monsterTurn++;
    }
    return monster.isDead();
}

int main() {
    Room* dungeon = createDungeon();
    string choice;
    while (true) {
        // if monster exist
        displayMap(&dungeon[0]);
        if (dungeon[currentRoom(dungeon)].isMonsterExist()) {
            // play 
            bool isMonsterDead = fight(dungeon[currentRoom(dungeon)].currentPlayer, *dungeon[currentRoom(dungeon)].monster);
            if (isMonsterDead) {
                dungeon[currentRoom(dungeon)].currentPlayer[0].hp += 200; dungeon[currentRoom(dungeon)].currentPlayer[1].hp += 200;
                dungeon[currentRoom(dungeon)].currentPlayer[0].atk += 50; dungeon[currentRoom(dungeon)].currentPlayer[1].atk += 50;
                dungeon[currentRoom(dungeon)].monster = nullptr;
                delete dungeon[currentRoom(dungeon)].monster;
                displayMap(&dungeon[0]);
            }else{
                main(); return 0;
            }
            if(dungeon[6].monster == nullptr){
                system("cls");
                bar();
                centerText("Last monster defeated");
                centerText("You win the game");bar();
                // system("pause");
                return 0;
            }
        }
        // if item exist
        if (dungeon[currentRoom(dungeon)].isItemExist()) {
            displayMap(&dungeon[0]);
            bar();
            centerText("You found an item");
            centerText(dungeon[currentRoom(dungeon)].item->name);
            centerText(dungeon[currentRoom(dungeon)].item->efek);
            bar();
            cout << "who's gonna take it? " << endl;
            string playerName;
            while (true) {
                cout << ">>>>> ";
                getline(cin, playerName);
                if (playerName == "Holil" || playerName == "holil") {
                    if(dungeon[currentRoom(dungeon)].currentPlayer[0].item == nullptr){
                        dungeon[currentRoom(dungeon)].currentPlayer[0].item = new Item(*dungeon[currentRoom(dungeon)].item);
                        break;
                    }else{
                        cout<<"holil already have an item"<<endl;
                    }
                }else if (playerName == "Gilang" || playerName == "gilang") {
                    if(dungeon[currentRoom(dungeon)].currentPlayer[1].item == nullptr){
                        dungeon[currentRoom(dungeon)].currentPlayer[1].item = new Item(*dungeon[currentRoom(dungeon)].item);
                        break;
                    }else{
                        cout<<"gilang already have an item"<<endl;
                    }
                }else {
                    cout << "Player not found" << endl;
                }
            }displayMap(&dungeon[0]);
            dungeon[currentRoom(dungeon)].item = nullptr;
            delete dungeon[currentRoom(dungeon)].item;
        }
        // if monster and item not exist
        if (!dungeon[currentRoom(dungeon)].isMonsterExist() && !dungeon[currentRoom(dungeon)].isItemExist()) {
            bar();
            centerText("There's nothing here...");
            bar();
        }
        if (countNextRoom(dungeon[currentRoom(dungeon)].nextRoom) == 2) {
            cout << "\tChoose next room..." << endl;
            cout << "\t" << 1 << ". " << dungeon[dungeon[currentRoom(dungeon)].nextRoom[0]].roomName << endl;
            cout << "\t" << 2 << ". " << dungeon[dungeon[currentRoom(dungeon)].nextRoom[1]].roomName << endl;
            cout << "\tGo back" << endl;
            while (true) {
                cout << ">>>>> ";
                getline(cin, choice);
                if (choice == "1") {
                    gotoNextRoom(dungeon, currentRoom(dungeon), dungeon[currentRoom(dungeon)].nextRoom[0]);
                    break;
                }else if (choice == "2") {
                    gotoNextRoom(dungeon, currentRoom(dungeon), dungeon[currentRoom(dungeon)].nextRoom[1]);
                    break;
                }else if (choice == "back") {
                    goBack(dungeon, currentRoom(dungeon));
                    break;
                }else if (choice == "restart" || choice == "restar" || choice == "r" || choice == "ulang") {
                    main();
                    return 0;
                }
            }
        } else if (countNextRoom(dungeon[currentRoom(dungeon)].nextRoom) == 1) {
            cout << "\tGo next room = " << dungeon[dungeon[currentRoom(dungeon)].nextRoom[0]].roomName << endl;
            cout << "\tGo back" << endl;
            while (true) {
                cout << ">>>>> ";
                getline(cin, choice);
                if (choice == "back") {
                    goBack(dungeon, currentRoom(dungeon));
                    break;
                }else if (choice == "next" || choice == "go") {
                    gotoNextRoom(dungeon, currentRoom(dungeon), dungeon[currentRoom(dungeon)].nextRoom[0]);
                    break;
                }else if (choice == "restart" || choice == "restar" || choice == "r" || choice == "ulang") {
                    main();
                    return 0;
                }
            }
        } else {
            centerText("There are no other next room...");
            bar();
            cout << "\tGo back " << endl;
            while (true) {
                cout << ">>>>> ";
                getline(cin, choice);
                if (choice == "back") {
                    goBack(dungeon, currentRoom(dungeon));
                    break;
                }else if (choice == "restart" || choice == "restar" || choice == "r" || choice == "ulang") {
                    main();
                    return 0;
                }
            }
        }
    }
}