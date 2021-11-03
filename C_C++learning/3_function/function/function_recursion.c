#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <math.h>
#include "add.h"

//库函数
// 1.IO函数
// 2.字符串操作函数
// 3.字符操作函数
// 4.内存操作函数
// 5.时间/日期函数
// 6.数学函数
// ...

//自定义函数

//函数的参数
// 1.实际参数  
// 2.形式参数(只有在函数被调用的过程中才实例化(分配内存单元)),当函数调用完成后自动销毁.
// 当实参传给形参时,形参其实是实参的一份临时拷贝,对形参的修改是不会改变实参的.

//函数的调用
// 1.传值调用:函数的形参和实参分别占有不同的内存块,对形参的修改不会影响实参.
// 2.传址调用:函数内部可以直接操作函数外部的变量.

//函数的嵌套调用和链式访问

//函数的声明和定义

int Add1(int x, int y)
{
	int sum = x + y;
	return sum;
}

// 两个数中的较大值
int get_max(int x, int y)
{
	return (x > y) ? (x) : (y);
}

// 交换两个变量的值
void swap_two(int* x, int* y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

// 判断某个数是否是素数
int is_prime(int x)
{
	int i1;
	for (i1 = 2;i1 <= sqrt(x);i1++)
	{
		if (x % i1 == 0)
		{
			return 0; //直接跳出函数
		}
	}
	return 1;
}

// 判断某一年是否是闰年
int is_leapyear(int x)
{
	if (x % 4 == 0 && x % 100 != 0 || x % 400 == 0)
		return 1;
	return 0;
}

//整型有序数组的二分查找
int binary_search(int arr[], int k,int sz)
{
	int left = 0;
	// int right = sizeof(arr) / sizeof(arr[0]) - 1;//这里arr本质上是一个指针
	int right = sz - 1;
	int midarr;
	while (left <= right)
	{
		midarr = (left + right) / 2;
		if (arr[midarr] == k)
		{
			return midarr;
		}
		else if (arr[midarr] > k)
		{
			right = midarr - 1;
		}
		else if (arr[midarr] < k)
		{
			left = midarr + 1;
		}
	}
	if (left > right)
	{
		return -1;
	}
}

// num自增函数
void numplus(int* pnum)
{
	*pnum += 1;
}

// 按照顺序打印一个无符号整型值n的每一位.
void printnum(int n)
{
	if (n/10 != 0)
	{
		printnum(n / 10);
	}
	printf("%d\n", n % 10);
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

// 求n的阶乘
int factorial1(int n)
{
	int ret = 1;
	for (int i2 = 1; i2 <= n; i2++)
	{
		ret = ret * i2;
	}
	return ret;
}
int factorial2(int n)
{
	if (n > 1)
	{
		return n * factorial2(n - 1);
	}
	return 1;
}

// 求第n个fibonacci数
int fibonacci(int n)
{
	if (n > 2)
	{
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
	return 1;
}
int fibonacci2(int n)
{
	int c1 = 1;
	int c2 = 1;
	int c3;
	while (n > 2)
	{
		c3 = c1 + c2;
		c1 = c2;
		c2 = c3;
		n--;
	}
	return c2;
}

int main()
{
	int a1 = 10;
	int a2 = 20;
	int sum1 = Add1(a1, a2);
	printf("%d\n", sum1);

	// strcpy
	char str1[] = "bit";
	char str2[20] = "######";
	printf("%d %d\n", sizeof(str2), strlen(str2));
	strcpy(str2,str1);
	printf("%s\n", str2);
	printf("%d %d\n", sizeof(str2), strlen(str2));
	int str3[5] = { 1,2,3 };
	printf("%d\n", sizeof(str3));

	// memset 内存设置
	char str4[] = "hello world";
	memset(str4, '*', 5);
	printf("%s\n", str4);

	//get_max()
	int max1 = get_max(a1, a2);
	printf("max1 = %d\n", max1);
	
	//swap_two()
	int* pa1 = &a1;
	int* pa2 = &a2;
	printf("%d %d\n", a1, a2);
	swap_two(&a1, &a2);
	printf("%d %d\n", a1, a2);

	//打印100-200间的素数
	int count1 = 0;
	for (int i2 = 101; i2 <= 200; i2+=2)
	{
		if (is_prime(i2) == 1)
		{
			count1++;
			printf("%d %d\n", i2,count1);
		}
	}

	//打印1000-2000年间的闰年

	int count2 = 0;
	for (int i3 = 1000; i3 <= 2000; i3++)
	{
		if (is_leapyear(i3) == 1)
		{
			count2++;
			printf("%d %d\n", i3, count2);
		}
	}

	//二分查找

	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
	int k;
	int sz = sizeof(arr1) / sizeof(arr1[0]);

	printf("输入数字:>");
	scanf("%d", &k);
	int ret1 = binary_search(arr1,k,sz);//数组名为首个元素的地址
	if (ret1 == -1)
	{
		printf("未找到\n");
	}
	else
	{
		printf("该数字的下标为:%d\n", ret1);
	}

	//num1自增1
	int num1 = 0;
	int* pnum = &num1;
	numplus(pnum);
	numplus(pnum);
	printf("num1 = %d\n", num1);

	//函数的链式访问

	printf("%d", printf("%d", printf("%d", 43)));//printf返回值为所打印的字符个数

	//函数的声明和定义: .h文件放函数声明; .c文件放函数定义

	int sum2 = Add(a1, a2);
	printf("%d\n", sum2);

	//函数递归:程序调用自身
	 
	//递归的两个必要条件:
	//	1.存在限制条件
	// 	2.每次递归调用后越来越接近这个限制条件
	// 
	//递归常见的错误:栈溢出(stack_overflow)
	//内存区域:
	//	栈区(局部变量,函数形参);堆区(动态开辟的内存:malloc, calloc); 静态区(全局变量, static修饰的变量);

	// 接受一个无符号整型值,按照顺序打印它的每一位.
	unsigned int a3 = 0;
	scanf("%d", &a3);
	printnum(a3);

	//编写函数不允许创建临时变量,求字符串的长度(strlen)

		char str5[] = "bit";
		int len = my_strlen2(str5);
		printf("len=%d\n", len);

	//递归与迭代(循环)
	//求n1的阶乘
	int n1;
	scanf("%d", &n1);
	int ret2 = factorial1(n1);
	printf("ret2=%d\n", ret2);

	int ret3 = factorial2(n1);
	printf("ret3=%d\n", ret3);

	//求第n2个斐波那契数
	int n2;
	scanf("%d", &n2);
	int ret4 = fibonacci(n2);
	printf("ret4=%d\n", ret4);

	//循环求第n2个斐波那契数
	int ret5 = fibonacci2(n2);
	printf("ret5=%d\n", ret5);
	
	//汉诺塔问题
	//青蛙跳台阶问题(斐波那契数列)(剑指offer)
	return 0;
} 