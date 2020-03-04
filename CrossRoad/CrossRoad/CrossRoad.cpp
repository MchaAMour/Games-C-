// CrossRoad.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <deque>
#include <vector>
#include <conio.h>
#include <random>
#include <time.h>
using namespace std;

class cPlayer {

public:
	int x, y;
	cPlayer(int width) { x = width / 2; y = 0; }

};

class cLane {
private:
	deque<bool> cars;
	bool right;

public:
	cLane(int width) {

		for (int i = 0; i < width; i++)
			cars.push_front(false);

		right = rand() % 2;
	}

	void Move() {
		if (right)
		{
			if (rand() % 10 == 1)
				cars.push_front(true);
			else
				cars.push_front(false);
			cars.pop_back();
		}
		else
		{
			if (rand() % 10 == 1)
				cars.push_back(true);
			else
				cars.push_back(false);
			cars.pop_front();
		}

	}
	bool CheckPos(int pos) {return cars[pos] ; }
	void ChangeDir() { right = !right; }
};

class cGame {

private:
	bool quit;
	int numlanes;
	int width;
	int score;
	cPlayer * player;
	vector<cLane*> map;

public:
	cGame(int w , int h) {
		numlanes = h;
		score = 0;
		width = w;
		quit = false;
		for (int i = 0; i < numlanes; i++)
			map.push_back(new cLane(width));
		player = new cPlayer(width);
	}
	void Draw(){ // min 7:44 from video 

		system("cls");
		for (int i = 0; i < numlanes; i++)
		{
			for (int j = 0; j < width; j++)
			{
				if (i == 0 && (j == 0 || j == width - 1)) cout << "S" << endl;
				if (i == numlanes -1 && (j == 0 || j == width - 1)) cout << "F" << endl;
				if (map[i]->CheckPos(j) && i != 0 && i != numlanes - 1)
					cout << "#";
				else if (player->x == j && player->y == i)
					cout << "O";
				else
					cout << " ";
			}
			cout << endl;
		}
		cout << "Score:" << score << endl;
	}
	void Input(){
		
		if (_kbhit())
		{
			char current = _getch();
			if (current == 'a')
				player->x--;
			if (current == 'd')
				player->x++;
			if (current == 'w')
				player->y--;
			if (current == 's')
				player->y++;
			if (current == 'q')
				quit = true;
		}
		
	
	}
	void Logic(){
	
		for (int i = 1; i < numlanes - 1; i++)
		{
			if (rand() % 10 == 1)
				map[i]->Move();
			if (map[i]->CheckPos(player->x) && player->y == i)
				quit = true;
		}
		if (player->y == numlanes - 1)
		{
			score++;
			player->y == 0;
			cout << "\x07" <<endl;
			map[rand() % numlanes]->ChangeDir();
		}
	
	}
	void Run() {
		while (! quit)
		{
			Input();
			Draw();
			Logic();
		}
	
	}

};















int main()
{
	srand(time(NULL));
	cGame game(30, 5);
	cout << "Game Over" << endl;
	game.Run();


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
