#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
// ��֧���(ѡ��ṹ)

// if; if else; if else if else;
// switch ���

// ѭ���ṹ

// whileѭ��;do whileѭ��;forѭ��

void menu()
{
	printf("************************\n");
	printf("*** 1. play  0. exit ***\n");
	printf("************************\n");
}

void game()
{
	int ret;
	int guessnum;
	//ʱ���:1970��1��1��00:00:00��������
	//srand((unsigned int)time(NULL));//��ʱ����������������������ʼ��,time()�������ص�long��(time_t����)ǿ��ת��Ϊint��
	ret = rand()%100 + 1; //����һ��0-RAND_MAX(32767)���������,תΪ1-100�������
	
	while (1)
	{
		printf("��������:");
		scanf("%d", &guessnum);
		if (ret == guessnum)
		{
			printf("����!\n");
			break;
		}
		else if (ret < guessnum)
		{
			printf("����ƫ��...\n");
		}
		else
		{
			printf("����ƫС...\n");
		}
	}
}

int main()
{
	; //�����

	int age = 25;

	if (age < 18)
		printf("δ����\n");
	else if (age < 28)
		printf("����\n");
	else
		printf("������\n");

	//����else

	int a1 = 0;
	int a2 = 2;

	if (a1 == 1)//if (1 == a1)
		if (a2 == 2)
			printf("hehe\n");
	else //�ͽ�ƥ��
		printf("haha\n");

	for (int i = 1; i <= 100; i++)
	{
		if (i % 2 == 1)
			printf("%d ", i);
	}
	
	int j = 1;
	while (j <= 100)
	{
		if (j % 2 == 1)
			printf("%d ", j);
		j++;
	}
	
	int k = 1;
	while (k <= 100)
	{
		printf("%d ", k);
		k += 2;
	}

	int day = 0;
	// scanf("%d", &day);

	switch (day) //(���ͱ��ʽ)
	{
	case 1:		//case ���ͳ������ʽ
		printf("����һ\n");
		break; // ����switch_case���
	case 2:
		printf("���ڶ�\n");
		break;
	case 3:
		printf("������\n");
		break;
	case 4:
		printf("������\n");
		break;
	case 5:
		printf("������\n");
		break;
	case 6:
		printf("������\n");
		break;
	case 7:
		printf("������\n");
		break;
	default:
		printf("�������\n");
		break;
	}

	switch (day)
	{
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
		printf("������\n");
		break;
	case 6:
	case 7:
		printf("��Ϣ��\n");
		break;
	default:
		printf("�������\n");
		break;
	}

	// ѭ���ṹ

	//whileѭ��
	int a3 = 0;
	while (a3 < 10)
	{
		a3++;
		if (a3 == 5)
			continue; // ��ֹ����ѭ��,����ѭ����continue��Ĵ��벻��ִ��,ֱ������while���жϲ���
		printf("%d\n",a3);
		
	}

	int ch1 = getchar(); // ���ռ���������ַ�

	putchar(ch1); // ����ַ�

	printf("%c\n", ch1);

	int ch2 = 0;
	while ((ch2 = getchar()) != EOF) // Ctrl + Z; end of file -> -1;�ļ�������־
	{
		putchar(ch2);
	}

	char password[20] = { 0 };
	int ret = 0;
	printf("��������:");
	scanf("%s", password); //scanfֻ�ܶ�ȡ�ո�ǰ���ַ���;���뻺����;ʣ��ո�֮����ַ���+'\n'
	
	int ch3;
	while (ch3 = getchar() != '\n')
	{
		;
	}

	printf("Y/N:");
	ret = getchar();
	if (ret == 'Y')
	{
		printf("�ɹ�\n");
	}
	else
	{
		printf("ʧ��\n");
	}

	int ch4 = 0;
	while ((ch4 = getchar()) != EOF)
	{
		if (ch4 < '0' || ch4 > '9')
			continue;
		putchar(ch4);
	}
	

	//forѭ��
	for (int i = 0; i < 10; i++)
	{
		if (i == 5)
			break;
		printf("%d\n", i);
	}
	
	for (int i = 0; i < 10; i++)
	{
		if (i == 5)
			continue;
		printf("%d\n", i);
	}
	
	// for (;;) //��ѭ��,�ж�������Ϊ��
	// {
	//	 printf("hehe\n");
	// }

	int x, y;
	for (x = 0,y = 0; x<2 && y<5; ++x,y++)
	{
		printf("hehe\n");
	}

	// do...while ѭ��
	
	int i = 1;
	do //����ִ��һ��
	{
		printf("%d\n", i);
		i++;
	} 
	while (i<=10);

	// n�Ľ׳�
	int i1 = 1;
	int prod = 1;
	int n = 0;
	printf("n = ");
	scanf("%d", &n);
	for(i1 = 1; i1 <= n; i1++)
	{
		prod = prod * i1;
	}
	printf("prod = %d\n", prod);

	// �׳˺�
	int prosum = 0;
	for (int i2 = 1; i2 <= 10; i2++)
	{
		int prod1 = 1;
		for (int i3 = 1; i3 <= i2; i3++)
		{
			prod1 = prod1 * i3;
		}
		prosum = prosum + prod1;
	}
	printf("prosum = %d\n", prosum);

	//�׳˺ͼ򻯴���
	int prosum2 = 0;
	int prod2 = 1;
	for (int i4 = 1; i4 <= 10; i4++)
	{
		prod2 = prod2 * i4;
		prosum2 = prosum2 + prod2;
	}
	printf("prosum2 = %d\n", prosum2);


	//����������v[]�в�������n5�ı��
	
	int v[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int n5 = 7;

	for (int i = 0; i < 10; i++)
	{
		if (v[i] == n5)
		{
			printf("%d\n", i);
			break;
		}
	}
	if (i == 10)
		printf("δ�ҵ�\n");

	//����������۰���ҷ�;���ֲ��ҷ�(ʱ�临�Ӷ�:log2(n))
	int low = 0;
	int high = sizeof(v)/sizeof(v[0]) - 1;
	int loca;

	while (low <= high)
	{
		loca = (low + high) / 2;

		if (n5 == v[loca])
		{
			printf("n5�������±� = %d\n", loca);
			break;
		}
		else if (n5 < v[loca])
		{
			high = loca - 1;
		}
		else if (n5 > v[loca])
		{
			low = loca + 1;
		}
	}
	if (low > high) 
	{
		printf("δ�ҵ�\n");
	}


	//����ַ��������ƶ�,���м���

	char str1[] = "welcome to bit!!!!" ;
	char str2[] = "##################" ;
	int left = 0;
	int right = strlen(str1)-1;//�ַ�����С
	for (left = 0; left <= right; left++,right--)
	{
		system("cls"); //ִ��ϵͳ�����һ������: cls,�����Ļ
		str2[left] = str1[left];
		str2[right] = str1[right];
		printf("%s\n", str2);
		Sleep(500); //��Ϣ500ms
	}
	
	// ����¼���εĽ���
	int i2 = 0;
	char str3[] = "ningbangjie";
	char passwords[20] = { 0 };
	for (i2 = 0;i2 < 3;i2 ++)
	{
		printf("����������:");
		scanf("%s", passwords);
		if (strcmp(passwords,str3) == 0) //�Ƚ������ַ����Ƿ����:strcmp
		{
			printf("��¼�ɹ�\n");
			break;
		}
		else
		{
			printf("�������\n");
		}
	}
	if (i2 == 3)
	{
		printf("�������������\n");
	}

	//�Ӵ�С���3����

	int c1 = 0;
	int c2 = 0;
	int c3 = 0;
	scanf("%d%d%d", &c1, &c2, &c3);

	if (c1<c2)
	{
		int tmp = c1;
		c1 = c2;
		c2 = tmp;
	}
	if (c3<c2)
	{
		printf("%d %d %d\n", c1, c2, c3);
	}
	else if (c3>c1)
	{
		printf("%d %d %d\n", c3, c1, c2);
	}
	else
	{
		printf("%d %d %d\n", c1, c3, c2);
	}

	//1-100��3�ı�������
	for (int i3 = 1; i3 <= 100; i3++)
	{
		if (i3 % 3 == 0)
			printf("%d ", i3);
	}

	//���������Լ��(շת�����)
	int a4, a5;
	int tmp2;
	scanf("%d%d", &a4, &a5);

	while (1)
	{
		if (a4 % a5 == 0)
		{
			printf("%d\n", a5);
			break;
		}
		else
		{
			tmp2 = a5;
			a5 = a4 % a5;
			a4 = tmp2;
		}
	}
	//����
	/*while (a4%a5)
	{
		tmp2 = a5;
		a5 = a4 % a5;
		a4 = tmp2;
	}
	printf("%d\n", a5);*/

	// 1000-2000��֮�������
	// ����: �ܱ�4���������ܱ�100����,�ܱ�400����
	int a6 = 0;
	for (int year = 1000; year <= 2000 ; year++)
	{
		if (year % 4 == 0 && year % 100 != 0 || year%400 == 0)
		{
			a6 ++;
			printf("%d %d\n", year,a6);
		}
	}


	// 100-200֮�������
	// ����: �Գ���
	int a7, a8;
	int a9 = 0;
	for (a7 = 101; a7 <= 200; a7+=2)
	{
		for (a8 = 2; a8 <= sqrt(a7) ; a8++)
		{
			if (a7 % a8 == 0)
			{
				break;
			}
		}
		if (a8 > sqrt(a7))
		{
			a9++;
			printf("%d %d\n", a7,a9);
			
		}
	}

	// 1-100�г���9�Ĵ���
	int i4;
	int a10 = 0;
	for (i4 = 1; i4 <= 100; i4++)
	{
		if (i4%10 == 9)
		{
			a10++;
		}
		if (i4/10 == 9)
		{
			a10++;
		}
	}
	printf("%d\n", a10);

	// �������:1-1/2+1/3-1/4+1/5...+1/99-1/100
	int i5;
	double sum = 0.0;
	for (i5 = 1; i5 <= 100; i5++)
	{
		sum += 1.0 / i5 * pow(-1,i5-1);
	}
	printf("%lf\n", sum);

	// ��10�������е����ֵ
	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
	int i6;
	int max;
	for ( i6 = 1; i6 < 10; i6++)
	{
		if (arr1[0]<arr1[i6])
		{
			arr1[0] = arr1[i6];
		}
	}
	printf("%d\n", arr1[0]);

	//����˷��ھ���
	int i7, i8;
	int prod1;
	for (i7 = 1; i7 <= 9 ; i7++)
	{
		for (i8 = 1; i8 <= i7; i8++)
		{
			prod = i7 * i8;
			printf("%d*%d=%-2d ", i7, i8, prod);//%2d��λ�Ҷ���
		}
		printf("\n");
	}

	// ��������Ϸ:����һ�������,�����ַ�����Сֱ���¶�
	int choose1;
	srand((unsigned int)time(NULL));//�����������ʼ��ֻ��ִ��һ��
	do
	{
		menu();
		printf("��ѡ��>:");
		scanf("%d", &choose1);
		switch (choose1)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�������\n");
			break;
		}
	} while (choose1);
	
	//goto���,�������������Ƕ�׽ṹ
	again:
	printf("hello bit\n");
	goto again;// ��ת��again,��ѭ��

	//һ���ػ�����

	// shutdown -s -t 60	60���ڹػ�
	// shutdown -a			ȡ���ػ�
	char closeins[20] = {0};
	system("shutdown -s -t 60");

	//
	again:
	printf("���Խ���60s�ڹػ�,����:\"ȡ���ػ�\"����ֹͣ����\n����:>");
	scanf("%s", closeins);
	if (strcmp(closeins,"ȡ���ػ�")==0)
	{
		system("shutdown -a");
		printf("��ȡ���ػ�����");
	}
	else
	{
		goto again;
	}

	//
	while (1)
	{
		printf("���Խ���60s�ڹػ�,����:\"ȡ���ػ�\"����ֹͣ����\n����:>");
		scanf("%s", closeins);
		if (strcmp(closeins, "ȡ���ػ�")==0)
		{
			system("shutdown -a");
			printf("��ȡ���ػ�����");
			break;
		}
	}
	
	return 0;
}