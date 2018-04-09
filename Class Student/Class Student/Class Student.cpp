//Advanced: Write class Student.Class Student has 4 variables : 
//ID#, age, Gender, and LastName, 
//and two functions: 
//init and print.Instantiate 4 - 5 students and push them into a vector.
//Use a for loop to print the information for each student.
#include<iostream>
#include<vector>
#include<string>
#include <ctime>

using namespace std;

int InfoAge();
string InfoGender();
string Name();


class Students {
private:
	int IDNumber;
	int Age;
	string Gender;
	string LastName;
public:
	void InitStudent(int IDN, int A, string G, string LN);
	void PrintInfo();

};

int main() {
	srand(time(NULL));

	Students Tj;
	Students Tre;
	Students Ferny;

	vector<Students> Class;
	vector<Students>::iterator iter;



	Class.push_back(Tj);
	Class.push_back(Tre);
	Class.push_back(Ferny);

	for (iter = Class.begin(); iter != Class.end(); iter++) {
		iter->InitStudent(rand(), InfoAge(), InfoGender(), Name());
	}


	for (iter = Class.begin(); iter != Class.end(); iter++) {
		iter->PrintInfo();//member selection
	}
	system("pause");


}

void Students::InitStudent(int IDN, int A, string G, string LN) {
	IDNumber = IDN;
	Age = A;
	Gender = G;
	LastName = LN;
}

void Students::PrintInfo() {
	cout << "Your Student Last Name " << LastName << endl;
	cout << "ID Number is " << IDNumber << endl;
	cout << "THeir Gender is " << Gender << endl;
	cout << "With the age of " << Age << endl;
	cout << endl;
}
int InfoAge() {
	int Num1 = rand() % 100 + 1;
	return Num1;

}
string InfoGender() {
	string Gender[2] = { "Male","Female", };
	int Num2 = rand() % 2;
	return Gender[Num2];
}
string name() {
	string LastName[20] = { "Jesus","Tj","Water","Wall","Time","Sky","Phone","Wolf","Baby","Turtle","Star","Moon","Jump","Dogg","Cube","Square","Lighting","Mr.Fluffers","roots","Fire" };
	int num3 = rand() % 20;;
	return LastName[num3];
}