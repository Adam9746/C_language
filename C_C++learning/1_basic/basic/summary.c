#define _CRT_SECURE_NO_WARNINGS 1

int g_val = 2021;
static int g_val1 = 2022;//static����ȫ�ֱ���, �ı��˱�����������, ��̬��ȫ�ֱ���ֻ��������Դ�ļ����ڲ�ʹ��
static int Add1(int x, int y)//static���κ���,�ı��˺�������������(�ⲿ��������-->�ڲ���������)
{
	int z = x + y;
	return z;
}