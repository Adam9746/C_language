#define _CRT_SECURE_NO_WARNINGS 1
#define MAX 10
//#define ���Զ����-������
#include <stdio.h>
#include <string.h>
int num1 = 20;//ȫ�ֱ���

void test()
{
	printf("%d\n", num1);
}

enum Sex //ö������
{
	MALE,
	FEMALE,
	SECRET  //ö�ٳ���
};

void test2()
{
	int a = 1;
	a++;
	printf("a=%d\n", a);
}

void test3()//static���ξֲ�����,�������ڱ䳤;
{
	static int a = 1;//��̬�ľֲ�����
	a++;
	printf("a=%d\n", a);
}
//�Զ��庯��
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
// ��Ķ��巽ʽ
#define MAx(X,Y) (X>Y?X:Y)

int main()//���������������ڣ����ҽ���1��
{
	test();
	extern int g_val;//�����ⲿ����,ȫ�ֱ���������������������
	printf("g_val=%d\n", g_val);
	printf("%d\n", num1);
	int num2 = 10;
	int num1 = 15;//�ֲ�������ȫ�ֱ�������ͬʱ����
	printf("%d\n",num1);//�ֲ���������
	printf("hello world\n");
	char ch = 'a';
	printf("%c\n",ch);//��ӡ�ַ���ʽ������
	int age = 20;
	printf("%d\n",age);//��ӡ����ʮ��������;%p ��ַ;
	long num = 100;
	printf("%d\n",num);
	float f = 5.0;
	printf("%f\n",f);//��ӡ�����ȸ�����
	float d = 5.0;
	printf("%lf\n",d);//��ӡ˫���ȸ�����

	printf("%d\n", sizeof(char));//����������ռ�ֽ���
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
	//��������
	/*scanf("%d%d", &num3, &num4);//ȡ��ַ
	sum = num3 + num4;
	printf("sum = %d\n", sum);*/
	const int num5 = 5;//������
	// int arr[num5] = { 0 };
	
	int arr[MAX] = { 0 };
	printf("%d\n", MAX);

	enum Sex s = MALE;
	s = FEMALE; //sΪ����
	printf("%d\n", s);

	char arr1[] = "abc"; //�ַ�����
	// "abc" -- 'a' 'b' 'c' '\0':�ַ����Ľ�����־
	printf("%s\n", arr1);
	char arr2[] = {'a','b','c'}; // {'a', 'b', 'c', '\0'} '\0'��ֵΪ0,'a'��ֵΪ97,'A'��ֵΪ65
	// ASCII����
	printf("arr2=%s\n", arr2);

	printf("%d\n", strlen(arr1));
	printf("%d\n", strlen(arr2));
	printf("c:\\test\\32\\test.c\n");// \ת��
	printf("%c\n", '\'');
	printf("%s\n", "\"");

	printf("%d\n", strlen("c:\test\32\test.c"));
	//  \32 -- 32��2��8��������,ת��Ϊ10���� 26,ASCII��26������ַ�
	//  \ddd �˽��ƣ� \xdd ʮ������

	printf("%s\n", "c:\test\32\test.c"); 

	//ѡ�����
	/*int input = 0;
	scanf("%d", &input);
	if (input == 1)
		printf("good\n");
	else
		printf("bad\n");*/

	//ѭ�����

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

	int arr3[10] = {1,2,3,4,5,6,7,8,9,10};//����,��ֵһ�����10�����͵�����
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

	//��λ������ <<;>>,������λ
	int a = 1;
	//00000000 00000000 00000000 00000001,���ֽ�
	int b = a << 2;//00000000 00000000 00000000 00000010
	printf("%d\n", a); 
	printf("%d\n", b);

	int a1 = 3;
	int a2 = 5;
	int max1 = (a1 > a2 ? a1 : a2);
	printf("max1=%d\n", max1);
	printf("%d\n",a1 & a2);
	printf("%d\n", a1 | a2);
	printf("%d\n", a1 ^ a2);// ��Ӧ������λ��ͬΪ0,����Ϊ1
	printf("%d\n", !a1);

	printf("%d\n", sizeof(arr3));//10*4
	printf("%d\n", sizeof(arr3) / sizeof(arr3[0]));//��������Ԫ�ظ���

	printf("%d\n", Max(20, 21));

	// ��
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

	int a4 = (int)3.54;//ǿ������ת��
	printf("%d\n", a4);

	register int a5 = 10;//�����a5����ɼĴ�������

	unsigned int a6 = -10;//�޷���,��Զ������
	printf("%d\n",a6);

	typedef unsigned int u_int;//����������
	unsigned int a7 = -10;
	u_int a8 = -10;
	printf("%d\n%d\n", a7,a8);

	int k = 0;
	while (k<5)
	{
		test3();
		k++;
	}

	//extern int g_val1; //static����ȫ�ֱ���, �ı��˱�����������, ��̬��ȫ�ֱ���ֻ��������Դ�ļ����ڲ�ʹ��
	//printf("%d\n", g_val1);
	//return 0;

	//extern int Add1(int,int);//static���κ���,�ı��˺�������������(�ⲿ��������-->�ڲ���������)
	//int sum1 = Add1(10, 20);
	//printf("sum1 = %d\n", sum1);
	

	//ָ��

	int ad = 10;
	int* p = &ad;// ָ�����,��ŵ�ַ
	printf("%p\n", &ad);
	printf("%p\n", p);
	printf("%d\n", *p);//* - �����ò�����
	*p = 20;// *p = ad
	printf("%d\n", ad);

	char adr = 'w';
	char* pc = &adr;
	printf("%p\n", pc);
	printf("%d\n", sizeof(pc));
	printf("%c\n", adr);
	*pc = 'm';
	printf("%c\n", adr);

	//ָ���С��32λƽ̨����4���ֽ�,��64λƽ̨����8���ֽ�

	//�ṹ�� struct,�������Ӷ���

	//����һ���ṹ������
	struct Book
	{
		char name[20];
		short price;
	};

	//���������͵Ľṹ�����
	struct Book book1 = {"C programming",55};

	printf("%s\n", book1.name);
	printf("%d\n", book1.price);

	strcpy(book1.name,"C_pro"); //�ַ�������
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

C������������

	char �ַ�����  1�ֽ�
	short ������  2�ֽ�	
	int ����  4�ֽ�
	long ������  4�ֽ�/8�ֽ� sizeof(long)>=sizeof(int)
	long long ��������  8�ֽ�
	float �����ȸ�����  4�ֽ�
	double ˫���ȸ����� 8�ֽ�

�洢��λ

	bit ����λ,һ��������λ
	byte �ֽ�,8������λ
	kb 1024���ֽ�
	mb
	gb
	tb
	pb

ȫ�ֱ����;ֲ�����

	�������ڵ��Ǿֲ�����

���������������������

����

	1.���泣�� 3,100,3.14
	2.const���εĳ�����(������)
	3.#define����ı�ʶ������
	4.ö�ٳ���

�ַ�����ת���ַ���ע��
	\n	���з�
	\t	ˮƽ�Ʊ��(Tab)

ѡ����� if...else

ѭ����� while;for;do...while

����(�Զ��庯��,�⺯��)

����(һ����ͬ����Ԫ�صļ���)

������

	����������
	��λ������
	λ������: & ��λ��;| ��λ��;^ ��λ���
	��Ŀ������(������): !; ~,��λȡ��; ++; --; *��ӷ��ʲ�����(�����ò�����); (����)ǿ������ת��;
	˫Ŀ������: &&�߼���; ||�߼���; 
	��Ŀ������: (...?...:...)����������

ԭ��,����,����

	ԭ����ֱ�Ӱ�������д���Ķ���������;

	�������ڴ��д洢�Ķ��Ƕ����ƵĲ���;
	����: ԭ��,����,������ͬ
	����: ����:ԭ�����λ����,����λ��λȡ���õ�;
		  ����:���� + 1;
		  ���� - 1 = ����; �����ȥ����λȡ�� = ԭ��

�����ؼ���

	auto;break;case;char;const;continue;default;do;while;double;else;enum;extern;
	float;for;goto;if;int;long;register(�Ĵ���);return;short;signed(����);unsigned;
	sizeof;static(��̬);struct(�ṹ��);switch;typedef(���Ͷ���/�����ض���);union(������/������);void;volatile;

*/


