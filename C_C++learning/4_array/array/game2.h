#define _CRT_SECURE_NO_WARNINGS 1
#define ROW1 4
#define COL1 4
#define ROW2 ROW1+2
#define COL2 COL1+2
#define EASY_NUM 1


void InitMine(char Mine[ROW2][COL2], int row2, int col2,char set);
void DisplayMine(char Mine[ROW2][COL2], int row1, int col1);
void SetMine(char Mine[ROW2][COL2], int row1, int col1);
void FindMine(char Field[ROW2][COL2], char Show[ROW2][COL2], int row1, int col1);