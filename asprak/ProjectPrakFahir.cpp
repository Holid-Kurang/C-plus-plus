#include <iostream>
#include <string>

using namespace std;

string nama, pauser;
int acorn, charprogress, uang, hargaarmor, hargasenjata, uparmor, uphealth, upatt, endlessmodereward, endlessmodestage;
bool charunlock_phoenix, charunlock_crystal, charunlock_Desolator_Slime, endlessmode;

void mainmenu();
void cheat(string input);

struct
{
    int health;
    int armor;
    int att;
} endlessmodemodiffier;
struct
{
    int health = 1500;
    int armor = 10;
    int attdimeg = 75;
} phoenix;
struct
{
    int health = 2500;
    int attdimeg = 40;
    int armor = 30;
} crystal;
struct
{
    int health = 3000;
    int attdimeg = 120;
    int armor = 0;
} desolator_slime;
struct
{
    int health = 2000 + uphealth;
    int attdimeg = 50 + upatt;
    int armor = 25 + uparmor;
} player;

void reset()
{
    if (player.health < 20000)
        player.health = 2000 + uphealth;
    if (player.attdimeg < 20000)
        player.attdimeg = 50 + upatt;
    if (player.armor < 20000)
        player.armor = 25 + uparmor;
    phoenix.health = 1500;
    phoenix.armor = 10;
    phoenix.attdimeg = 75;
    crystal.health = 2500;
    crystal.armor = 30;
    crystal.attdimeg = 40;
    desolator_slime.health = 3000 + (endlessmodemodiffier.health);
    desolator_slime.armor = 0 + (endlessmodemodiffier.armor);
    desolator_slime.attdimeg = 120 + (endlessmodemodiffier.att);
}

void phoenixmodel()
{
    cout << "               /|  !!  / |            \n";
    cout << "              /  | || /   |           \n";
    cout << "             /    ||||     |          \n";
    cout << "             |/|/|/|| |/|/|/          \n";
    cout << "                  //||                \n";
    cout << "                 ///|||               \n";
    cout << "\n";
}
void crystalmodel()
{
    cout << "                   /|             \n";
    cout << "                  /  |            \n";
    cout << "                 /  | |           \n";
    cout << "                 |  | /           \n";
    cout << "                  |  /            \n";
    cout << "                   |/             \n";
    cout << "\n";
}
void desoslimemodel()
{
    cout << "                                  \n";
    cout << "                                  \n";
    cout << "              @@@@@@              \n";
    cout << "             @@@@@@@@             \n";
    cout << "              @@@@@@              \n";
    cout << "                                  \n";
    cout << "\n";
}
void infophoenix()
{
    system("cls");
    phoenixmodel();
    cout << " The Immortal Phoenix";
    cout << "\n Health     = " << phoenix.health;
    cout << "\n Armor      = " << phoenix.armor;
    cout << "\n Att Damage = " << phoenix.attdimeg;
    cout << "\n\n Phoenix First Ability (Burn Attack)";
    cout << "\n Deal A Initial Damage 35, And a 20 Damage For Every Turn (last 2 trun).";
    cout << "\n\n Phoenix Second Ability (Reincernation)";
    cout << "\n If Phoenix Would Take A Lethal Damage, Phoenix Reviva as Half Healt (once per macth).";
    cout << "\n\nInput Any Key to Continue : ";
    string input;
    cin >> input;
}
void infocrystal()
{
    system("cls");
    crystalmodel();
    cout << " The Living Crystal";
    cout << "\n Health     = " << crystal.health;
    cout << "\n Armor      = " << crystal.armor;
    cout << "\n Att Damage = " << crystal.attdimeg;
    cout << "\n\n Crystal First Ability (Dispersion)";
    cout << "\n Increase Crystal Armor by 20, And whenever crystal take physical damage"
         << "\n it return to the source for 1/10 of damage deal to crsytal (last 2 turn)";
    cout << "\n\n Crystal Second Ability (Regen)";
    cout << "\n At the end of a trun Crystal heal himself by 15 HP (last entire macth).";
    cout << "\n\nInput Any Key to Continue : ";
    string input;
    cin >> input;
}
void infodeslime()
{
    system("cls");
    desoslimemodel();
    cout << " The Desolator Slime";
    cout << "\n Health     = " << desolator_slime.health - endlessmodemodiffier.health;
    cout << "\n Armor      = " << desolator_slime.armor - endlessmodemodiffier.armor;
    cout << "\n Att Damage = " << desolator_slime.attdimeg - endlessmodemodiffier.att;
    cout << "\n\n crystal First Ability (Dispersion)";
    cout << "\n Increase Crystal Armor by 20, And whenever crystal take physical damage"
         << "\n it return to the source for 1/10 of damage deal to crsytal (last 2 turn)";
    cout << "\n\n Crystal Second Ability (Regen)";
    cout << "\n At the end of a trun Crystal heal himself by 15 point (last entire macth).";
    cout << "\n\nInput Any Key to Continue : ";
    string input;
    cin >> input;
}
void infoplayer()
{
    system("cls");
    cout << " " << nama;
    cout << "\n Health     = " << player.health << " (+ " << uphealth << ")";
    cout << "\n Armor      = " << player.armor << " (+ " << uparmor << ")";
    cout << "\n Att Damage = " << player.attdimeg << " (+ " << upatt << ")";
    cout << "\n\n Player First Ability (Heal)";
    cout << "\n Heal Player by 70 HP";
    cout << "\n\n Player Second Ability (Att Boost)";
    cout << "\n Increase Player Att Damage by 25 Point (last 2 turn)";
    cout << "\n\nInput Any Key to Continue : ";
    string input;
    cin >> input;
}

bool playersecondability(bool active)
{
    if (active == true)
    {
        player.attdimeg += 25;
        return true;
    }
    if (active == false)
    {
        player.attdimeg -= 25;
        return false;
    }
    return false;
}
bool phoenixmove2()
{
    system("cls");
    cout << "  {--                         --}\n";
    cout << "{--  Phoenix Using Burn Attack  --}\n";
    cout << "  {--                         --}\n\n\n\n";
    player.health -= 35;
    cout << "Input Any Key To Continue : ";
    cin >> pauser;
    pauser += pauser;
    return true;
}
void phoenixmove1()
{
    system("cls");
    cout << "  {--                         --}\n";
    cout << "{-- Phoenix Using Normal Attack --}\n";
    cout << "  {--                         --}\n\n\n\n";
    player.health -= (phoenix.attdimeg - player.armor);
    cout << "Input Any Key : ";
    cin >> pauser;
    pauser += pauser;
}
void crystalmove1()
{
    system("cls");
    cout << "  {--                         --}\n";
    cout << "{-- Crystal Using Normal Attack --}\n";
    cout << "  {--                         --}\n\n\n\n";
    player.health -= (crystal.attdimeg - player.armor);
    cout << "Input Any Key : ";
    cin >> pauser;
    pauser += pauser;
}
bool crystalmove2(int active)
{
    if (active == true)
    {
        system("cls");
        cout << "  {--                         --}\n";
        cout << "{--  Crystal Using Dispersion   --}\n";
        cout << "  {--                         --}\n\n\n\n";
        cout << "Input Any Key : ";
        cin >> pauser;
        pauser += pauser;
        crystal.armor += 20;
        return true;
    }
    if (active == false)
    {
        crystal.armor -= 20;
        return false;
    }
    return false;
}
void slimemove1()
{
    system("cls");
    cout << "  {--                         --}\n";
    cout << "{-- Deslime Using Normal Attack --}\n";
    cout << "  {--                         --}\n\n\n\n";
    player.health -= (desolator_slime.attdimeg - player.armor);
    cout << "Input Any Key : ";
    cin >> pauser;
    pauser += pauser;
}
bool slimemove2()
{
    system("cls");
    cout << "  {--                         --}\n";
    cout << "{--  Slime Using Poison Attack  --}\n";
    cout << "  {--                         --}\n\n\n\n";
    cout << "Input Any Key To Continue : ";
    cin >> pauser;
    pauser += pauser;
    return true;
}

bool fight(int Opponent)
{
    reset();
    bool macth;
    if (Opponent == 1)
    {
        int pilih;
        int abilityturncounter[4] = {4, 4, 5, 5};
        bool playersecondabilitybuff = false, playerdebuffburn = false, phoenixpasif = true;
        int turn = 0;
        macth = true;
        do
        {
            system("cls");
            if (abilityturncounter[2] == 3)
                playerdebuffburn = false;
            if (abilityturncounter[1] == 3)
                playersecondabilitybuff = playersecondability(false);
            if (playerdebuffburn)
                player.health -= 20;
            if (player.health <= 0)
                return false;
            // if()
            cout << "Objective : Win Again The Phoenix.             HP     = " << player.health << "\n";
            cout << "                                               Armor  = " << player.armor << "\n";
            cout << "                                               Damage = " << player.attdimeg << "\n";
            if (playerdebuffburn)
            {
                cout << "                                               (burn)\n";
            }
            if (playersecondabilitybuff)
            {
                cout << "                                               (att boost)\n";
            }
            phoenixmodel();
            // cout <<"                 ///\\\               \n";
            cout << "         HP |";
            int tempo = phoenix.health / 100;
            for (int i = 0; i < tempo; i++)
            {
                cout << "I";
            }
            cout << "|\n";
            cout << "        Turn : " << turn << "\n\n\n\n";
            cout << "Move : \n";
            cout << "1. Attack\n";
            cout << "2. Heal\n";
            cout << "3. Attack Boost\n";
            cout << "Pilih : ";
            cin >> pilih;
            if (pilih == 1)
                phoenix.health -= (player.attdimeg - phoenix.armor);
            if (pilih == 2)
                player.health += 70;
            if (pilih == 3 && playersecondabilitybuff == false)
            {
                playersecondabilitybuff = playersecondability(true);
                abilityturncounter[1] = 0;
            }
            if (phoenix.health <= 0 && phoenixpasif == false)
                return true;
            if (phoenix.health <= 0)
            {
                system("cls");
                cout << "Phoenix Have Passife Skill, Whenever He Take Lethal Damage Phoenix Will Revive With Half Max HP\n";
                string input;
                cout << "Input Any Key to Continue : ";
                cin >> input;
                phoenixpasif = false;
                phoenix.health = 750;
            }
            if (acorn % 2 == 1 && playerdebuffburn == false)
            {
                playerdebuffburn = phoenixmove2();
                abilityturncounter[2] = 0;
            }
            else
                phoenixmove1();
            turn++;
            acorn += 1;
            abilityturncounter[1]++;
            abilityturncounter[2]++;
        } while (macth);
        if (turn <= 30)
            uang += 75;
        if (turn <= 60)
            uang += 50;
        if (turn <= 90)
            uang += 25;
        if (turn > 90)
            uang += 10;
    }
    if (Opponent == 2)
    {
        int pilih;
        int abilityturncounter[4] = {4, 4, 5, 5};
        bool playersecondabilitybuff = false, crystalabilitybuff = false;
        int turn = 0;
        macth = true;
        do
        {
            system("cls");
            if (abilityturncounter[2] == 4)
                crystalabilitybuff = crystalmove2(false);
            if (abilityturncounter[1] == 3)
                playersecondabilitybuff = playersecondability(false);
            if (player.health <= 0)
                return false;
            cout << "Objective : Win Again The Living Crystal.      HP     = " << player.health << "\n";
            cout << "                                               Armor  = " << player.armor << "\n";
            cout << "                                               Damage = " << player.attdimeg << "\n";
            if (playersecondabilitybuff)
            {
                cout << "                                               (att boost)\n";
            }
            crystalmodel();
            // cout <<"                 ///\\\               \n";
            cout << "         HP |";
            int tempo = crystal.health / 100;
            for (int i = 0; i < tempo; i++)
            {
                cout << "I";
            }
            cout << "|\n";
            if (crystalabilitybuff)
                cout << "            (Dispersion)\n";
            cout << "        Turn : " << turn << "\n\n\n\n";
            cout << "Move : \n";
            cout << "1. Attack\n";
            cout << "2. Heal\n";
            cout << "3. Attack Boost\n";
            cout << "Pilih : ";
            cin >> pilih;
            if (pilih == 1)
            {
                crystal.health -= (player.attdimeg - crystal.armor);
                if (crystalabilitybuff)
                {
                    player.health -= (player.attdimeg / 10);
                }
            }
            if (pilih == 2)
                player.health += 70;
            if (pilih == 3 && playersecondabilitybuff == false)
            {
                playersecondabilitybuff = playersecondability(true);
                abilityturncounter[1] = 0;
            }
            if (crystal.health <= 0)
                return true;
            if (acorn % 2 == 1 && crystalabilitybuff == false)
            {
                crystalabilitybuff = crystalmove2(true);
                abilityturncounter[2] = 0;
            }
            else
                crystalmove1();
            crystal.health += 15;
            turn++;
            acorn += 1;
            abilityturncounter[1]++;
            abilityturncounter[2]++;
        } while (macth);
        if (turn <= 30)
            uang += 90;
        if (turn <= 60)
            uang += 70;
        if (turn <= 90)
            uang += 50;
        if (turn > 90)
            uang += 25;
    }
    if (Opponent == 3)
    {
        int pilih, debuffatt;
        int abilityturncounter[4] = {5, 5, 5, 5};
        bool playersecondabilitybuff = false, deslimedebuffatt = false, deslimedebuffpoison = false;
        int turn = 0;
        macth = true;
        do
        {
            system("cls");
            if (abilityturncounter[2] == 2)
            {
                deslimedebuffatt = false;
            }
            if (abilityturncounter[3] == 4)
            {
                deslimedebuffpoison = false;
            }
            if (deslimedebuffpoison = true)
            {
                if (endlessmode)
                    player.health -= (20 * endlessmodestage);
                else
                    player.health -= 20;
            }
            if (deslimedebuffatt)
            {
                if (endlessmode)
                    debuffatt += (10 * endlessmodestage);
                else
                    debuffatt += 10;
            }
            else
                debuffatt = 0;
            if (abilityturncounter[1] == 3)
                playersecondabilitybuff = playersecondability(false);
            if (player.health <= 0)
                return false;
            cout << "Objective : Win Again The Desolator Slime.     HP     = " << player.health << "\n";
            cout << "                                               Armor  = " << player.armor << "\n";
            cout << "                                               Damage = " << player.attdimeg << "\n";
            if (playersecondabilitybuff)
            {
                cout << "                                               (att boost)\n";
            }
            if (deslimedebuffatt)
            {
                cout << "                                               (Corrosion)\n";
            }
            desoslimemodel();
            // cout <<"                 ///\\\               \n";
            cout << "         HP |";
            int tempo = desolator_slime.health / 100;
            for (int i = 0; i < tempo; i++)
            {
                cout << "I";
            }
            cout << "|\n";

            cout << "        Turn : " << turn << "\n\n\n\n";
            cout << "Move : \n";
            cout << "1. Attack\n";
            cout << "2. Heal\n";
            cout << "3. Attack Boost\n";
            cout << "Pilih : ";
            cin >> pilih;
            if (pilih == 1)
            {
                desolator_slime.health -= ((player.attdimeg - desolator_slime.armor) - debuffatt);
                deslimedebuffatt = true;
                abilityturncounter[2] = 0;
            }
            if (pilih == 2)
                player.health += 70;
            if (pilih == 3 && playersecondabilitybuff == false)
            {
                playersecondabilitybuff = playersecondability(true);
                abilityturncounter[1] = 0;
            }
            if (desolator_slime.health <= 0)
                return true;
            if (acorn % 2 == 1 && deslimedebuffpoison == false)
            {
                deslimedebuffpoison = slimemove2();
                abilityturncounter[3] = 0;
            }
            else
                slimemove1();
            turn++;
            acorn += 1;
            abilityturncounter[1]++;
            abilityturncounter[2]++;
        } while (macth);
        if (turn <= 30)
            uang += 130;
        if (turn <= 60)
            uang += 120;
        if (turn <= 90)
            uang += 110;
        if (turn > 90)
            uang += 90;
    }
    return fight(Opponent);
}

void campaign()
{
    endlessmode = true;
    string input;
    bool winstatus;
    if (charprogress <= 1)
        winstatus = fight(3);
    if (charprogress == 2)
        winstatus = fight(2);
    if (charprogress == 3)
        winstatus = fight(1);
    system("cls");
    if (winstatus)
    {
        if (charprogress == 3)
        {
            charunlock_phoenix = true;
            cout << "\n Congrutalation You Unlock Phoenix";
            cout << "\n Reward 100 Coin";
            uang += 100;
            cout << "\n Input Any Key To Continue : ";
            cin >> input;
        }
        if (charprogress == 2)
        {
            cout << "\n Congrutalation You Unlock Crystal ";
            cout << "\n Reward 200 Coin";
            uang += 200;
            charunlock_crystal = true;
            cout << "\n Input Any Key To Continue : ";
            cin >> input;
        }
        if (charprogress == 1)
        {
            cout << "\n Congrutalation You Unlock DeSlime And Endless Mode\n";
            charunlock_Desolator_Slime = true;
            cout << "\n Reward 300 Coin";
            uang += 300;
            cout << "\n Input Any Key To Continue : ";
            cin >> input;
            endlessmodemodiffier.health = 100;
            endlessmodemodiffier.armor = 5;
            endlessmodemodiffier.att = 15;
        }
        if (charprogress < 1)
        {
            endlessmodemodiffier.armor += (endlessmodemodiffier.armor / 2);
            endlessmodemodiffier.health += (endlessmodemodiffier.health / 2);
            endlessmodemodiffier.att += (endlessmodemodiffier.att / 2);
            cout << "\n Congrutalation You Won Endless Stage " << endlessmodestage << "\n";
            endlessmodestage++;
            charunlock_Desolator_Slime = true;
            cout << "\n Reward " << endlessmodereward << " Coin";
            uang += endlessmodereward;
            endlessmodereward += (endlessmodereward / 10);
            cout << "\n Input Any Key To Continue : ";
            cin >> input;
        }
        charprogress -= 1;
    }
    else
    {
        cout << "\n You Lose \n";
        cout << "Input Any Key To Continue : ";
        cin >> input;
    }
}
void versus(int check)
{
    endlessmode = false;
    bool winstatus;
    system("cls");
    int pilih;
    cout << "choose Oppoent \n";
    cout << "1. Phoenix ";
    if (check == 1)
        cout << "(Char Not Unlock Yet)";
    cout << "\n";
    cout << "2. Crystal";
    if (check == 2)
        cout << "(Char Not Unlock Yet)";
    cout << "\n";
    cout << "3. Desolator Slime ";
    if (check == 3)
        cout << "(Char Not Unlock Yet)";
    cout << "\n";
    cout << "4. Return\n";
    cout << "Pilih : ";
    cin >> pilih;
    if (pilih == 1 && charunlock_phoenix == false)
        versus(1);
    else if (pilih == 1 && charunlock_phoenix)
    {
        winstatus = fight(1);
        system("cls");
        if (winstatus)
            cout << "YOU WIN";
        else
            cout << "YOU LOSE";
    }
    if (pilih == 2 && charunlock_crystal == false)
        versus(2);
    else if (pilih == 2 && charunlock_crystal)
    {
        winstatus = fight(2);
        system("cls");
        if (winstatus)
            cout << "YOU WIN";
        else
            cout << "YOU LOSE";
    }
    if (pilih == 3 && charunlock_Desolator_Slime == false)
        versus(3);
    else if (pilih == 3 && charunlock_Desolator_Slime)
    {
        winstatus = fight(3);
        system("cls");
        if (winstatus)
            cout << "YOU WIN";
        else
            cout << "YOU LOSE";
    }
    if (pilih == 4)
        return mainmenu();
    cout << "\nInput Any Key to Continue : ";
    cin >> pauser;
    pauser += pauser;
}
void codex(int check)
{
    system("cls");
    int pilih;
    cout << "1. Player";
    cout << "\n";
    cout << "2. Phoenix";
    if (check == 1)
        cout << "(Char Not Unlock Yet)";
    cout << "\n";
    cout << "3. Crystal";
    if (check == 2)
        cout << "(Char Not Unlock Yet)";
    cout << "\n";
    cout << "4. Deslime";
    if (check == 3)
        cout << "(Char Not Unlock Yet)";
    cout << "\n";
    cout << "5. Return";
    cout << "\nPilih : ";
    cin >> pilih;
    if (pilih == 1)
    {
        infoplayer();
    }
    if (pilih == 2 && charunlock_phoenix == false)
        codex(1);
    else if (pilih == 2)
        infophoenix();
    if (pilih == 3 && charunlock_crystal == false)
        codex(2);
    else if (pilih == 3)
        infocrystal();
    if (pilih == 4 && charunlock_Desolator_Slime == false)
        codex(3);
    else if (pilih == 4)
        infodeslime();
    if (pilih == 5)
        return mainmenu();
    return codex(0);
}
void shopmenu()
{
    system("cls");

    cout << " Select Gear To Upgrade : ";
    cout << "                           Coin = " << uang;
    cout << "\n 1. Armor (+1 armor and +70 health) : (" << hargaarmor << " Coin)";
    cout << "\n 2. Weapon (+5 Damage) : (" << hargasenjata << " Coin)";
    cout << "\n 3. Return";
    int pilih;
    cout << "\n Pilih : ";
    cin >> pilih;
    system("cls");
    if (pilih == 3)
        return mainmenu();
    if (pilih == 1 && uang >= hargaarmor)
    {
        uphealth += 70;
        uparmor += 1;
        uang -= hargaarmor;
        hargaarmor += (hargaarmor / 2);
        cout << "\n Upgrade Succes";
    }
    else if (pilih == 2 && uang >= hargasenjata)
    {
        upatt += 5;
        uang -= hargasenjata;
        hargasenjata += (hargasenjata / 2);
        cout << "\n Upgrade Succes";
    }
    else
    {
        cout << "\n Not Enought Coin Farm More!!!!\n";
    }
    string input;
    cout << "\nInput Any Key : ";
    cin >> input;
    return shopmenu();
}

void mainmenu()
{
    reset();
    system("cls");
    int pilih;
    cout << "1. Campaign \n";
    cout << "2. Versus Mode\n";
    cout << "3. Codex\n";
    cout << "4. Upgrade\n";
    cout << "5. Exit \n";
    cout << "Pilih : ";
    cin >> pilih;
    if (pilih == 4)
        shopmenu();
    if (pilih == 5)
        return;
    if (pilih == 3)
        codex(0);
    if (pilih == 2)
        versus(0);
    if (pilih == 1)
        campaign();
    if (pilih == 111)
        cheat("att");
    if (pilih == 222)
        cheat("armor");
    if (pilih == 333)
        cheat("health");
    if (pilih == 444)
        cheat("uang");
    return mainmenu();
}
int main()
{
    charunlock_Desolator_Slime = false, charunlock_crystal = false, charunlock_phoenix = false;
    charprogress = 3, uang = 0, hargaarmor = 50, hargasenjata = 50, uphealth = 0, upatt = 0, uparmor = 0, endlessmodereward = 350, endlessmodestage = 1, endlessmodemodiffier.health = 0, endlessmodemodiffier.armor = 0, endlessmodemodiffier.att = 0, endlessmode = false;
    cout << "Welcome To Monster Arena\n";
    cout << "Masukkan Nama Anda : ";
    cin >> nama;
    system("cls");
    mainmenu();
    return 0;
}

void cheat(string input)
{
    if (input == "att")
        player.attdimeg = 999999;
    if (input == "armor")
        player.armor = 999999;
    if (input == "health")
        player.health = 999999;
    if (input == "uang")
        uang = 999999;
}