#include <iostream>
#include <ctime>    //���ڲ���������ݵ�����
using namespace std;
#define N 8    //���Ծ���ά������

//����һ��չ������|A|
double getA(double arcs[N][N], int n)
{
	if (n == 1)
	{
		return arcs[0][0];
	}
	double ans = 0;
	double temp[N][N] = { 0.0 };
	int i, j, k;
	for (i = 0; i<n; i++)
	{
		for (j = 0; j<n - 1; j++)
		{
			for (k = 0; k<n - 1; k++)
			{
				temp[j][k] = arcs[j + 1][(k >= i) ? k + 1 : k];

			}
		}
		double t = getA(temp, n - 1);
		if (i % 2 == 0)
		{
			ans += arcs[0][i] * t;
		}
		else
		{
			ans -= arcs[0][i] * t;
		}
	}
	return ans;
}

//����ÿһ��ÿһ�е�ÿ��Ԫ������Ӧ������ʽ�����A*
void  getAStart(double arcs[N][N], int n, double ans[N][N])
{
	if (n == 1)
	{
		ans[0][0] = 1;
		return;
	}
	int i, j, k, t;
	double temp[N][N];
	for (i = 0; i<n; i++)
	{
		for (j = 0; j<n; j++)
		{
			for (k = 0; k<n - 1; k++)
			{
				for (t = 0; t<n - 1; t++)
				{
					temp[k][t] = arcs[k >= i ? k + 1 : k][t >= j ? t + 1 : t];
				}
			}


			ans[j][i] = getA(temp, n - 1);  //�˴�˳�������ת��
			if ((i + j) % 2 == 1)
			{
				ans[j][i] = -ans[j][i];
			}
		}
	}
}

//�õ���������src������󱣴浽des�С�
bool GetMatrixInverse(double src[N][N], int n, double des[N][N])
{
	double flag = getA(src, n);
	double t[N][N];
	if (0 == flag)
	{
		cout << "ԭ��������ʽΪ0���޷����档����������" << endl;
		return false;//���������������ʽΪ0�������½���
	}
	else
	{
		getAStart(src, n, t);
		for (int i = 0; i<n; i++)
		{
			for (int j = 0; j<n; j++)
			{
				des[i][j] = t[i][j] / flag;
			}

		}
	}

	return true;
}
