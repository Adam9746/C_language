#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ָ�����
// 1. �ַ�ָ��
// 2. ����ָ��
// 3. ָ������
// 4. ���鴫�κ�ָ�봫��
// 5. ����ָ��
// 6. ����ָ������
// 7. ָ����ָ�������ָ��
// 8. �ص�����

void Print1(int arr[3][5], int x, int y)
{
	int i = 0;
	int j = 0;
	for ( i = 0; i < x; i++)
	{
		for ( j = 0; j < y; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

//void Print1(int arr[3][5], int x, int y)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < x; i++)
//	{
//		for (j = 0; j < y; j++)
//		{
//			printf("%d ", *(*(arr+i)+j));
//		}
//		printf("\n");
//	}
//}

void Print2(int(*p)[5], int x, int y)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < x; i++)
	{
		for (j = 0; j < y; j++)
		{
			printf("%d ", (*(p+i))[j]);
		}
		printf("\n");
	}
}

int Add(int x, int y)
{
	int z;
	z = x + y;
	return z;
}

int Sub(int x, int y)
{
	int z;
	z = x - y;
	return z;
}

int Mul(int x, int y)
{
	int z;
	z = x * y;
	return z;
}

int Div(int x, int y)
{
	int z;
	z = x / y;
	return z;
}

void Print3(char* str)
{
	printf("%s\n", str);
}

void menu()
{
	printf("**************************************************\n");
	printf("**1.add*****2.sub*****3.mul*****4.div*****0.exit**\n");
	printf("**************************************************\n");
}

void Calc(int(*p)(int,int))
{
	int x, y = 0;
	printf("������������:>");
	scanf("%d%d", &x, &y);
	printf("%d\n", p(x, y));
}

struct Stu
{
	char name[20];
	int age;
};

int compar_int(const void* p1, const void* p2)
{
	if (*(int*)p1 < *(int*)p2)
		return -1;
	else if (*(int*)p1 == *(int*)p2)
		return 0;
	else
		return 1;
}

int compar_float(const void* p1, const void* p2)
{
	if (*(float*)p1 < *(float*)p2)
		return -1;
	else if (*(float*)p1 == *(float*)p2)
		return 0;
	else
		return 1;
}

int compar_struc_byage(const void* p1, const void* p2)
{
	if (((struct Stu*)p1)->age > ((struct Stu*)p2)->age)
		return 1;
	else if (((struct Stu*)p1)->age == ((struct Stu*)p2)->age)
		return 0;
	else
		return -1;	
}

int compar_struc_byname(const void* p1, const void* p2) //�ַ����Ƚϲ���ֱ����<>=,Ӧ����strcmp����
{
	return strcmp(((struct Stu*)p1)->name, ((struct Stu*)p2)->name);
}

//void Swap(char* s1, char* s2,int width) //�����ֽ�Ϊ��λ���н���
//{
//	int i = 0;
//	for ( i = 0; i < width; i++)
//	{
//		char tmp = *s1;
//		*s1 = *s2;
//		*s2 = tmp;
//		s1++;
//		s2++;
//	}
//}
void Swap(char* s1, char* s2, int width) //�����ֽ�Ϊ��λ���н���
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char tmp = s1[i];
		s1[i] = s2[i];
		s2[i] = tmp;
	}
}

void bubble_sort(void* base, int sz, int width,int (*cmp)(void* p1,void* p2))
{
	int i = 0;
	for ( i = 0; i < sz - 1; i++)
	{
		int j = 0;
		for ( j = 0; j < sz - 1 - i; j++)
		{
			// ����Ԫ�صıȽ�
			if (cmp((char*)base+j*width,(char*)base+(j+1)*width) > 0)
			{
				// ��������Ԫ��
				Swap((char*)base + j * width, (char*)base + (j + 1) * width,width);
			}
		}
	}
}

int main()
{
	// �ַ�ָ��
	char ch1 = 'w';
	char* pc1 = &ch1;
	
	char arr[] = "abcdef";
	char* pc2 = arr;
	printf("%s\n", arr);
	printf("%s\n", pc2);

	const char* pc3 = "abcdefg"; //�����ַ���,�ַ������ַ��ĵ�ַ��ֵ��pc3
	printf("%c\n", *pc3);
	// *pc3 = 'W'; ���ܱ��ı�
	printf("%s\n", pc3);

	char arr1[] = "abcdef";
	char arr2[] = "abcdef";
	const char* pc4 = "abcdef";
	const char* pc5 = "abcdef";

	if (arr1 == arr2)
	{
		printf("haha\n");
	}
	else
	{
		printf("�Ǻ�\n");
	}

	if (pc4 == pc5)
	{
		printf("haha\n");
	}
	else
	{
		printf("�Ǻ�\n");
	}

	// ָ������

	int arr3[10] = { 0 }; //��������
	char ch2[5] = { 0 }; //�ַ�����
	int* arr4[4]; //ָ������
	char* arr5[4];

	int a1 = 10;
	int a2 = 20;
	int a3 = 30;
	int a4 = 40;
	int* arr6[4] = { &a1,&a2,&a3,&a4 };
	int i1 = 0;
	for ( i1 = 0; i1 < 4; i1++)
	{
		printf("%d\n", *arr6[i1]);
	}

	int arr7[] = { 1,2,3,4,5 };
	int arr8[] = { 2,3,4,5,6 };
	int arr9[] = { 3,4,5,6,7 };
	int* arr11[] = { arr7,arr8,arr9 };
	int i2 = 0;
	for ( i2 = 0; i2 < 3; i2++)
	{
		int j2 = 0;
		for ( j2 = 0; j2 < 5; j2++)
		{
			printf("%d ", *(arr11[i2] + j2));
		}
		printf("\n");
	}

	// ����ָ��,ָ�������ָ��,�������ĵ�ַ

	int* pc6 = NULL; // ����ָ��
	char* pc7 = NULL; // �ַ�ָ��

	int arr12[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int(*pc8)[10] = &arr12;// ����ָ��

	char* arr13[5];
	char* (*pc9)[5] = &arr13;

	int i3 = 0;
	for ( i3 = 0; i3 < 10; i3++)
	{
		printf("%d\n",(*pc8)[i3]);  // *pc8 = arr12
		printf("%d\n", *(*pc8 + i3));
	}

	int arr14[3][5] = { {1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7} };
	Print1(arr14, 3, 5);
	Print2(arr14, 3, 5);

	// int (*parr1[10])[5]  parr:����ָ������,10��Ԫ��,ÿ��Ԫ��Ϊ����ָ��,ÿ������ָ��ָ��Ԫ�ظ���Ϊ5����������

	// �������,ָ�����

	// һά���鴫��
	// 
	// int arr[10] = {0};
	// test(arr);
	// void test(int arr[])
	// void test(int arr[10])  //�����С����ʡ��
	// void test(int* arr)
	//
	// int* arr2[20] = {0};
	// test2(arr2);
	// void test2(int* arr[])  //�����С����ʡ��
	// void test2(int** arr)
	
	// ��ά���鴫��
	// 
	// int arr[3][5] = {0};
	// test(arr);
	// void test(int arr[3][5])
	// void test(int arr[][5])  //��������ʡ��
	// void test(int(*arr)[5])

	// һ��ָ�봫��
	// 
	// void test(char* p)
	// void test(int* p)

	// ����ָ�봫��
	// 
	// void test(int** ptr)
	// int* arr[10];
	// test(arr);
	// 
	// int* pc13 = arr12;
	// int** pc10 = &pc13;
	// int** pc12 = &arr12;
	// int(*pc11)[10] = &arr12;
	// printf("%p\n", pc13);
	// printf("%p\n", pc10);
	// printf("%p\n", pc11);
	// printf("%p\n", pc12);
	// printf("%d %d\n", *pc13, *arr12);

	// ����ָ��,ָ������ָ��,��ź����ĵ�ַ
	
	printf("%d\n", Add(a1, a2));

	// ȡ��ַ�������ͺ��������Ǻ����ĵ�ַ
	printf("%p\n", &Add); // �����ĵ�ַ
	printf("%p\n", Add);  // �����ĵ�ַ
	int(*pc14)(int, int) = Add;
	printf("%d\n", (*pc14)(2, 3));

	void(*pc15)(char*) = Print3;
	(pc15)(pc3);
	(*pc15)(pc3);
	(**pc15)(pc3);

	(*pc15)("hello world!");

	//(*(void (*)())0)(); // ��0ǿ������ת���ɺ���ָ������,0��Ϊ�����ĵ�ַ

	//void(*signal(int, void(*)(int)))(int); // ����signal(int, void(*)(int))������,������������Ϊvoid(*)(int)

	//typedef void(*pfun_t)(int);
	//pfun_t signal(int, pfun_t);

	// ����ָ������

	int (*parr2[4])(int, int) = { Add,Sub,Mul,Div };
	int i4 = 0;
	for ( i4 = 0; i4 < 4; i4++)
	{
		printf("%d\n", parr2[i4](2, 3));
	}

	// ������
	
	int input = 0;
	int x, y = 0;
	int (*parr3[])(int, int) = { 0,Add,Sub,Mul,Div }; //ת�Ʊ�
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		
		//if (input >= 1 && input <= sizeof(parr3) / sizeof(parr3[0]) - 1)
		//{
		//	printf("������������:>");
		//	scanf("%d%d", &x, &y);
		//	printf("%d\n", parr3[input](x, y));
		//}
		//else if(input == 0)
		//{
		//	printf("�˳�\n");
		//}
		//else
		//{
		//	printf("�������\n");
		//}

		//switch (input)
		//{
		//case 1:
		//	printf("������������:>");
		//	scanf("%d%d", &x, &y);
		//	printf("%d\n", Add(x, y));
		//	break;
		//case 2:
		//	printf("������������:>");
		//	scanf("%d%d", &x, &y);
		//	printf("%d\n", Sub(x, y));
		//	break;
		//case 3:
		//	printf("������������:>");
		//	scanf("%d%d", &x, &y);
		//	printf("%d\n", Mul(x, y));
		//	break;
		//case 4:
		//	printf("������������:>");
		//	scanf("%d%d", &x, &y);
		//	printf("%d\n", Div(x, y));
		//	break;
		//case 0:
		//	printf("�˳�\n");
		//	break;
		//default:
		//	printf("�������\n");
		//	break;
		//}

		// �ص�����(ͨ������ָ����õĺ���)
		switch (input)
		{
		case 1:
			Calc(Add);
			break;
		case 2:
			Calc(Sub);
			break;
		case 3:
			Calc(Mul);
			break;
		case 4:
			Calc(Div);
			break;
		case 0:
			printf("�˳�\n");
			break;
		default:
			printf("�������\n");
			break;
		}
	 
	} while (input);

	// ָ����ָ�������ָ��

	int(*(*pfarr)[4])(int, int) = &parr2;

	// qsort - ���������������͵�����(��������)
	// void qsort(void* base, size_t num, size_t size,int (*compar)(const void* p1, const void* p2));
	// void* ������ָ��,���Խ����������͵ĵ�ַ,���ܽ��н����ò���

	int arr15[10] = { 9,0,1,7,2,4,3,5,6,8 };
	int sz15 = sizeof(arr15) / sizeof(arr15[0]);

	float farr[] = { 9.0,8.4,5.6,7.9,6.4,3.2,2.8,1.7 };
	int sz16 = sizeof(farr) / sizeof(farr[0]);

	struct Stu stuarr[3] = { {"bang",24},{"ning",20},{"jie",28} };
	int sz17 = sizeof(stuarr) / sizeof(stuarr[0]);

	//qsort(arr15,sz15,sizeof(arr15[0]),compar_int);
	//int i15 = 0;
	//for ( i15 = 0; i15 < sz15; i15++)
	//{
	//	printf("%d\n", *(arr15 + i15));
	//}

	qsort(farr, sz16, sizeof(farr[0]), compar_float);
	int i16 = 0;
	for (i16 = 0; i16 < sz16; i16++)
	{
		printf("%f\n", *(farr + i16));
	}

	qsort(stuarr, sz17, sizeof(stuarr[0]), compar_struc_byage);
	int i17 = 0;
	for ( i17 = 0; i17 < sz17; i17++)
	{
		printf("%d\n", (stuarr + i17)->age);
	}

	qsort(stuarr, sz17, sizeof(stuarr[0]), compar_struc_byname);
	for (i17 = 0; i17 < sz17; i17++)
	{
		printf("%s\n", (stuarr + i17)->name);
	}

	//ð������������͵�����

	bubble_sort(arr15, sz15, sizeof(arr15[0]), compar_int);


	return 0;

} 