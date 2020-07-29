#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<Windows.h>
#include<ctime>
#include<conio.h>
#include<iomanip>  
#include<deque>

using namespace std;

#define ESC 27

class Snake
{
	deque<pair<int, int>> body;
	int speed = 15;
	int ratio = 2;
	char direction;
	char prevdirection;
	pair<int, int> points[5];
	pair<string, int> results[10];
	string yourname;
	int yourpoints = 0;
	int miejsce = 0;

	void DrawSnake();
	void DrawPoints();
	void CheckDeath(int &keypress, int map);
	bool CheckPoint(int map);
	void SpeedInrcease();
	void Results();
	void ShowResults();

public:
	Snake();
	void Move(int &keypress, int map);
	void ChangeDirection(char ch);
	int GetSpeed() { return speed * ratio; }
	void SaveResults();
};