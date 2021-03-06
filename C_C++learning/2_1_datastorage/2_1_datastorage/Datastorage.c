#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <windows.h>
//C语言类型
// 
//1. 内置类型
// (1) 整型家族
//	   char(ASCII码)
//		 unsigned char(0 - 255); signed char(-128 - 127)
//	   short
//		 unsigned short;signed short
//	   int
//		 unsigned int;signed int
//	   long
//		 unsigned long;signed long
// (2) 浮点型家族
//	   float(单精度)
//	   double(双精度)
// 
//2. 自定义类型(构造类型)
//	   数组类型;结构体类型(struct);枚举类型(enum);联合类型(union)
//3. 指针类型
//	   int*;char*;float*;void*(无具体类型的指针)
//4. 空类型
//     void 表示空类型(无类型),通常应用于函数的返回类型,函数的参数,指针类型

// 整型在内存中的存储
// 计算机中的有符号(整型)数有三种表示方法:原码,反码,补码;无符号数:原码,反码,补码都相同
// 均有符号位和数值位;符号位0表示正,1表示负;正数的原码,反码,补码都相同

// 判断当前机器的字节序
int check_sys()  //函数内部尽量不要printf
{
	int a = 1;
	char* p = (char*)&a;
	return *p;
}

int main()
{
	int a1 = 10;     //0a 00 00 00
	// a1原码:00000000 00000000 00000000 00001010
	// a1反码:00000000 00000000 00000000 00001010
	// a1补码:00000000 00000000 00000000 00001010

	float a2 = 10.0; // 00 00 20 41

	int a3 = -20;	 // ec ff ff ff
	// a3原码:10000000 00000000 00000000 00010100
	// a3反码:11111111 11111111 11111111 11101011
	// a3补码:11111111 11111111 11111111 11101100

	// 大端小端字节序
	// 大端存储模式:数据的低位保存在内存的高地址,高位保存在低地址
	// 小端存储模式:数据的低位保存在内存的低地址,高位保存在高地址

	// 判断当前机器的字节序
	
	int ret1 = check_sys();
	if (ret1 == 1)
	{
		printf("小端\n");
	}
	else
	{
		printf("大端\n");
	}

	char a4 = -1;
	signed char a5 = -1;
	unsigned char a6 = -1;
	// 10000000 00000000 00000000 00000001
	// 11111111 11111111 11111111 11111110
	// 11111111 11111111 11111111 11111111
	// a4:11111111
	//    11111111 11111111 11111111 11111111
	// a5:11111111
	//    11111111 11111111 11111111 11111111
	// a6:11111111
	//    00000000 00000000 00000000 11111111
	printf("a4=%d,a5=%d,a6=%d\n", a4, a5, a6);

	char a7 = -128;
	// 10000000 00000000 00000000 10000000
	// 11111111 11111111 11111111 01111111
	// 11111111 11111111 11111111 10000000
	// 10000000
	// 11111111 11111111 11111111 10000000
	printf("a7=%u\n", a7);// %u:打印十进制的无符号数
	printf("a7=%d\n", a7);

	char a8 = 128;
	printf("a8=%u\n", a8);// %u:打印十进制的无符号数
	printf("a8=%d\n", a8);

	// char
	// signed char (-128,127)
	// unsigned char (0,255)

	int a9 = -20;
	// 10000000 00000000 00000000 00010100
	// 11111111 11111111 11111111 11101011
	// 11111111 11111111 11111111 11101100
	unsigned int a10 = 10;
	// 00000000 00000000 00000000 00001010

	// 11111111 11111111 11111111 11110110
	// 11111111 11111111 11111111 11110101
	// 10000000 00000000 00000000 00001010
	printf("%d\n", a9 + a10);

	// unsigned int i1;
	// for ( i1 = 9; i1 >= 0; i1--)
	// {
	// 	 printf("%u\n", i1);
	//	 Sleep(100); // ms
	// }

	char arr1[1000];
	int i2;
	for ( i2 = 0; i2 < 1000; i2++)
	{
		arr1[i2] = -1 - i2;
	}
	printf("%d", strlen(arr1)); // (-1,-2,...,-128,127,126,...,1,0,-1,...)

	// unsigned char i3 = 0;
	// for ( i3 = 0; i3 <= 255; i3++)
	// {
	//	 printf("hello world\n");
	// }


	// 浮点型在内存中的存储
	// 浮点数家族包括:float,double,long double
	// limits.h, float.h
	double b1 = 1E10;
	printf("%lf\n", b1);

	// 任意一个二进制浮点数V可表示为:(-1)^S * M * 2^E
	// 9.0 // 1001.0 // (-1)^0 * 1.001 * 2^3 // S,0; M,1.001; E,3
	// 0.5 // 0.1 // (-1)^0 * 1.0 * 2^(-1) // S,0; M,1.0; E,-1
	// 
	// float:
	// S(1bit),
	// E(8bit),无符号位 (0,255) - 127 = (-127,128)
	// M(23bit)存储除整数部分1的小数部分,1<=M<=2
	// 
	// double:
	// S(1bit),
	// E(11bit),无符号位 (0,2047) - 1023 = (-1023,1024)
	// M(52bit)存储除整数部分1的小数部分,1<=M<=2

	float b3 = 5.5;
	// 5.5 // 101.1 // (-1)^0 * 1.011 * 2^2 // S,0; M,1.011; E,2 // 2+127=129
	// 0 10000001 01100000000000000000000
	// 0x 40 b0 00 00

	// 1. E不为全0或不为全1
	// 2. E为全0: // 0 00000000 01100000000000000000000 // 0.011 * 2^(1-127)
	// 3. E为全1: // 0 11111111 01100000000000000000000 // 1.011 * 2^128

	int b2 = 9; //00000000 00000000 00000000 00001001
	float* pFloat = (float*)&b2;
	printf("b2=%d\n", b2);
	printf("*pFloat=%f\n", *pFloat);//0 00000000 00000000000000000001001 // (-1)^0 * 0.00000000000000000001001*2^(-126)

	*pFloat = 9.0; // 1001.0 // (-1)^0 * 1.001 * 2^3 // S,0; M,1.001; E,3 (3+127=130)// 0 10000010 00100000000000000000000
	printf("b2=%d\n", b2);
	printf("*pFloat=%f\n", *pFloat);

	return 0;
}