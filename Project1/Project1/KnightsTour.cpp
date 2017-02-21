#include <iostream>
#include <random>
#include <cstdio>
#include "Header.h"

using namespace std;

int knightTour(int sizeX, int sizeY) {
	step = 1;

	boardSizeX = sizeX;
	boardSizeY = sizeY;
	solutions = 0;
	board = new int*[boardSizeX];

	for (int i = 0; i < boardSizeX; i++) {
		board[i] = new int[boardSizeY];
	}
	for (int i = 0; i < boardSizeX; i++) {
		for (int j = 0; j < boardSizeY; j++) {
			board[i][j] = 0;
		}
	}
	return 0;
}
 	

void print() {
	for (int i = 0; i < boardSizeX; i++)
	{
		for (int j = 0; j < boardSizeY; j++)
		{
			cout << board[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}

bool canMoveKnight(int x, int y) {
	if (board[x][y] == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void knightConfig() {
	for (int x = 0; x < boardSizeX; x++)
	{
		for (int y = 0; y < boardSizeY; y++)
		{
			step = 1;
			board[x][y] = step;
			step++;
			possibleMoves(x, y);
			board[x][y] = 0;
		}

	}
}

void possibleMoves(int x, int y) {
	// going 2 to right and both up and down 1
	if (x + 2 < boardSizeX)
	{
		if (y + 1 < boardSizeY)
		{
			if (canMoveKnight(x + 2, y + 1))
			{
				moveKnight(x + 2, y + 1);
			}
		}
		if (y - 1 >= 0) {
			if (canMoveKnight(x + 2, y - 1))
			{
				moveKnight(x + 2, y - 1);
			}
		}
	}
	if (x + 1 < boardSizeX) // moving 1 right and/or 2 up and down
	{
		if (y + 2 < boardSizeY)
		{
			if (canMoveKnight(x + 1, y + 2))
			{
				moveKnight(x + 1, y + 2);
			}
		}
		if (y - 2 >= 0) {
			if (canMoveKnight(x + 1, y - 2))
			{
				moveKnight(x + 1, y - 2);
			}
		}
	}
	if (x - 1 >= 0) //going left 1 and 2 up/down
	{
		if (y + 2 < boardSizeY)
		{
			if (canMoveKnight(x - 1, y + 2))
			{
				moveKnight(x - 1, y + 2);
			}
		}
		if (y - 2 >= 0) {
			if (canMoveKnight(x - 1, y - 2))
			{
				moveKnight(x - 1, y - 2);
			}
		}
	}
	if (x - 2 >= 0) //going left 2 and 1 up/down
	{
		if (y + 1 < boardSizeY)
		{
			if (canMoveKnight(x - 2, y + 1))
			{
				moveKnight(x - 2, y + 1);
			}
		}
		if (y - 1 >= 0) {
			if (canMoveKnight(x - 2, y - 1))
			{
				moveKnight(x - 2, y - 1);
			}
		}
	}
}

int moveKnight(int x, int y) {
	board[x][y] = step;

	if (step == (boardSizeX * boardSizeY)) {
		print();
		solutions++;
		board[x][y] = 0;
		step--;
	}
	else {
		step++;
		possibleMoves(x, y);
		board[x][y] = 0;
		step--;
	}
	return step;
}

int solutionCount() {
	return solutions;
}

int main() {
	int sizeX;
	int sizeY;
	cout << "knights tour" << endl << endl;
	cout << "Enter the size of the board" << endl;
	cout << "enter the x value ";
	cin >> sizeX;
	cout << "enter the y value " << endl;
	cin >> sizeY;
	knightTour(sizeX, sizeY);
	knightConfig();

	cout << "solutions " << solutionCount() << endl;
	system("pause");
	return 0;
}


