#include "pch.h"
#include <iostream>
#include <conio.h>

using namespace std;

void clockwiseToTheCenter(short int width, short int height, short int (&arr)[8][8])
{
	short int i = 1, step = 0;
	while (i <= width * height)
	{
		for (short int j = step; j < width - step; j++)
		{
			arr[step][j] = i;
			i++;
			if (i > width * height)
				break;
		}
		if (i > width * height)
			break;
		for (short int j = step + 1; j < height - step; j++)
		{
			arr[j][width - step - 1] = i;
			i++;
			if (i > width * height)
				break;
		}
		if (i > width * height)
			break;
		for (short int j = width - 2 - step; j >= step; j--)
		{
			arr[height - step - 1][j] = i;
			i++;
			if (i > width * height)
				break;
		}
		if (i > width * height)
			break;
		for (short int j = height - 2 - step; j > step; j--)
		{
			arr[j][step] = i;
			i++;
			if (i > width * height)
				break;
		}
		if (i > width * height)
			break;
		step++;
	}
	_getch();
}

void counterclockwiseToTheCenter(short int width, short int height, short int(&arr)[8][8])
{
	short int i = 1, step = 0;
	while (i <= width * height)
	{
		for (short int j = width - step - 1; j >= step; j--)
		{
			arr[step][j] = i;
			i++;
			if (i > width * height)
				break;
		}
		if (i > width * height)
			break;
		for (short int j = step + 1; j <= height - step - 1; j++)
		{
			arr[j][step] = i;
			i++;
			if (i > width * height)
				break;
		}
		if (i > width * height)
			break;
		for (short int j = step + 1; j < width - step - 1; j++)
		{
			arr[height - step - 1][j] = i;
			i++;
			if (i > width * height)
				break;
		}
		if (i > width * height)
			break;
		for (short int j = height - step - 1; j > step; j--)
		{
			arr[j][width - step - 1] = i;
			i++;
			if (i > width * height)
				break;
		}
		if (i > width * height)
			break;
		step++;
	}
	_getch();
}

void clockwiseFromTheCenter(short int width, short int height, short int(&arr)[8][8])
{
	short int i = width * height, step = 0;
	while (i > 0)
	{
		for (short int j = width - step - 1; j >= step; j--)
		{
			arr[step][j] = i;
			i--;
			if (i < 1)
				break;
		}
		if (i < 1)
			break;
		for (short int j = step + 1; j <= height - step - 1; j++)
		{
			arr[j][step] = i;
			i--;
			if (i < 1)
				break;
		}
		if (i < 1)
			break;
		for (short int j = step + 1; j < width - step - 1; j++)
		{
			arr[height - step - 1][j] = i;
			i--;
			if (i < 1)
				break;
		}
		if (i < 1)
			break;
		
		for (short int j = height - step - 1; j > step; j--)
		{
			arr[j][width - step - 1] = i;
			i--;
			if (i < 1)
				break;
		}
		if (i < 1)
			break;
		step++;
	}
	_getch();
}

void counterclockwiseFromTheCenter(short int width, short int height, short int(&arr)[8][8])
{
	short int i = width * height, step = 0;
	while (i > 0)
	{
		for (short int j = step; j < width - step; j++)
		{
			arr[step][j] = i;
			i--;
			if (i < 1)
				break;
		}
		if (i < 1)
			break;
		for (short int j = step + 1; j < height - step; j++)
		{
			arr[j][width - step - 1] = i;
			i--;
			if (i < 1)
				break;
		}
		if (i < 1)
			break;
		for (short int j = width - 2 - step; j >= step; j--)
		{
			arr[height - step - 1][j] = i;
			i--;
			if (i < 1)
				break;
		}
		if (i < 1)
			break;
		for (short int j = height - 2 - step; j > step; j--)
		{
			arr[j][step] = i;
			i--;
			if (i < 1)
				break;
		}
		if (i < 1)
			break;
		step++;
	}
	_getch();
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
	cout << '\n' << '\n' << "Press Esc to exit";
	return num1;
}

int main()
{
	short int matrix[8][8] = {0};
	short int choose = 0, tempChoose = 0, arrowControl = 49;
	short int M = 0, N = 0;
	
	while ((M > 8) || (N > 8) || (M < 1) || (N < 1))
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

	cout << "M = " << M << "; N = " << N << '\n';
	cout << '\n' << "Clockwise to the center          ";
	cout << "<--";
	cout << '\n' << "Counterclockwise to the center   ";
	cout << '\n' << "Clockwise from the center        ";
	cout << '\n' << "Counterclockwise from the center ";
	cout << '\n' << '\n' << "Press Esc to exit";

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
					clockwiseToTheCenter(M, N, matrix);
					break;
				case 50: 
					counterclockwiseToTheCenter(M, N, matrix);
					break;
				case 51: 
					clockwiseFromTheCenter(M, N, matrix);
					break;
				case 52: 
					counterclockwiseFromTheCenter(M, N, matrix);
				default:;
			}
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < M; j++)
					printf("%5d", matrix[i][j]);
				cout << '\n' << '\n';
			}
			cout << "Press any key";
			_getch();
			choose = arrowControl;
		}
		system("cls");
		cout << "M = " << M << "; N = " << N << '\n';
		arrowControl = menu(choose, tempChoose, arrowControl);
	}
	return 0;
}
