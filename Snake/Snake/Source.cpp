#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <random>
using namespace std;
bool gameOver;
const int width = 20; // map width dimension
const int height = 20; // map height dimension
int x, y; //variable for head positions
int fruitX, fruitY; // fruit positions
int score; // Keep Score
int tailX[100],tailY[100];
int nTail; 
enum eDirection {STOP = 0, LEFT , RIGHT, UP, DOWN};
eDirection dir;
// main functions in a game [setup ,draw, input,logic] and map dimensions

void Setup() {
	gameOver = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;

}
void Draw() {
	system("cls"); // it will clear the console
	for (int i = 0; i < width+2; i++) // display the top border of the map
		cout << "#";
	cout << endl;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0)
				cout << "#";
			if (i == y && j == x)
				cout << "O";
			else if (i == fruitY && j == fruitX)
				cout << "*" << endl;
			else
			{
				bool print = false;
				for (int k = 0; k < nTail; k++)
				{

					if (tailX[k] == j && tailY[k] == i)
					{
						cout << "o";
						print = true;
					}
				}
				if (!print)
					cout << " ";

			}
				
			if (j == width - 1)
				cout << "#";

		}
		cout << endl;
	}

	for (int i = 0; i < width+2; i++) // display the bottom border of the map
		cout << "#";
	cout << endl;
	cout << "Score : " << score <<endl;
}
void Input() {

	if (_kbhit()) // check if keyboard key is pressed
	{
		switch (_getch()) // get the keyboard pressed
		{
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'x':
			gameOver = true;
			break;
			
		}
	}
}
void Logic() {

	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;
	for (int i = 1; i < nTail; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}

	switch (dir)
	{
	case LEFT:
		x--;
		break;

	case RIGHT:
		x++;
		break;

	case UP:
		y--;
		break;

	case DOWN:
		y++;
		break;
	default:
		break;
	}
	//if (x > width || x < 0 || y > height || y < 0)
	//	gameOver = true;

	if (x >= width)  x = 0; else if (x < 0) x = width - 1;
	if (y >= height) y = 0; else if (y < 0) y = height - 1;



	for (int i = 0; i < nTail; i++)
	{
		if (tailX[i] == x && tailY[i] == y )
			gameOver = true;
	}

	if (x == fruitX && y == fruitY) {
		score += 10;
		fruitX = rand() % width;
		fruitY = rand() % height;
		nTail++;

	}

}

int main() {

	Setup();
	while (!gameOver) {
		Draw();
		Input();
		Logic();
		Sleep(10);
		

		//if (dir == LEFT || dir == RIGHT)
		//{
		//	Sleep(5);
		//}

		//Sleep(50);

		//if (dir == UP || dir == DOWN)
		//{
		//	Sleep(60);
		//}



	}
	
	return 0;
}