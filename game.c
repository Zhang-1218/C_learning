#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void Init_Array(char Array[ROWS][COLS], int row, int col, char set)
{
	memset(Array, set, (row*col*sizeof(Array[0][0])));
}

void Display(char Array[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("      ");
	for (i = 1; i <= row; i++)
		printf(" %d  ", i);
	printf("\n      -----------------------------------\n");
	for (i = 1; i <=col; i++)
	{
		printf("   %d |",i);
		for (j = 1; j <= col; j++)
		{
			printf(" %c |", Array[i][j]);
		}
		printf("\n     |---|---|---|---|---|---|---|---|---|\n");
	}
	printf("\n");
}

void Set_Mine(char Array[ROWS][COLS], int MINE)
{
	int count = MINE;
	int x = 0;
	int y = 0;
	while (count)
	{
		x = rand() % ROW + 1;
		y = rand() % COL + 1;
		if (Array[x][y] == '0')
		{
			Array[x][y] = '1';
			count--;
		}
	}
}

void Get_Mine_Count(char Array[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	if (x < (ROWS - 1) && y < (COLS - 1) && x > 0 && y > 0)
	{
		if ((Array[x][y] == '0'))
		{
			int count = 0;
			if (Array[x - 1][y - 1] == '1')
				count++;
			if (Array[x - 1][y] == '1')
				count++;
			if (Array[x - 1][y + 1] == '1')
				count++;
			if (Array[x][y - 1] == '1')
				count++;
			if (Array[x][y + 1] == '1')
				count++;
			if (Array[x + 1][y - 1] == '1')
				count++;
			if (Array[x + 1][y] == '1')
				count++;
			if (Array[x + 1][y + 1] == '1')
				count++;
			show[x][y] = (count + '0');
		}
		if (show[x][y] == '0')
		{
			if (show[x - 1][y - 1] == '*')
				Get_Mine_Count(Array, show, x - 1, y - 1);

			if (show[x - 1][y] == '*')
				Get_Mine_Count(Array, show, x - 1, y);

			if (show[x - 1][y + 1] == '*')
				Get_Mine_Count(Array, show, x - 1, y + 1);

			if (show[x][y - 1] == '*')
				Get_Mine_Count(Array, show, x, y - 1);

			if (show[x][y + 1] == '*')
				Get_Mine_Count(Array, show, x, y + 1);

			if (show[x + 1][y - 1] == '*')
				Get_Mine_Count(Array, show, x + 1, y - 1);

			if (show[x + 1][y] == '*')
				Get_Mine_Count(Array, show, x + 1, y);

			if (show[x + 1][y + 1] == '*')
				Get_Mine_Count(Array, show, x + 1, y + 1);
		}
	}
}


void Move_mine(char Array[ROWS][COLS], int x, int y)
{
	int ret = 1;
	do
	{
		Array[x][y] = '0';
		while (ret)
		{
			x = rand() % ROW + 1;
			y = rand() % COL + 1;
			if (Array[x][y] == '0')
			{
				Array[x][y] = '1';
			}
			ret--;
		}
	} while (ret);
}

void Mark_Mine(char show[ROWS][COLS])
{
	int x = 0;
	int y = 0;
	printf("请输入您要标记的位置(不标记请输入0，0)：<");
	scanf("%d%d", &x, &y);
	printf("\n");
	if (x == 0 && y == 0)
		return 0;
	else
		show[x][y] = '$';
}

void Sweep_Mine(char Array[ROWS][COLS], char show[ROWS][COLS], int row, int col,int MINE)
{
	int x = 0;
	int y = 0;
	int count = 0;
	int temp = 0;
	int win = 0;
	while (win<(row*col-MINE))
	{
		printf("请输入您要扫雷的坐标：<");
		scanf("%d%d", &x, &y);
		temp++;
		if (((x >= 1) && (x <= row)) && (y >= 1) && (y <= col))
		{
			while ((Array[x][y] == '1') && (temp == 1))
			{
				Move_mine(Array, x, y);
				Get_Mine_Count(Array, show, x, y);
			}
			if (Array[x][y] == '1')
			{
				printf("\n哈哈，你被炸死啦!\n\n");
				Display(Array, ROW, COL);
				break;
			}
			else 
			{
				Get_Mine_Count(Array, show, x, y);
				printf("\n\n");
				win++;
			}
			Display(show, ROW, COL);
			Mark_Mine(show);
		}
		else
		{
			printf("坐标输入有误，请重新输入！\n");
		}
	}
	if (win == (row*col - MINE))
		printf("恭喜你，排完了所有的雷！\n");
}