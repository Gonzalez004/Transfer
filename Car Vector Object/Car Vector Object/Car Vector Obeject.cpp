#include<iostream>
#include<vector>
#include<string>
#include <ctime>
using namespace std;

int Fuel();
string Name();
string Paint();
string WheelDrive();

class Car {
private:
	int FuelAmount;
	string Color;
	string TypeDrive;
	string Brand;
public:
	void InitCar(int FA, string C, string TD, string B);
	void PrintInfo();
};

int main() {

	srand(time(NULL));
	Car C1;
	Car C2;
	Car C3;

	vector<Car> MyCar;
	vector<Car>::iterator iter;

	MyCar.push_back(C1);
	MyCar.push_back(C2);
	MyCar.push_back(C3);
	while (true) {
		for (iter = MyCar.begin(); iter != MyCar.end(); iter++) {
			iter->InitCar(Fuel(), Paint(), WheelDrive(), Name());
		}
		for (iter = MyCar.begin(); iter != MyCar.end(); iter++) {
			iter->PrintInfo();
			cout << endl;
		}
		system("pause");
	}
}
void Car::InitCar(int FA, string C, string TD, string B) {
	FuelAmount = FA;
	Color = C;
	TypeDrive = TD;
	Brand = B;
}
void Car::PrintInfo() {
	cout << "Your car is " << Brand << endl;
	cout << "Your " << Brand << " FuelAmount is " << FuelAmount << " gallon" << endl;
	cout << "The color is " << Color << endl;
	cout << "The type of drive is " << TypeDrive << endl;
}
string Name() {
	string CarName[20] = { "Chevy","Alfo Romero","Land Rover","Kia","Ford","BMW","Mahindra","Toyota","Porche","Audi","Volkswagen","Lamborghini","Cadillac","Nissan","Bugatti","Mercades","GMC","Ferrari","Fiat","Hyundai" };
	int Num = rand() % 20;
	return CarName[Num];
}
int Fuel() {
	int Num1 = rand() % 10 + 10;
	return Num1;
}
string Paint() {
	string P[3] = { "Red", "Blue", "Green" };
	int Num2 = rand() % 3;
	return P[Num2];

}
string WheelDrive() {
	string WD[3] = { "All-Wheel Drive", "Rear Wheel Drive", "Front Wheel Drive" };
	int Num3 = rand() % 3;
	return WD[Num3];
}