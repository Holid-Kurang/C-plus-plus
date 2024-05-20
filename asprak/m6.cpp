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
    int countSlot() {
        int count = 0;
        for (int i = 0; i < 2; i++) {
            if (!item[i].isItemEmpty()) {
                count++;
            }
        }
        return count;
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

    Monster beastBear = { true,"Beast Bear", 1250, 45, 30 };
    Monster phoneix = { true,"Phoneix", 750, 75, 10 };
    Monster leviathan = { true,"Leviathan", 1750, 120, 20 };

    room[1].monster = new Monster(beastBear);
    room[4].monster = new Monster(phoneix);
    room[6].monster = new Monster(leviathan);

    Item obatKuat = { "Obat Kuat", "Increase attack by 5005", 0, 9999 };
    Item obatSehat = { "Obat Sehat", "Increase HP by 5005", 9999, 0 };
    room[3].item = new Item(obatSehat);
    room[4].item = new Item(obatKuat);

    player[0].name = "Holil";
    player[0].hp = 1000;
    player[0].atk = 90;
    player[0].def = 10;
    player[1].name = "Gilang";
    player[1].hp = 1000;
    player[1].atk = 80;
    player[1].def = 15;

    room[0].currentPlayer[0] = player[0];
    room[0].currentPlayer[1] = player[1];

    return room;
}

void centerText(string mess){
    cout<<"| |";
	bool front = true;
	for(int i = mess.size(); i<35; i++){
		if(front){
			mess = " " + mess;
		}else{
			mess = mess + " ";
		}
		front = !front;
	}
	cout<<mess<<"| |"<<endl;
}

void bar() {
    cout << "|+|===================================|+|" << endl;
}

void beastBearModel() {
    bar();
    cout << "                                " << endl;
    cout << "                                " << endl;
    cout << "\t   ..------~~~--.__           " << endl;
    cout << "\t  /               c~\\        " << endl;
    cout << "\t  /             \\__ `\\      " << endl;
    cout << "\t  |  /~~--__/  /'\\ ~~'       " << endl;
    cout << "\t /'/'\\ |    | |`\\ \\_       " << endl;
    cout << "\t`-))  `-))  `-)) `-))         " << endl;
    cout << "                                " << endl;
    cout << "                                " << endl;
    bar();
    centerText("Beast Bear");
    bar();
}

void phoneixModel() {
    bar();
    cout << "\t    ///,        ////" << endl;
    cout << "\t    \\ `/,      /` .>." << endl;
    cout << "\t     \\  /,   _/` /." << endl;
    cout << "\t      \\_ `/_/`  /." << endl;
    cout << "\t       \\__/_  .<" << endl;
    cout << "\t       /<<<<\\_\\_" << endl;
    cout << "\t      /,)^>>_._\\\\" << endl;
    cout << "\t      (/   \\\\ /\\\\\\" << endl;
    cout << "\t           //  ```` " << endl;
    cout << "\t          ((``" << endl;
    bar();
    centerText("Phoenix");
    bar();
}

void levithanModel() {
    bar();
    cout << endl;
    cout << "\t         ,--._______,-." << endl;
    cout << "\t       ,_____\\.--.,.--./" << endl;
    cout << "\t    ((__@@/  /         \\" << endl;
    cout << "\t   (.`\\@@/  / (|)' '(|) \\" << endl;
    cout << "\t  *'@@  /|''\\--,:___:,--/" << endl;
    cout << "\t/ @,--~/|(~~`\\_ V   V _/" << endl;
    cout << "\t|\"---< | \\    \\\\ ___ //" << endl;
    cout << "\t|>----<\\ @)    `;~~~;`" << endl;
    cout << "\t\\(>-----<\\@\")" << endl;
    bar();
    centerText("Leviathan");
    bar();
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
    }
    cout << "\t           (" << condition[0] << ")" << endl;
    cout << "\t            |" << endl;
    cout << "\t            |" << endl;
    cout << "\t           (" << condition[1] << ")" << endl;
    cout << "\t            |" << endl;
    cout << "\t            |" << endl;
    cout << "\t           (" << condition[2] << ")" << endl;
    cout << "\t           /  \\_" << endl;
    cout << "\t          /     \\_" << endl;
    cout << "\t         /       (" << condition[5] << ")" << endl;
    cout << "\t(" << condition[3] << ")----(" << condition[4] << ")        |" << endl;
    cout << "\t                 /" << endl;
    cout << "\t                |" << endl;
    cout << "\t                 \\" << endl;
    cout << "\t                 (" << condition[6] << ")" << endl;
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

int main() {
    Room* dungeon = createDungeon();
    string choice;
    while (true){
        // if monster exist
        if(dungeon[currentRoom(dungeon)].isMonsterExist()){
            // displayMap(&dungeon[0]);
            // if(dungeon[currentRoom(dungeon)].monster->type == "Beast Bear"){
            //     beastBearModel();
            // }else if(dungeon[currentRoom(dungeon)].monster->type == "Phoneix"){
            //     phoneixModel();
            // }else if(dungeon[currentRoom(dungeon)].monster->type == "Leviathan"){
            //     levithanModel();
            // }
            // //play 
        }
        
        // if item exist
        if(dungeon[currentRoom(dungeon)].isItemExist()){
            displayMap(&dungeon[0]);
            bar();
            centerText("You found an item");
            centerText(dungeon[currentRoom(dungeon)].item->name);
            bar();
            while(true){
                cout<<"Want to take it?.. (y/n) ";
                getline(cin, choice);
                if(choice == "y" || choice == "Y"){
                    cout<<"who's gonna take it? "<<endl;
                    string playerName;
                    while(true){
                        cout<<">>>>> ";
                        getline(cin, playerName);
                        if(playerName == player[0].name || playerName == "holil"){
                            player[0].item[0] = *dungeon[currentRoom(dungeon)].item;
                            break;
                        }else if (playerName == player[1].name || playerName == "gilang"){
                            player[1].item[0] = *dungeon[currentRoom(dungeon)].item;
                            break;
                        }else{
                            cout<<"Player not found"<<endl;
                        }
                    }
                    delete dungeon[currentRoom(dungeon)].item;
                    dungeon[currentRoom(dungeon)].item = nullptr;
                    break;
                }else if(choice == "n" || choice == "N"){
                    cout<<"You left the item"<<endl;
                    break;
                }
            }
        }

        displayMap(&dungeon[0]);
        if(!dungeon[currentRoom(dungeon)].isMonsterExist() && !dungeon[currentRoom(dungeon)].isItemExist()){
            bar();
            centerText("There's nothing here...");
            bar();
        }  

        if(countNextRoom(dungeon[currentRoom(dungeon)].nextRoom) == 2){
            cout<<"\tChoose next room..."<<endl;
            cout<<"\t"<<1<<". "<<dungeon[dungeon[currentRoom(dungeon)].nextRoom[0]].roomName<<endl;
            cout<<"\t"<<2<<". "<<dungeon[dungeon[currentRoom(dungeon)].nextRoom[1]].roomName<<endl;
            cout<<"\tGo back"<<endl;
            while (true){
                cout<<">>>>> ";
                getline(cin, choice);
                if (choice == "1"){
                    gotoNextRoom(dungeon, currentRoom(dungeon), dungeon[currentRoom(dungeon)].nextRoom[0]);
                    break;
                }else if(choice == "2"){
                    gotoNextRoom(dungeon, currentRoom(dungeon), dungeon[currentRoom(dungeon)].nextRoom[1]);
                    break;
                }else if(choice == "back"){
                    goBack(dungeon, currentRoom(dungeon));
                    break;
                }
            }
        }else if(countNextRoom(dungeon[currentRoom(dungeon)].nextRoom) == 1){
            cout<<"\tNext room = "<<dungeon[dungeon[currentRoom(dungeon)].nextRoom[0]].roomName<<endl;
            cout<<"\tGo back"<<endl;
            while (true){
                cout<<">>>>> ";
                getline(cin, choice);
                if(choice == "back"){
                    goBack(dungeon, currentRoom(dungeon));
                    break;
                }else if(choice == "next"){
                    gotoNextRoom(dungeon, currentRoom(dungeon), dungeon[currentRoom(dungeon)].nextRoom[0]);
                    break;
                }
            }
        }else{
            centerText("There are no other next room..");
            bar();
            cout<<"\tGo back "<<endl;
            while(true){
                cout<<">>>>> ";
                getline(cin, choice);
                if(choice == "back"){
                    goBack(dungeon, currentRoom(dungeon));
                    break;
                }
            }
        }
    }

}