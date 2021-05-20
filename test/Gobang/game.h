#define _CRT_SECURE_NO_WARNINGS 1

#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>

#define ROW 10
#define COL 10

#define PLAYER1 1
#define PLAYER2 2

#define NEXT        0
#define PLAYER1_WIN 1
#define PLAYER2_WIN 2
#define DRAW        3


enum Dir{
	LEFT,
	RIGHT,
	UP,
	DOWN,
	LEFT_UP,
	LEFT_DOWN,
	RIGHT_UP,
	RIGHT_DOWN
};


void Menu();
void Game();