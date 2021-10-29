#define _CRT_SECURE_NO_WARNINGS 1

// ָ��
// ָ������
#include <stdio.h>
#include <string.h>

int* test()
{
	int a4 = 10;
	return &a4;
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

	// ָ�����;�����ָ����н����ò���ʱ�ܹ����ʿռ�Ĵ�С
	// int* p; *p�ܹ�����4���ֽ�
	// char* p; *p�ܹ�����1���ֽ�
	// double* p; *p�ܹ�����8���ֽ�

	int* p1 = &a1;
	*p1 = 0;
	printf("%#x\n", a1);
	char* p2 = &a2;
	*p2 = 0;
	printf("%#x\n", a2);

	printf("%p\n", p1);
	printf("%p\n", p2);

	// ָ��+-����
	// ָ�����;�����ָ��Ĳ���
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

	// Ұָ��:ָ��ָ���λ���ǲ���֪��(�����,����ȷ��,û����ȷ���Ƶ�)
	//
	// 1.ָ��δ��ʼ��
	// int a; �ֲ���������ʼ��,Ĭ�������ֵ
	// int* p; �ֲ���ָ�����,�ͱ���ʼ��Ϊ���ֵ
	// 
	// 2.ָ��Խ�����
	// int arr3[10] = { 0 };
	// int* p7 = arr3;
	// int i3 = 0;
	// for ( i3 = 0; i3 < 12; i3++)
	// {
	//	 *p7 = i3;
	//   p7++;//Ұָ��
	// }
	// 3.ָ��ָ����ڴ�ռ��ͷ�
	
	// int* p8 = test();
	// *p8 = 20;
	// printf("%d\n",*p8);
	// p8 = NULL;
	// 
	// ���Ұָ��
	// 1. ָ���ʼ��
	// 2. С��ָ��Խ��
	// 3. ָ��ָ��Ŀռ��ͷ�ʱ��ΪNULL
	// 4. ָ��ʹ��֮ǰ�����Ч��

	int* p9 = NULL; // ָ�������ʼ����ֵ
	printf("%p\n", p9);

	// ���ָ�����Ч��
	if (p9 != NULL)
	{
		*p9 = 20;
	}


	// ָ������
	// 
	// ָ��+-����
	// ָ��-ָ��
	// ָ��Ĺ�ϵ����(�Ƚϴ�С)

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
	// ָ��-ָ�� = ָ��֮��Ԫ�صĸ���
	printf("%d\n", &arr3[9] - &arr3[0]);
	printf("%d\n", &arr3[0] - &arr3[9]);
	printf("%d\n", &ch1[4] - &ch1[0]);

	// ���ַ����ĳ���

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

	// ָ�������
	// 
	// &������:������������Ԫ�صĵ�ַ,��������ʾ��������;ȡ��������������ĵ�ַ
	// sizeof(������):��������ʾ��������;���������������Ĵ�С,��λ���ֽ�

	printf("%p\n", arr3);
	printf("%p\n", arr3 + 1);
	printf("%p\n", &arr3[0]);
	printf("%p\n", &arr3[0] + 1);
	printf("%p\n", &arr3);
	printf("%p\n", &arr3 + 1);

	// ����ָ��
	
	int a4 = 10;
	int* p13 = &a4;
	int** p14 = &p13; // ����ָ��
	**p14 = 20;
	printf("%d\n", **p14);
	printf("%d\n", a4);

	// ָ������:���ָ�������

	int* arr4[4] = {&a1,&a2,&a3,&a4};
	int i6 = 0;
	for ( i6 = 0; i6 < 4; i6++)
	{
		printf("%d\n", *(arr4[i6]));
		printf("%d\n", **(arr4+i6));
	}

	return 0;
}

