#include<iostream>

using namespace std;

int Factorial(const int factorial);

int Power(const int number, const int power);

int main()
{
	//system("chcp 65001");
	setlocale(LC_ALL, "");

	//int factor = 5;
	//cout << "Факториал числа " << factor << " равен: " << Factorial(factor) << endl << endl;

	//int number, power;
	//cout << "Введите целое число, которое хотите возвести в степень: ";
	//cin >> number;
	//cout << "В какую степень хотите возвести - введите число: ";
	//cin >> power;
	//cout << endl << "Число " << number << " в степени " << power << " будет - " << Power(number, power) << endl;

	//---------------------------------------------------------------------------------------------------------------

	int counter = 0;
	for (int i = 32; i <= 127; i++)
	{
		if (i % 16 == 0) cout << endl;
		cout << (char)i << " ";
	}


}

int Factorial(const int factorial)
{
	int total = 1;
	for (int i = 1; i <= factorial; i++)
	{
		total *= i;
	}
	return total;
}

int Power(const int number, const int power)
{
	int product = number;
	for (int i = 0; i < power - 1; i++)
	{
		product *= number;
	}
	return product;
}

