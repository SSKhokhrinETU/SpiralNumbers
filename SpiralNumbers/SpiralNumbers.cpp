#include "pch.h"
#include <iostream>
#include <conio.h>

using namespace std;

void clockwiseToTheCenter()
{
	cout << "clockwiseToTheCenter" << '\n'; _getch();
}

void counterclockwiseToTheCenter()
{
	cout << "counterclockwiseToTheCenter" << '\n'; _getch();
}

void clockwiseFromTheCenter()
{
	cout << "clockwiseFromTheCenter" << '\n'; _getch();
}

void counterclockwiseFromTheCenter()
{
	cout << "counterclockwiseFromTheCenter" << '\n'; _getch();
}

short int menu(short int num1, short int num2, short int arrow)
{
	if (num1 == 224)
	{
		if (num2 == 72)
			if (arrow > 49)
				num1 = --arrow;
			else
				num1 = 52; //num1 = arrow;
		else if (num2 == 80)
			if (arrow < 52)
				num1 = ++arrow;
			else
				num1 = 49; //num1 = arrow;
		else
			num1 = arrow;
	}

	cout << '\n' << "Clockwise to the center          ";
	if (num1 == 49)
		cout << "<--";
	cout << '\n' << "Counterclockwise to the center   ";
	if (num1 == 50)
		cout << "<--";
	cout << '\n' << "Clockwise from the center        ";
	if (num1 == 51)
		cout << "<--";
	cout << '\n' << "Counterclockwise from the center ";
	if (num1 == 52)
		cout << "<--";
	return num1;
}

int main()
{
	short int choose = 0, tempChoose = 0, arrowControl = 49;
	short int M = 0, N = 0;

	while ((M > 8) || (N > 8) || !M || !N)
	{
		cout << "M = ";
		M = _getch();
		_getch();
		if ((M > 47) && (M < 58))
		{
			M -= 48;
			cout << M;
		} else
		{
			M = 0;
			cout << "incorrect";
		}
		cout << "\nN = ";
		N = _getch();
		_getch();
		if ((N > 47) && (N < 58))
		{
			N -= 48;
			cout << M;
		} else
		{
			N = 0;
			cout << "incorrect";
			_getch();
		}
		system("cls");
	}

	cout << "M = " << M << "; N = " << N;
	cout << '\n' << "Clockwise to the center          ";
	cout << "<--";
	cout << '\n' << "Counterclockwise to the center   ";
	cout << '\n' << "Clockwise from the center        ";
	cout << '\n' << "Counterclockwise from the center ";
	
	while (choose != 27)
	{
		do
		{
			choose = _getch();
			if (choose == 224)
				tempChoose = _getch();
		} while ((choose != 27) && (choose != 49) && (choose != 50) && (choose != 51) 
								&& (choose != 52) && (choose != 224) && (choose != 13));

		if (choose == 13)
		{
			system("cls");
			switch (arrowControl)
			{
				case 49: 
					clockwiseToTheCenter();
					break;
				case 50: 
					counterclockwiseToTheCenter();
					break;
				case 51: 
					clockwiseFromTheCenter();
					break;
				case 52: 
					counterclockwiseFromTheCenter();
			}
			_getch();
			choose = arrowControl;
		}
		system("cls");
		cout << "M = " << M << "; N = " << N;
		arrowControl = menu(choose, tempChoose, arrowControl);
	}
	return 0;
}
