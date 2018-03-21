#include<iostream>
#include<vector>
#include<string>
#include <ctime>
using namespace std;

string name();



class yugioh {
private:
	int attack;
	int defence;
	int level;
	string name;
public:
	void InitCard(int a, int d, int l, string n);
	void printInfo();

};

int main() {

	srand(time(NULL));
	yugioh poland;
	yugioh paxton;
	yugioh potato;

	vector<yugioh> myDeck;
	vector<yugioh>::iterator iter;



	myDeck.push_back(poland);
	myDeck.push_back(paxton);
	myDeck.push_back(potato);

	for (iter = myDeck.begin(); iter != myDeck.end(); iter++) {
		iter->InitCard(rand(), rand(), rand(), name());
	}


	for (iter = myDeck.begin(); iter != myDeck.end(); iter++) {
		iter->printInfo();//member selection
	}
	system("pause");


}

void yugioh::InitCard(int a, int d, int l, string n) {
	attack = a;
	defence = d;
	level = l;
	name = n;
}

void yugioh::printInfo() {
	cout << "card is " << name << endl;
	cout << "stats are " << attack << " , " << defence << " , " << level << endl;
}



string name() {
	string input;
	string RapperFirstName[20] = { "Young","Lil","Notorious","Snoop","50","Thug","Dj","Big","Killa","Weast","SuperHot","Master","Kid","Wild","Slick","Heavy","Fresh","MC","Rapper","Doctor" };
	string RapperLastName[20] = { "Jesus","Tj","Water","Wall","Time","Sky","Phone","Wolf","Baby","Turtle","Star","Moon","Jump","Dogg","Cube","Square","Lighting","Mr.Fluffers","roots","Fire" };
	int num1 = rand() % 20;
	int num2 = rand() % 20;
	return RapperFirstName[num1] + RapperLastName[num2];


}