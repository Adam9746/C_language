#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// 实用调试技巧
//
// Debug版本(调试版本):   可调试,因为文件中包含了调试信息
// Release版本(发布版本): 在代码大小和运行速度上进行了优化

// 调试快捷键
// F5(启动调试)和F9(创建/取消断点)配合使用
// F10(逐过程),一个过程可以是一次函数调用,或者是一条语句
// F11(逐语句),执行逻辑要进入函数内部
// shift+F11(跳出函数内部)
// shift+F5(停止调试)

// 调试时查看程序当前的信息
// 1.查看临时变量的值:监视窗口,自动窗口,局部变量
// 2.查看内存信息
// 3.查看调用堆栈
// 4.查看汇编信息
// 5.查看寄存器信息

// 编程常见的错误
// 1.编译型错误(语法错误)
// 2.链接型错误(无法解析的外部符号)
// 3.运行时错误(需调试排错)

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
	if (des != NULL && src != NULL) // 判断指针的有效性
	{
		while (*des++ = *src++)
			{
				;
			}
	} 
}

void my_strcpy3(char* des, char* src)
{
	assert(des != NULL); //断言:表达式为假,程序报错;表达式为真,程序继续执行.
	assert(src != NULL);

	while (*des++ = *src++)
	{
		;
	}
}

char* my_strcpy4(char* des, const char* src) // *src不能被改变,src可以被改变
{
	char* ret = des;
	assert(des != NULL); //断言:表达式为假,程序报错;表达式为真,程序继续执行.
	assert(src != NULL);

	while (*des++ = *src++)
	{
		;
	}
	return ret; // 返回目标字符串的起始地址
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

	//调用堆栈
	test1();

	// 栈区的默认使用:先使用高地址处的空间,再使用低地址处的空间

	// 模拟实现库函数:strcpy

	char arr3[] = "##########";
	char arr4[] = "hit";

	my_strcpy1(arr3, arr4);
	my_strcpy2(arr3, arr4);
	my_strcpy3(arr3, arr4);
	printf("%s\n",my_strcpy4(arr3, arr4)); // 链式访问
	printf("%s\n", arr3);

	// const:指针常量和常量指针 
	const int a4 = 10;
	const int a5 = 15;
	const int a6 = 20;

	const int* p1 = &a4;
	// *p1 = 20;  // const 放在指针变量的*左边时,修饰的是*p1,不能通过p来改变*p1 (a4)的值

	int* const p2 = &a5;
	*p2 = 30;  // p2 = &a4;  // const 放在指针变量的*右边时,修饰的是p2本身,p2不能被改变

	const int* const p3 = &a6;

	printf("%d\n", a4); 
	printf("%d\n", a5);

	// 实现库函数:strlen
	char arr5[] = "abcdefg";
	int len1 = my_strlen(arr5);
	printf("%d\n", len1);






	return 0;

}