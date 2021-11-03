#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// ʵ�õ��Լ���
//
// Debug�汾(���԰汾):   �ɵ���,��Ϊ�ļ��а����˵�����Ϣ
// Release�汾(�����汾): �ڴ����С�������ٶ��Ͻ������Ż�

// ���Կ�ݼ�
// F5(��������)��F9(����/ȡ���ϵ�)���ʹ��
// F10(�����),һ�����̿�����һ�κ�������,������һ�����
// F11(�����),ִ���߼�Ҫ���뺯���ڲ�
// shift+F11(���������ڲ�)
// shift+F5(ֹͣ����)

// ����ʱ�鿴����ǰ����Ϣ
// 1.�鿴��ʱ������ֵ:���Ӵ���,�Զ�����,�ֲ�����
// 2.�鿴�ڴ���Ϣ
// 3.�鿴���ö�ջ
// 4.�鿴�����Ϣ
// 5.�鿴�Ĵ�����Ϣ

// ��̳����Ĵ���
// 1.�����ʹ���(�﷨����)
// 2.�����ʹ���(�޷��������ⲿ����)
// 3.����ʱ����(������Ŵ�)

int Add(int x, int y)
{
	return x + y;
}

void test3()
{
	printf("haha");
}

void test2()
{
	test3();
}

void test1()
{
	test2();
}

void my_strcpy1(char* des, char* src)
{
	while (*src != '\0')
	{
		*des = *src;
		src++;
		des++;
	}
	*des = *src;
}

void my_strcpy2(char* des, char* src)
{
	if (des != NULL && src != NULL) // �ж�ָ�����Ч��
	{
		while (*des++ = *src++)
			{
				;
			}
	} 
}

void my_strcpy3(char* des, char* src)
{
	assert(des != NULL); //����:���ʽΪ��,���򱨴�;���ʽΪ��,�������ִ��.
	assert(src != NULL);

	while (*des++ = *src++)
	{
		;
	}
}

char* my_strcpy4(char* des, const char* src) // *src���ܱ��ı�,src���Ա��ı�
{
	char* ret = des;
	assert(des != NULL); //����:���ʽΪ��,���򱨴�;���ʽΪ��,�������ִ��.
	assert(src != NULL);

	while (*des++ = *src++)
	{
		;
	}
	return ret; // ����Ŀ���ַ�������ʼ��ַ
}

int my_strlen(const char* str)
{
	int count = 0;
	assert(str != NULL);

	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}

int main()
{
	int i1 = 0;

	for ( i1 = 0; i1 < 100; i1++)
	{
		printf("%d ", i1);
	}

	for (i1 = 0; i1 < 100; i1++)
	{
		printf("%d ", 100 - i1);
	}

	int a1 = 10;
	int a2 = 20;
	int a3 = Add(a1, a2);

	//// Debug and Release
	//// 
	//int i2 = 0;
	//int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
	//for (i2 = 0; i2 <= 12; i2++)
	//{
	// 	printf("haha\n");
	// 	arr1[i2] = 0;
	//}
	//system("pause");

	int i3 = 0;
	int arr2[10] = { 0 };
	for (i3 = 0; i3 < 10; i3++)
	{
		arr2[i3] = i3;
	}

	//���ö�ջ
	test1();

	// ջ����Ĭ��ʹ��:��ʹ�øߵ�ַ���Ŀռ�,��ʹ�õ͵�ַ���Ŀռ�

	// ģ��ʵ�ֿ⺯��:strcpy

	char arr3[] = "##########";
	char arr4[] = "hit";

	my_strcpy1(arr3, arr4);
	my_strcpy2(arr3, arr4);
	my_strcpy3(arr3, arr4);
	printf("%s\n",my_strcpy4(arr3, arr4)); // ��ʽ����
	printf("%s\n", arr3);

	// const:ָ�볣���ͳ���ָ�� 
	const int a4 = 10;
	const int a5 = 15;
	const int a6 = 20;

	const int* p1 = &a4;
	// *p1 = 20;  // const ����ָ�������*���ʱ,���ε���*p1,����ͨ��p���ı�*p1 (a4)��ֵ

	int* const p2 = &a5;
	*p2 = 30;  // p2 = &a4;  // const ����ָ�������*�ұ�ʱ,���ε���p2����,p2���ܱ��ı�

	const int* const p3 = &a6;

	printf("%d\n", a4); 
	printf("%d\n", a5);

	// ʵ�ֿ⺯��:strlen
	char arr5[] = "abcdefg";
	int len1 = my_strlen(arr5);
	printf("%d\n", len1);






	return 0;

}