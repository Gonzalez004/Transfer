#include<iostream>
#include<stdlib.h>
#include<string>
#include <ctime>
using namespace std;

string CountDown1();
int StopV1; 
int Adding1;
//string CountDown2();	
//int StopV2; 
//int Adding2;
//string CountDown3();
//string CountDown4();
//string CountDown5();
//string CountDown6();
//string CountDown7();
//string CountDown8();
//string CountDown9();
//string CountDown10();
int main() {
	srand(time(NULL));
	StopV1 = rand() % 35;
	StopV2 = rand() % 35;
	
	/*int StopV3;
	int Adding3;
	int StopV4; 
	int Adding4;
	int StopV5;
	int Adding5; 
	int StopV6; 
	int Adding6;
	int StopV7;
	int Adding7; 
	int StopV8;
	int Adding8;
	int StopV9; 
	int Adding9;
	int StopV10; 
	int Adding10;*/
	
	/*StopV3 = rand() % 35;
	StopV4 = rand() % 35;
	StopV5 = rand() % 35;
	StopV6 = rand() % 35;
	StopV7 = rand() % 35;
	StopV8 = rand() % 35; 
	StopV9 = rand() % 35;
	StopV10 = rand() % 35;*/

	while(Adding1 <= StopV1) {
		system("CLS");
		cout << CountDown1() << endl;
		Adding1++;
	}

	return 0;
}
string CountDown1() {
	string Chara1[35] = { "A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z","1","2","3","4","5","6","7","8","9"};
	int num1 = rand() % 35;
	return Chara1[num1];
}
//string CountDown2() {
//	string Chara2[35] = { "A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z","1","2","3","4","5","6","7","8","9" };
//	int num2 = rand() % 35;
//	return Chara2[num2];
//}
//string CountDown3() {
//	string Chara3[35] = { "A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z","1","2","3","4","5","6","7","8","9" };
//	int num3 = rand() % 35;
//	return Chara3[num3];
//}
//string CountDown4() {
//	string Chara4[35] = { "A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z","1","2","3","4","5","6","7","8","9" };
//	int num4 = rand() % 35;
//	return Chara4[num4];
//}
//string CountDown5() {
//	string Chara5[35] = { "A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z","1","2","3","4","5","6","7","8","9" };
//	int num5 = rand() % 35;
//	return Chara5[num5];
//}
//string CountDown6() {
//	string Chara6[35] = { "A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z","1","2","3","4","5","6","7","8","9" };
//	int num6 = rand() % 35;
//	return Chara6[num6];
//}
//string CountDown7() {
//	string Chara7[35] = { "A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z","1","2","3","4","5","6","7","8","9" };
//	int num7 = rand() % 35;
//	return Chara7[num7];
//}
//string CountDown8() {
//	string Chara8[35] = { "A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z","1","2","3","4","5","6","7","8","9" };
//	int num8 = rand() % 35;
//	return Chara8[num8];
//}
//string CountDown9() {
//	string Chara9[35] = { "A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z","1","2","3","4","5","6","7","8","9" };
//	int num9 = rand() % 35;
//	return Chara9[num9];
//}
//string CountDown10() {
//	string Chara10[35] = { "A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z","1","2","3","4","5","6","7","8","9" };
//	int num10 = rand() % 35;
//	return Chara10[num10];
//}