#define _CRT_SECURE_NO_WARNINGS 1

int g_val = 2021;
static int g_val1 = 2022;//static修饰全局变量, 改变了变量的作用域, 静态的全局变量只能在所在源文件的内部使用
static int Add1(int x, int y)//static修饰函数,改变了函数的链接属性(外部链接属性-->内部链接属性)
{
	int z = x + y;
	return z;
}