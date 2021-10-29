#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
// 结构体

// struct 结构体关键字;Stu 结构体标签;struct Stu 结构体类型
// 定义结构体类型
// struct Stu
// {
//	 // 成员变量
//	 char name[20];
//	 short age;
//	 char tele[12];
//	 char sex[5];
// }s1,s2,s3; // s1,s2,s3 是三个全局结构体变量

typedef struct Stu
{
	// 成员变量
	char name[20];
	short age;
	char tele[12];
	char sex[5];
}Stu; // 将结构体类型名struct Stu改为Stu

struct S
{
	int a;
	char c;
	char arr[20];
	double d;
};

struct T
{
	char ch[10];
	struct S s;
	char* pc;

};

void Print1(Stu s)
{
	printf("name:%s\n", s.name);
	printf("age:%d\n", s.age);
	printf("tele:%s\n", s.tele);
	printf("sex:%s\n", s.sex);
}

void Print2(Stu* p)
{
	printf("name:%s\n", p->name);
	printf("age:%d\n", p->age);
	printf("tele:%s\n", p->tele);
	printf("sex:%s\n", p->sex);
}

int Add(int x, int y)
{
	int z = 0;
	z = x + y;
	return z;
}

int main()
{
	Stu student1; // 创建结构体变量,局部结构体变量
	Stu student2;

	// 结构体变量的初始化
	Stu student3 = { "ningbangjie",20,"18888888888","男" };
	char arr1[] = "hello world!";
	struct T t1 = { "hit",{10,'A',"NING",2.0},arr1};

	// 成员访问
	printf("%s\n", arr1);
	printf("%s\n", t1.ch);
	printf("%s\n", t1.s.arr);

	// 结构体传参时,要传结构体的地址

	// 打印结构体数据
	Print1(student3); // 形参临时拷贝时占用时间空间大
	Print2(&student3);

	// 压栈
	// 函数传参时,参数是需要压栈的
	int a1 = 20;
	int a2 = 30;
	int sum1 = Add(a1, a2);

	// 内存:
	// 1.栈区:   局部变量;函数的形参;函数调用也开辟空间
	// 2.堆区:   动态内存分配,malloc/free,realloc,ralloc
	// 3.静态区: 全局变量;静态变量

	// 数据结构:
	// 线性数据结构: 顺序表; 链表; 栈; 队列
	// 树形数据结构: 二叉树;
	// 图形数据结构: 图;

	return 0;
}