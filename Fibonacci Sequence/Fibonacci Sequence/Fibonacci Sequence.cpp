// Fibonacci sequence
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string line;
unsigned long long input;
unsigned long long i;
unsigned long long Num = 0;
unsigned long long Sum;
unsigned long long First = 0;
unsigned long long Second = 1;
unsigned long long Specfic = 1;
int Term;

int main() {
	cout << "what term in the squence do you want?" << endl;
	cin >> Term;
	ofstream Bob;
	Bob.open("Prob01.in.txt");
	for (int i = 0; i < Term; i++) {
		if (i <= 1) {
			Sum = i;
			
		}
		else {
			Sum = First + Second;
			First = Second;
			Second = Sum;
			
		}
		
		Bob << Specfic << " = " << Sum << endl;
		Specfic++;
	}
	Bob.close();

	cout << Term << " = " << Sum << endl;
	
}