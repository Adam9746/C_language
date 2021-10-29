#define _CRT_SECURE_NO_WARNINGS 1

// 指针
// 指针类型
#include <stdio.h>
#include <string.h>

int* test()
{
	int a4 = 10;
	return &a4;
}

// 求某个字符串的长度
int my_strlen1(char* str)
{
	int count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}
//递归实现
int my_strlen2(char* str)
{
	if (*str != '\0')
	{
		str++;
		return 1 + my_strlen2(str);
	}
	return 0;
}

int my_strlen3(char* str)
{
	char* start = str;
	char* end = str;
	while (*end != '\0')
	{
		end++;
	}
	return end - start;
}

int main()
{
	printf("%d\n", sizeof(char*));
	printf("%d\n", sizeof(short*));
	printf("%d\n", sizeof(int*));
	printf("%d\n", sizeof(double*));

	int a1 = 0x11223344;
	int a2 = 0x11223344;

	// 指针类型决定了指针进行解引用操作时能够访问空间的大小
	// int* p; *p能够访问4个字节
	// char* p; *p能够访问1个字节
	// double* p; *p能够访问8个字节

	int* p1 = &a1;
	*p1 = 0;
	printf("%#x\n", a1);
	char* p2 = &a2;
	*p2 = 0;
	printf("%#x\n", a2);

	printf("%p\n", p1);
	printf("%p\n", p2);

	// 指针+-整数
	// 指针类型决定了指针的步长
	// int*p: p+1 --> 4
	// char*p: p+1 --> 1
	// double*p: p+1 --> 8
	int a3 = 0x11223344;
	int* p3 = &a3;
	char* p4 = &a3;
	printf("%p\n", p3);
	printf("%p\n", p3 + 1);

	printf("%p\n", p4);
	printf("%p\n", p4 + 1);

	int arr1[10] = { 0 };

	int* p5 = arr1;
	int i1 = 0;
	for ( i1 = 0; i1 < 10; i1++)
	{
		*(p5 + i1) = 1;
	}

	int arr2[10] = { 0 };

	char* p6 = arr2;
	int i2 = 0;
	for (i2 = 0; i2 < 10; i2++)
	{
		*(p6 + i2) = 10;
	}

	// 野指针:指针指向的位置是不可知的(随机的,不正确的,没有明确限制的)
	//
	// 1.指针未初始化
	// int a; 局部变量不初始化,默认是随机值
	// int* p; 局部的指针变量,就被初始化为随机值
	// 
	// 2.指针越界访问
	// int arr3[10] = { 0 };
	// int* p7 = arr3;
	// int i3 = 0;
	// for ( i3 = 0; i3 < 12; i3++)
	// {
	//	 *p7 = i3;
	//   p7++;//野指针
	// }
	// 3.指针指向的内存空间释放
	
	// int* p8 = test();
	// *p8 = 20;
	// printf("%d\n",*p8);
	// p8 = NULL;
	// 
	// 规避野指针
	// 1. 指针初始化
	// 2. 小心指针越界
	// 3. 指针指向的空间释放时置为NULL
	// 4. 指针使用之前检查有效性

	int* p9 = NULL; // 指针变量初始化空值
	printf("%p\n", p9);

	// 检查指针的有效性
	if (p9 != NULL)
	{
		*p9 = 20;
	}


	// 指针运算
	// 
	// 指针+-整数
	// 指针-指针
	// 指针的关系运算(比较大小)

	int arr3[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int i4 = 0;
	int i5 = 0;
	int sz1 = sizeof(arr3) / sizeof(arr3[0]);
	int* p10 = arr3;
	int* p11 = &arr3[9];
	for ( i4 = 0; i4 < sz1; i4++)
	{
		printf("%d ", *(p10 + i4));
	}
	for (i5 = sz1; i5 > 0; i5--)
	{
		printf("%d ", *(p11 - i5 + 1));
	}

	char ch1[5] = { 0 };
	// 指针-指针 = 指针之间元素的个数
	printf("%d\n", &arr3[9] - &arr3[0]);
	printf("%d\n", &arr3[0] - &arr3[9]);
	printf("%d\n", &ch1[4] - &ch1[0]);

	// 求字符串的长度

	char ch2[] = "hit";
	int len3 = my_strlen3(ch2);
	printf("%d\n", len3);

	char* p12;
	for (p12 = &ch2[3];p12 > &ch2[0];)
	{
		*--p12 = 0;
	}

	// for (p12 = &ch2[2]; p12 >= &ch2[0];p12--)
	// {
	//		*p12 = 0;
	// }

	// 指针和数组
	// 
	// &数组名:数组名不是首元素的地址,数组名表示整个数组;取出的是整个数组的地址
	// sizeof(数组名):数组名表示整个数组;计算的是整个数组的大小,单位是字节

	printf("%p\n", arr3);
	printf("%p\n", arr3 + 1);
	printf("%p\n", &arr3[0]);
	printf("%p\n", &arr3[0] + 1);
	printf("%p\n", &arr3);
	printf("%p\n", &arr3 + 1);

	// 二级指针
	
	int a4 = 10;
	int* p13 = &a4;
	int** p14 = &p13; // 二级指针
	**p14 = 20;
	printf("%d\n", **p14);
	printf("%d\n", a4);

	// 指针数组:存放指针的数组

	int* arr4[4] = {&a1,&a2,&a3,&a4};
	int i6 = 0;
	for ( i6 = 0; i6 < 4; i6++)
	{
		printf("%d\n", *(arr4[i6]));
		printf("%d\n", **(arr4+i6));
	}

	return 0;
}

