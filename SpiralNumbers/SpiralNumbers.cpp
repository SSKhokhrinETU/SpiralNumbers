#include "pch.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

short int menu(short int num1, short int num2, short int arrow)
{
	if (num1 == 224)
	{
		if (num2 == 72)
		{
			if (arrow > 49)
				num1 = --arrow;
			else
				num1 = arrow;
		}
		else if (num2 == 80)
			if (arrow < 52)
				num1 = ++arrow;
			else
				num1 = arrow;
		else
			num1 = arrow;
	}

	cout << '\n' << "1 ";
	if (num1 == 49)
		cout << "<--";
	cout << '\n' << "2 ";
	if (num1 == 50)
		cout << "<--";
	cout << '\n' << "3 ";
	if (num1 == 51)
		cout << "<--";
	cout << '\n' << "4 ";
	if (num1 == 52)
		cout << "<--";
	return num1;
}

int main()
{
	short int choose = 0, tempChoose = 0, arrowControl = 0;
	while (choose != 27)
	{
		do
		{
			choose = _getch();
			if (choose == 224)
				tempChoose = _getch();
		} while ((choose != 27) && (choose != 49) && (choose != 50) && (choose != 51) && (choose != 52) && (choose != 224));
		system("cls");
		arrowControl = menu(choose, tempChoose, arrowControl);
		//_getch();
	}
	return 0;
}
