#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
	int Num;
	string line;
	string input;
	string str(input);
		cout << "";
		cout << "What do you want to translate?" << endl;
		getline(cin, str);
		cout << endl; 
		ofstream Bob;
		Bob.open("Prob01.in.txt");
		Bob << str;
		Bob << endl;


		for (int i = 0; i < str.length(); i++) {
			if (str.at(i) == 'A' || str.at(i) == 'a') {
				/*cout << "Alfa"; cout << "-";*/
				Bob << "Alfa-";
			}
			else if (str.at(i) == 'B' || str.at(i) == 'b') {
				/*cout << "Beta"; cout << "-";*/
				Bob << "Beta-";
			}
			else if (str.at(i) == 'C' || str.at(i) == 'c') {
				/*cout << "Charlie"; cout << "-";*/
				Bob << "Charlie-";
			}
			else if (str.at(i) == 'D' || str.at(i) == 'd') {
				/*cout << "Delta"; cout << "-";*/
				Bob << "Delta-";
			}
			else if (str.at(i) == 'E' || str.at(i) == 'e') {
				/*cout << "Echo"; cout << "-";*/
				Bob << "Echo-";
			}
			else if (str.at(i) == 'F' || str.at(i) == 'f') {
				/*cout << "Foxtrot";  cout << "-";*/
				Bob << "Foxtrot-";
			}
			else if (str.at(i) == 'G' || str.at(i) == 'g') {
				/*cout << "Golf"; cout << "-";*/
				Bob << "Golf-";
			}
			else if (str.at(i) == 'H' || str.at(i) == 'h') {
				/*cout << "Hotel"; cout << "-";*/
				Bob << "Hotel-";
			}
			else if (str.at(i) == 'I' || str.at(i) == 'i') {
				/*cout << "India"; cout << "-";*/
				Bob << "India-";
			}
			else if (str.at(i) == 'J' || str.at(i) == 'j') {
				/*cout << "Juliet"; cout << "-";*/
				Bob << "Juliet";
			}
			else if (str.at(i) == 'K' || str.at(i) == 'k') {
				/*cout << "Kilo"; cout << "-";*/
				Bob << "Kilo";
			}
			else if (str.at(i) == 'L' || str.at(i) == 'l') {
				/*cout << "Lima"; cout << "-";*/
				Bob << "Lima-";
			}
			else if (str.at(i) == 'M' || str.at(i) == 'm') {
				/*cout << "Mike"; cout << "-";*/
				Bob << "Mike-";
			}
			else if (str.at(i) == 'N' || str.at(i) == 'n') {
				/*cout << "November"; cout << "-";*/
				Bob << "November-";
			}
			else if (str.at(i) == 'O' || str.at(i) == 'o') {
				/*cout << "Oscar"; cout << "-";*/
				Bob << "Oscar-";
			}
			else if (str.at(i) == 'P' || str.at(i) == 'p') {
				/*cout << "Papa"; cout << "-";*/
				Bob << "Papa";
			}
			else if (str.at(i) == 'Q' || str.at(i) == 'q') {
				/*cout << "Quebec"; cout << "-";*/
				Bob << "Quebec-";
			}
			else if (str.at(i) == 'R' || str.at(i) == 'r') {
				/*cout << "Romeo"; cout << "-";*/
				Bob << "Romeo-";
			}
			else if (str.at(i) == 'S' || str.at(i) == 's') {
				/*cout << "Sierra"; cout << "-";*/
				Bob << "Sierra-";
			}
			else if (str.at(i) == 'T' || str.at(i) == 't') {
				/*cout << "Tango"; cout << "-";*/
				Bob << "Tango-";
			}
			else if (str.at(i) == 'U' || str.at(i) == 'u') {
				/*cout << "Uniform"; cout << "-";*/
				Bob << "Uniform-";
			}
			else if (str.at(i) == 'V' || str.at(i) == 'v') {
				/*cout << "Victor"; cout << "-";*/
				Bob << "Victor-";
			}
			else if (str.at(i) == 'W' || str.at(i) == 'w') {
				/*cout << "Whiskey"; cout << "-";*/
				Bob << "Whiskey-";
			}
			else if (str.at(i) == 'X' || str.at(i) == 'x') {
				/*cout << "Xray"; cout << "-";*/
				Bob << "Xray-";
			}
			else if (str.at(i) == 'Y' || str.at(i) == 'y') {
				/*cout << "Yankee"; cout << "-";*/
				Bob << "Yankee-";
			}
			else if (str.at(i) == 'Z' || str.at(i) == 'z') {
				/*cout << "Zulu"; cout << "-";*/
				Bob << "Zulu-";
			}
			else if (str.at(i) == ' ') {
				/*cout << endl;*/
				Bob << endl;;
			}
			//cout << "-";
			
		}
		Bob.close();
			ifstream Bob1("Prob01.in.txt");
			while (getline(Bob1, line)) {
					cout << line << endl;
			}
				Bob1.close();

		cout << endl;
	
	return 0;
}