#pragma once
int step;
int solutions;
int boardSizeX;
int boardSizeY;
int **board;
int moves[][2] = { { 1, -2 },{ 2, -1 },{ 2, 1 },{ 1, 2 },{ -1, 2 },{ -2, 1 },{ -2, -1 },{ -1, -2 } };
void possibleMoves(int x, int y);
int moveKnight(int x, int y);