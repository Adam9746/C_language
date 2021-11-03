#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <math.h>
#include "add.h"

//�⺯��
// 1.IO����
// 2.�ַ�����������
// 3.�ַ���������
// 4.�ڴ��������
// 5.ʱ��/���ں���
// 6.��ѧ����
// ...

//�Զ��庯��

//�����Ĳ���
// 1.ʵ�ʲ���  
// 2.��ʽ����(ֻ���ں��������õĹ����в�ʵ����(�����ڴ浥Ԫ)),������������ɺ��Զ�����.
// ��ʵ�δ����β�ʱ,�β���ʵ��ʵ�ε�һ����ʱ����,���βε��޸��ǲ���ı�ʵ�ε�.

//�����ĵ���
// 1.��ֵ����:�������βκ�ʵ�ηֱ�ռ�в�ͬ���ڴ��,���βε��޸Ĳ���Ӱ��ʵ��.
// 2.��ַ����:�����ڲ�����ֱ�Ӳ��������ⲿ�ı���.

//������Ƕ�׵��ú���ʽ����

//�����������Ͷ���

int Add1(int x, int y)
{
	int sum = x + y;
	return sum;
}

// �������еĽϴ�ֵ
int get_max(int x, int y)
{
	return (x > y) ? (x) : (y);
}

// ��������������ֵ
void swap_two(int* x, int* y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

// �ж�ĳ�����Ƿ�������
int is_prime(int x)
{
	int i1;
	for (i1 = 2;i1 <= sqrt(x);i1++)
	{
		if (x % i1 == 0)
		{
			return 0; //ֱ����������
		}
	}
	return 1;
}

// �ж�ĳһ���Ƿ�������
int is_leapyear(int x)
{
	if (x % 4 == 0 && x % 100 != 0 || x % 400 == 0)
		return 1;
	return 0;
}

//������������Ķ��ֲ���
int binary_search(int arr[], int k,int sz)
{
	int left = 0;
	// int right = sizeof(arr) / sizeof(arr[0]) - 1;//����arr��������һ��ָ��
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

// num��������
void numplus(int* pnum)
{
	*pnum += 1;
}

// ����˳���ӡһ���޷�������ֵn��ÿһλ.
void printnum(int n)
{
	if (n/10 != 0)
	{
		printnum(n / 10);
	}
	printf("%d\n", n % 10);
}

// ��ĳ���ַ����ĳ���
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
//�ݹ�ʵ��
int my_strlen2(char* str)
{
	if (*str != '\0')
	{
		str++;
		return 1 + my_strlen2(str);
	}
	return 0;
}

// ��n�Ľ׳�
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

// ���n��fibonacci��
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

	// memset �ڴ�����
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

	//��ӡ100-200�������
	int count1 = 0;
	for (int i2 = 101; i2 <= 200; i2+=2)
	{
		if (is_prime(i2) == 1)
		{
			count1++;
			printf("%d %d\n", i2,count1);
		}
	}

	//��ӡ1000-2000��������

	int count2 = 0;
	for (int i3 = 1000; i3 <= 2000; i3++)
	{
		if (is_leapyear(i3) == 1)
		{
			count2++;
			printf("%d %d\n", i3, count2);
		}
	}

	//���ֲ���

	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
	int k;
	int sz = sizeof(arr1) / sizeof(arr1[0]);

	printf("��������:>");
	scanf("%d", &k);
	int ret1 = binary_search(arr1,k,sz);//������Ϊ�׸�Ԫ�صĵ�ַ
	if (ret1 == -1)
	{
		printf("δ�ҵ�\n");
	}
	else
	{
		printf("�����ֵ��±�Ϊ:%d\n", ret1);
	}

	//num1����1
	int num1 = 0;
	int* pnum = &num1;
	numplus(pnum);
	numplus(pnum);
	printf("num1 = %d\n", num1);

	//��������ʽ����

	printf("%d", printf("%d", printf("%d", 43)));//printf����ֵΪ����ӡ���ַ�����

	//�����������Ͷ���: .h�ļ��ź�������; .c�ļ��ź�������

	int sum2 = Add(a1, a2);
	printf("%d\n", sum2);

	//�����ݹ�:�����������
	 
	//�ݹ��������Ҫ����:
	//	1.������������
	// 	2.ÿ�εݹ���ú�Խ��Խ�ӽ������������
	// 
	//�ݹ鳣���Ĵ���:ջ���(stack_overflow)
	//�ڴ�����:
	//	ջ��(�ֲ�����,�����β�);����(��̬���ٵ��ڴ�:malloc, calloc); ��̬��(ȫ�ֱ���, static���εı���);

	// ����һ���޷�������ֵ,����˳���ӡ����ÿһλ.
	unsigned int a3 = 0;
	scanf("%d", &a3);
	printnum(a3);

	//��д��������������ʱ����,���ַ����ĳ���(strlen)

		char str5[] = "bit";
		int len = my_strlen2(str5);
		printf("len=%d\n", len);

	//�ݹ������(ѭ��)
	//��n1�Ľ׳�
	int n1;
	scanf("%d", &n1);
	int ret2 = factorial1(n1);
	printf("ret2=%d\n", ret2);

	int ret3 = factorial2(n1);
	printf("ret3=%d\n", ret3);

	//���n2��쳲�������
	int n2;
	scanf("%d", &n2);
	int ret4 = fibonacci(n2);
	printf("ret4=%d\n", ret4);

	//ѭ�����n2��쳲�������
	int ret5 = fibonacci2(n2);
	printf("ret5=%d\n", ret5);
	
	//��ŵ������
	//������̨������(쳲���������)(��ָoffer)
	return 0;
} 