#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
// 需要easyx库才能运行
#include<graphics.h>
#include<conio.h>
#include<windows.h>
#include<stdio.h>
#include<string>
#include <time.h>
#include<mmsystem.h>// 包含多媒体设备接口头文件
#pragma comment(lib,"winmm.lib")
#define GridSize 15
#define InternalSize 33
using namespace std;
#pragma warning(disable:4996)

void PlayBGM();// BGM
void menu();// 菜单
bool play();// 打印界面并开始游戏
void display();// 展示棋盘
bool playgame();// 开始游戏
bool IsAgain(int index);// 有人获胜并判断是否继续
void DisplayExitGameMessage();// 退出游戏界面
bool IsWin(int i, int j, int player);// 判断是否有人获胜
