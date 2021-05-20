#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

int x = 0;
int y = 0;

void Menu()
{
	printf("############################\n");
	printf("## 1. Play        0. Exit ##\n");
	printf("############################\n");
	printf("Please Select# ");
}

//按照x,y作为起点，按照特定的方向，求连续相对的最大格式
int ChessCount(int board[][COL], int row, int col, enum Dir d)
{
	int _x = x - 1; //从1
	int _y = y - 1; //从1

	int count = 0;
	while (1){
		switch (d){
		case LEFT:
			_y--;
			break;
		case RIGHT:
			_y++;
			break;
		case UP:
			_x--;
			break;
		case DOWN:
			_x++;
			break;
		case LEFT_UP:
			_x--, _y--;
			break;
		case LEFT_DOWN:
			_x++, _y--;
			break;
		case RIGHT_UP:
			_x--, _y++;
			break;
		case RIGHT_DOWN:
			_x++, _y++;
			break;
		default:
			//Do Nothing
			break;
		}
		if (_x < 0 || _x > row - 1 || _y < 0 || _y > col - 1){
			break;
		}
		//合法
		if (board[x - 1][y - 1] == board[_x][_y]){
			count++;
		}
		else{
			break;
		}
	}
	return count;
}

//4种情况
//NEXT:表明要继续
//PLAYER1_WIN: 用户1赢了
//PLAYER2_WIN：用户2赢了
//DRAW: 平局
int IsOver(int board[][COL], int row, int col)
{
	//import && hard
	//wu zi lian zhu 
	//x, y;
	int count1 = ChessCount(board, row, col, LEFT) + ChessCount(board, row, col, RIGHT) + 1; //?
	int count2 = ChessCount(board, row, col, UP) + ChessCount(board, row, col, DOWN) + 1; //?
	int count3 = ChessCount(board, row, col, LEFT_UP) + ChessCount(board, row, col, RIGHT_DOWN) + 1; //?
	int count4 = ChessCount(board, row, col, LEFT_DOWN) + ChessCount(board, row, col, RIGHT_UP) + 1; //?

	if (count1 >= 5 || count2 >= 5 || count3 >= 5 || count4 >= 5){
		//有五子连珠
		//一定有人赢
		//x, y
		if (board[x - 1][y - 1] == PLAYER1){
			return PLAYER1_WIN;
		}
		else{
			return PLAYER2_WIN;
		}
	}

	int i = 0;
	for (; i < row; i++){
		int j = 0;
		for (; j < col; j++){
			if (board[i][j] == 0){
				return NEXT;
			}
		}
	}

	return DRAW;
}

void ShowBoard(int board[][COL], int row, int col)
{
	//讲数组内容，进行可视化
	printf("  ");
	int i = 1;
	for (; i <= col; i++){
		printf("%3d", i);
	}
	printf("\n");

	for (i = 0; i < row; i++){
		int j = 0;
		printf("%2d ", i + 1);
		for (; j < col; j++){
			if (board[i][j] == 0){
				printf(" . ");
			}
			else if (board[i][j] == PLAYER1){
				printf("● ");
			}
			else{
				printf("○ ");
			}
		}
		printf("\n");
	}
}

void PlayerMove(int board[][COL], int row, int col, int who)
{
	while (1){
		printf("Player[%d] Please Enter Your Pos# ", who);
		scanf("%d %d", &x, &y);
		if (x < 1 || x > row || y < 1 || y > col){
			printf("Pos Is Not Right!\n");
			continue;
		}
		else if (board[x - 1][y - 1] != 0){
			printf("Pos Is Occupied!\n");
			continue;
		}
		else{
			//合法性，去重
			board[x - 1][y - 1] = who;
			break;
		}
	}
}

void Game()
{
	int board[ROW][COL];
	memset(board, 0, sizeof(board));
	int result = NEXT;
	do{
		ShowBoard(board, ROW, COL);
		PlayerMove(board, ROW, COL, PLAYER1);
		result = IsOver(board, ROW, COL);
		system("cls");//清屏
		if (NEXT != result){
			break;
		}
		ShowBoard(board, ROW, COL);
		PlayerMove(board, ROW, COL, PLAYER2);
		result = IsOver(board, ROW, COL);
		system("cls");//清屏
		if (NEXT != result){
			break;
		}
	} while (1);
	//p1 win, p2 win, draw
	switch (result){
	case PLAYER1_WIN:
		printf("恭喜用户1，你已经赢了!\n");
		break;
	case PLAYER2_WIN:
		printf("恭喜用户2，你已经赢了!\n");
		break;
	case DRAW:
		printf("平局，和气生财!\n");
		break;
	default:
		//do nothing!
		break;
	}
	ShowBoard(board, ROW, COL);
}