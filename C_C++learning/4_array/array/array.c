#define _CRT_SECURE_NO_WARNINGS 1
#include "game1.h"
#include "game2.h"
// 数组的创建,初始化,使用和在内存中的存储

// 数组是一组相同类型元素的集合


// 对整型数组实现冒泡排序(升序)
// 两两相邻的元素进行比较(一趟冒泡排序)
void bubble_sort(int arr[],int sz) // int arr[] <=> int* arr
{
	// 确定冒泡排序的趟数
	for (int i1 = 0; i1 < sz - 1; i1++)
	{
		int flag = 1;//假设此趟要排序的数据已经有序

		for (int j = 0; j < sz - i1 - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
				flag = 0;// 本趟排序的数据不完全有序
			}
		}
		if (flag == 1) // 此趟要排序的数据已经有序
		{
			break;
		}
	}
}

//三子棋游戏
void menu1()
{
	printf("*********三子棋**********\n");
	printf("****1.play   2.exit****\n");
	printf("***********************\n");
}
void game1()
{
	char board[ROW][COL] = {0};//全部为空格

	// 初始化棋盘
	InitBoard(board, ROW, COL);
	
	// 打印棋盘
	DisplayBoard(board,ROW,COL);

	// 下棋
	char ret;

	while (1)
	{
		//玩家先手'*'
		PlayerMove(board,ROW,COL);
		DisplayBoard(board, ROW, COL);
		//判断输赢
		ret = Iswin(board,ROW,COL);

		if (ret != 'C')
		{
			break;
		}

		//电脑后手'#'
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断输赢
		ret = Iswin(board, ROW, COL);

		if (ret != 'C')
		{
			break;
		}
	}

	if (ret == '*')
	{
		printf("玩家赢\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢\n");
	}
	else
	{
		printf("平局\n");
	}

}
void test1()
{
	int input1;
	srand((unsigned int)time(NULL));
	do
	{
		menu1();
		printf("请选择:>");
		scanf("%d", &input1);
		switch (input1)
		{
		case 1:
			printf("三子棋\n");
			game1();
			break;
		case 2:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误,请重新选择!\n");
			break;
		}
	} while (input1 != 2);
}


// 扫雷游戏

void menu2()
{
	printf("*********扫雷**********\n");
	printf("****1.play   2.exit****\n");
	printf("***********************\n");
}

void game2()
{
	//雷的信息存储
	// 1. 布置好的雷的信息
	char MineField[ROW2][COL2] = { 0 };
	// 2. 排查出的雷的信息
	char MineShow[ROW2][COL2] = { 0 };

	// 初始化
	InitMine(MineField, ROW2, COL2,'0');
	InitMine(MineShow, ROW2, COL2,'*');

	// 打印雷区
	// DisplayMine(MineField, ROW1, COL1);
	DisplayMine(MineShow, ROW1, COL1);

	// 布置雷
	SetMine(MineField, ROW1, COL1);
	// DisplayMine(MineField, ROW1, COL1);

	// 排雷
	FindMine(MineField, MineShow, ROW1, COL1);
}

void test2()
{
	int input2;
	srand((unsigned int)time(NULL));
	do
	{
		menu2();
		printf("请选择:>");
		scanf("%d", &input2);
		switch (input2)
		{
		case 1:
			printf("扫雷\n");
			game2();
			break;
		case 2:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误,请重新选择!\n");
			break;
		}
	} while (input2 != 2);
}
int main()
{
	// 一维数组的创建和初始化

	int arr1[10] = { 1,2,3 };//不完全初始化,剩余的元素默认初始化为0
	
	char arr2[5] = { 'a','b' };
	char arr3[5] = "abc";
	char arr4[] = "abc";

	printf("%d\n", sizeof(arr4));//sizeof 计算变量,数组,类型所占空间的大小,单位是字节
	printf("%d\n", strlen(arr4));//strlen 只能针对字符串求长度
	printf("%d\n", sizeof(arr2));
	printf("%d\n", strlen(arr2));

	// 一维数组的使用

	printf("%c\n", arr3[1]);
	for (int i1 = 0; i1 < (int)strlen(arr3); i1++) //strlen()默认返回值为无符号整型值
	{
		printf("%c\n", arr3[i1]);
	}

	int num1 = sizeof(arr1) / sizeof(arr1[0]);
	for (int i2 = 0; i2 < num1; i2++)
	{
		printf("%d ", arr1[i2]);
	}
	printf("\n");

	// 一维数组在内存中的存储

	for (int i3 = 0; i3 < num1; i3++)
	{
		printf("&arr1[%d] = %p\n",i3, &arr1[i3]);
		//	&arr1[0] = 010FFB8C
		//	&arr1[1] = 010FFB90
		//	&arr1[2] = 010FFB94
		//	&arr1[3] = 010FFB98
		//	&arr1[4] = 010FFB9C
		//	&arr1[5] = 010FFBA0
		//	&arr1[6] = 010FFBA4
		//	&arr1[7] = 010FFBA8
		//	&arr1[8] = 010FFBAC
		//	&arr1[9] = 010FFBB0
		//  数组在内存中是连续存放的
	}

	// 二维数组的创建和初始化

	int arr5[3][4] = { 1,2,3,4,5,6 };
	int arr6[3][4] = { {1,2,3},{4,5,6} }; 
	int arr7[][4] = { 1,2,3,4,5,6 }; // 二维数组初始化时,行数可以省略,列数不能省略
	int arr8[][4] = { {1,2,3},{4,5,6} };

	//二维数组的使用

	for (int i4 = 0; i4 < 3; i4++)
	{
		for (int j1 = 0; j1 < 4; j1++)
		{
			printf("%d ", arr5[i4][j1]);
		}
		printf("\n");
	}

	// 二维数组在内存中的存储

	for (int i5 = 0; i5 < 3; i5++)
	{
		for (int j1 = 0; j1 < 4; j1++)
		{
			printf("%p ", &arr5[i5][j1]);
		}
		printf("\n");
	}
	
	// 数组作为函数参数

	// 冒泡排序函数 bubble_sort()
	int sz1 = sizeof(arr1) / sizeof(arr1[0]); // 数组元素个数

	bubble_sort(arr1,sz1);

	for (int i6 = 0; i6 < sz1; i6++)
	{
		printf("%d ", arr1[i6]);
	}
	printf("\n");

	// 数组名
	
	// 数组名是数组首元素的地址(两个例外)
	// 1. sizeof(数组名) - 数组名表示整个数组;sizeof(数组名)计算的是整个数组的大小,单位是字节
	// 2. &数组名 - 数组名表示整个数组;&数组名,取出的是整个数组的地址

	printf("%p\n", arr1); // 数组首元素的地址		003EFAF4
	printf("%p\n", arr1 + 1); //				003EFAF8

	printf("%p\n", &arr1[0]);// 数组首元素的地址	003EFAF4
	printf("%p\n", &arr1[0] + 1); //			003EFAF8

	printf("%d\n", *arr1); // 数组首元素			0

	printf("%p\n", &arr1); // 数组的地址			003EFAF4
	printf("%p\n", &arr1 + 1); //				003EFB1C
	
	// 数组的应用实例:三子棋
	test1();
	test2();
	return 0;
}


