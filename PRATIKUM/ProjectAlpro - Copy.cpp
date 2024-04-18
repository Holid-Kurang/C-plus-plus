#include <iostream>
#include <conio.h>
#include <ctime>
#include <vector>
using namespace std;

struct player {
	string nama;
	int skor=0;
	player *next;
	player *prev;
};
player *head=NULL, *tail=NULL;
string nama;
int skor=0;

// menu
int main();
void orang();

// control tampilan
void printMess(string mess, bool printTop, bool printBottom);
int digit(int abjad);

// leaderboard
void addPlayer(string nama, int skor);
void leaderboard();
void tukar(player *a, player *b);
void sortScore(player *otak);

// hangman
void hangMan(int guesscount);
void printLetter(string input, char from, char to);
void huruf(string question);
bool guess(string answer, string guess);
string randomWord(string path);
int coba(string word, string guessed);
void play();

int main() {
	int menu=1;
	char pilih;
	while(true) {
		while(true) {
			if(menu==1) {
				system("cls");
				printMess("HANGMAN IS BASED ",true, true);
				orang();
				printMess("    +-----------+     ",false,false);
				printMess("    |           |     ",false,false);
				printMess("    |           |     ",false,false);
				printMess("         ==>>\033[1;31m[   PLAY    ]\033[0m<<==          ",true, false);
				printMess("    [LEADERBOARD]     ",false, false);
				printMess("    [   EXIT    ]     ",false, true);
			} else if(menu==2) {
				system("cls");
				printMess("HANGMAN IS BASED ",true, true);
				orang();
				printMess("    +-----------+     ",false,false);
				printMess("    |           |     ",false,false);
				printMess("    |           |     ",false,false);
				printMess("    [   PLAY    ]     ",true, false);
				printMess("         ==>>\033[1;31m[LEADERBOARD]\033[0m<<==          ",false, false);
				printMess("    [   EXIT    ]     ",false, true);
			} else if(menu==3) {
				system("cls");
				printMess("HANGMAN IS BASED ",true, true);
				orang();
				printMess("    +-----------+     ",false,false);
				printMess("    |           |     ",false,false);
				printMess("    |           |     ",false,false);
				printMess("    [   PLAY    ]     ",true, false);
				printMess("    [LEADERBOARD]     ",false, false);
				printMess("         ==>>\033[1;31m[   EXIT    ]\033[0m<<==          ",false, true);
			}
			pilih=getch();
			if(pilih==72) { // nilai ascii kode untk arrow key atas
				menu--;
				if(menu<1) {
					menu=3;
				}
			} else if(pilih==80) { // nilai ascii kode untk arrow key bawah
				menu++;
				if(menu>3) {
					menu=1;
				}
			} else if(pilih==13) { // nilai ascii kode untk enter
				break;
			}
		}
		if(menu==1) {
//			nama="";
			skor=0;
			system("cls");
//			printMess("HANGMAN IS BASED",true, true);
//			printMess("",false, false);
//			printMess("Insert name...",true, true);
//			cin>>nama;
			play();
			addPlayer(nama, skor);
		} else if(menu==2) {
			system("cls");
			sortScore(head);
			leaderboard();
		} else if(menu==3) {
			break;
		}
	}
}

void printMess(string mess, bool printTop = true, bool printBottom = true) {
	if(printTop) {
		cout<<"+----------------------------------------+"<<endl;
	}

	cout<<"|";
	bool front = true;
	for(int i = mess.size(); i<40; i++) {
		if(front) {
			mess = " " + mess;
		} else {
			mess = mess + " ";
		}
		front = !front;
	}
	cout<<mess<<"|"<<endl;

	if(printBottom) {
		cout<<"+----------------------------------------+"<<endl;
	}
}
void orang() {
	printMess("", false, false);
	printMess("", false, false);
	printMess("", false, false);
	printMess("0 ", false, false);
	printMess("/|\\ ", false, false);
	printMess("| ", false, false);
	printMess("/ \\ ", false, false);
}
void hangMan(int guesscount) {
	printMess("+---------+            ", false, false);
	if(guesscount >= 1) {
		printMess("|         |            ", false, false);
	} else {
		printMess("|                      ", false, false);
	}

	if(guesscount >= 2) {
		printMess("|         |            ", false, false);
	} else {
		printMess("|                      ", false, false);
	}

	if(guesscount >= 3) {
		printMess("|         0            ", false, false);
	} else {
		printMess("|                      ", false, false);
	}

	if(guesscount == 4) {
		printMess("|        /             ", false, false);
	} else if(guesscount == 5) {
		printMess("|        /|            ", false, false);
	} else if(guesscount >= 6) {
		printMess("|        /|\\          ", false, false);
	} else {
		printMess("|                      ", false, false);
	}

	if(guesscount >= 7) {
		printMess("|         |            ", false, false);
	} else {
		printMess("|                      ", false, false);
	}

	if(guesscount == 8) {
		printMess("|        /             ", false, false);
	} else if(guesscount >= 9) {
		printMess("|        / \\           ", false, false);
	} else {
		printMess("|                      ", false, false);
	}
}
void printLetter(string input, char from, char to) {
	string s="";//	A		M
	for(char i = from; i<=to; i++) {
		if(input.find(i) == string::npos) { //jika tidak ditemukan nilai i oleh input
			s += i;
			s += " ";
		} else {
			s += "  ";
		}
	}
	printMess(s, false, false);
}

void huruf(string question) {
	printMess("Huruf yang Tersisa",true,false);
	printLetter(question, 'A', 'M');
	printLetter(question, 'N', 'Z');
	printMess("Tebak Kata",true,false);
}

bool guess(string word, string answer) {
	bool won = true;
	string s;
	for(int i=0; i<word.size(); i++) {
		if(answer.find(word[i]) == string::npos) {
			won = false;
			s += "_ ";
		} else {
			s += word[i];
			s += " ";
		}
	}
	printMess(s, false, true);
	return won;
}
string randomWord(int tipe) {
	srand(time(0));
	string word;
	vector<string>tema;
	if(tipe==1) {
		tema= {"CAT","CHICKEN","HORSE","GIRAFFE","SHEEP","RHINO","BUTTERFLY","FLY",
		       "KANGAROO","EAGLE","ANT","DOG","SNAKE",
		       "PANDA","PARROT","OWL","LION","WOLF","SHARK","GORILLA"
		      };
	} else if(tipe==2) {
		tema= {"APPLE", "BANANA", "CHERRY", "DURIAN", "ELDERBERRY",
		       "FIG", "GRAPE", "HONEYDEW", "JACKFRUIT", "KIWI",
		       "LEMON", "MANGO", "NECTARINE", "ORANGE", "PAPAYA",
		       "QUINCE", "RASPBERRY", "STRAWBERRY", "TANGERINE", "WATERMELON"
		      };
	} else if(tipe==3) {
		tema= {"BOOK", "CHAIR", "DESK", "ELECTRONICS", "FURNITURE",
		       "GLASSWARE", "HANDBAG", "INSTRUMENT", "JEWELRY", "KEYBOARD",
		       "LAMP", "MIRROR", "NECKTIE", "ORNAMENT", "PEN",
		       "QUIVER", "RUG", "COMPUTER", "TABLE", "UMBRELLA"
		      };
	} else if(tipe==4) {
		tema= {"AIRPORT", "BEACH", "CAFE", "DESERT", "FOREST",
		       "GARDEN", "HOSPITAL", "ISLAND", "JUNGLE", "KITCHEN",
		       "LIBRARY", "MOUNTAIN", "NIGHTCLUB", "OFFICE", "PARK",
		       "QUARRY", "RESTAURANT", "STADIUM", "TRAINSTATION", "UNIVERSITY"
		      };
	} else if(tipe==5) {
		tema= {"HEAD", "NECK", "SHOULDER", "ARM", "ELBOW",
		       "HAND", "CHEST", "BACK", "ABDOMEN", "HIP",
		       "LEG", "KNEE", "FOOT", "TOE", "EYE",
		       "NOSE", "EAR", "MOUTH", "TEETH", "HAIR"
		      };
	}
	int randomLine = rand() % tema.size();
	word = tema[randomLine];
	return word;
}
int coba(string word, string guessed) {
	int error=0;
	for(int i = 0; i<guessed.length(); i++) {
		if(word.find(guessed[i]) == string::npos) {
			error++;
		}
	}
	return error;
}
bool isNotExist(string word, string guessed) {
	bool error = false;
	for (int i = 0; i < guessed.length(); i++) {
		if (word.find(guessed[i]) == string::npos) {
			return true; // Mengembalikan true segera setelah menemukan karakter yang tidak ada
		}
	}
	return false; // Mengembalikan false jika semua karakter ditemukan
}

void play() {
	int round = 1, tipe=0;
//	while(true){
//		system("cls");
//		printMess("HANGMAN IS BASED ");
//		cout<<"+----------------------------------------+"<<endl;
//		cout<<"|   1. Animal                            |"<<endl;
//		cout<<"|   2. Food                              |"<<endl;
//		cout<<"|   3. Thing                             |"<<endl;
//		cout<<"|   4. Place                             |"<<endl;
//		cout<<"|   5. Body                              |"<<endl;
//		cout<<"+----------------------------------------+"<<endl;
//		printMess("Choose!! (1/2/3/4/5)...");
//		cout<<'>';
//		cin>>tipe;
//		if(tipe>=1 && tipe<=5){
//			break;
//		}
//	}
	int tries = 0;
	while(true) {
		srand(time(0));
		string guesses;
		string word;
		tipe = (rand()%4)+1;
		word = randomWord(tipe);
		bool win;
		do {
			system("cls");
			printMess("HANGMAN IS BASED ");
			if(tipe==1) {
				printMess(" Clue : Animal ",false);
			} else if(tipe ==2) {
				printMess(" Clue : Food ",false);
			} else if(tipe ==3) {
				printMess(" Clue : Thing ",false);
			} else if(tipe ==4) {
				printMess(" Clue : Place ",false);
			} else if(tipe ==5) {
				printMess(" Clue : Body ",false);
			}
			hangMan(tries);
			printMess("|   +-----------+     ",false,false);
			printMess("/|\\  |           |      ",false,false);
			printMess("/ | \\ |           |       ",false,false);

			cout<<"+----------------------------------------+"<<endl;
			cout<<"|";
			for(int i=0; i<17; i++) cout<<" ";
			cout<<"|"<<round<<"/7|";
			for(int i=0; i<18-digit(round); i++) cout<<" ";
			cout<<" |"<<endl;

			huruf(guesses);
			win = guess(word, guesses);

			if(win==true) {
				break;
			}
			char x;
			cout<<'>';
			cin>>x;
			if(x>96) {
				x-=32;
			}
			if(guesses.find(x) == string::npos) {
				guesses += x;
				if(word.find(x) == string::npos) {
					tries++;
				} 
			}
		} while(tries<10);

		if(win==true) {
			round++;
			if(round>7) {
				system("cls");
				printMess("YOU WON!!!");
				printMess("GO BACK TO MENU",false,false);
				printMess("Press Any key to Go Menu....",false);
				system("pause");
				return;
			}
			system("cls");
			printMess("CORRECT!!!",true,false);
			printMess("Press Any key to go Next Round...",false);
			system("pause");
		} else {
			system("cls");
			printMess("Answer : "+word);
			printMess("GAME OVER",false);
			printMess("GO BACK TO MENU",false,false);
			printMess("Press Any key to Go Menu....",false);
			system("pause");
			return;
		}
	}
}
void addPlayer(string nama, int skor) {
	player *baru;
	baru = new player;
	baru->nama=nama;
	baru->skor=skor;
	baru->next=NULL;
	baru->prev=NULL;

	if(head == NULL) {
		tail = baru;
		head = tail;
	} else {
		tail->next = baru;
		baru->prev = tail;
		tail=baru;
	}
}
void leaderboard() {
	int nomor=1;
	string temp;
	player *print;
	printMess("HANGMAN IS BASED ");
	printMess("    |      NAME      |      SCORES      ",false, false);
	cout<<"+----+----------------+------------------+"<<endl;
	if(head!=NULL) {
		for(print=head;	print!=NULL; print = print->next) {
			cout<<"| "<<nomor;
			for(int i=0; i<3-digit(nomor); i++) cout<<" ";
			cout<<"|";
			bool front = true;
			temp=print->nama;
			for(int i = temp.size(); i<16; i++) {
				if(front) {
					temp = " " + temp;
				} else {
					temp = temp + " ";
				}
				front = !front;
			}
			cout<<temp<<"|    ";
			cout<<print->skor;
			for(int i=0; i<14-digit(print->skor); i++) cout<<" ";
			cout<<"|"<<endl;
			nomor++;
		}
		cout<<"+----------------------------------------+"<<endl;
	} else {
		printMess("",false, false);
		printMess("Empty Player's Record  ",false, false);
		printMess("",false, true);
	}
	system("pause");
}

int digit(int abjad) {
	int count=0;
	if(abjad<=0) {
		count++;
	}
	while(abjad!=0) {
		abjad/=10;
		count++;
	}
	return count;
}
void tukar(player *a, player *b) {
	string swapName;
	swapName=a->nama;
	a->nama=b->nama;
	b->nama=swapName;

	int swapSkor;
	swapSkor=a->skor;
	a->skor=b->skor;
	b->skor=swapSkor;
}
void sortScore(player *otak) {
	int swap;
	player *ptr;
	player *help = NULL;
	if(otak==NULL) {
		return;
	}
	do {
		swap=0;
		ptr = otak;
		while(ptr->next!=help) {
			if(ptr->skor < ptr->next->skor) {
				int temp;
				tukar(ptr, ptr->next);
				swap=1;
			}
			ptr=ptr->next;
		}
		help=ptr;
	} while(swap);
}
