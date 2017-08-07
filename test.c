#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void game()
{
	int input = 0;
	int MINE = 0;
	char mine[ROWS][COLS];
	char show[ROWS][COLS];
	Init_Array(mine, ROWS, COLS, '0');
	Init_Array(show, ROWS, COLS, '*');
	printf("***********  1.EASY    2.HARD  ***********\n");
	printf("\n������ѡ����Ѷ�:< ");
	scanf("%d", &input);
	switch (input)
	{
	case 1:
		MINE = EASY;
		break;
	case 2:
		MINE = HARD;
		break;
	default:printf("������������\n");
	}
	printf("\n���������%d���ף�С�Ŀ�!!!\n\n", MINE);
	Set_Mine(mine, MINE);
	Display(show,ROW,COL);
	Sweep_Mine(mine, show, ROW, COL,MINE);
}

void menu()
{
	printf("******************************************\n");
	printf("***********    ��ӭ����ɨ��    ***********\n");
	printf("***********  1.PLAY    0.EXIT  ***********\n");
	printf("******************************************\n");
}

void test()
{
	int input;
	do
	{
		srand((unsigned int)rand(NULL));
		menu();
		printf("\n��ѡ��< ");
		scanf("%d", &input);
		printf("\n");
		switch (input)
		{
		case 1:
				game();
				break;
		case 0:
			printf("�����˳���Ϸ��лл��\n");
			break;
		default:
			printf("���벻�Ϸ�,���������룡\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
	system("pause");
	return 0;
}