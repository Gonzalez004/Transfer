#include<iostream>
using namespace std;
void swapThemByVal(int num1, int num2);
void swapThemByRef(int& num1, int& num2);

int main() {
	int i = 10, j = 20;
	swapThemByVal(i, j);
	cout << i << "  " << j << endl;     // displays 10  20
	swapThemByRef(i, j);
	cout << i << "  " << j << endl;     // displays 20  10
	system("pause");
}

void swapThemByVal(int num1, int num2) {
	int temp = num1;
	num1 = num2;
	num2 = temp;
}

void swapThemByRef(int& num1, int& num2) {
	int temp = num1;
	num1 = num2;
	num2 = temp;
}