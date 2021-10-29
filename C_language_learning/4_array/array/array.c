#define _CRT_SECURE_NO_WARNINGS 1
#include "game1.h"
#include "game2.h"
// ����Ĵ���,��ʼ��,ʹ�ú����ڴ��еĴ洢

// ������һ����ͬ����Ԫ�صļ���


// ����������ʵ��ð������(����)
// �������ڵ�Ԫ�ؽ��бȽ�(һ��ð������)
void bubble_sort(int arr[],int sz) // int arr[] <=> int* arr
{
	// ȷ��ð�����������
	for (int i1 = 0; i1 < sz - 1; i1++)
	{
		int flag = 1;//�������Ҫ����������Ѿ�����

		for (int j = 0; j < sz - i1 - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
				flag = 0;// ������������ݲ���ȫ����
			}
		}
		if (flag == 1) // ����Ҫ����������Ѿ�����
		{
			break;
		}
	}
}

//��������Ϸ
void menu1()
{
	printf("*********������**********\n");
	printf("****1.play   2.exit****\n");
	printf("***********************\n");
}
void game1()
{
	char board[ROW][COL] = {0};//ȫ��Ϊ�ո�

	// ��ʼ������
	InitBoard(board, ROW, COL);
	
	// ��ӡ����
	DisplayBoard(board,ROW,COL);

	// ����
	char ret;

	while (1)
	{
		//�������'*'
		PlayerMove(board,ROW,COL);
		DisplayBoard(board, ROW, COL);
		//�ж���Ӯ
		ret = Iswin(board,ROW,COL);

		if (ret != 'C')
		{
			break;
		}

		//���Ժ���'#'
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�ж���Ӯ
		ret = Iswin(board, ROW, COL);

		if (ret != 'C')
		{
			break;
		}
	}

	if (ret == '*')
	{
		printf("���Ӯ\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ\n");
	}
	else
	{
		printf("ƽ��\n");
	}

}
void test1()
{
	int input1;
	srand((unsigned int)time(NULL));
	do
	{
		menu1();
		printf("��ѡ��:>");
		scanf("%d", &input1);
		switch (input1)
		{
		case 1:
			printf("������\n");
			game1();
			break;
		case 2:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����,������ѡ��!\n");
			break;
		}
	} while (input1 != 2);
}


// ɨ����Ϸ

void menu2()
{
	printf("*********ɨ��**********\n");
	printf("****1.play   2.exit****\n");
	printf("***********************\n");
}

void game2()
{
	//�׵���Ϣ�洢
	// 1. ���úõ��׵���Ϣ
	char MineField[ROW2][COL2] = { 0 };
	// 2. �Ų�����׵���Ϣ
	char MineShow[ROW2][COL2] = { 0 };

	// ��ʼ��
	InitMine(MineField, ROW2, COL2,'0');
	InitMine(MineShow, ROW2, COL2,'*');

	// ��ӡ����
	// DisplayMine(MineField, ROW1, COL1);
	DisplayMine(MineShow, ROW1, COL1);

	// ������
	SetMine(MineField, ROW1, COL1);
	// DisplayMine(MineField, ROW1, COL1);

	// ����
	FindMine(MineField, MineShow, ROW1, COL1);
}

void test2()
{
	int input2;
	srand((unsigned int)time(NULL));
	do
	{
		menu2();
		printf("��ѡ��:>");
		scanf("%d", &input2);
		switch (input2)
		{
		case 1:
			printf("ɨ��\n");
			game2();
			break;
		case 2:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����,������ѡ��!\n");
			break;
		}
	} while (input2 != 2);
}
int main()
{
	// һά����Ĵ����ͳ�ʼ��

	int arr1[10] = { 1,2,3 };//����ȫ��ʼ��,ʣ���Ԫ��Ĭ�ϳ�ʼ��Ϊ0
	
	char arr2[5] = { 'a','b' };
	char arr3[5] = "abc";
	char arr4[] = "abc";

	printf("%d\n", sizeof(arr4));//sizeof �������,����,������ռ�ռ�Ĵ�С,��λ���ֽ�
	printf("%d\n", strlen(arr4));//strlen ֻ������ַ����󳤶�
	printf("%d\n", sizeof(arr2));
	printf("%d\n", strlen(arr2));

	// һά�����ʹ��

	printf("%c\n", arr3[1]);
	for (int i1 = 0; i1 < (int)strlen(arr3); i1++) //strlen()Ĭ�Ϸ���ֵΪ�޷�������ֵ
	{
		printf("%c\n", arr3[i1]);
	}

	int num1 = sizeof(arr1) / sizeof(arr1[0]);
	for (int i2 = 0; i2 < num1; i2++)
	{
		printf("%d ", arr1[i2]);
	}
	printf("\n");

	// һά�������ڴ��еĴ洢

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
		//  �������ڴ�����������ŵ�
	}

	// ��ά����Ĵ����ͳ�ʼ��

	int arr5[3][4] = { 1,2,3,4,5,6 };
	int arr6[3][4] = { {1,2,3},{4,5,6} }; 
	int arr7[][4] = { 1,2,3,4,5,6 }; // ��ά�����ʼ��ʱ,��������ʡ��,��������ʡ��
	int arr8[][4] = { {1,2,3},{4,5,6} };

	//��ά�����ʹ��

	for (int i4 = 0; i4 < 3; i4++)
	{
		for (int j1 = 0; j1 < 4; j1++)
		{
			printf("%d ", arr5[i4][j1]);
		}
		printf("\n");
	}

	// ��ά�������ڴ��еĴ洢

	for (int i5 = 0; i5 < 3; i5++)
	{
		for (int j1 = 0; j1 < 4; j1++)
		{
			printf("%p ", &arr5[i5][j1]);
		}
		printf("\n");
	}
	
	// ������Ϊ��������

	// ð�������� bubble_sort()
	int sz1 = sizeof(arr1) / sizeof(arr1[0]); // ����Ԫ�ظ���

	bubble_sort(arr1,sz1);

	for (int i6 = 0; i6 < sz1; i6++)
	{
		printf("%d ", arr1[i6]);
	}
	printf("\n");

	// ������
	
	// ��������������Ԫ�صĵ�ַ(��������)
	// 1. sizeof(������) - ��������ʾ��������;sizeof(������)���������������Ĵ�С,��λ���ֽ�
	// 2. &������ - ��������ʾ��������;&������,ȡ��������������ĵ�ַ

	printf("%p\n", arr1); // ������Ԫ�صĵ�ַ		003EFAF4
	printf("%p\n", arr1 + 1); //				003EFAF8

	printf("%p\n", &arr1[0]);// ������Ԫ�صĵ�ַ	003EFAF4
	printf("%p\n", &arr1[0] + 1); //			003EFAF8

	printf("%d\n", *arr1); // ������Ԫ��			0

	printf("%p\n", &arr1); // ����ĵ�ַ			003EFAF4
	printf("%p\n", &arr1 + 1); //				003EFB1C
	
	// �����Ӧ��ʵ��:������
	test1();
	test2();
	return 0;
}


