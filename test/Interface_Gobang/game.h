#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
// ��Ҫeasyx���������
#include<graphics.h>
#include<conio.h>
#include<windows.h>
#include<stdio.h>
#include<string>
#include <time.h>
#include<mmsystem.h>// ������ý���豸�ӿ�ͷ�ļ�
#pragma comment(lib,"winmm.lib")
#define GridSize 15
#define InternalSize 33
using namespace std;
#pragma warning(disable:4996)

void PlayBGM();// BGM
void menu();// �˵�
bool play();// ��ӡ���沢��ʼ��Ϸ
void display();// չʾ����
bool playgame();// ��ʼ��Ϸ
bool IsAgain(int index);// ���˻�ʤ���ж��Ƿ����
void DisplayExitGameMessage();// �˳���Ϸ����
bool IsWin(int i, int j, int player);// �ж��Ƿ����˻�ʤ
