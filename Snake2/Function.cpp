#include"Function.h"

void ChooseMap(int &map)
{
	cout << "Please enter number from 1 to 3 to choose map: ";
	cin >> map;
}

void CreateBoard(int map)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 11);
	COORD coord;
	
	coord.X = 15;
	coord.Y = 10;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	for (int i = 15; i <= 165; i++)
		cout << "*";

	if (map == 1)
	{
		coord.X = 45;
		coord.Y = 20;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		for (int i = 45; i <= 90; i++)
			cout << "*";
		coord.X = 130;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		for (int i = 130; i < 165; i++)
			cout << "*";

		coord.X = 45;
		coord.Y = 40;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		for (int i = 45; i <= 90; i++)
			cout << "*";
		coord.X = 130;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		for (int i = 130; i < 165; i++)
			cout << "*";

		for (int i = 25; i <= 35; i++)
		{
			coord.X = 80;
			coord.Y = i;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
			cout << "*";
			coord.X = 120;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
			cout << "*";
		}
	}
	
	for (int i = 11; i <= 50; i++)
	{
		coord.X = 165;
		coord.Y = i;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		cout << "*";
		coord.X = 15;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		cout << "*";
	}
	
	for (int i = 16; i < 165; i++)
		cout << "*";

	CreateRecordsTable();
}

void CreateRecordsTable()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 6);
	COORD coord;
	coord.X = 180;
	coord.Y = 29;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	cout << "    ! Best Records !";
	
	coord.X = 178;
	coord.Y = 27;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	for (int i = 178; i <= 205; i++)
		cout << "*";
	cout << endl;
	for (int i = 27; i <= 43; i++)
	{
		coord.X = 205;
		coord.Y = i;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		cout << "*";
		coord.X = 178;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		cout << "*";
	}
	for (int i = 178; i < 205; i++)
		cout << "*";

}

int GetKeypress(int keypress)
{
	if (GetAsyncKeyState(ESC)) 
		keypress = ESC;
	else if (GetAsyncKeyState(VK_UP))
		keypress = VK_UP;
	else if (GetAsyncKeyState(VK_DOWN))
		keypress = VK_DOWN;
	else if (GetAsyncKeyState(VK_LEFT))
		keypress = VK_LEFT;
	else if (GetAsyncKeyState(VK_RIGHT))
		keypress = VK_RIGHT;


	return keypress;
}

void GameOver()
{
	Sleep(500);

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 4);
	COORD coord;
	coord.X = 60;
	coord.Y = 4;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	cout << " ****     *     *       * ******    ***  *       * ***** ***** " << endl;
	coord.X = 60;
	coord.Y = 5;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	cout << "*        * *    * *   * * *        *   *  *     *  *     *    *" << endl;
	coord.X = 60;
	coord.Y = 6;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	cout << "* ***   *   *   *  * *  * ****     *   *   *   *   ****  ***** " << endl;
	coord.X = 60;
	coord.Y = 7;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	cout << "*   *  *******  *   *   * *        *   *    * *    *     *  **  " << endl;
	coord.X = 60;
	coord.Y = 8;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	cout << " **** *       * *       * ******    ***      *     ***** *    * " << endl;
}