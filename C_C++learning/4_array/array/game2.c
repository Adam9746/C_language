#define _CRT_SECURE_NO_WARNINGS 1
#include "game1.h"
#include "game2.h"

void InitMine(char Mine[ROW2][COL2], int row2, int col2,char set)
{
	int i = 0;
	int j = 0;
	for ( i = 0; i < row2; i++)
	{
		for ( j = 0; j < col2; j++)
		{
			Mine[i][j] = set;
		}
	}
}

void DisplayMine(char Mine[ROW2][COL2], int row1, int col1)
{
	int i;
	int j;

	// 打印列号
	printf("   ");
	for (j = 1; j <= col1; j++)
	{
		printf(" %d ", j);
	}
	printf("\n");

	for (i = 1; i <= row1; i++)
	{
		printf(" %d ", i);
		for (j = 1; j <= col1; j++)
		{
			printf(" %c ", Mine[i][j]);
		}
		printf("\n");
	}
}

void SetMine(char Mine[ROW2][COL2], int row1, int col1)
{
	int Minenum = EASY_NUM;
	int x, y;
	int i = 0;

	while(Minenum)
	{
		x = rand() % row1 + 1;
		y = rand() % col1 + 1;

		if (Mine[x][y] == '0')
		{
			Mine[x][y] = '1';
			Minenum--;
		}
		
	}
}

//'1'-'0'= 1
int get_minenum(char Field[ROW2][COL2], int x, int y)
{
	return Field[x - 1][y] + Field[x - 1][y - 1] + Field[x][y - 1] + Field[x + 1][y - 1] + Field[x + 1][y] + Field[x + 1][y + 1] + Field[x][y + 1] + Field[x - 1][y + 1] - 8 * '0';
}

//void Expand_safefield(char Field[ROW2][COL2], char Show[ROW2][COL2], int x, int y,int row1, int col1)
//{
//	if (get_minenum(Field, x, y) == 0)
//	{
//		Show[x][y] = ' ';
//
//		int i, j;
//
//		for (i = x - 1; i <= x + 1; i++)
//		{
//			for (j = y - 1; j <= y + 1; j++)
//			{
//				if (i != x || j != y && i >= 1 && j>=1 && i<=row1 && j<= col1)
//				{
//					Expand_safefield(Field, Show, i, j, row1, col1);
//				}
//			}
//		} 
//	}
//	else
//	{
//		Show[x][y] = get_minenum(Field, x, y) + '0';
//	}
//}

void FindMine(char Field[ROW2][COL2], char Show[ROW2][COL2], int row1, int col1)
{
	int x = 0;
	int y = 0;
	int i, j;
	
	while (1)
	{
		printf("请输入排雷坐标:>\n");
		scanf("%d%d", &x, &y);

		//判断(x,y)的合法性
		if (x >= 1 && x <= row1 && y >= 1 && y <= col1)
		{
			if (Field[x][y] == '1')
			{
				printf("踩雷,游戏结束!\n");
				DisplayMine(Field, row1, col1);
				break;
			}
			else // 计算(x,y)周围有几个雷
			{
				int minenum = get_minenum(Field, x, y);

				Show[x][y] = minenum + '0';
				
				// Expand_safefield(Field,Show, x, y, row1, col1);

				DisplayMine(Show, row1, col1);

				int countmine = 0;

				for (i = 1; i <= row1; i++)
				{
					for (j = 1; j <= col1; j++)
					{
						if (Show[i][j] == '*')
						{
							countmine++;
						}
					}
				}
				if (countmine == EASY_NUM)
				{
					printf("扫雷成功!\n");
					DisplayMine(Field, ROW1, COL1);
					break;
				}
			}
		}
		else
		{
			printf("坐标非法,请重新输入:>\n");
		}
	}
}