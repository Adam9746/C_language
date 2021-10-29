#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
// 分支语句(选择结构)

// if; if else; if else if else;
// switch 语句

// 循环结构

// while循环;do while循环;for循环

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
	//时间戳:1970年1月1日00:00:00距今的秒数
	//srand((unsigned int)time(NULL));//用时间戳来设置随机数的生成起始点,time()函数返回的long型(time_t类型)强制转换为int型
	ret = rand()%100 + 1; //返回一个0-RAND_MAX(32767)的随机整数,转为1-100的随机数
	
	while (1)
	{
		printf("输入整数:");
		scanf("%d", &guessnum);
		if (ret == guessnum)
		{
			printf("猜中!\n");
			break;
		}
		else if (ret < guessnum)
		{
			printf("数字偏大...\n");
		}
		else
		{
			printf("数字偏小...\n");
		}
	}
}

int main()
{
	; //空语句

	int age = 25;

	if (age < 18)
		printf("未成年\n");
	else if (age < 28)
		printf("青年\n");
	else
		printf("中老年\n");

	//悬空else

	int a1 = 0;
	int a2 = 2;

	if (a1 == 1)//if (1 == a1)
		if (a2 == 2)
			printf("hehe\n");
	else //就近匹配
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

	switch (day) //(整型表达式)
	{
	case 1:		//case 整型常量表达式
		printf("星期一\n");
		break; // 跳出switch_case语句
	case 2:
		printf("星期二\n");
		break;
	case 3:
		printf("星期三\n");
		break;
	case 4:
		printf("星期四\n");
		break;
	case 5:
		printf("星期五\n");
		break;
	case 6:
		printf("星期六\n");
		break;
	case 7:
		printf("星期日\n");
		break;
	default:
		printf("输入错误\n");
		break;
	}

	switch (day)
	{
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
		printf("工作日\n");
		break;
	case 6:
	case 7:
		printf("休息日\n");
		break;
	default:
		printf("输入错误\n");
		break;
	}

	// 循环结构

	//while循环
	int a3 = 0;
	while (a3 < 10)
	{
		a3++;
		if (a3 == 5)
			continue; // 终止本次循环,本次循环中continue后的代码不再执行,直接跳到while的判断部分
		printf("%d\n",a3);
		
	}

	int ch1 = getchar(); // 接收键盘输入的字符

	putchar(ch1); // 输出字符

	printf("%c\n", ch1);

	int ch2 = 0;
	while ((ch2 = getchar()) != EOF) // Ctrl + Z; end of file -> -1;文件结束标志
	{
		putchar(ch2);
	}

	char password[20] = { 0 };
	int ret = 0;
	printf("输入密码:");
	scanf("%s", password); //scanf只能读取空格前的字符串;输入缓冲区;剩余空格及之后的字符串+'\n'
	
	int ch3;
	while (ch3 = getchar() != '\n')
	{
		;
	}

	printf("Y/N:");
	ret = getchar();
	if (ret == 'Y')
	{
		printf("成功\n");
	}
	else
	{
		printf("失败\n");
	}

	int ch4 = 0;
	while ((ch4 = getchar()) != EOF)
	{
		if (ch4 < '0' || ch4 > '9')
			continue;
		putchar(ch4);
	}
	

	//for循环
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
	
	// for (;;) //死循环,判断条件恒为真
	// {
	//	 printf("hehe\n");
	// }

	int x, y;
	for (x = 0,y = 0; x<2 && y<5; ++x,y++)
	{
		printf("hehe\n");
	}

	// do...while 循环
	
	int i = 1;
	do //至少执行一次
	{
		printf("%d\n", i);
		i++;
	} 
	while (i<=10);

	// n的阶乘
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

	// 阶乘和
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

	//阶乘和简化代码
	int prosum2 = 0;
	int prod2 = 1;
	for (int i4 = 1; i4 <= 10; i4++)
	{
		prod2 = prod2 * i4;
		prosum2 = prosum2 + prod2;
	}
	printf("prosum2 = %d\n", prosum2);


	//在有序数组v[]中查找数字n5的编号
	
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
		printf("未找到\n");

	//有序数组的折半查找法;二分查找法(时间复杂度:log2(n))
	int low = 0;
	int high = sizeof(v)/sizeof(v[0]) - 1;
	int loca;

	while (low <= high)
	{
		loca = (low + high) / 2;

		if (n5 == v[loca])
		{
			printf("n5的数组下标 = %d\n", loca);
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
		printf("未找到\n");
	}


	//多个字符从两端移动,向中间汇聚

	char str1[] = "welcome to bit!!!!" ;
	char str2[] = "##################" ;
	int left = 0;
	int right = strlen(str1)-1;//字符串大小
	for (left = 0; left <= right; left++,right--)
	{
		system("cls"); //执行系统命令的一个函数: cls,清空屏幕
		str2[left] = str1[left];
		str2[right] = str1[right];
		printf("%s\n", str2);
		Sleep(500); //休息500ms
	}
	
	// 最多登录三次的界面
	int i2 = 0;
	char str3[] = "ningbangjie";
	char passwords[20] = { 0 };
	for (i2 = 0;i2 < 3;i2 ++)
	{
		printf("请输入密码:");
		scanf("%s", passwords);
		if (strcmp(passwords,str3) == 0) //比较两个字符串是否相等:strcmp
		{
			printf("登录成功\n");
			break;
		}
		else
		{
			printf("密码错误\n");
		}
	}
	if (i2 == 3)
	{
		printf("错误次数达上限\n");
	}

	//从大到小输出3个数

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

	//1-100间3的倍数的数
	for (int i3 = 1; i3 <= 100; i3++)
	{
		if (i3 % 3 == 0)
			printf("%d ", i3);
	}

	//两数的最大公约数(辗转相除法)
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
	//或者
	/*while (a4%a5)
	{
		tmp2 = a5;
		a5 = a4 % a5;
		a4 = tmp2;
	}
	printf("%d\n", a5);*/

	// 1000-2000年之间的闰年
	// 闰年: 能被4整除但不能被100整除,能被400整除
	int a6 = 0;
	for (int year = 1000; year <= 2000 ; year++)
	{
		if (year % 4 == 0 && year % 100 != 0 || year%400 == 0)
		{
			a6 ++;
			printf("%d %d\n", year,a6);
		}
	}


	// 100-200之间的素数
	// 素数: 试除法
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

	// 1-100中出现9的次数
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

	// 分数求和:1-1/2+1/3-1/4+1/5...+1/99-1/100
	int i5;
	double sum = 0.0;
	for (i5 = 1; i5 <= 100; i5++)
	{
		sum += 1.0 / i5 * pow(-1,i5-1);
	}
	printf("%lf\n", sum);

	// 求10个整数中的最大值
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

	//输出乘法口诀表
	int i7, i8;
	int prod1;
	for (i7 = 1; i7 <= 9 ; i7++)
	{
		for (i8 = 1; i8 <= i7; i8++)
		{
			prod = i7 * i8;
			printf("%d*%d=%-2d ", i7, i8, prod);//%2d两位右对齐
		}
		printf("\n");
	}

	// 猜数字游戏:生成一个随机数,猜数字反馈大小直至猜对
	int choose1;
	srand((unsigned int)time(NULL));//随机数生成起始点只需执行一次
	do
	{
		menu();
		printf("请选择>:");
		scanf("%d", &choose1);
		switch (choose1)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误\n");
			break;
		}
	} while (choose1);
	
	//goto语句,适用于跳出深层嵌套结构
	again:
	printf("hello bit\n");
	goto again;// 跳转到again,死循环

	//一个关机程序

	// shutdown -s -t 60	60秒内关机
	// shutdown -a			取消关机
	char closeins[20] = {0};
	system("shutdown -s -t 60");

	//
	again:
	printf("电脑将在60s内关机,输入:\"取消关机\"即可停止命令\n输入:>");
	scanf("%s", closeins);
	if (strcmp(closeins,"取消关机")==0)
	{
		system("shutdown -a");
		printf("已取消关机命令");
	}
	else
	{
		goto again;
	}

	//
	while (1)
	{
		printf("电脑将在60s内关机,输入:\"取消关机\"即可停止命令\n输入:>");
		scanf("%s", closeins);
		if (strcmp(closeins, "取消关机")==0)
		{
			system("shutdown -a");
			printf("已取消关机命令");
			break;
		}
	}
	
	return 0;
}