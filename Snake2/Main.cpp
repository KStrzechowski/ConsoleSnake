#include<iostream>
#include<conio.h>
#include<cstdlib>
#include"Function.h"

using namespace std;


int main()
{
	int map;
	ChooseMap(map);
	Snake Snake;
	CreateBoard(map);

	int keypress = 0;
	while (keypress != ESC)
	{
		keypress = 0;
		keypress = GetKeypress(keypress);
		Snake.ChangeDirection(keypress);
		Snake.Move(keypress, map);
		Sleep(15 * Snake.GetSpeed());
	}

	GameOver();
	Snake.SaveResults();

	COORD coord;
	coord.X = 1;
	coord.Y = 60;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	return 0;
}
