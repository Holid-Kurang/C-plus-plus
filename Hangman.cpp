#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <conio.h>
#include <ctime>
#include <cstdlib>
using namespace std;

void printMess(string mess, bool printTop = true, bool printBottom = true){
	if(printTop){
		cout<<"+-----------------------------------+"<<endl;
		cout<<"|";
	}else{
		cout<<"|";
	}
	
	bool front = true;
	for(int i = mess.size(); i<35; i++){
		if(front){
			mess = " " + mess;
		}else{
			mess = mess + " ";
		}
		front = !front;
	}
	cout<<mess;
	
	if(printBottom){
		cout<<"|\n";
		cout<<"+-----------------------------------+"<<endl;
	}else{
		cout<<"|"<<endl;
	}
}

void hangMan(int guesscount){
	if(guesscount >= 1){
		printMess("|", false, false);
	}else{
		printMess("", false, false);
	}
	
	if(guesscount >= 2){
		printMess("|", false, false);
	}else{
		printMess("", false, false);
	}
	
	if(guesscount >= 3){
		printMess("0", false, false);
	}else{
		printMess("", false, false);
	}
	
	if(guesscount == 4){
		printMess("/  ", false, false);
	}
	
	if(guesscount == 5){
		printMess("/| ", false, false);
	}

	if(guesscount >= 6){
		printMess("/|\\", false, false);
	}else{
		printMess("", false, false);
	}
	
	if(guesscount >= 7){
		printMess("|", false, false);
	}else{
		printMess("", false, false);
	}
	if(guesscount == 8){
		printMess("/  ", false, false);
	}
	if(guesscount >= 9){
		printMess("/ \\", false, false);
	}else{
		printMess("", false, false);
	}
}

void printLetter(string input, char from, char to){
	string s;
	for(char i = from; i<=to; i++){
		if(input.find(i) == string::npos){
			s += i;
			s += " ";
		}else{
			s += "  ";
		}
	}
	printMess(s, false, false);
}

void huruf(string question){
	printMess("+-----------+",false,false);
	printMess("|           |",false,false);
	printMess("Huruf yang Tersisa");
	printLetter(question, 'A', 'M');
	printLetter(question, 'N', 'Z');
	printMess("Tebak Kata");
}

bool guess(string answer, string guess){
	bool won = true;
	string s;
	for(int i=0; i<answer.size(); i++){
		if(guess.find(answer[i]) == string::npos){
			won = false;
			s += "_ ";
		}else{
			s += answer[i];
			s += " ";
		}
	}
	printMess(s, false, true);
	return won;
}

string randomWord(string path){
	string word;
	vector<string>v;
	ifstream reader(path.c_str());
	
	if (reader.is_open()){
		while(getline(reader, word)){
			v.push_back(word);
		}
		int randomLine = rand() % v.size();
		word = v.at(randomLine);
		reader.close();
	}
	return word;
}

int coba(string word, string guessed){
	int error=0;
	for(int i = 0; i<guessed.size(); i++){
		if(word.find(guessed[i]) == string::npos){
			error++;
		}
	}
	return error;
}
void menuhangman(){
	while(true){
		char cobalagi;
		srand(time(0));
		string guesses;
		string word;
		word = randomWord("words.txt");
		int tries = 0;
		bool win;
		do{
			system("cls");
			printMess("HANGMAN IS BASED");
			hangMan(tries);
			huruf(guesses);
			win = guess(word, guesses);
  			if(win==true){
				break;
			}
		
			char x;
			cout<<'>';
			cin>>x;
			if(x>96){
				x=x-32;
			}
			if(guesses.find(x) == string::npos){
				guesses += x;
			}
			tries = coba(word, guesses);
		}while(tries<10);

		if(win==true){
			system("cls");
			printMess("YOU WON!");
			printMess(word);
		}else{
			system("cls");
			printMess("GAME OVER");
			printMess(word);
		}
	
		cout<<"\nTRY AGAIN?!\n";
		cobalagi=getch();
		if(cobalagi=='y' || cobalagi=='Y'|| cobalagi==13){
			system("cls");
		}else{
			break;
		}
	}
}

int main(){
	menuhangman();
}
