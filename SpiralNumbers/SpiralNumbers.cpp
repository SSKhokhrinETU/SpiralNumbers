#include "pch.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

void menu(int num1, int num2)
{
	cout << '\n' << "1 ";
	if (num1 == 1)
		cout << "<--";
	cout << '\n' << "2 ";
	if (num1 == 2)
		cout << "<--";
	cout << '\n' << "3 ";
	if (num1 == 3)
		cout << "<--";
	cout << '\n' << "4 ";
	if (num1 == 4)
		cout << "<--";
}

int main()
{
	int choose = 1, tempChoose = 0;
	while (choose != 27)
	{
		choose = _getch();
		if (choose > 4)
			tempChoose = _getch();
		//cls();
		menu(choose, tempChoose);
	}
	return 0;
}
