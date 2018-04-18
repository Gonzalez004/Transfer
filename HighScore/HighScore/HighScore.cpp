//Fernando Gonzalez-Clara 2017 Spring Ms.Moe Video Programming
//"Edyan The Game" text based adventure game

#include <iostream>
#include <Windows.h>
#include<stdlib.h> 
#include <String>
#include <ctime>
#include <cstdlib>
//#include <allegro5/allegro.h>
//#include <allegro5/allegro_audio.h>
//#include <allegro5/allegro_acodec.h>
using namespace std;
string input = "a";
string name;
string answer;
int score = 0;
int room = 0;
int health = 10000;
string inventory[7] = { "Flashlight","empty","empty","empty","empty","empty","empty" };
int Highscore[5] = { '0','0','0','0','0'};
void monster();
void tryagain();
void healroom();

int main() {
	/*al_init();
	al_install_audio();
	al_init_acodec_addon();
	ALLEGRO_SAMPLE* sample = NULL;
	al_reserve_samples(1);*/

	srand(time(NULL));
	string inventory[7];
	for (int i = 0; i < 7; i++)

		system("color a0");

	Beep(750, 50);

	Beep(300, 250);
	Sleep(25);
	Beep(300, 250);
	Sleep(25);
	Beep(300, 250);
	Sleep(25);

	Beep(250, 250);
	Sleep(25);

	Beep(350, 63);
	Beep(300, 250);
	Sleep(25);

	Beep(250, 250);
	Sleep(25);

	Beep(350, 63);
	Beep(300, 250);
	Sleep(25);

	//cout << "Thank you to her, she helped and inspired me to create this game. Coudn't have done this without her." << endl;
	//cout << "E. Gonzalez " << endl;
	cout << " " << endl;
	cout << "/$$$$$$$$       /$$" << endl;
	cout << "| $$_____/      | $$" << endl;
	cout << "| $$        /$$$$$$$ /$$   /$$  /$$$$$$  /$$$$$$$" << endl;
	cout << "| $$$$$    /$$__  $$| $$  | $$ |____  $$| $$__ $$" << endl;
	cout << "| $$__/   | $$  | $$| $$  | $$  /$$$$$$$| $$  \ $$" << endl;
	cout << "| $$      | $$  | $$| $$  | $$ /$$__  $$| $$  |$$" << endl;
	cout << "| $$$$$$$$|  $$$$$$$|  $$$$$$$|  $$$$$$$| $$  |$$" << endl;
	cout << "|________/ \_______/ \____  $$ \_______/|__/  |__/" << endl;
	cout << "                   /$$  | $$" << endl;
	cout << "                  |  $$$$$$/" << endl;
	cout << "                    \______/" << endl;
	cout << "Welcome to Edyan the game" << endl;
	cout << "____________________________________________________" << endl;
	cout << "What is your name young adventure?" << endl;
	getline(cin, name);
	cout << "Welcome " << name << endl;

	cout << "____________________________________________________" << endl;
	cout << "Instruction:" << endl;
	cout << "Type 'Health' when you want to know your health" << endl;
	system("pause");
	cout << "Type 'Quit' when you want to exit the game" << endl;
	system("pause");
	cout << "Type 'Bag' when you want to see your inventory" << endl;
	system("pause");
	cout << "type 'North', 'South', 'West', or 'East' to move rooms" << endl;
	system("pause");
	cout << "Type 'Pick Up' when you want pick up an item you find" << endl;
	system("pause");
	cout << "When typing in the input, the word can be capitalized or not" << endl;
	system("pause");
	cout << "There might be a hidden rooms so LOOK OUT!" << endl;
	system("pause");
	cout << "____________________________________________________" << endl;


	cout << "Introduction:" << endl;
	cout << "____________________________________________________" << endl;
	cout << "You find yourself walking inside a old bar" << endl;
	cout << "You hear an old man telling a group of people in the corner, about something... " << endl;
	system("pause");
	cout << "____________________________________________________" << endl;
	cout << "You walk over to hear to about a mysterious cave filled with riches!" << endl;
	system("pause");
	cout << "____________________________________________________" << endl;
	cout << "You think to yourself" << endl;
	cout << "'This is the money I need for my family," << endl;
	cout << "so we can finally be free from our cruel master'" << endl;
	system("pause");
	cout << "____________________________________________________" << endl;
	cout << "You ask the old man where this cave is" << endl;
	system("pause");
	cout << "____________________________________________________" << endl;
	cout << "He replies with," << endl;
	cout << "'Now now...who may you be?...'" << endl;
	system("pause");
	cout << "____________________________________________________" << endl;
	cout << "You reply with," << endl;
	cout << "'My name is " << name << endl;
	cout << "and I wish to go find these riches within the cave'" << endl;
	system("pause");
	cout << "____________________________________________________" << endl;
	cout << "The old man says," << endl;
	cout << "'Young man, anyone who dare venture within the cave has died, but very well'" << endl;
	system("pause");
	cout << "____________________________________________________" << endl;
	cout << "He gives you the location of the cave, while everyone else around you laughs" << endl;
	system("pause");
	cout << "____________________________________________________" << endl;

	while (input.compare("quit") != 0) {
		switch (room) {
		case 0:
			system("color a0");
			cout << "____________________________________________________" << endl;
			inventory[0] = "Flashlight";
			inventory[1] = "empty";
			inventory[2] = "empty";
			inventory[3] = "empty";
			inventory[4] = "empty";
			inventory[5] = "empty";
			inventory[6] = "empty";
			health = 100;
			cout << "Your health is " << health << endl;
			cout << "Here's your inventory" << endl;
			for (int i = 0; i < 7; i++)
				cout << inventory[i] << endl;
			room = 1;


		case 1:
			cout << "____________________________________________________" << endl;
			system("color b0");
			score++;
			cout << "You're in front of a mysterious cave!" << endl;
			cout << "You brought a Flashlight around to look around in the cave" << endl;
			cout << "The cave has signs in front of it saying," << endl;
			cout << "'DO NOT ENTER IF YOU VALUE YOUR LIFE'" << endl;
			cout << "It also has scratches on the outside of the cave" << endl;
			cout << "You can head North" << endl;
			getline(cin, input);

			if (input.compare("North") == 0 || input.compare("north") == 0) {
				if (inventory[1] == "Water Bottle")
					room = 26;
				else if (inventory[1] == "Empty Water Bottle")
					room = 26;
				else
					room = 2;
			}
			else if (input.compare("quit") == 0)
				exit(0);
			else if (input.compare("Drink Red Bull Can") == 0 || input.compare("drink red bull can") == 0) {
				if (inventory[2] == "Red Bull Can") {
					health = health + 60;
					cout << "You're health is now " << health << endl;
					inventory[2] = "Empty Red Bull Can";
				}
				else if (inventory[1] == "empty" || inventory[1] == "Empty Red Bull Can")
					cout << "You have nothing to drink" << endl;
			}
			else if (input.compare("health") == 0)
				cout << "You're health is " << health << endl;
			else if (input.compare("bag") == 0) {
				cout << "Here's your inventory" << endl;
				for (int i = 0; i < 7; i++)
					cout << inventory[i] << endl;
			}
			else if (input.compare("Drink Water Bottle") == 0 || input.compare("drink water bottle") == 0) {
				if (inventory[1] == "Water Bottle") {
					health = health + 25;
					cout << "You're health is now " << health << endl;
					inventory[1] = "Empty Water Bottle";
				}
				else if (inventory[1] == "empty" || inventory[1] == "Empty Water Bottle")
					cout << "You have nothing to drink" << endl;
			}
			else
				cout << "Invalid Input" << endl;

			break;

		case 2:
			system("color f4");
			score++;
			cout << "____________________________________________________" << endl;
			cout << "You're in the beginning of the cave" << endl;
			cout << "In a hallway of the cave" << endl;
			cout << "There are scratch marks on the side of the walls of the cave" << endl;
			cout << "You hear sounds if front on you" << endl;
			cout << "You found a water bottle on the floor, seems it can heal you +25 health" << endl;
			cout << "You can head North or South" << endl;

			getline(cin, input);

			if (input.compare("North") == 0 || input.compare("north") == 0)
				room = 3;
			else if (input.compare("South") == 0 || input.compare("south") == 0)
				room = 22;
			else if (input.compare("Yes") == 0 || input.compare("yes") == 0)
				room = 1;
			else if (input.compare("Quit") == 0 || input.compare("quit") == 0)
				exit(0);
			else if (input.compare("Drink Red Bull Can") == 0 || input.compare("drink red bull can") == 0) {
				if (inventory[2] == "Red Bull Can") {
					health = health + 60;
					cout << "You're health is now " << health << endl;
					inventory[2] = "Empty Red Bull Can";
				}
				else if (inventory[1] == "empty" || inventory[1] == "Empty Red Bull Can")
					cout << "You have nothing to drink" << endl;
			}
			else if (input.compare("Health") == 0 || input.compare("health") == 0)
				cout << "You're health is " << health << endl;
			else if (input.compare("Bag") == 0 || input.compare("bag") == 0) {
				cout << "Here's your inventory" << endl;
				for (int i = 0; i < 7; i++)
					cout << inventory[i] << endl;
			}
			else if (input.compare("Pick Up") == 0 || input.compare("pick up") == 0) {
				inventory[1] = "Water Bottle";
				cout << "Water Bottle has been added to your inventory" << endl;
				cout << "Type 'Drink Water Bottle' to gain those +25 health" << endl;
				room = 26;
			}
			else
				cout << "Invalid Input" << endl;

			break;

		case 3:
			system("color 9a");
			score++;
			cout << "____________________________________________________" << endl;
			cout << "As you keep walking..." << endl;
			monster();
			if (health <= 0) {
				tryagain();
				break;
			}
			cout << "There are three ways you can go" << endl;
			cout << "You can go back, or you can decide between the twos ways" << endl;
			cout << "North has a calling towards you" << endl;
			cout << "East has skid marks and their some noises over there" << endl;
			cout << "You can head North, South, or East" << endl;
			getline(cin, input);

			if (input.compare("North") == 0 || input.compare("north") == 0) {
				if (inventory[2] == "Red Bull Can")
					room = 27;
				else if (inventory[2] == "Empty Red Bull Can")
					room = 27;
				else
					room = 4;
			}
			else if (input.compare("South") == 0 || input.compare("south") == 0) {
				if (inventory[1] == "Water Bottle")
					room = 26;
				else if (inventory[1] == "Empty Water Bottle")
					room = 26;
				else
					room = 2;
			}
			else if (input.compare("East") == 0 || input.compare("east") == 0) {
				if (inventory[4] == "Key")
					room = 29;
				else
					room = 9;
			}
			else if (input.compare("Drink Water Bottle") == 0 || input.compare("drink water bottle") == 0) {
				if (inventory[1] == "Water Bottle") {
					health = health + 25;
					cout << "You're health is now " << health << endl;
					inventory[1] = "Empty Water Bottle";
				}
				else if (inventory[1] == "empty" || inventory[1] == "Empty Water Bottle")
					cout << "You have nothing to drink" << endl;
			}
			else if (input.compare("Quit") == 0 || input.compare("quit") == 0)
				exit(0);
			else if (input.compare("Drink Red Bull Can") == 0 || input.compare("drink red bull can") == 0) {
				if (inventory[2] == "Red Bull Can") {
					health = health + 60;
					cout << "You're health is now " << health << endl;
					inventory[2] = "Empty Red Bull Can";
				}
				else if (inventory[1] == "empty" || inventory[1] == "Empty Red Bull Can")
					cout << "You have nothing to drink" << endl;
			}
			else if (input.compare("Health") == 0 || input.compare("health") == 0)
				cout << "You're health is " << health << endl;
			else if (input.compare("Bag") == 0 || input.compare("bag") == 0) {
				cout << "Here's your inventory" << endl;
				for (int i = 0; i < 7; i++)
					cout << inventory[i] << endl;
			}
			else
				cout << "Invalid Input" << endl;

			break;

		case 4:
			score++;
			system("color 3f");
			cout << "____________________________________________________" << endl;
			cout << "You come to a corner of the the cave" << endl;
			cout << "You see a wall that has the words 'The sword only come to those who are in trouble' written on it" << endl;
			cout << "You found a Red Bull can on the floor, seems it can heal you +60 health" << endl;
			cout << "You can head South or West" << endl;
			getline(cin, input);

			if (input.compare("South") == 0 || input.compare("south") == 0)
				room = 3;
			else if (input.compare("West") == 0 || input.compare("west") == 0)
				room = 5;
			else if (input.compare("Quit") == 0 || input.compare("quit") == 0)
				exit(0);
			else if (input.compare("Health") == 0 || input.compare("health") == 0)
				cout << "You're health is " << health << endl;
			else if (input.compare("Drink Water Bottle") == 0 || input.compare("drink water bottle") == 0) {
				if (inventory[1] == "Water Bottle") {
					health = health + 25;
					cout << "You're health is now " << health << endl;
					inventory[1] = "Empty Water Bottle";
				}
				else if (inventory[1] == "empty" || inventory[1] == "Empty Water Bottle")
					cout << "You have nothing to drink" << endl;
			}
			else if (input.compare("Drink Red Bull Can") == 0 || input.compare("drink red bull can") == 0) {
				if (inventory[2] == "Red Bull Can") {
					health = health + 60;
					cout << "You're health is now " << health << endl;
					inventory[2] = "Empty Red Bull Can";
				}
				else if (inventory[1] == "empty" || inventory[1] == "Empty Red Bull Can")
					cout << "You have nothing to drink" << endl;
			}
			else if (input.compare("Bag") == 0 || input.compare("bag") == 0) {
				cout << "Here's your inventory" << endl;
				for (int i = 0; i < 7; i++)
					cout << inventory[i] << endl;
			}
			else if (input.compare("Pick Up") == 0 || input.compare("pick up") == 0) {
				inventory[2] = "Red Bull Can";
				cout << "Red Bull Can has been added to your inventory" << endl;
				cout << "Type 'Drink Red Bull Can' to gain those +60 health" << endl;
				room = 27;
			}
			else
				cout << "Invalid Input" << endl;

			break;

		case 5:
			system("color e0");
			score++;
			cout << "____________________________________________________" << endl;
			cout << "As you go around the corner you're in the hallway" << endl;
			cout << "Everything seems quiet however their is a light at the end of the hallway" << endl;
			cout << "You can head West or East" << endl;
			getline(cin, input);

			if (input.compare("West") == 0 || input.compare("west") == 0) {
				if (inventory[3] == "Sword of Edyan")
					room = 28;
				else
					room = 6;
			}
			else if (input.compare("East") == 0 || input.compare("east") == 0) {
				if (inventory[2] == "Red Bull Can")
					room = 27;
				else if (inventory[2] == "Empty Red Bull Can")
					room = 27;
				else
					room = 4;
			}
			else if (input.compare("Quit") == 0 || input.compare("quit") == 0)
				exit(0);
			else if (input.compare("Drink Red Bull Can") == 0 || input.compare("drink red bull can") == 0) {
				if (inventory[2] == "Red Bull Can") {
					health = health + 60;
					cout << "You're health is now " << health << endl;
					inventory[2] = "Empty Red Bull Can";
				}
				else if (inventory[1] == "empty" || inventory[1] == "Empty Red Bull Can")
					cout << "You have nothing to drink" << endl;
			}
			else if (input.compare("Drink Water Bottle") == 0 || input.compare("drink water bottle") == 0) {
				if (inventory[1] == "Water Bottle") {
					health = health + 25;
					cout << "You're health is now " << health << endl;
					inventory[1] = "Empty Water Bottle";
				}
				else if (inventory[1] == "empty" || inventory[1] == "Empty Water Bottle")
					cout << "You have nothing to drink" << endl;
			}
			else if (input.compare("Health") == 0 || input.compare("health") == 0)
				cout << "You're health is " << health << endl;
			else if (input.compare("Bag") == 0 || input.compare("bag") == 0) {
				cout << "Here's your inventory" << endl;
				for (int i = 0; i < 7; i++)
					cout << inventory[i] << endl;
			}
			else
				cout << "Invalid Input" << endl;

			break;

		case 6:
			system("color b0");
			score++;
			cout << "____________________________________________________" << endl;
			cout << "A rock stands before you with a sword sticking out of it" << endl;
			cout << "You can go towards it and grab it" << endl;
			cout << "seems it can be useful..." << endl;
			cout << "You can head North, South, or East" << endl;
			getline(cin, input);

			if (input.compare("North") == 0 || input.compare("north") == 0)
				room = 8;
			else if (input.compare("South") == 0 || input.compare("south") == 0)
				room = 7;
			else if (input.compare("East") == 0 || input.compare("east") == 0)
				room = 5;
			else if (input.compare("Quit") == 0 || input.compare("quit") == 0)
				exit(0);
			else if (input.compare("Drink Red Bull Can") == 0 || input.compare("drink red bull can") == 0) {
				if (inventory[2] == "Red Bull Can") {
					health = health + 60;
					cout << "You're health is now " << health << endl;
					inventory[2] = "Empty Red Bull Can";
				}
				else if (inventory[1] == "empty" || inventory[1] == "Empty Red Bull Can")
					cout << "You have nothing to drink" << endl;
			}
			else if (input.compare("Drink Water Bottle") == 0 || input.compare("drink water bottle") == 0) {
				if (inventory[1] == "Water Bottle") {
					health = health + 25;
					cout << "You're health is now " << health << endl;
					inventory[1] = "Empty Water Bottle";
				}
				else if (inventory[1] == "empty" || inventory[1] == "Empty Water Bottle")
					cout << "You have nothing to drink" << endl;
			}
			else if (input.compare("Health") == 0 || input.compare("health") == 0)
				cout << "You're health is " << health << endl;
			else if (input.compare("Bag") == 0 || input.compare("bag") == 0) {
				cout << "Here's your inventory" << endl;
				for (int i = 0; i < 7; i++)
					cout << inventory[i] << endl;
			}
			else if (input.compare("Pick Up") == 0 || input.compare("pick up") == 0) {
				inventory[3] = "Sword of Edyan";
				cout << "Sword of Edyan has been added to your inventory" << endl;
				room = 28;
			}
			else
				cout << "Invalid Input" << endl;

			break;

		case 7:
			system("color 40");
			score++;
			cout << "____________________________________________________" << endl;
			cout << "As you go South You died!" << endl;
			cout << "You fell into a pit of snakes! They ate you..." << endl;
			health = 0;
			system("pause");
			tryagain();

			break;

		case 8:
			system("color b0");
			score++;

			cout << "____________________________________________________" << endl;
			cout << "As you keep walking..." << endl;
			monster();
			if (health <= 0) {
				tryagain();
				break;
			}
			cout << "It's a dead end! You have to go back!" << endl;
			cout << "You can head South" << endl;
			getline(cin, input);

			if (input.compare("South") == 0 || input.compare("south") == 0) {
				if (inventory[3] == "Sword of Edyan")
					room = 28;
				else
					room = 6;
			}
			else if (input.compare("Quit") == 0 || input.compare("quit") == 0)
				exit(0);
			else if (input.compare("Drink Red Bull Can") == 0 || input.compare("drink red bull can") == 0) {
				if (inventory[2] == "Red Bull Can") {
					health = health + 60;
					cout << "You're health is now " << health << endl;
					inventory[2] = "Empty Red Bull Can";
				}
				else if (inventory[1] == "empty" || inventory[1] == "Empty Red Bull Can")
					cout << "You have nothing to drink" << endl;
			}
			else if (input.compare("Drink Water Bottle") == 0 || input.compare("drink water bottle") == 0) {
				if (inventory[1] == "Water Bottle") {
					health = health + 25;
					cout << "You're health is now " << health << endl;
					inventory[1] = "Empty Water Bottle";
				}
				else if (inventory[1] == "empty" || inventory[1] == "Empty Water Bottle")
					cout << "You have nothing to drink" << endl;
			}
			else if (input.compare("Health") == 0 || input.compare("health") == 0)
				cout << "You're health is " << health << endl;
			else if (input.compare("Bag") == 0 || input.compare("bag") == 0) {
				cout << "Here's your inventory" << endl;
				for (int i = 0; i < 7; i++)
					cout << inventory[i] << endl;
			}
			else
				cout << "Invalid Input" << endl;

			break;

		case 9:
			system("color f4");
			score++;
			cout << "____________________________________________________" << endl;
			cout << "You go toward the voices" << endl;
			cout << "There are a lot of scratches on the floor and on the sides of the walls" << endl;
			cout << "You see something shiny on the floor, looks like a key" << endl;
			cout << "You can head West or East" << endl;
			getline(cin, input);

			if (input.compare("West") == 0 || input.compare("west") == 0)
				room = 3;
			else if (input.compare("East") == 0 || input.compare("east") == 0)
				room = 10;
			else if (input.compare("Quit") == 0 || input.compare("quit") == 0)
				exit(0);
			else if (input.compare("Pick Up") == 0 || input.compare("pick up") == 0) {
				inventory[4] = "Key";
				cout << "a key has been added to your inventory" << endl;
				room = 29;
			}
			else if (input.compare("Drink Red Bull Can") == 0 || input.compare("drink red bull can") == 0) {
				if (inventory[2] == "Red Bull Can") {
					health = health + 60;
					cout << "You're health is now " << health << endl;
					inventory[2] = "Empty Red Bull Can";
				}
				else if (inventory[1] == "empty" || inventory[1] == "Empty Red Bull Can")
					cout << "You have nothing to drink" << endl;
			}
			else if (input.compare("Drink Water Bottle") == 0 || input.compare("drink water bottle") == 0) {
				if (inventory[1] == "Water Bottle") {
					health = health + 25;
					cout << "You're health is now " << health << endl;
					inventory[1] = "Empty Water Bottle";
				}
				else if (inventory[1] == "empty" || inventory[1] == "Empty Water Bottle")
					cout << "You have nothing to drink" << endl;
			}
			else if (input.compare("Health") == 0 || input.compare("health") == 0)
				cout << "You're health is " << health << endl;
			else if (input.compare("Bag") == 0 || input.compare("bag") == 0) {
				cout << "Here's your inventory" << endl;
				for (int i = 0; i < 7; i++)
					cout << inventory[i] << endl;
			}
			else
				cout << "Invalid Input" << endl;

			break;

		case 10:
			system("color 9a");
			score++;
			cout << "____________________________________________________" << endl;
			cout << "you encounter 3 ways to go" << endl;
			cout << "There is a crack in the ceiling above you, that let some light slip through" << endl;
			cout << "You can see a two hallways (North and East) and the passage from where you came from (West)" << endl;
			cout << "However...there is a wall behind you, seems to have scratch marks on the floor..." << endl;
			system("pause");
			cout << "Can that wall move?" << endl;
			cout << "You can head North, West, or East" << endl;
			getline(cin, input);

			if (input.compare("North") == 0 || input.compare("north") == 0) {
				if (inventory[4] == "Key")
					room = 30;
				else
					room = 13;
			}
			else if (input.compare("South") == 0 || input.compare("south") == 0)
				room = 11;
			else if (input.compare("West") == 0 || input.compare("west") == 0) {
				if (inventory[4] == "Key")
					room = 29;
				else
					room = 9;
			}
			else if (input.compare("East") == 0 || input.compare("east") == 0)
				room = 12;
			else if (input.compare("Quit") == 0 || input.compare("quit") == 0)
				exit(0);
			else if (input.compare("Drink Red Bull Can") == 0 || input.compare("drink red bull can") == 0) {
				if (inventory[2] == "Red Bull Can") {
					health = health + 60;
					cout << "You're health is now " << health << endl;
					inventory[2] = "Empty Red Bull Can";
				}
				else if (inventory[1] == "empty" || inventory[1] == "Empty Red Bull Can")
					cout << "You have nothing to drink" << endl;
			}
			else if (input.compare("Drink Water Bottle") == 0 || input.compare("drink water bottle") == 0) {
				if (inventory[1] == "Water Bottle") {
					health = health + 25;
					cout << "You're health is now " << health << endl;
					inventory[1] = "Empty Water Bottle";
				}
				else if (inventory[1] == "empty" || inventory[1] == "Empty Water Bottle")
					cout << "You have nothing to drink" << endl;
			}
			else if (input.compare("Health") == 0 || input.compare("health") == 0)
				cout << "You're health is " << health << endl;
			else if (input.compare("Bag") == 0 || input.compare("bag") == 0) {
				cout << "Here's your inventory" << endl;
				for (int i = 0; i < 7; i++)
					cout << inventory[i] << endl;
			}
			else
				cout << "Invalid Input" << endl;

			break;

		case 11:
			system("color 3f");
			score++;
			cout << "____________________________________________________" << endl;
			cout << "You have discovered a secret room!!!" << endl;
			cout << "There is a fountain in the middle of the room" << endl;
			Beep(500, 500);
			healroom();
			cout << "You can head North" << endl;
			getline(cin, input);

			if (input.compare("North") == 0 || input.compare("north") == 0)
				room = 10;
			else if (input.compare("Quit") == 0 || input.compare("quit") == 0)
				exit(0);
			else if (input.compare("Drink Red Bull Can") == 0 || input.compare("drink red bull can") == 0) {
				if (inventory[2] == "Red Bull Can") {
					health = health + 60;
					cout << "You're health is now " << health << endl;
					inventory[2] = "Empty Red Bull Can";
				}
				else if (inventory[1] == "empty" || inventory[1] == "Empty Red Bull Can")
					cout << "You have nothing to drink" << endl;
			}
			else if (input.compare("Drink Water Bottle") == 0 || input.compare("drink water bottle") == 0) {
				if (inventory[1] == "Water Bottle") {
					health = health + 25;
					cout << "You're health is now " << health << endl;
					inventory[1] = "Empty Water Bottle";
				}
				else if (inventory[1] == "empty" || inventory[1] == "Empty Water Bottle")
					cout << "You have nothing to drink" << endl;
			}
			else if (input.compare("Health") == 0 || input.compare("health") == 0)
				cout << "You're health is " << health << endl;
			else if (input.compare("Bag") == 0 || input.compare("bag") == 0) {
				cout << "Here's your inventory" << endl;
				for (int i = 0; i < 7; i++)
					cout << inventory[i] << endl;
			}
			else
				cout << "Invalid Input" << endl;

			break;

		case 12:
			system("color 40");
			score++;
			cout << "____________________________________________________" << endl;
			cout << "Oooooooo snaps! A big deadly turtle has snap your head off!" << endl;
			Beep(700, 500);
			Beep(700, 500);
			Beep(700, 500);
			health = 0;
			system("pause");
			tryagain();

			break;

		case 13:
			system("color e0");
			score++;
			cout << "____________________________________________________" << endl;
			cout << "You encounter a hallway, but their is a door...seems to be locked! hmmmm..." << endl;
			cout << "Looks like you need a key to open it up" << endl;
			cout << "You can head South" << endl;
			getline(cin, input);

			if (input.compare("North") == 0 || input.compare("north") == 0) {
				cout << "Can't go this way" << endl;
				room = 13;
			}
			else if (input.compare("South") == 0 || input.compare("south") == 0)
				room = 10;
			else if (input.compare("Quit") == 0 || input.compare("quit") == 0)
				exit(0);
			else if (input.compare("Drink Red Bull Can") == 0 || input.compare("drink red bull can") == 0) {
				if (inventory[2] == "Red Bull Can") {
					health = health + 60;
					cout << "You're health is now " << health << endl;
					inventory[2] = "Empty Red Bull Can";
				}
				else if (inventory[1] == "empty" || inventory[1] == "Empty Red Bull Can")
					cout << "You have nothing to drink" << endl;
			}
			else if (input.compare("Drink Water Bottle") == 0 || input.compare("drink water bottle") == 0) {
				if (inventory[1] == "Water Bottle") {
					health = health + 25;
					cout << "You're health is now " << health << endl;
					inventory[1] = "Empty Water Bottle";
				}
				else if (inventory[1] == "empty" || inventory[1] == "Empty Water Bottle")
					cout << "You have nothing to drink" << endl;
			}
			else if (input.compare("Health") == 0 || input.compare("health") == 0)
				cout << "You're health is " << health << endl;
			else if (input.compare("Bag") == 0 || input.compare("bag") == 0) {
				cout << "Here's your inventory" << endl;
				for (int i = 0; i < 7; i++)
					cout << inventory[i] << endl;
			}
			else
				cout << "Invalid Input" << endl;

			break;

		case 14:
			system("color b0");
			score++;
			cout << "____________________________________________________" << endl;
			cout << "As you keep walking..." << endl;
			monster();
			if (health <= 0) {
				tryagain();
				break;
			}
			cout << "You can head North or South" << endl;
			getline(cin, input);

			if (input.compare("North") == 0 || input.compare("north") == 0)
				room = 15;
			else if (input.compare("South") == 0 || input.compare("south") == 0) {
				if (inventory[4] == "Key")
					room = 30;
				else
					room = 13;
			}
			else if (input.compare("Quit") == 0 || input.compare("quit") == 0)
				exit(0);
			else if (input.compare("Drink Red Bull Can") == 0 || input.compare("drink red bull can") == 0) {
				if (inventory[2] == "Red Bull Can") {
					health = health + 60;
					cout << "You're health is now " << health << endl;
					inventory[2] = "Empty Red Bull Can";
				}
				else if (inventory[1] == "empty" || inventory[1] == "Empty Red Bull Can")
					cout << "You have nothing to drink" << endl;
			}
			else if (input.compare("Drink Water Bottle") == 0 || input.compare("drink water bottle") == 0) {
				if (inventory[1] == "Water Bottle") {
					health = health + 25;
					cout << "You're health is now " << health << endl;
					inventory[1] = "Empty Water Bottle";
				}
				else if (inventory[1] == "empty" || inventory[1] == "Empty Water Bottle")
					cout << "You have nothing to drink" << endl;
			}
			else if (input.compare("Health") == 0 || input.compare("health") == 0)
				cout << "You're health is " << health << endl;
			else if (input.compare("Bag") == 0 || input.compare("bag") == 0) {
				cout << "Here's your inventory" << endl;
				for (int i = 0; i < 7; i++)
					cout << inventory[i] << endl;
			}
			else
				cout << "Invalid Input" << endl;

			break;

		case 15:
			system("color f4");
			score++;
			cout << "____________________________________________________" << endl;
			cout << "There are three ways to go!" << endl;
			cout << "You can go back south, or decided between the other two hallways.." << endl;
			cout << "One hallway contains screeching, while the other hallway contains a person talking" << endl;
			cout << "You can't tell where it's coming from" << endl;
			cout << "You do hear a water fountain coming from a wall!?!?" << endl;
			cout << "You can go North, South, or West" << endl;
			getline(cin, input);

			if (input.compare("North") == 0 || input.compare("north") == 0) {
				if (inventory[5] == "Piece Of Paper That Says, 'Man'")
					room = 31;
				else
					room = 18;
			}
			else if (input.compare("South") == 0 || input.compare("south") == 0)
				room = 14;
			else if (input.compare("West") == 0 || input.compare("west") == 0)
				room = 17;
			else if (input.compare("East") == 0 || input.compare("east") == 0)
				room = 16;
			else if (input.compare("Quit") == 0 || input.compare("quit") == 0)
				exit(0);
			else if (input.compare("Drink Red Bull Can") == 0 || input.compare("drink red bull can") == 0) {
				if (inventory[2] == "Red Bull Can") {
					health = health + 60;
					cout << "You're health is now " << health << endl;
					inventory[2] = "Empty Red Bull Can";
				}
				else if (inventory[1] == "empty" || inventory[1] == "Empty Red Bull Can")
					cout << "You have nothing to drink" << endl;
			}
			else if (input.compare("Drink Water Bottle") == 0 || input.compare("drink water bottle") == 0) {
				if (inventory[1] == "Water Bottle") {
					health = health + 25;
					cout << "You're health is now " << health << endl;
					inventory[1] = "Empty Water Bottle";
				}
				else if (inventory[1] == "empty" || inventory[1] == "Empty Water Bottle")
					cout << "You have nothing to drink" << endl;
			}
			else if (input.compare("Health") == 0 || input.compare("health") == 0)
				cout << "You're health is " << health << endl;
			else if (input.compare("Bag") == 0 || input.compare("bag") == 0) {
				cout << "Here's your inventory" << endl;
				for (int i = 0; i < 7; i++)
					cout << inventory[i] << endl;
			}
			else
				cout << "Invalid Input" << endl;

			break;

		case 16:
			system("color 9a");
			score++;
			cout << "____________________________________________________" << endl;
			cout << "You have discovered a secret room!!!" << endl;
			cout << "There is a fountain in the middle of the room" << endl;
			Beep(500, 500);
			healroom();
			cout << "You can head West" << endl;
			getline(cin, input);

			if (input.compare("West") == 0 || input.compare("west") == 0)
				room = 15;
			else if (input.compare("Quit") == 0 || input.compare("quit") == 0)
				exit(0);
			else if (input.compare("Drink Red Bull Can") == 0 || input.compare("drink red bull can") == 0) {
				if (inventory[2] == "Red Bull Can") {
					health = health + 60;
					cout << "You're health is now " << health << endl;
					inventory[2] = "Empty Red Bull Can";
				}
				else if (inventory[1] == "empty" || inventory[1] == "Empty Red Bull Can")
					cout << "You have nothing to drink" << endl;
			}
			else if (input.compare("Drink Water Bottle") == 0 || input.compare("drink water bottle") == 0) {
				if (inventory[1] == "Water Bottle") {
					health = health + 25;
					cout << "You're health is now " << health << endl;
					inventory[1] = "Empty Water Bottle";
				}
				else if (inventory[1] == "empty" || inventory[1] == "Empty Water Bottle")
					cout << "You have nothing to drink" << endl;
			}
			else if (input.compare("Health") == 0 || input.compare("health") == 0)
				cout << "You're health is " << health << endl;
			else if (input.compare("Bag") == 0 || input.compare("bag") == 0) {
				cout << "Here's your inventory" << endl;
				for (int i = 0; i < 7; i++)
					cout << inventory[i] << endl;
			}
			else
				cout << "Invalid Input" << endl;

			break;

		case 17:
			system("color 3f");
			score++;
			cout << "____________________________________________________" << endl;
			cout << "As you keep walking..." << endl;
			monster();
			if (health <= 0) {
				tryagain();
				break;
			}
			cout << "You can go West or East" << endl;
			getline(cin, input);

			if (input.compare("West") == 0 || input.compare("west") == 0)
				room = 19;
			else if (input.compare("East") == 0 || input.compare("east") == 0)
				room = 15;
			else if (input.compare("Quit") == 0 || input.compare("quit") == 0)
				exit(0);
			else if (input.compare("Drink Water Bottle") == 0 || input.compare("drink water bottle") == 0) {
				if (inventory[1] == "Water Bottle") {
					health = health + 25;
					cout << "You're health is now " << health << endl;
					inventory[1] = "Empty Water Bottle";
				}
				else if (inventory[1] == "empty" || inventory[1] == "Empty Water Bottle")
					cout << "You have nothing to drink" << endl;
			}
			else if (input.compare("Health") == 0 || input.compare("health") == 0)
				cout << "You're health is " << health << endl;
			else if (input.compare("Bag") == 0 || input.compare("bag") == 0) {
				cout << "Here's your inventory" << endl;
				for (int i = 0; i < 7; i++)
					cout << inventory[i] << endl;
			}
			else
				cout << "Invalid Input" << endl;

			break;

		case 18:
			system("color e0");
			score++;
			cout << "____________________________________________________" << endl;
			cout << "The voices of a person talking get's louder!" << endl;
			cout << "OOOOO a piece of ripped paper on the floor! strange..." << endl;
			cout << "There are skulls on the floor now...." << endl;
			cout << "There is also a sign next to one of the skulls that says," << endl;
			cout << "Beware...for the riddler...." << endl;
			cout << "You can go North or South" << endl;
			getline(cin, input);

			if (input.compare("North") == 0 || input.compare("north") == 0)
				room = 20;
			else if (input.compare("South") == 0 || input.compare("south") == 0)
				room = 15;
			else if (input.compare("Quit") == 0 || input.compare("quit") == 0)
				exit(0);
			else if (input.compare("Pick Up") == 0 || input.compare("pick up") == 0) {
				inventory[5] = "Piece Of Paper That Says, 'Man'";
				cout << "a piece of ripped paper has been added to your inventory" << endl;
				room = 31;
			}
			else if (input.compare("Drink Red Bull Can") == 0 || input.compare("drink red bull can") == 0) {
				if (inventory[2] == "Red Bull Can") {
					health = health + 60;
					cout << "You're health is now " << health << endl;
					inventory[2] = "Empty Red Bull Can";
				}
				else if (inventory[1] == "empty" || inventory[1] == "Empty Red Bull Can")
					cout << "You have nothing to drink" << endl;
			}
			else if (input.compare("Drink Water Bottle") == 0 || input.compare("drink water bottle") == 0) {
				if (inventory[1] == "Water Bottle") {
					health = health + 25;
					cout << "You're health is now " << health << endl;
					inventory[1] = "Empty Water Bottle";
				}
				else if (inventory[1] == "empty" || inventory[1] == "Empty Water Bottle")
					cout << "You have nothing to drink" << endl;
			}
			else if (input.compare("Health") == 0 || input.compare("health") == 0)
				cout << "You're health is " << health << endl;
			else if (input.compare("bag") == 0 || input.compare("bag") == 0) {
				cout << "Here's your inventory" << endl;
				for (int i = 0; i < 7; i++)
					cout << inventory[i] << endl;
			}
			else
				cout << "Invalid Input" << endl;

			break;

		case 19:
			system("color 40");
			score++;
			cout << "____________________________________________________" << endl;
			Beep(700, 500);
			Beep(700, 500);
			Beep(700, 500);
			cout << "it's a trap room! As you enter a wall comes down to trap you in!" << endl;
			system("pause");
			cout << "Fire come out the walls burning the whole room..." << endl;
			cout << "And everyone in it! (That Means You Died)" << endl;
			health = 0;
			system("pause");
			tryagain();

			break;

		case 20:
			system("color b0");
			score++;
			cout << "____________________________________________________" << endl;
			cout << "As you keep walking..." << endl;
			monster();
			if (health <= 0) {
				tryagain();
				break;
			}
			cout << "You can head North, South, or West" << endl;
			getline(cin, input);

			if (input.compare("North") == 0 || input.compare("north") == 0)
				room = 23;
			else if (input.compare("South") == 0 || input.compare("south") == 0) {
				if (inventory[5] == "Piece Of Paper That Says, 'Man'")
					room = 31;
				else
					room = 18;
			}
			else if (input.compare("West") == 0 || input.compare("west") == 0)
				room = 21;
			else if (input.compare("Quit") == 0 || input.compare("quit") == 0)
				exit(0);
			else if (input.compare("Drink Red Bull Can") == 0 || input.compare("drink red bull can") == 0) {
				if (inventory[2] == "Red Bull Can") {
					health = health + 60;
					cout << "You're health is now " << health << endl;
					inventory[2] = "Empty Red Bull Can";
				}
				else if (inventory[1] == "empty" || inventory[1] == "Empty Red Bull Can")
					cout << "You have nothing to drink" << endl;
			}
			else if (input.compare("Drink Water Bottle") == 0 || input.compare("drink water bottle") == 0) {
				if (inventory[1] == "Water Bottle") {
					health = health + 25;
					cout << "You're health is now " << health << endl;
					inventory[1] = "Empty Water Bottle";
				}
				else if (inventory[1] == "empty" || inventory[1] == "Empty Water Bottle")
					cout << "You have nothing to drink" << endl;
			}
			else if (input.compare("Health") == 0 || input.compare("health") == 0)
				cout << "You're health is " << health << endl;
			else if (input.compare("Bag") == 0 || input.compare("bag") == 0) {
				cout << "Here's your inventory" << endl;
				for (int i = 0; i < 7; i++)
					cout << inventory[i] << endl;
			}
			else
				cout << "Invalid Input" << endl;

			break;

		case 21:
			system("color f4");
			score++;
			cout << "____________________________________________________" << endl;
			cout << "As you continued you see an animal!" << endl;
			cout << "There are feathers all over the floor!" << endl;
			cout << "This is getting a little strange..." << endl;
			cout << "You can head West or East" << endl;
			getline(cin, input);

			if (input.compare("West") == 0 || input.compare("west") == 0)
				room = 24;
			else if (input.compare("East") == 0 || input.compare("east") == 0)
				room = 20;
			else if (input.compare("Quit") == 0 || input.compare("quit") == 0)
				exit(0);
			else if (input.compare("Drink Red Bull Can") == 0 || input.compare("drink red bull can") == 0) {
				if (inventory[2] == "Red Bull Can") {
					health = health + 60;
					cout << "You're health is now " << health << endl;
					inventory[2] = "Empty Red Bull Can";
				}
				else if (inventory[1] == "empty" || inventory[1] == "Empty Red Bull Can")
					cout << "You have nothing to drink" << endl;
			}
			else if (input.compare("Drink Water Bottle") == 0 || input.compare("drink water bottle") == 0) {
				if (inventory[1] == "Water Bottle") {
					health = health + 25;
					cout << "You're health is now " << health << endl;
					inventory[1] = "Empty Water Bottle";
				}
				else if (inventory[1] == "empty" || inventory[1] == "Empty Water Bottle")
					cout << "You have nothing to drink" << endl;
			}
			else if (input.compare("Health") == 0 || input.compare("health") == 0)
				cout << "You're health is " << health << endl;
			else if (input.compare("Bag") == 0 || input.compare("bag") == 0) {
				cout << "Here's your inventory" << endl;
				for (int i = 0; i < 7; i++)
					cout << inventory[i] << endl;
			}
			else
				cout << "Invalid Input" << endl;

			break;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		case 22:
			score++;
			cout << "____________________________________________________" << endl;

			if (inventory[3] == "Sword of Edyan" && inventory[6] == "Gold") {
				cout << "You won!" << endl;
				system("pause");
				cout << "You had all the money needed for your family" << endl;
				cout << "When the master tried to take the gold from you, you used the sword to defend yourself" << endl;
				system("pause");
				cout << "Good Game" << endl;
				cout << "Try Again? Yes or No?" << endl;

				getline(cin, answer);

				if (answer.compare("Yes") == 0 || answer.compare("yes") == 0) {

					room = 34;

				}
				else if (answer.compare("No") == 0 || answer.compare("no") == 0) {
					score = 0;
					system("pause");
					exit(0);
				}
				else if (answer.compare("quit") == 0 || answer.compare("quit") == 0)
					exit(0);
			}
			else if (inventory[3] == "Sword Of Edyan" && inventory[6] == "empty") {
				cout << "You lost!" << endl;
				cout << "You didn't find the gold however you did find the sword" << endl;
				cout << "You fought with the master and defend yourself with sword. You won!" << endl;
				cout << "You were kicked out of his house and back to living on the streets" << endl;
				cout << "You died in the end" << endl;
				system("pause");
				cout << "Good Game" << endl;
				cout << "Try Again? Yes or No?" << endl;

				getline(cin, answer);

				if (answer.compare("Yes") == 0 || answer.compare("yes") == 0) {

					room = 0;

				}
				else if (answer.compare("No") == 0 || answer.compare("no") == 0) {
					system("pause");
					exit(0);
				}
				else if (answer.compare("quit") == 0 || answer.compare("quit") == 0)
					exit(0);
			}
			else if (inventory[3] == "empty" && inventory[6] == "Gold") {
				cout << "You lost!" << endl;
				cout << "You found the gold!" << endl;
				cout << "However your master took the gold from you when you return home" << endl;
				cout << "You're poor again and your family are still working for your master" << endl;
				system("pause");
				cout << "Good Game" << endl;
				cout << "Try Again? Yes or No?" << endl;

				getline(cin, answer);

				if (answer.compare("Yes") == 0 || answer.compare("yes") == 0) {

					room = 0;

				}
				else if (answer.compare("No") == 0 || answer.compare("no") == 0) {
					system("pause");
					exit(0);
				}
				else if (answer.compare("quit") == 0 || answer.compare("quit") == 0)
					exit(0);
			}
			else {
				cout << "You lost!" << endl;
				cout << "You didn't find anything at all!" << endl;
				cout << "You're still poor and your family are still working for your master" << endl;
				system("pause");
				cout << "Good Game" << endl;
				cout << "Try Again? Yes or No?" << endl;

				getline(cin, answer);

				if (answer.compare("Yes") == 0 || answer.compare("yes") == 0) {
					room = 0;
				}
				else if (answer.compare("No") == 0 || answer.compare("no") == 0) {
					system("pause");
					exit(0);
				}
				else if (answer.compare("quit") == 0 || answer.compare("quit") == 0)
					exit(0);
			}
			break;
			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		case 23:
			score++;
			system("color 40");
			cout << "____________________________________________________" << endl;
			Beep(700, 500);
			Beep(700, 500);
			Beep(700, 500);
			cout << "You find yourself face to a mirror..." << endl;
			cout << "It shows your worst nightmare(s) and bring them to life" << endl;
			system("pause");
			cout << "You die from a heart attack" << endl;
			health = 0;
			system("pause");
			tryagain();

			break;

		case 24:
			system("color 3f");
			score++;
			cout << "____________________________________________________" << endl;
			cout << "You are faced in front of a great animal known as the sphinx" << endl;
			system("pause");
			cout << "____________________________________________________" << endl;
			cout << "It speaks..." << endl;
			cout << "'You have come for the richest behind me " << name << "?" << endl;
			system("pause");
			cout << "____________________________________________________" << endl;
			cout << "You responded with," << endl;
			cout << "'Yes I have! Now let me pass!" << endl;
			system("pause");
			cout << "____________________________________________________" << endl;
			cout << "'You must first answer a riddle." << endl;
			cout << "If you answer correctly you may pass." << endl;
			cout << "Beware, whatever you say next is your answer'" << endl;
			system("pause");
			cout << "____________________________________________________" << endl;
			cout << "It walks on four legs in the morning," << endl;
			cout << "two legs at noon and three legs in the evening." << endl;
			cout << "What is it?" << endl;
			getline(cin, input);

			if (input.compare("Man") == 0 || input.compare("man") == 0) {
				cout << "Correct!" << endl;
				room = 32;
			}
			else {
				cout << "Wrong!" << endl;
				health = 0;
				system("pause");
				tryagain();
			}

			break;

		case 25:
			score++;
			system("color e0");
			cout << "____________________________________________________" << endl;
			cout << "You're at the end of the Cave!!!! You find Gold!!!" << endl;
			cout << "this is exactly the amount of money you need to be free of you master!" << endl;
			cout << "You need to pick up all this gold!" << endl;
			system("pause");
			cout << "Now you need to find your way out of the cave!" << endl;
			cout << "You can head East" << endl;
			getline(cin, input);

			if (input.compare("East") == 0 || input.compare("east") == 0) {
				room = 32;
			}

			else if (input.compare("Quit") == 0 || input.compare("quit") == 0)
				exit(0);
			else if (input.compare("Drink Red Bull Can") == 0 || input.compare("drink red bull can") == 0) {
				if (inventory[2] == "Red Bull Can") {
					health = health + 60;
					cout << "You're health is now " << health << endl;
					inventory[2] = "Empty Red Bull Can";
				}
				else if (inventory[1] == "empty" || inventory[1] == "Empty Red Bull Can")
					cout << "You have nothing to drink" << endl;
			}
			else if (input.compare("Pick Up") == 0 || input.compare("pick up") == 0) {
				cout << "Gold has been added your inventory" << endl;
				room = 33;
				inventory[6] = "Gold";
			}
			else if (input.compare("Drink Water Bottle") == 0 || input.compare("drink water bottle") == 0) {
				if (inventory[1] == "Water Bottle") {
					health = health + 25;
					cout << "You're health is now " << health << endl;
					inventory[1] = "Empty Water Bottle";
				}
				else if (inventory[1] == "empty" || inventory[1] == "Empty Water Bottle")
					cout << "You have nothing to drink" << endl;
			}
			else if (input.compare("Health") == 0 || input.compare("health") == 0)
				cout << "You're health is " << health << endl;
			else if (input.compare("Bag") == 0 || input.compare("bag") == 0) {
				cout << "Here's your inventory" << endl;
				for (int i = 0; i < 7; i++)
					cout << inventory[i] << endl;
			}
			else
				cout << "Invalid Input" << endl;

			break;

		case 26:
			score++;
			system("color f4");
			cout << "____________________________________________________" << endl;
			cout << "You are in the beginning of the cave" << endl;
			cout << "You're in a hallway of the cave" << endl;
			cout << "There are scratch marks on the side of the walls of the cave" << endl;
			cout << "You hear sounds if front on you" << endl;
			cout << "You can go North or South" << endl;

			getline(cin, input);

			if (input.compare("North") == 0 || input.compare("north") == 0)
				room = 3;
			else if (input.compare("South") == 0 || input.compare("south") == 0)
				room = 22;
			else if (input.compare("Yes") == 0 || input.compare("yes") == 0)
				room = 1;
			else if (input.compare("Quit") == 0 || input.compare("quit") == 0)
				exit(0);
			else if (input.compare("Drink Red Bull Can") == 0 || input.compare("drink red bull can") == 0) {
				if (inventory[2] == "Red Bull Can") {
					health = health + 60;
					cout << "You're health is now " << health << endl;
					inventory[2] = "Empty Red Bull Can";
				}
				else if (inventory[1] == "empty" || inventory[1] == "Empty Red Bull Can")
					cout << "You have nothing to drink" << endl;
			}
			else if (input.compare("Health") == 0 || input.compare("health") == 0)
				cout << "You're health is " << health << endl;
			else if (input.compare("Drink Water Bottle") == 0 || input.compare("drink water bottle") == 0) {
				if (inventory[1] == "Water Bottle") {
					health = health + 25;
					cout << "You're health is now " << health << endl;
					inventory[1] = "Empty Water Bottle";
				}
				else if (inventory[1] == "empty")
					cout << "You have nothing to drink" << endl;
			}
			else if (input.compare("Bag") == 0 || input.compare("bag") == 0) {
				cout << "Here's your inventory" << endl;
				for (int i = 0; i < 7; i++)
					cout << inventory[i] << endl;
			}
			else
				cout << "Invalid Input" << endl;

			break;

		case 27:
			score++;
			system("color 3f");
			cout << "____________________________________________________" << endl;
			cout << "You come to a corner of the the cave" << endl;
			cout << "You see a wall that has the words 'The sword only come to those who are in trouble' written on it" << endl;
			cout << "You can go South or West" << endl;
			getline(cin, input);

			if (input.compare("South") == 0 || input.compare("south") == 0)
				room = 3;
			else if (input.compare("West") == 0 || input.compare("west") == 0)
				room = 5;
			else if (input.compare("Quit") == 0 || input.compare("quit") == 0)
				exit(0);
			else if (input.compare("Drink Water Bottle") == 0 || input.compare("drink water bottle") == 0) {
				if (inventory[1] == "Water Bottle") {
					health = health + 25;
					cout << "You're health is now " << health << endl;
					inventory[1] = "Empty Water Bottle";
				}
				else if (inventory[1] == "empty" || inventory[1] == "Empty Water Bottle")
					cout << "You have nothing to drink" << endl;
			}
			else if (input.compare("Drink Red Bull Can") == 0 || input.compare("drink red bull can") == 0) {
				if (inventory[2] == "Red Bull Can") {
					health = health + 60;
					cout << "You're health is now " << health << endl;
					inventory[2] = "Empty Red Bull Can";
				}
				else if (inventory[1] == "empty" || inventory[1] == "Empty Red Bull Can")
					cout << "You have nothing to drink" << endl;
			}
			else if (input.compare("Health") == 0 || input.compare("health") == 0)
				cout << "You're health is " << health << endl;
			else if (input.compare("Bag") == 0 || input.compare("bag") == 0) {
				cout << "Here's your inventory" << endl;
				for (int i = 0; i < 7; i++)
					cout << inventory[i] << endl;
			}
			else
				cout << "Invalid Input" << endl;

			break;

		case 28:
			score++;
			system("color b0");
			cout << "____________________________________________________" << endl;
			cout << "A rock stands before you with a hole in it" << endl;
			cout << "You can head North, South, or East" << endl;
			getline(cin, input);

			if (input.compare("North") == 0 || input.compare("north") == 0)
				room = 8;
			else if (input.compare("South") == 0 || input.compare("south") == 0)
				room = 7;
			else if (input.compare("East") == 0 || input.compare("east") == 0)
				room = 5;
			else if (input.compare("Quit") == 0 || input.compare("quit") == 0)
				exit(0);
			else if (input.compare("Drink Red Bull Can") == 0 || input.compare("drink red bull can") == 0) {
				if (inventory[2] == "Red Bull Can") {
					health = health + 60;
					cout << "You're health is now " << health << endl;
					inventory[2] = "Empty Red Bull Can";
				}
				else if (inventory[1] == "empty" || inventory[1] == "Empty Red Bull Can")
					cout << "You have nothing to drink" << endl;
			}
			else if (input.compare("Drink Water Bottle") == 0 || input.compare("drink water bottle") == 0) {
				if (inventory[1] == "Water Bottle") {
					health = health + 25;
					cout << "You're health is now " << health << endl;
					inventory[1] = "Empty Water Bottle";
				}
				else if (inventory[1] == "empty" || inventory[1] == "Empty Water Bottle")
					cout << "You have nothing to drink" << endl;
			}
			else if (input.compare("Health") == 0 || input.compare("health") == 0)
				cout << "You're health is " << health << endl;
			else if (input.compare("Bag") == 0 || input.compare("bag") == 0) {
				cout << "Here's your inventory" << endl;
				for (int i = 0; i < 7; i++)
					cout << inventory[i] << endl;
			}
			else
				cout << "Invalid Input" << endl;

			break;

		case 29:
			score++;
			system("color f4");
			cout << "____________________________________________________" << endl;
			cout << "You go toward the voices" << endl;
			cout << "There are a lot of scratches on the floor and on the sides of the walls" << endl;
			cout << "You can head West or East" << endl;
			getline(cin, input);

			if (input.compare("West") == 0 || input.compare("west") == 0)
				room = 3;
			else if (input.compare("East") == 0 || input.compare("east") == 0)
				room = 10;
			else if (input.compare("Quit") == 0 || input.compare("quit") == 0)
				exit(0);
			else if (input.compare("Drink Red Bull Can") == 0 || input.compare("drink red bull can") == 0) {
				if (inventory[2] == "Red Bull Can") {
					health = health + 60;
					cout << "You're health is now " << health << endl;
					inventory[2] = "Empty Red Bull Can";
				}
				else if (inventory[1] == "empty" || inventory[1] == "Empty Red Bull Can")
					cout << "You have nothing to drink" << endl;
			}
			else if (input.compare("Drink Water Bottle") == 0 || input.compare("drink water bottle") == 0) {
				if (inventory[1] == "Water Bottle") {
					health = health + 25;
					cout << "You're health is now " << health << endl;
					inventory[1] = "Empty Water Bottle";
				}
				else if (inventory[1] == "empty" || inventory[1] == "Empty Water Bottle")
					cout << "You have nothing to drink" << endl;
			}
			else if (input.compare("Health") == 0 || input.compare("health") == 0)
				cout << "You're health is " << health << endl;
			else if (input.compare("Bag") == 0 || input.compare("bag") == 0) {
				cout << "Here's your inventory" << endl;
				for (int i = 0; i < 7; i++)
					cout << inventory[i] << endl;
			}
			else
				cout << "Invalid Input" << endl;

			break;

		case 30:
			score++;
			system("color e0");
			cout << "____________________________________________________" << endl;
			cout << "you have the key to open the locked door!" << endl;
			cout << "Better keep the key just in case It locks again" << endl;
			cout << "You can head North or South" << endl;
			getline(cin, input);

			if (input.compare("North") == 0 || input.compare("north") == 0)
				room = 14;
			else if (input.compare("South") == 0 || input.compare("south") == 0)
				room = 10;
			else if (input.compare("Quit") == 0 || input.compare("quit") == 0)
				exit(0);
			else if (input.compare("Drink Red Bull Can") == 0 || input.compare("drink red bull can") == 0) {
				if (inventory[2] == "Red Bull Can") {
					health = health + 60;
					cout << "You're health is now " << health << endl;
					inventory[2] = "Empty Red Bull Can";
				}
				else if (inventory[1] == "empty" || inventory[1] == "Empty Red Bull Can")
					cout << "You have nothing to drink" << endl;
			}
			else if (input.compare("Drink Water Bottle") == 0 || input.compare("drink water bottle") == 0) {
				if (inventory[1] == "Water Bottle") {
					health = health + 25;
					cout << "You're health is now " << health << endl;
					inventory[1] = "Empty Water Bottle";
				}
				else if (inventory[1] == "empty" || inventory[1] == "Empty Water Bottle")
					cout << "You have nothing to drink" << endl;
			}
			else if (input.compare("Health") == 0 || input.compare("health") == 0)
				cout << "You're health is " << health << endl;
			else if (input.compare("Bag") == 0 || input.compare("bag") == 0) {
				cout << "Here's your inventory" << endl;
				for (int i = 0; i < 7; i++)
					cout << inventory[i] << endl;
			}
			else
				cout << "Invalid Input" << endl;

			break;

		case 31:
			score++;
			system("color e0");
			cout << "____________________________________________________" << endl;
			cout << "The voices of a person talking get's louder!" << endl;
			cout << "There are skulls on the floor now...." << endl;
			cout << "There is also a sign next to one of the skulls that says," << endl;
			cout << "Beware...for the riddler...." << endl;
			cout << "You can go North or South" << endl;
			getline(cin, input);

			if (input.compare("North") == 0 || input.compare("north") == 0)
				room = 20;
			else if (input.compare("South") == 0 || input.compare("south") == 0)
				room = 15;
			else if (input.compare("Quit") == 0 || input.compare("quit") == 0)
				exit(0);
			else if (input.compare("Drink Red Bull Can") == 0 || input.compare("drink red bull can") == 0) {
				if (inventory[2] == "Red Bull Can") {
					health = health + 60;
					cout << "You're health is now " << health << endl;
					inventory[2] = "Empty Red Bull Can";
				}
				else if (inventory[1] == "empty" || inventory[1] == "Empty Red Bull Can")
					cout << "You have nothing to drink" << endl;
			}
			else if (input.compare("Drink Water Bottle") == 0 || input.compare("drink water bottle") == 0) {
				if (inventory[1] == "Water Bottle") {
					health = health + 25;
					cout << "You're health is now " << health << endl;
					inventory[1] = "Empty Water Bottle";
				}
				else if (inventory[1] == "empty" || inventory[1] == "Empty Water Bottle")
					cout << "You have nothing to drink" << endl;
			}
			else if (input.compare("Health") == 0 || input.compare("health") == 0)
				cout << "You're health is " << health << endl;
			else if (input.compare("bag") == 0 || input.compare("bag") == 0) {
				cout << "Here's your inventory" << endl;
				for (int i = 0; i < 7; i++)
					cout << inventory[i] << endl;
			}
			else
				cout << "Invalid Input" << endl;

			break;

		case 32:
			score++;
			system("color 3f");
			cout << "____________________________________________________" << endl;

			if (inventory[6] == "Gold") {
				cout << "The sphinx in chilling in the corner, while making loud noises" << endl;
			}
			else {
				cout << "The sphinx lest you pass" << endl;
				cout << "You see something shiny but the sphinx is kinda in your way. LOL. " << endl;
				cout << "Could it be?..." << endl;
			}
			cout << "You can head West or East" << endl;
			getline(cin, input);

			if (input.compare("West") == 0 || input.compare("west") == 0) {
				if (inventory[6] == "Gold")
					room = 33;
				else
					room = 25;
			}
			else if (input.compare("East") == 0 || input.compare("east") == 0)
				room = 21;
			else if (input.compare("Quit") == 0 || input.compare("quit") == 0)
				exit(0);
			else if (input.compare("Drink Red Bull Can") == 0 || input.compare("drink red bull can") == 0) {
				if (inventory[2] == "Red Bull Can") {
					health = health + 60;
					cout << "You're health is now " << health << endl;
					inventory[2] = "Empty Red Bull Can";
				}
				else if (inventory[1] == "empty" || inventory[1] == "Empty Red Bull Can")
					cout << "You have nothing to drink" << endl;
			}
			else if (input.compare("Drink Water Bottle") == 0 || input.compare("drink water bottle") == 0) {
				if (inventory[1] == "Water Bottle") {
					health = health + 25;
					cout << "You're health is now " << health << endl;
					inventory[1] = "Empty Water Bottle";
				}
				else if (inventory[1] == "empty" || inventory[1] == "Empty Water Bottle")
					cout << "You have nothing to drink" << endl;
			}
			else if (input.compare("Health") == 0 || input.compare("health") == 0)
				cout << "You're health is " << health << endl;
			else if (input.compare("Bag") == 0 || input.compare("bag") == 0) {
				cout << "Here's your inventory" << endl;
				for (int i = 0; i < 7; i++)
					cout << inventory[i] << endl;
			}
			else
				cout << "Invalid Input" << endl;

			break;

		case 33:
			score++;
			system("color e0");
			cout << "____________________________________________________" << endl;
			cout << "You need to get out of the cave now!" << endl;
			cout << "You can head East" << endl;
			getline(cin, input);
			if (input.compare("East") == 0 || input.compare("east") == 0)
				room = 32;
			else if (input.compare("Quit") == 0 || input.compare("quit") == 0)
				exit(0);
			else if (input.compare("Drink Red Bull Can") == 0 || input.compare("drink red bull can") == 0) {
				if (inventory[2] == "Red Bull Can") {
					health = health + 60;
					cout << "You're health is now " << health << endl;
					inventory[2] = "Empty Red Bull Can";
				}
				else if (inventory[1] == "empty" || inventory[1] == "Empty Red Bull Can")
					cout << "You have nothing to drink" << endl;
			}
			else if (input.compare("Drink Water Bottle") == 0 || input.compare("drink water bottle") == 0) {
				if (inventory[1] == "Water Bottle") {
					health = health + 25;
					cout << "You're health is now " << health << endl;
					inventory[1] = "Empty Water Bottle";
				}
				else if (inventory[1] == "empty" || inventory[1] == "Empty Water Bottle")
					cout << "You have nothing to drink" << endl;
			}
			else if (input.compare("Health") == 0 || input.compare("health") == 0)
				cout << "You're health is " << health << endl;
			else if (input.compare("Bag") == 0 || input.compare("bag") == 0) {
				cout << "Here's your inventory" << endl;
				for (int i = 0; i < 7; i++)
					cout << inventory[i] << endl;
			}
			else
				cout << "Invalid Input" << endl;

			break;
		case 34:
			for (int i = 0; i < 5; i++) {
				if (Highscore[i] >= score) {
					score = Highscore[i];
				}
			}
			room = 0;
			break;




		}
	}
}


void monster() {
	int number = rand() % 100 + 1;

	if (number <= 10) {
		cout << "A Pegasus appeared to give you a +15 health" << endl;
		health = health + 15;
		cout << "Your health is now " << health << endl;
	}
	else if (number > 10 && number <= 15) {
		cout << "You've encounter a rare Unicorn that gives you +25 health" << endl;
		health = health + 25;
		cout << "Your health is now " << health << endl;
	}
	else if (number > 16 && number <= 19) {
		cout << "You've encounter a Dragon!" << endl;
		health = health - 90;
		cout << "Your health is now " << health << endl;
	}
	else if (number > 20 && number <= 29) {
		cout << "Harambe's Spirit has risen from the ground to give you life" << endl;
		health = health + 10;
		cout << "Your health is now " << health << endl;
	}
	else if (number > 20 && number <= 43) {
		cout << "A small dark fairy has attacked you from nowhere" << endl;
		health = health - 20;
		cout << "Your health is now " << health << endl;
	}
	else if (number > 44 && number <= 67) {
		cout << "A group of gnomes attacked you from nowhere" << endl;
		health = health - 30;
		cout << "Your health is now " << health << endl;
	}
	else if (number > 68 && number <= 83) {
		cout << "A werewolf appears and is sooooo hungry it attacks you" << endl;
		cout << "You run away " << endl;
		health = health - 40;
		cout << "Your health is now " << health << endl;
	}
	else {
		cout << "A Dino appears and says,'RAWR XD'" << endl;
		cout << "ughhh damaged by the cuteness" << endl;
		health = health - 15;
		cout << "Your health is now " << health << endl;
	}
}

void tryagain() {
	if (health == 0) {
		Beep(750, 50);
		Beep(750, 50);
		Beep(750, 50);
		system("color 40");
		cout << "You have no more life left" << endl;
		system("pause");
	}
	else if (health <= -1) {
		system("color 40");
		Beep(750, 50);
		Beep(750, 50);
		Beep(750, 50);
		Beep(750, 50);
		cout << "FATALITY" << endl;
		cout << "You have suffered a gruesome death" << endl;
		system("pause");
	}
	cout << "____________________________________________________" << endl;
	cout << "Good Game" << endl;
	cout << "Try Again? Yes or No?" << endl;

	getline(cin, answer);

	if (answer.compare("Yes") == 0 || input.compare("yes") == 0) {

		room = 0;

	}
	else if (answer.compare("No") == 0 || input.compare("no") == 0) {
		system("pause");
		exit(0);
	}
	else if (answer.compare("quit") == 0 || input.compare("quit") == 0)
		exit(0);

}

void healroom() {
	if (health <= 25) {
		health = health + 100;
		cout << "You gain a lot of health" << endl;
		cout << "your health is now " << health << endl;
	}
	else if (health >= 26 && health <= 50) {
		cout << "You only gain some health" << endl;
		health = health + 25;
		cout << "your health is now " << health << endl;
	}
	else {
		cout << "I only give health to those who need it" << endl;
		cout << "your health is still " << health << endl;
	}
}