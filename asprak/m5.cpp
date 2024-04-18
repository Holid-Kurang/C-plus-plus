#include <iostream>
using namespace std;

struct Entity
{
	string name = "";
	int health = 0;
	int attack = 0;
	int defence = 0;

	int count = 1;
};
Entity alien = { "Alien", 80, 20, 10 };
Entity monster = { "Monster", 80, 20, 10 };

int alienAttack(int defenceLawan)
{
	cout << "The Alien Attack with Normal attack"<<endl;
	alien.count++;
	int atk = alien.attack - defenceLawan;
	return atk;
}

int alienUlti()  
{
	cout<<"the Alien use special skill"<<endl;
	alien.count++;
	int specialAtk = alien.attack * 2;
	return specialAtk;
}

bool alienDead()  
{
	if (alien.health <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int monsterAttack(int defenceLawan)
{
	cout << "The Monster Attack with Normal attack"<<endl;
	monster.count++;
	int atk = monster.attack - defenceLawan;
	return atk;
}

int monsterUlti()
{
	// heal
	cout << "the Monster use special skill"<<endl;
	monster.count++;
	int heal = monster.health + monster.health/2;
	return heal;
}

bool monsterDead()
{
	if (monster.health <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	int turnMonsterUlti = 3;
	int turnAlienUlti = 4;

	while(!alienDead() && !monsterDead()){
		cout<<"============================"<<endl;
		
		if(monster.count%turnMonsterUlti==0){
			int heal = monsterUlti();
			monster.health = heal;
			cout<<"alien | "<<alien.health<<endl;
			cout<<"monster | "<<monster.health<<endl;
			cout<<endl;
		}
		else{
			int atk = monsterAttack(alien.defence);
			alien.health -= atk;
			cout<<"alien | "<<alien.health<<endl;
			cout<<"monster | "<<monster.health<<endl;
			cout<<endl;
		}
		if(alienDead()){
			cout<<"Monster Win"<<endl;
			cout<<"the alien is dead"<<endl;
			break;
		}
		else if(monsterDead()){
			cout<<"Alien Win"<<endl;
			cout<<"the monster is dead"<<endl;
			break;
		}
		if(alien.count%turnAlienUlti==0){
			int atk = alienUlti();
			monster.health -= atk;
			cout<<"alien | "<<alien.health<<endl;
			cout<<"monster | "<<monster.health<<endl;
			cout<<endl;
		}
		else{
			int atk = alienAttack(monster.defence);
			monster.health -= atk;
			cout<<"alien | "<<alien.health<<endl;
			cout<<"monster | "<<monster.health<<endl;
			cout<<endl;
		}

		if(alienDead()){
			cout<<"Monster Win"<<endl;
			cout<<"the alien is dead"<<endl;
			break;
		}
		else if(monsterDead()){
			cout<<"Alien Win"<<endl;
			cout<<"the monster is dead"<<endl;
			break;
		}
	}
}
