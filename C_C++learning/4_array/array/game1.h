#define _CRT_SECURE_NO_WARNINGS 1
#define ROW 3
#define COL 3
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// 三子棋
// 函数声明
void InitBoard(char board[ROW][COL], int row, int col);
void DisplayBoard(char board[ROW][COL], int row, int col);
void PlayerMove(char board[ROW][COL], int row, int col);
void ComputerMove(char board[ROW][COL], int row, int col);
char Iswin(char board[ROW][COL], int row, int col);