#include "game.h"
int a[GridSize][GridSize] = { 0 };// 棋盘标记场
IMAGE img_bk1, img_bk2;
int Player1WinCount = 0, Player2WinCount = 0;
//菜单
void menu()
{
	IMAGE img;//创建图片变量
	loadimage(&img, "./res/五子棋1.jpg");//加载初始界面  E:\\code\\test_5_24\\test_5_24
	putimage(0, 0, &img, SRCPAINT);//绘制图像到屏幕
	settextstyle(50, 20, (LPCTSTR)"楷体");//设置字体
	settextcolor(YELLOW);//设置字体颜色
	setbkmode(WHITE);//设置背景混合模式
	outtextxy(150, 100, (LPCTSTR)"五子棋双人对战");//在指定位置输出字符串
	outtextxy(200, 400, (LPCTSTR)"开始游戏");//在指定位置输出字符串
	outtextxy(200, 451, (LPCTSTR)"退出游戏");//在指定位置输出字符串
	PlayBGM();//播放音乐
	MOUSEMSG m;//定义鼠标变量
	while (true)
	{
		m = GetMouseMsg();//获取鼠标信息
		if (m.uMsg == WM_MOUSEMOVE && m.x >= 200 && m.x <= 360 && m.y >= 400 && m.y <= 450){//判断鼠标是否移动到了开始游戏，是则用黄色方框标记	
			setlinecolor(YELLOW);
			rectangle(200, 400, 360, 450);
		}
		else{
			setlinecolor(getbkcolor());
			rectangle(200, 400, 360, 450);
		}
		if (m.uMsg == WM_MOUSEMOVE && m.x >= 200 && m.x <= 360 && m.y >= 451 && m.y <= 500){//判断鼠标是否移动到了退出游戏，是则用黄色方框标记	
			setlinecolor(YELLOW);
			rectangle(200, 451, 360, 500);
		}
		else{
			setlinecolor(getbkcolor());
			rectangle(200, 451, 360, 500);
		}
		if (m.uMsg == WM_LBUTTONDOWN && m.x >= 200 && m.x <= 360 && m.y >= 400 && m.y <= 450){//判断是否点击开始游戏
			cleardevice();//清屏
			Sleep(200);
			bool Continue_Game = true;
			while (Continue_Game){
				Continue_Game = play();//开始游戏并循环判断是否继续游戏
			}
			break;
		}
		if (m.uMsg == WM_LBUTTONDOWN && m.x >= 200 && m.x <= 360 && m.y >= 451 && m.y <= 500){//判断是否点击退出游戏	
			break;
		}
	}
}
//打开BGM
void PlayBGM()
{
	//打开音乐,想多媒体设备接口发送一个字符串，代表指令 alias 取别名
	mciSendString("open ./res/亡灵序曲.mp3 alias BGM", 0, 0, 0);
	//播放音乐
	mciSendString("play BGM", 0, 0, 0);
	//关闭音乐
	//Sleep(3000);
	//mciSendString("close BGM", 0, 0, 0);
}
//设置初始界面
bool play()
{
	cleardevice();// 清屏
	graphdefaults();// 重置所有绘图设置为默认值
	display();//显示背景棋盘
	setlinecolor(WHITE);// 设置当前线条颜色
	settextstyle(20, 10, (LPCTSTR)"楷体");//设置字体大小
	settextcolor(GREEN);// 设置字体颜色
	setbkmode(WHITE);//// 设置背景混合模式
	outtextxy(5, 5, (LPCTSTR)"player1:黑子");
	outtextxy(5, 28, (LPCTSTR)"步数: ");
	outtextxy(475, 5, (LPCTSTR)"player2:白子");
	outtextxy(475, 28, (LPCTSTR) "步数: ");
	settextstyle(25, 15, (LPCTSTR)"楷体");//高25个像素，宽15个像素
	outtextxy(475, 560, (LPCTSTR) "退出游戏");
	outtextxy(10, 560, (LPCTSTR) "重新开始");
	outtextxy(270, 560, (LPCTSTR) "悔棋");
	return playgame();
}
//显示棋盘网格
void display()
{
	loadimage(&img_bk1, "./res/游戏背景.jpg");// 加载图片
	putimage(0, 0, &img_bk1, SRCPAINT);// 显示图片
	clearrectangle(50, 50, 550, 550);// 清空矩形区域
	loadimage(&img_bk2, "./res/五子棋棋盘.jpg");// 加载图片
	putimage(50, 50, &img_bk2, SRCPAINT);// 显示图片
}
// 正式开始游戏
bool playgame()
{
	settextstyle(25, 15, (LPCTSTR)"楷体");// 高25个像素，宽15个像素
	string str = to_string(Player1WinCount) + " : " + to_string(Player2WinCount);//
	outtextxy(265, 15, (LPCTSTR)str.data());//
	int StepNum1 = 0, StepNum2 = 0;
	settextstyle(20, 10, (LPCTSTR)"楷体");
	outtextxy(60, 27, (LPCTSTR)to_string(StepNum1).data());//
	outtextxy(530, 27, (LPCTSTR)to_string(StepNum2).data());//
	settextstyle(25, 15, (LPCTSTR)"楷体", 2700, 0, 0, 0, 0, 0);//高25个像素，宽15个像素
	outtextxy(25, 50, (LPCTSTR)"黑方落子");
	memset(a, 0, sizeof(a));
	int Pre_i = -1, Pre_j = -1, Pre_C = -1, Pre_R = -1;
	int player = 1; bool UndoAble = true;
	MOUSEMSG msg;
	while (true)
	{
		msg = GetMouseMsg();
		//“退出游戏”区域相关操作
		if (msg.uMsg == WM_MOUSEMOVE && msg.x >= 475 && msg.x <= 595 && msg.y >= 560 && msg.y <= 585){//判断鼠标是否移动到了退出游戏，是则用黄色方框标记
			setlinecolor(YELLOW);
			rectangle(475, 560, 595, 585);
		}
		else{
			setlinecolor(BLACK);
			rectangle(475, 560, 595, 585);
		}
		if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 460 && msg.x <= 580 && msg.y >= 550 && msg.y <= 575){//判断鼠标是否点击了退出游戏	
			return false;
		}
		//“重新开始”区域相关操作
		if (msg.uMsg == WM_MOUSEMOVE && msg.x >= 10 && msg.x <= 130 && msg.y >= 560 && msg.y <= 585){//判断鼠标是否移动到了退出游戏，是则用黄色方框标记	
			setlinecolor(YELLOW);
			rectangle(10, 560, 130, 585);
		}
		else{
			setlinecolor(BLACK);
			rectangle(10, 560, 130, 585);
		}
		if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 10 && msg.x <= 130 && msg.y >= 560 && msg.y <= 585){//判断鼠标是否点击了退出游戏	
			Player1WinCount = 0, Player2WinCount = 0;
			return true;
		}
		//“悔棋”区域相关操作
		if (msg.uMsg == WM_MOUSEMOVE && msg.x >= 270 && msg.x <= 330 && msg.y >= 560 && msg.y <= 585){//判断鼠标是否移动到了悔棋，是则用黄色方框标记	
			setlinecolor(YELLOW);
			rectangle(270, 560, 330, 585);
		}
		else{
			setlinecolor(BLACK);
			rectangle(270, 560, 330, 585);
		}
		if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 270 && msg.x <= 330 && msg.y >= 560 && msg.y <= 585)//判断鼠标是否点击了悔棋
		{
			HWND hq = FindWindow(NULL, "五子棋双人对战");//获取父窗口句柄
			if (Pre_i == -1) {
				MessageBox(hq, (LPCTSTR) "目前还不能悔棋", "提示", MB_OK);
			}
			else if (UndoAble){
				UndoAble = false;
				a[Pre_i][Pre_j] = 0;
				clearcircle(Pre_C, Pre_R, 12);
				putimage(Pre_C - 12, Pre_R - 12, 25, 25, &img_bk2, Pre_C - 12 - 50, Pre_R - 12 - 50, SRCCOPY);
				if (player == 1){
					settextstyle(20, 10, (LPCTSTR)"楷体");
					putimage(530, 27, 20, 20, &img_bk1, 530, 27, SRCCOPY);
					outtextxy(530, 27, (LPCTSTR)to_string(--StepNum2).data());
					settextstyle(25, 15, (LPCTSTR)"楷体", 2700, 0, 0, 0, 0, 0);//高25个像素，宽15个像素
					outtextxy(575, 50, (LPCTSTR)"白方落子");
					settextstyle(25, 15, (LPCTSTR)"楷体", 0, 0, 0, 0, 0, 0);//高25个像素，宽15个像素
					clearrectangle(10, 70, 40, 150);
					putimage(10, 70, 30 + 1, 100 + 1, &img_bk1, 10, 70, SRCCOPY);
					player = 2;
				}
				else{
					settextstyle(20, 10, (LPCTSTR)"楷体");
					putimage(60, 27, 20, 20, &img_bk1, 60, 27, SRCCOPY);
					outtextxy(60, 27, (LPCTSTR)to_string(--StepNum1).data());
					settextstyle(25, 15, (LPCTSTR)"楷体", 2700, 0, 0, 0, 0, 0);//高25个像素，宽15个像素
					outtextxy(25, 50, (LPCTSTR)"黑方落子");
					settextstyle(25, 15, (LPCTSTR)"楷体", 0, 0, 0, 0, 0, 0);//高25个像素，宽15个像素
					clearrectangle(560, 70, 590, 150);
					putimage(560, 70, 30 + 1, 100 + 1, &img_bk1, 560, 70, SRCCOPY);
					player = 1;
				}
			}
			else{
				MessageBox(hq, (LPCTSTR) "最多连续悔一次", "已经悔过棋了", MB_OK);
			}
		}
		//棋盘区域点击操作
		if (msg.uMsg == WM_LBUTTONDOWN){
			int i = 0, j = 0;
			for (int column = 71; j < GridSize; j++, j % 2 == 0 ? column += InternalSize : column += InternalSize - 1){
				if (msg.x <= column + 10 && msg.x >= column - 10){//检测鼠标点击所在列	
					for (int row = 70; i < GridSize; i++, i % 2 == 0 ? row += InternalSize : row += InternalSize - 1){
						if (msg.y <= row + 10 && msg.y >= row - 10){//检测鼠标点击所在行
							Pre_i = i; Pre_j = j; UndoAble = true;
							Pre_C = column; Pre_R = row;
							if (player == 1 && a[i][j] == 0){
								setfillcolor(BLACK);
								solidcircle(column, row, 12);
								a[i][j] = 1;
								settextstyle(20, 10, (LPCTSTR)"楷体", 0, 0, 0, 0, 0, 0);
								putimage(60, 27, 20, 20, &img_bk1, 60, 27, SRCCOPY);
								outtextxy(60, 27, (LPCTSTR)to_string(++StepNum1).data());
								settextstyle(25, 15, (LPCTSTR)"楷体", 2700, 0, 0, 0, 0, 0);//高25个像素，宽15个像素
								outtextxy(575, 50, (LPCTSTR)"白方落子");
								settextstyle(25, 15, (LPCTSTR)"楷体", 0, 0, 0, 0, 0, 0);//高25个像素，宽15个像素
								clearrectangle(10, 70, 40, 200);
								putimage(10, 70, 30 + 1, 100 + 1, &img_bk1, 10, 70, SRCCOPY);
								if (IsWin(i, j, 1)){
									settextstyle(25, 15, (LPCTSTR)"楷体");//高25个像素，宽15个像素
									putimage(265, 15, 75, 25, &img_bk1, 265, 15, SRCCOPY);
									str = to_string(++Player1WinCount) + " : " + to_string(Player2WinCount);
									outtextxy(265, 15, (LPCTSTR)str.data());
									return IsAgain(1);//判断是否赢及是否继续玩
								}
								player = 2;
								break;
							}
							else if (player == 2 && a[i][j] == 0){
								setfillcolor(WHITE);
								solidcircle(column, row, 12);
								a[i][j] = 2;
								settextstyle(20, 10, (LPCTSTR)"楷体", 0, 0, 0, 0, 0, 0);
								putimage(530, 27, 20, 20, &img_bk1, 530, 27, SRCCOPY);
								outtextxy(530, 27, (LPCTSTR)to_string(++StepNum2).data());
								settextstyle(25, 15, (LPCTSTR)"楷体", 2700, 0, 0, 0, 0, 0);//高25个像素，宽15个像素
								outtextxy(25, 50, (LPCTSTR)"黑方落子");
								settextstyle(25, 15, (LPCTSTR)"楷体", 0, 0, 0, 0, 0, 0);//高25个像素，宽15个像素
								clearrectangle(560, 70, 590, 200);
								putimage(560, 70, 30 + 1, 100 + 1, &img_bk1, 560, 70, SRCCOPY);
								if (IsWin(i, j, 2)){
									settextstyle(25, 15, (LPCTSTR)"楷体");//高25个像素，宽15个像素
									putimage(265, 15, 75, 25, &img_bk1, 265, 15, SRCCOPY);
									str = to_string(Player1WinCount) + " : " + to_string(++Player2WinCount);
									outtextxy(265, 15, (LPCTSTR)str.data());
									return IsAgain(2);//判断是否赢及是否继续玩
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
//判断是否有人获胜
bool IsWin(int i, int j, int player)
{
	int count = 1;
	//判断纵向是否有五子连珠
	for (int index_i = i - 1, index_j = j; index_i >= 0 && a[index_i][index_j] == player; index_i--) count++;
	for (int index_i = i + 1, index_j = j; index_i < GridSize && a[index_i][index_j] == player; index_i++) count++;
	if (count >= 5)  return true;
	else count = 1;
	//判断横向是否有五子连珠
	for (int index_i = i, index_j = j - 1; index_j >= 0 && a[index_i][index_j] == player; index_j--) count++;
	for (int index_i = i, index_j = j + 1; index_j < GridSize && a[index_i][index_j] == player; index_j++) count++;
	if (count >= 5)  return true;
	else count = 1;
	//判断135度斜轴是否有五子连珠
	for (int index_i = i - 1, index_j = j - 1; index_i >= 0 && index_j >= 0 && a[index_i][index_j] == player; index_i--, index_j--) count++;
	for (int index_i = i + 1, index_j = j + 1; index_i < GridSize && index_j < GridSize&& a[index_i][index_j] == player; index_i++, index_j++) count++;
	if (count >= 5)  return true;
	else count = 1;
	//判断45度斜轴是否有五子连珠
	for (int index_i = i - 1, index_j = j + 1; index_i >= 0 && index_j < GridSize && a[index_i][index_j] == player; index_i--, index_j++) count++;
	for (int index_i = i + 1, index_j = j - 1; index_i < GridSize && index_j >= 0 && a[index_i][index_j] == player; index_i++, index_j--) count++;
	if (count >= 5)  return true;
	else count = 1;
	return false;
}
//获胜并判断是否继续
bool IsAgain(int index)
{
	settextstyle(20, 10, (LPCTSTR)"楷体");
	settextcolor(YELLOW);
	if (index == 1) {
		outtextxy(250, 50, (LPCTSTR) "player1 win!");
	}
	else {
		outtextxy(250, 50, (LPCTSTR) "player2 win!");
	}
	HWND hq = FindWindow(NULL, "五子棋双人对战");//获取父窗口句柄
	string str = "Player" + to_string(index) + "  Win";
	int quit = MessageBox(hq, (LPCTSTR) "是否继续游戏", (LPCTSTR)str.data(), MB_YESNO);//
	if (IDYES == quit)
		return true;
	else
		return false;
}
//退出游戏
void DisplayExitGameMessage()
{
	cleardevice();//清屏
	IMAGE img;//图片变量
	loadimage(&img, "./res/退出背景.jpg");//加载照片
	putimage(0, 0, &img, SRCPAINT);//展示照片
	settextcolor(GREEN);//设置字体颜色
	settextstyle(50, 20, (LPCTSTR)"楷体");//设置字体大小
	outtextxy(160, 80, (LPCTSTR)"欢迎下次再来！");
	Sleep(1500);
}
