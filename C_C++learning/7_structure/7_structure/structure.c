#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
// �ṹ��

// struct �ṹ��ؼ���;Stu �ṹ���ǩ;struct Stu �ṹ������
// ����ṹ������
// struct Stu
// {
//	 // ��Ա����
//	 char name[20];
//	 short age;
//	 char tele[12];
//	 char sex[5];
// }s1,s2,s3; // s1,s2,s3 ������ȫ�ֽṹ�����

typedef struct Stu
{
	// ��Ա����
	char name[20];
	short age;
	char tele[12];
	char sex[5];
}Stu; // ���ṹ��������struct Stu��ΪStu

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
	Stu student1; // �����ṹ�����,�ֲ��ṹ�����
	Stu student2;

	// �ṹ������ĳ�ʼ��
	Stu student3 = { "ningbangjie",20,"18888888888","��" };
	char arr1[] = "hello world!";
	struct T t1 = { "hit",{10,'A',"NING",2.0},arr1};

	// ��Ա����
	printf("%s\n", arr1);
	printf("%s\n", t1.ch);
	printf("%s\n", t1.s.arr);

	// �ṹ�崫��ʱ,Ҫ���ṹ��ĵ�ַ

	// ��ӡ�ṹ������
	Print1(student3); // �β���ʱ����ʱռ��ʱ��ռ��
	Print2(&student3);

	// ѹջ
	// ��������ʱ,��������Ҫѹջ��
	int a1 = 20;
	int a2 = 30;
	int sum1 = Add(a1, a2);

	// �ڴ�:
	// 1.ջ��:   �ֲ�����;�������β�;��������Ҳ���ٿռ�
	// 2.����:   ��̬�ڴ����,malloc/free,realloc,ralloc
	// 3.��̬��: ȫ�ֱ���;��̬����

	// ���ݽṹ:
	// �������ݽṹ: ˳���; ����; ջ; ����
	// �������ݽṹ: ������;
	// ͼ�����ݽṹ: ͼ;

	return 0;
}