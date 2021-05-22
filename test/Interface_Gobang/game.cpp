#include "game.h"
int a[GridSize][GridSize] = { 0 };// ���̱�ǳ�
IMAGE img_bk1, img_bk2;
int Player1WinCount = 0, Player2WinCount = 0;
//�˵�
void menu()
{
	IMAGE img;//����ͼƬ����
	loadimage(&img, "./res/������1.jpg");//���س�ʼ����  E:\\code\\test_5_24\\test_5_24
	putimage(0, 0, &img, SRCPAINT);//����ͼ����Ļ
	settextstyle(50, 20, (LPCTSTR)"����");//��������
	settextcolor(YELLOW);//����������ɫ
	setbkmode(WHITE);//���ñ������ģʽ
	outtextxy(150, 100, (LPCTSTR)"������˫�˶�ս");//��ָ��λ������ַ���
	outtextxy(200, 400, (LPCTSTR)"��ʼ��Ϸ");//��ָ��λ������ַ���
	outtextxy(200, 451, (LPCTSTR)"�˳���Ϸ");//��ָ��λ������ַ���
	PlayBGM();//��������
	MOUSEMSG m;//����������
	while (true)
	{
		m = GetMouseMsg();//��ȡ�����Ϣ
		if (m.uMsg == WM_MOUSEMOVE && m.x >= 200 && m.x <= 360 && m.y >= 400 && m.y <= 450){//�ж�����Ƿ��ƶ����˿�ʼ��Ϸ�������û�ɫ������	
			setlinecolor(YELLOW);
			rectangle(200, 400, 360, 450);
		}
		else{
			setlinecolor(getbkcolor());
			rectangle(200, 400, 360, 450);
		}
		if (m.uMsg == WM_MOUSEMOVE && m.x >= 200 && m.x <= 360 && m.y >= 451 && m.y <= 500){//�ж�����Ƿ��ƶ������˳���Ϸ�������û�ɫ������	
			setlinecolor(YELLOW);
			rectangle(200, 451, 360, 500);
		}
		else{
			setlinecolor(getbkcolor());
			rectangle(200, 451, 360, 500);
		}
		if (m.uMsg == WM_LBUTTONDOWN && m.x >= 200 && m.x <= 360 && m.y >= 400 && m.y <= 450){//�ж��Ƿ�����ʼ��Ϸ
			cleardevice();//����
			Sleep(200);
			bool Continue_Game = true;
			while (Continue_Game){
				Continue_Game = play();//��ʼ��Ϸ��ѭ���ж��Ƿ������Ϸ
			}
			break;
		}
		if (m.uMsg == WM_LBUTTONDOWN && m.x >= 200 && m.x <= 360 && m.y >= 451 && m.y <= 500){//�ж��Ƿ����˳���Ϸ	
			break;
		}
	}
}
//��BGM
void PlayBGM()
{
	//������,���ý���豸�ӿڷ���һ���ַ���������ָ�� alias ȡ����
	mciSendString("open ./res/��������.mp3 alias BGM", 0, 0, 0);
	//��������
	mciSendString("play BGM", 0, 0, 0);
	//�ر�����
	//Sleep(3000);
	//mciSendString("close BGM", 0, 0, 0);
}
//���ó�ʼ����
bool play()
{
	cleardevice();// ����
	graphdefaults();// �������л�ͼ����ΪĬ��ֵ
	display();//��ʾ��������
	setlinecolor(WHITE);// ���õ�ǰ������ɫ
	settextstyle(20, 10, (LPCTSTR)"����");//���������С
	settextcolor(GREEN);// ����������ɫ
	setbkmode(WHITE);//// ���ñ������ģʽ
	outtextxy(5, 5, (LPCTSTR)"player1:����");
	outtextxy(5, 28, (LPCTSTR)"����: ");
	outtextxy(475, 5, (LPCTSTR)"player2:����");
	outtextxy(475, 28, (LPCTSTR) "����: ");
	settextstyle(25, 15, (LPCTSTR)"����");//��25�����أ���15������
	outtextxy(475, 560, (LPCTSTR) "�˳���Ϸ");
	outtextxy(10, 560, (LPCTSTR) "���¿�ʼ");
	outtextxy(270, 560, (LPCTSTR) "����");
	return playgame();
}
//��ʾ��������
void display()
{
	loadimage(&img_bk1, "./res/��Ϸ����.jpg");// ����ͼƬ
	putimage(0, 0, &img_bk1, SRCPAINT);// ��ʾͼƬ
	clearrectangle(50, 50, 550, 550);// ��վ�������
	loadimage(&img_bk2, "./res/����������.jpg");// ����ͼƬ
	putimage(50, 50, &img_bk2, SRCPAINT);// ��ʾͼƬ
}
// ��ʽ��ʼ��Ϸ
bool playgame()
{
	settextstyle(25, 15, (LPCTSTR)"����");// ��25�����أ���15������
	string str = to_string(Player1WinCount) + " : " + to_string(Player2WinCount);//
	outtextxy(265, 15, (LPCTSTR)str.data());//
	int StepNum1 = 0, StepNum2 = 0;
	settextstyle(20, 10, (LPCTSTR)"����");
	outtextxy(60, 27, (LPCTSTR)to_string(StepNum1).data());//
	outtextxy(530, 27, (LPCTSTR)to_string(StepNum2).data());//
	settextstyle(25, 15, (LPCTSTR)"����", 2700, 0, 0, 0, 0, 0);//��25�����أ���15������
	outtextxy(25, 50, (LPCTSTR)"�ڷ�����");
	memset(a, 0, sizeof(a));
	int Pre_i = -1, Pre_j = -1, Pre_C = -1, Pre_R = -1;
	int player = 1; bool UndoAble = true;
	MOUSEMSG msg;
	while (true)
	{
		msg = GetMouseMsg();
		//���˳���Ϸ��������ز���
		if (msg.uMsg == WM_MOUSEMOVE && msg.x >= 475 && msg.x <= 595 && msg.y >= 560 && msg.y <= 585){//�ж�����Ƿ��ƶ������˳���Ϸ�������û�ɫ������
			setlinecolor(YELLOW);
			rectangle(475, 560, 595, 585);
		}
		else{
			setlinecolor(BLACK);
			rectangle(475, 560, 595, 585);
		}
		if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 460 && msg.x <= 580 && msg.y >= 550 && msg.y <= 575){//�ж�����Ƿ������˳���Ϸ	
			return false;
		}
		//�����¿�ʼ��������ز���
		if (msg.uMsg == WM_MOUSEMOVE && msg.x >= 10 && msg.x <= 130 && msg.y >= 560 && msg.y <= 585){//�ж�����Ƿ��ƶ������˳���Ϸ�������û�ɫ������	
			setlinecolor(YELLOW);
			rectangle(10, 560, 130, 585);
		}
		else{
			setlinecolor(BLACK);
			rectangle(10, 560, 130, 585);
		}
		if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 10 && msg.x <= 130 && msg.y >= 560 && msg.y <= 585){//�ж�����Ƿ������˳���Ϸ	
			Player1WinCount = 0, Player2WinCount = 0;
			return true;
		}
		//�����塱������ز���
		if (msg.uMsg == WM_MOUSEMOVE && msg.x >= 270 && msg.x <= 330 && msg.y >= 560 && msg.y <= 585){//�ж�����Ƿ��ƶ����˻��壬�����û�ɫ������	
			setlinecolor(YELLOW);
			rectangle(270, 560, 330, 585);
		}
		else{
			setlinecolor(BLACK);
			rectangle(270, 560, 330, 585);
		}
		if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 270 && msg.x <= 330 && msg.y >= 560 && msg.y <= 585)//�ж�����Ƿ����˻���
		{
			HWND hq = FindWindow(NULL, "������˫�˶�ս");//��ȡ�����ھ��
			if (Pre_i == -1) {
				MessageBox(hq, (LPCTSTR) "Ŀǰ�����ܻ���", "��ʾ", MB_OK);
			}
			else if (UndoAble){
				UndoAble = false;
				a[Pre_i][Pre_j] = 0;
				clearcircle(Pre_C, Pre_R, 12);
				putimage(Pre_C - 12, Pre_R - 12, 25, 25, &img_bk2, Pre_C - 12 - 50, Pre_R - 12 - 50, SRCCOPY);
				if (player == 1){
					settextstyle(20, 10, (LPCTSTR)"����");
					putimage(530, 27, 20, 20, &img_bk1, 530, 27, SRCCOPY);
					outtextxy(530, 27, (LPCTSTR)to_string(--StepNum2).data());
					settextstyle(25, 15, (LPCTSTR)"����", 2700, 0, 0, 0, 0, 0);//��25�����أ���15������
					outtextxy(575, 50, (LPCTSTR)"�׷�����");
					settextstyle(25, 15, (LPCTSTR)"����", 0, 0, 0, 0, 0, 0);//��25�����أ���15������
					clearrectangle(10, 70, 40, 150);
					putimage(10, 70, 30 + 1, 100 + 1, &img_bk1, 10, 70, SRCCOPY);
					player = 2;
				}
				else{
					settextstyle(20, 10, (LPCTSTR)"����");
					putimage(60, 27, 20, 20, &img_bk1, 60, 27, SRCCOPY);
					outtextxy(60, 27, (LPCTSTR)to_string(--StepNum1).data());
					settextstyle(25, 15, (LPCTSTR)"����", 2700, 0, 0, 0, 0, 0);//��25�����أ���15������
					outtextxy(25, 50, (LPCTSTR)"�ڷ�����");
					settextstyle(25, 15, (LPCTSTR)"����", 0, 0, 0, 0, 0, 0);//��25�����أ���15������
					clearrectangle(560, 70, 590, 150);
					putimage(560, 70, 30 + 1, 100 + 1, &img_bk1, 560, 70, SRCCOPY);
					player = 1;
				}
			}
			else{
				MessageBox(hq, (LPCTSTR) "���������һ��", "�Ѿ��ڹ�����", MB_OK);
			}
		}
		//��������������
		if (msg.uMsg == WM_LBUTTONDOWN){
			int i = 0, j = 0;
			for (int column = 71; j < GridSize; j++, j % 2 == 0 ? column += InternalSize : column += InternalSize - 1){
				if (msg.x <= column + 10 && msg.x >= column - 10){//��������������	
					for (int row = 70; i < GridSize; i++, i % 2 == 0 ? row += InternalSize : row += InternalSize - 1){
						if (msg.y <= row + 10 && msg.y >= row - 10){//��������������
							Pre_i = i; Pre_j = j; UndoAble = true;
							Pre_C = column; Pre_R = row;
							if (player == 1 && a[i][j] == 0){
								setfillcolor(BLACK);
								solidcircle(column, row, 12);
								a[i][j] = 1;
								settextstyle(20, 10, (LPCTSTR)"����", 0, 0, 0, 0, 0, 0);
								putimage(60, 27, 20, 20, &img_bk1, 60, 27, SRCCOPY);
								outtextxy(60, 27, (LPCTSTR)to_string(++StepNum1).data());
								settextstyle(25, 15, (LPCTSTR)"����", 2700, 0, 0, 0, 0, 0);//��25�����أ���15������
								outtextxy(575, 50, (LPCTSTR)"�׷�����");
								settextstyle(25, 15, (LPCTSTR)"����", 0, 0, 0, 0, 0, 0);//��25�����أ���15������
								clearrectangle(10, 70, 40, 200);
								putimage(10, 70, 30 + 1, 100 + 1, &img_bk1, 10, 70, SRCCOPY);
								if (IsWin(i, j, 1)){
									settextstyle(25, 15, (LPCTSTR)"����");//��25�����أ���15������
									putimage(265, 15, 75, 25, &img_bk1, 265, 15, SRCCOPY);
									str = to_string(++Player1WinCount) + " : " + to_string(Player2WinCount);
									outtextxy(265, 15, (LPCTSTR)str.data());
									return IsAgain(1);//�ж��Ƿ�Ӯ���Ƿ������
								}
								player = 2;
								break;
							}
							else if (player == 2 && a[i][j] == 0){
								setfillcolor(WHITE);
								solidcircle(column, row, 12);
								a[i][j] = 2;
								settextstyle(20, 10, (LPCTSTR)"����", 0, 0, 0, 0, 0, 0);
								putimage(530, 27, 20, 20, &img_bk1, 530, 27, SRCCOPY);
								outtextxy(530, 27, (LPCTSTR)to_string(++StepNum2).data());
								settextstyle(25, 15, (LPCTSTR)"����", 2700, 0, 0, 0, 0, 0);//��25�����أ���15������
								outtextxy(25, 50, (LPCTSTR)"�ڷ�����");
								settextstyle(25, 15, (LPCTSTR)"����", 0, 0, 0, 0, 0, 0);//��25�����أ���15������
								clearrectangle(560, 70, 590, 200);
								putimage(560, 70, 30 + 1, 100 + 1, &img_bk1, 560, 70, SRCCOPY);
								if (IsWin(i, j, 2)){
									settextstyle(25, 15, (LPCTSTR)"����");//��25�����أ���15������
									putimage(265, 15, 75, 25, &img_bk1, 265, 15, SRCCOPY);
									str = to_string(Player1WinCount) + " : " + to_string(++Player2WinCount);
									outtextxy(265, 15, (LPCTSTR)str.data());
									return IsAgain(2);//�ж��Ƿ�Ӯ���Ƿ������
								}
								player = 1;
								break;
							}
						}
					}
					break;
				}
			}
		}
	}
}
//�ж��Ƿ����˻�ʤ
bool IsWin(int i, int j, int player)
{
	int count = 1;
	//�ж������Ƿ�����������
	for (int index_i = i - 1, index_j = j; index_i >= 0 && a[index_i][index_j] == player; index_i--) count++;
	for (int index_i = i + 1, index_j = j; index_i < GridSize && a[index_i][index_j] == player; index_i++) count++;
	if (count >= 5)  return true;
	else count = 1;
	//�жϺ����Ƿ�����������
	for (int index_i = i, index_j = j - 1; index_j >= 0 && a[index_i][index_j] == player; index_j--) count++;
	for (int index_i = i, index_j = j + 1; index_j < GridSize && a[index_i][index_j] == player; index_j++) count++;
	if (count >= 5)  return true;
	else count = 1;
	//�ж�135��б���Ƿ�����������
	for (int index_i = i - 1, index_j = j - 1; index_i >= 0 && index_j >= 0 && a[index_i][index_j] == player; index_i--, index_j--) count++;
	for (int index_i = i + 1, index_j = j + 1; index_i < GridSize && index_j < GridSize&& a[index_i][index_j] == player; index_i++, index_j++) count++;
	if (count >= 5)  return true;
	else count = 1;
	//�ж�45��б���Ƿ�����������
	for (int index_i = i - 1, index_j = j + 1; index_i >= 0 && index_j < GridSize && a[index_i][index_j] == player; index_i--, index_j++) count++;
	for (int index_i = i + 1, index_j = j - 1; index_i < GridSize && index_j >= 0 && a[index_i][index_j] == player; index_i++, index_j--) count++;
	if (count >= 5)  return true;
	else count = 1;
	return false;
}
//��ʤ���ж��Ƿ����
bool IsAgain(int index)
{
	settextstyle(20, 10, (LPCTSTR)"����");
	settextcolor(YELLOW);
	if (index == 1) {
		outtextxy(250, 50, (LPCTSTR) "player1 win!");
	}
	else {
		outtextxy(250, 50, (LPCTSTR) "player2 win!");
	}
	HWND hq = FindWindow(NULL, "������˫�˶�ս");//��ȡ�����ھ��
	string str = "Player" + to_string(index) + "  Win";
	int quit = MessageBox(hq, (LPCTSTR) "�Ƿ������Ϸ", (LPCTSTR)str.data(), MB_YESNO);//
	if (IDYES == quit)
		return true;
	else
		return false;
}
//�˳���Ϸ
void DisplayExitGameMessage()
{
	cleardevice();//����
	IMAGE img;//ͼƬ����
	loadimage(&img, "./res/�˳�����.jpg");//������Ƭ
	putimage(0, 0, &img, SRCPAINT);//չʾ��Ƭ
	settextcolor(GREEN);//����������ɫ
	settextstyle(50, 20, (LPCTSTR)"����");//���������С
	outtextxy(160, 80, (LPCTSTR)"��ӭ�´�������");
	Sleep(1500);
}
