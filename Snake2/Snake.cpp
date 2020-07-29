#include"Snake.h"


Snake::Snake()
{
	HWND console_window = GetConsoleWindow();
	ShowWindow(console_window, SW_MAXIMIZE);
	cout << "Enter your name: ";
	cin >> yourname;
	system("ClS");

	Results();
	ShowResults();

	for (int i = 30; i < 35; i++)
		body.push_back(make_pair(i, 30));
	direction = VK_RIGHT;
	prevdirection = -1;
	DrawSnake();

	srand(time(NULL));
	for (int i = 0; i < 5; i++)
	{
		points[i].first = rand() % 149 + 16;
		points[i].second = rand() % 39 + 11;
	}
	DrawPoints();

}

void Snake::Move(int& keypress, int map)
{
	if (direction == VK_UP)
		body.push_back(make_pair(body.rbegin()->first, body.rbegin()->second - 1));
	else if (direction == VK_DOWN)
		body.push_back(make_pair(body.rbegin()->first, body.rbegin()->second + 1));
	else if (direction == VK_RIGHT)
		body.push_back(make_pair(body.rbegin()->first + 1, body.rbegin()->second));
	else
		body.push_back(make_pair(body.rbegin()->first - 1, body.rbegin()->second));

	if (prevdirection == direction && (direction == VK_UP || direction == VK_DOWN))
		ratio = 2;
	else if (prevdirection == direction)
		ratio = 1;
	else if (direction == VK_UP || direction == VK_DOWN)
		ratio = 4;
	else
		ratio = 2;

	COORD coord;
	coord.X = body.begin()->first;
	coord.Y = body.begin()->second;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	cout << " ";
	if (!CheckPoint(map)) { body.pop_front(); }
	DrawSnake();
	CheckDeath(keypress, map);
}

void Snake::DrawSnake()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 2);

	for (deque<pair<int, int>>::const_iterator it = body.begin(); it != body.end(); it++)
	{
		COORD coord;
		coord.X = it->first;
		coord.Y = it->second;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		cout << "o";
	}
}

void Snake::DrawPoints()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 6);
	for (int i = 0; i < 5; i++)
	{
		COORD coord;
		coord.X = points[i].first;
		coord.Y = points[i].second;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		cout << "$";
	}
}

void Snake::ChangeDirection(char ch)
{
	if ((ch == VK_UP && direction != VK_DOWN) || (ch == VK_DOWN && direction != VK_UP) || 
		(ch == VK_RIGHT && direction != VK_LEFT) || (ch == VK_LEFT && direction != VK_RIGHT))
	{
		prevdirection = direction;
		direction = ch;
	}
}

void Snake::CheckDeath(int& keypress, int map)
{
	COORD coord;
	coord.X = body.rbegin()->first;
	coord.Y = body.rbegin()->second;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 4);
	deque<pair<int, int>>::reverse_iterator it = body.rbegin();
	it++;
	for (it; it != body.rend(); it++)
	{
		if (body.rbegin()->first == it->first && body.rbegin()->second == it->second)
		{
			cout << "X";
			keypress = ESC;
			return;
		}
	}

	if (body.rbegin()->first == 15 || body.rbegin()->first == 165 ||
		body.rbegin()->second == 10 || body.rbegin()->second == 50)
	{
		cout << "X";
		keypress = ESC;
		return;
	}

	if (map == 1)
	{
		if (((body.rbegin()->first >= 45 && body.rbegin()->first <= 90) || body.rbegin()->first >= 130) &&
			(body.rbegin()->second == 20 || body.rbegin()->second == 40))
		{
			cout << "X";
			keypress = ESC;
			return;
		}
		if ((body.rbegin()->first == 80 || body.rbegin()->first == 120) &&
			(body.rbegin()->second >= 25 && body.rbegin()->second <= 35))
		{
			cout << "X";
			keypress = ESC;
			return;
		}
	}
}

bool Snake::CheckPoint(int map)
{
	for (int i = 0; i < 5; i++)
	{
		if (body.rbegin()->first == points[i].first && body.rbegin()->second == points[i].second)
		{
			points[i].first = rand() % 149 + 16;
			points[i].second = rand() % 39 + 11;
			if (map == 1)
			{
				while (true)
				{
					if (((points[i].first >= 45 && points[i].first <= 90) || points[i].first >= 130) &&
						(points[i].second == 20 || points[i].second == 40))
					{
						points[i].first = rand() % 149 + 16;
						points[i].second = rand() % 39 + 11;
					}
					else if ((points[i].first == 80 || points[i].first == 120) &&
							(points[i].second >= 25 && points[i].second <= 35))
					{
						points[i].first = rand() % 149 + 16;
						points[i].second = rand() % 39 + 11;
					}
					else { break; }
				}
			}

			if (speed > 12) { yourpoints += 100; }
			else if (speed > 9) { yourpoints += 150; }
			else if (speed > 6) { yourpoints += 200; }
			else if (speed > 3) { yourpoints += 300; }
			else { yourpoints += 400; }
			DrawPoints();
			SpeedInrcease();
			ShowResults();
			return true;
		}
	}
	return false;
}

void Snake::SpeedInrcease()
{
	if (speed <= 1) { return; }
	else { speed--; }
}

void Snake::Results()
{
	fstream file;
	string word;

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 11);

	file.open("Results.txt", ios::in);
	if (!file.good())
	{
		cout << "Brak pliku z wynikami";
	}
	int i = 0;
	while (file >> word)
	{
		if (i % 2 == 0) { results[i / 2].first = word; }
		else {
			results[i / 2].second = stoi(word); }
		i++;
	}

	file.close();
}

void Snake::ShowResults()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 6);
	COORD coord;


	coord.X = 178;
	coord.Y = 18;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	cout << "*************************";
	coord.X = 178;
	coord.Y = 19;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	cout << "* Your name: " << setw(10) << left << yourname << " *";
	coord.X = 178;
	coord.Y = 20;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	cout << "* Your score: " << setw(10) << left << yourpoints << "*";
	coord.X = 178;
	coord.Y = 21;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	cout << "*************************";

	if (miejsce == 0 && yourpoints > results[9].second)
	{
		results[9].first = yourname;
		results[9].second = yourpoints;
		miejsce = 10;
	}
	else { results[miejsce - 1].second = yourpoints; }

	for (int i = miejsce; i > 1; i--)
	{
		if (results[i - 1].second > results[i - 2].second)
		{
			results[i - 1].second = results[i - 2].second;
			results[i - 1].first = results[i - 2].first;
			results[i - 2].second = yourpoints;
			results[i - 2].first = yourname;
			miejsce--;
		}
		else { break; }
	}
		
	for (int i = 1; i <= 10; i++)
	{
		coord.X = 180;
		coord.Y = 30 + i;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		cout << setw(4) << right << i << ". " << setw(10) << left << results[i - 1].first << " " << setw(6) <<results[i - 1].second << endl;
	}
}

void Snake::SaveResults()
{
	fstream file;
	file.open("Results.txt", ios::out);

	for (int i = 0; i < 10; i++)
	{
		file << results[i].first << " " << results[i].second << endl;
	}

	file.close();
}