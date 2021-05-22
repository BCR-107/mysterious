#include "game.h"

int main()
{
	initgraph(600, 600);//初始化界面
	menu();//初始化菜单
	DisplayExitGameMessage();//退出游戏界面
	closegraph();//关闭
	return 0;
}
