#define _CRT_SECURE_NO_WARNINGS 1
#define MAX 10
//#define 可以定义宏-带参数
#include <stdio.h>
#include <string.h>
int num1 = 20;//全局变量

void test()
{
	printf("%d\n", num1);
}

enum Sex //枚举类型
{
	MALE,
	FEMALE,
	SECRET  //枚举常量
};

void test2()
{
	int a = 1;
	a++;
	printf("a=%d\n", a);
}

void test3()//static修饰局部变量,生命周期变长;
{
	static int a = 1;//静态的局部变量
	a++;
	printf("a=%d\n", a);
}
//自定义函数
int Add(int x, int y)
{
	int z = x + y;
	return z;
}
int Max(int num1, int num2)
{
	int max;
	if (num1 > num2)
		max = num1;
	else
		max = num2;
	return max;
}
// 宏的定义方式
#define MAx(X,Y) (X>Y?X:Y)

int main()//主函数，程序的入口，有且仅有1个
{
	test();
	extern int g_val;//声明外部变量,全局变量的作用域是整个工程
	printf("g_val=%d\n", g_val);
	printf("%d\n", num1);
	int num2 = 10;
	int num1 = 15;//局部变量和全局变量可以同时存在
	printf("%d\n",num1);//局部变量优先
	printf("hello world\n");
	char ch = 'a';
	printf("%c\n",ch);//打印字符格式的数据
	int age = 20;
	printf("%d\n",age);//打印整型十进制数据;%p 地址;
	long num = 100;
	printf("%d\n",num);
	float f = 5.0;
	printf("%f\n",f);//打印单精度浮点数
	float d = 5.0;
	printf("%lf\n",d);//打印双精度浮点数

	printf("%d\n", sizeof(char));//数据类型所占字节数
	printf("%d\n", sizeof(short));
	printf("%d\n", sizeof(int));
	printf("%d\n", sizeof(long));
	printf("%d\n", sizeof(long long));
	printf("%d\n", sizeof(float));
	printf("%d\n", sizeof(double));

	short ages = 20;
	float weights = 95.6f;
	int num3 = 0;
	int num4 = 0;
	int sum = 0;
	//输入数据
	/*scanf("%d%d", &num3, &num4);//取地址
	sum = num3 + num4;
	printf("sum = %d\n", sum);*/
	const int num5 = 5;//常变量
	// int arr[num5] = { 0 };
	
	int arr[MAX] = { 0 };
	printf("%d\n", MAX);

	enum Sex s = MALE;
	s = FEMALE; //s为变量
	printf("%d\n", s);

	char arr1[] = "abc"; //字符数组
	// "abc" -- 'a' 'b' 'c' '\0':字符串的结束标志
	printf("%s\n", arr1);
	char arr2[] = {'a','b','c'}; // {'a', 'b', 'c', '\0'} '\0'的值为0,'a'的值为97,'A'的值为65
	// ASCII编码
	printf("arr2=%s\n", arr2);

	printf("%d\n", strlen(arr1));
	printf("%d\n", strlen(arr2));
	printf("c:\\test\\32\\test.c\n");// \转义
	printf("%c\n", '\'');
	printf("%s\n", "\"");

	printf("%d\n", strlen("c:\test\32\test.c"));
	//  \32 -- 32是2个8进制数字,转变为10进制 26,ASCII码26代表的字符
	//  \ddd 八进制； \xdd 十六进制

	printf("%s\n", "c:\test\32\test.c"); 

	//选择语句
	/*int input = 0;
	scanf("%d", &input);
	if (input == 1)
		printf("good\n");
	else
		printf("bad\n");*/

	//循环语句

	int line = 0;
	while (line < 20)
	{
		printf("one more %d\n",line);
		line++;
	}
	if (line >= 20)
	{
		printf("enough\n");
	}
	
	sum = Add(10, 20);
	printf("sum = %d\n", sum);

	int arr3[10] = {1,2,3,4,5,6,7,8,9,10};//定义,赋值一个存放10个整型的数组
	printf("%d\n", arr3[1]);

	int i = 0;
	while (i<10)
	{
		printf("%d\n",arr3[i]);
		i++;
	}

	char cha[20];
	float arr4[5];

	int f2 = 5 / 2;
	printf("%d\n",f2);

	//移位操作符 <<;>>,二进制位
	int a = 1;
	//00000000 00000000 00000000 00000001,四字节
	int b = a << 2;//00000000 00000000 00000000 00000010
	printf("%d\n", a); 
	printf("%d\n", b);

	int a1 = 3;
	int a2 = 5;
	int max1 = (a1 > a2 ? a1 : a2);
	printf("max1=%d\n", max1);
	printf("%d\n",a1 & a2);
	printf("%d\n", a1 | a2);
	printf("%d\n", a1 ^ a2);// 对应二进制位相同为0,相异为1
	printf("%d\n", !a1);

	printf("%d\n", sizeof(arr3));//10*4
	printf("%d\n", sizeof(arr3) / sizeof(arr3[0]));//计算数组元素个数

	printf("%d\n", Max(20, 21));

	// 宏
	int max2;
	max2 = MAx(a1,a2);
	printf("hong=%d\n", max2);

	int arr5[10] = { 1,2,3,4,5 };
	int j = 0;
	while (j < 10)
	{
		printf("%d\n", arr5[j]);
		j++;
	}

	int a3 = 0;// 00000000 00000000 00000000 00000000
	printf("%d\n", ~a3);

	int b3 = a3++;
	int c3 = ++a3;
	int d3 = a3--;
	int e3 = --a3;
	printf("a3=%d\nb3=%d\nc3=%d\nd3=%d\ne3=%d\n", a3, b3, c3, d3, e3);

	int a4 = (int)3.54;//强制类型转换
	printf("%d\n", a4);

	register int a5 = 10;//建议把a5定义成寄存器变量

	unsigned int a6 = -10;//无符号,永远是正数
	printf("%d\n",a6);

	typedef unsigned int u_int;//类型重命名
	unsigned int a7 = -10;
	u_int a8 = -10;
	printf("%d\n%d\n", a7,a8);

	int k = 0;
	while (k<5)
	{
		test3();
		k++;
	}

	//extern int g_val1; //static修饰全局变量, 改变了变量的作用域, 静态的全局变量只能在所在源文件的内部使用
	//printf("%d\n", g_val1);
	//return 0;

	//extern int Add1(int,int);//static修饰函数,改变了函数的链接属性(外部链接属性-->内部链接属性)
	//int sum1 = Add1(10, 20);
	//printf("sum1 = %d\n", sum1);
	

	//指针

	int ad = 10;
	int* p = &ad;// 指针变量,存放地址
	printf("%p\n", &ad);
	printf("%p\n", p);
	printf("%d\n", *p);//* - 解引用操作符
	*p = 20;// *p = ad
	printf("%d\n", ad);

	char adr = 'w';
	char* pc = &adr;
	printf("%p\n", pc);
	printf("%d\n", sizeof(pc));
	printf("%c\n", adr);
	*pc = 'm';
	printf("%c\n", adr);

	//指针大小在32位平台上是4个字节,在64位平台上是8个字节

	//结构体 struct,描述复杂对象

	//创建一个结构体类型
	struct Book
	{
		char name[20];
		short price;
	};

	//创建该类型的结构体变量
	struct Book book1 = {"C programming",55};

	printf("%s\n", book1.name);
	printf("%d\n", book1.price);

	strcpy(book1.name,"C_pro"); //字符串拷贝
	book1.price = 20;
	printf("%s\n", book1.name);
	printf("%d\n", book1.price);

	struct Book* adbook = &book1;
	printf("%s\n", (*adbook).name);
	printf("%d\n", (*adbook).price);
	printf("%s\n", adbook->name);
	printf("%d\n", adbook->price);
	return 0;
}
/*

C语言数据类型

	char 字符类型  1字节
	short 短整型  2字节	
	int 整型  4字节
	long 长整型  4字节/8字节 sizeof(long)>=sizeof(int)
	long long 长长整型  8字节
	float 单精度浮点数  4字节
	double 双精度浮点数 8字节

存储单位

	bit 比特位,一个二进制位
	byte 字节,8个比特位
	kb 1024个字节
	mb
	gb
	tb
	pb

全局变量和局部变量

	大括号内的是局部变量

变量的作用域和生命周期

常量

	1.字面常量 3,100,3.14
	2.const修饰的常变量(常属性)
	3.#define定义的标识符常量
	4.枚举常量

字符串、转义字符、注释
	\n	换行符
	\t	水平制表符(Tab)

选择语句 if...else

循环语句 while;for;do...while

函数(自定义函数,库函数)

数组(一组相同类型元素的集合)

操作符

	算术操作符
	移位操作符
	位操作符: & 按位与;| 按位或;^ 按位异或
	单目操作符(操作数): !; ~,按位取反; ++; --; *间接访问操作符(解引用操作符); (类型)强制类型转换;
	双目操作符: &&逻辑与; ||逻辑或; 
	三目操作符: (...?...:...)条件操作符

原码,反码,补码

	原码是直接按照正负写出的二进制序列;

	整数在内存中存储的都是二进制的补码;
	正数: 原码,反码,补码相同
	负数: 反码:原码符号位不变,其他位按位取反得到;
		  补码:反码 + 1;
		  补码 - 1 = 反码; 反码除去符号位取反 = 原码

常见关键字

	auto;break;case;char;const;continue;default;do;while;double;else;enum;extern;
	float;for;goto;if;int;long;register(寄存器);return;short;signed(符号);unsigned;
	sizeof;static(静态);struct(结构体);switch;typedef(类型定义/类型重定义);union(联合体/共用体);void;volatile;

*/


