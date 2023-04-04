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
	//               ��������� �����

	//int factor = 5;
	//cout << "��������� ����� " << factor << " �����: " << Factorial(factor) << endl << endl;

	//--------------------------------------------------------------------------------------------------------------
	//               ���������� ����� � �������

	//int number, power;
	//cout << "������� ����� �����, ������� ������ �������� � �������: ";
	//cin >> number;
	//cout << "� ����� ������� ������ �������� - ������� �����: ";
	//cin >> power;
	//cout << endl << "����� " << number << " � ������� " << power << " ����� - " << Power(number, power) << endl;

	//---------------------------------------------------------------------------------------------------------------
	//              ��������� ����� ���������

	//int counter = 0;
	//for (int i = 32; i <= 127; i++)
	//{
	//	if (i % 16 == 0) cout << endl;
	//	cout << (char)i << " ";
	//}

	//cout << endl << endl;
	//int serial_number;
	//cout << "������� ���������� ����� ����� �� ���� ���������: ";
	//cin >> serial_number;
	//cout << "���������� ����� " << serial_number <<" ���� ��������� = " << Fibonachi(serial_number);

	//---------------------------------------------------------------------------------------------------------------
	//            ������� �����

	//int limit;
	//cout << "������� �������� ������ �������� �����: ";
	//cin >> limit;
	//PrimeNumbers(limit);

	//--------------------------------------------------------------------------------------------------------------
	//				������� ��������
	
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
	int fibaOld = 0; //����� ���� � ����� ������ ������ ������, �� ��� ���������� ���� �����, � ������ � ������ ������ �������
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
	vector <int> arr; //��� ��� ���-�� ��������� � ��� �� ����������, ���� ������������ ��������� ������ (������������)
	
	arr.push_back(int(2)); // ��������� � ����� ������� �������, � ��� ��� �� ������ - ��� �������� ����� ������
	cout << arr[0] << " "; //������� ��� �����, ���� ����� �� ������������

	int serial_number = 1; // ��� ���������� ����� ������� ������� �����
	int examination = 2; // ��� ������� ����� ��� ������� � ��� �� ��� ������� �� ������

	while (examination < limit) 
	{
		
		examination++; // ����� ���������� ��� ��� ����� ��������� ����� ���� �������, ���� ������ ��� ��������
		bool chek = false; // ������� ��� ������� ����� examination �� ������� �� ������ ����� 1 � ���� (������� ������� �����)
		for (int j = 2; j < examination; j++)  // ��������� ��� �������
		{
			if (examination % j == 0)
			{
				chek = true;  //���� ������� ����������� ��������� ����, � ����� � ���������� ��� ��������
				break;  
			}
		}
		if (chek) continue;
		
		if (serial_number % 12 == 0) cout << endl;  //���� �� ������� �����������, �� ��������� �������� � ���� ������
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
