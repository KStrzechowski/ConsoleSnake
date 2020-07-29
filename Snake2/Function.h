#pragma once
#include<iostream>
#include<Windows.h>
#include<deque>
#include"Snake.h"
using namespace std;

void ChooseMap(int &map);
void CreateBoard(int map);
void CreateRecordsTable();

int GetKeypress(int keypress);

void GameOver();

