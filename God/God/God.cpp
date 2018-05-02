#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

int main() {

void print_menu();
void religion(int r);
double celsius(double c);
char Command = 'A';
int input;
print_menu();

	while (true) {
		cout << "Command: ";
		cin >> Command;
		switch (Command) {
		case 'T': case 't':
			cout << "Fahrenheit: ";
				cin >> input;
				celsius(input);
			break;
		case 'R': case 'r':
			cout << "Which religion? ";
			cin >> input;
			religion(input);
			break;
		default:
			cout << "Invalid command" << endl;
			break;
		} //Switch
	} // While
	return 0;
} // Main
void print_menu() {
	cout << "q: quit" << endl;
	cout << "h: help" << endl;
	cout << "r: info about a religion" << endl;
	cout << "t: temperature conversion" << endl;
}
void religion(int r) {
	switch (r) {
	case 1:
			cout << "Christianity:	31.2%" << endl;
			break;
	case 2:
			cout << "Islam:	24.1%" << endl;
			break;
	case 3:
			cout << "Secular/Nonreligious/Agnostic/Atheist:	16%" << endl;
			break;
	case 4:
			cout << "Hinduism:	15.1%" << endl;
			break;
	case 5:
			cout << "Buddhism:	6.9%" << endl;
			break;
	case 6:
			cout << "Chinese traditional religion:	5.50%" << endl;
			break;
	case 7:
			cout << "Ethnic religions:	4.19%" << endl;
			break;
	case 8:
			cout << "African traditional religions:	1.40%" << endl;
			break;
	case 9:
			cout << "Sikhism: 0.32%" << endl;
			break;
	case 10:
			cout << "Spiritism: 0.21%" << endl;
			break;
	default:
		cout << "Don't know anything about religion #" << r << endl;
		break;
	}
}
double celsius(double c) {
	double NewTemp = (c - 32) * 5 / 9;
	//65.500000 Fahrenheit is 18.611111 Celsius
	cout << c << " Fahrenheit is " << NewTemp << " Celsius" << endl;
	return 0;
}