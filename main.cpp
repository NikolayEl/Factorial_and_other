#include<iostream>
#include <vector>
11

using namespace std;

int Factorial(const int factorial);

int Power(const int number, const int power);

int Fibonachi(const int Series);

void PrimeNumbers(const int limit);

void MultiplicationTablePifagor(const int answer);

int main()
{
	//system("chcp 65001");
	setlocale(LC_ALL, "");

	//-------------------------------------------------------------------------------------------------------------
	//               Факториал числа

	//int factor = 5;
	//cout << "Факториал числа " << factor << " равен: " << Factorial(factor) << endl << endl;

	//--------------------------------------------------------------------------------------------------------------
	//               Возведение числа в степень

	//int number, power;
	//cout << "Введите целое число, которое хотите возвести в степень: ";
	//cin >> number;
	//cout << "В какую степень хотите возвести - введите число: ";
	//cin >> power;
	//cout << endl << "Число " << number << " в степени " << power << " будет - " << Power(number, power) << endl;

	//---------------------------------------------------------------------------------------------------------------
	//              Порядковй номер Фибоначчи

	//int counter = 0;
	//for (int i = 32; i <= 127; i++)
	//{
	//	if (i % 16 == 0) cout << endl;
	//	cout << (char)i << " ";
	//}

	//cout << endl << endl;
	//int serial_number;
	//cout << "Введите порядковый номер числа из ряда Фибоначчи: ";
	//cin >> serial_number;
	//cout << "Порядковый номер " << serial_number <<" ряда Фибоначчи = " << Fibonachi(serial_number);

	//---------------------------------------------------------------------------------------------------------------
	//            Простые числа

	//int limit;
	//cout << "Введите вверхний предел простого числа: ";
	//cin >> limit;
	//PrimeNumbers(limit);

	//--------------------------------------------------------------------------------------------------------------
	//				Таблица Пифагора
	
	int factor = 10;
	MultiplicationTablePifagor(factor);

	//---------------------------------------------------------------------------------------------------------------


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

int Fibonachi(const int Series)
{
	int fibaOld = 0; //Можно было и через массив решить вопрос, но так показалось даже проще, а значит и меньше памяти грузить
	int fibaNew = 1;
	int temp;
	if (Series == 1) return 0;
	if (Series == 2) return 1;

	for (int i = 2; i < Series; i++)
	{
		temp = fibaOld;
		fibaOld = fibaNew;
		fibaNew = fibaNew + temp;
	}
	return fibaNew;
}

void PrimeNumbers(const int limit)
{
	vector <int> arr; //так как кол-во элементов у нас не определено, буду использовать векторный массив (динамический)
	
	arr.push_back(int(2)); // Добавляем в конец массива элемент, а так как он пустой - это тэлемент будет первым
	cout << arr[0] << " "; //выведем его сразу, тобы потом не возвращаться

	int serial_number = 1; // Это порядковый номер массива простых чисел
	int examination = 2; // Это перебор чисел для деления и так же это счетчик до лимита

	while (examination < limit) 
	{
		
		examination++; // Сразу прибавляем так как будем проверять сразу след элемент, ведь первый нам известен
		bool chek = false; // Считаем что текущее число examination не делится на другие кроме 1 и себя (условия простых чисел)
		for (int j = 2; j < examination; j++)  // проверяем это условие
		{
			if (examination % j == 0)
			{
				chek = true;  //если условие невыполнено прерываем цикл, а потом и пропускаем эту итерацию
				break;  
			}
		}
		if (chek) continue;
		
		if (serial_number % 12 == 0) cout << endl;  //если же условие выполнилось, то сохраняем значение и идем дальше
		arr.push_back(examination);
		cout << arr[serial_number] << " ";
		serial_number++;
	}
}

void MultiplicationTablePifagor(const int factor)
{
	cout << "_____________________________________________________________________________________________" << endl;
	for (int i = 0; i <= factor; i++) 
	{
		for (int j = 0; j <= factor; j++)
		{
			if (i == 0 && j == 0)
			{
				cout << " \t   ";
				continue;
			}
			//if (j == 0) cout << " | ";
			(i == 0 ? 1 : i)* (j == 0 ? 1 : j) < 10 ? cout << "|\t" << (i == 0 ? 1 : i) * (j == 0 ? 1 : j) << "  " : cout << "|\t" << (i == 0 ? 1 : i) * (j == 0 ? 1 : j) << " ";
			if (j == 10 && i != 10)
			{
				cout << " |";
			}
			else if (j == 10 && i == 10)
			{
				cout << "|";
			}
		}
		cout << endl;
		cout << "---------------------------------------------------------------------------------------------" << endl;
	}
	//cout << "-------------------------------------------------------------------" << endl;
}
