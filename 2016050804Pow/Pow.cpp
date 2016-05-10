//ʵ��pow(x,y)����;�������Ǽ���x��y�η���x��y������ֵ����double�� 
//����ʹ�ÿ⺯�������迼�Ǵ������� 
#include<iostream>
using namespace std;
double PowerPositiveExponent(double base, int exponent)
{
	double ret = 1.0;
	for (; exponent > 0; exponent /=2)//�����2^4,һ��Ļ�Ҫret=2*2*2*2�����ĴΣ�
		//��num1=2*2��ret=num*num,ֻ������Σ����Ч��
	{
		if (exponent % 2)
			ret *= base;
		base *= base;
	}
	return ret;
}
double Power(double base, int exponse)
{
	double ret = 0;
	if (exponse == 0)
		return 1;
	if (base - 1 > -0.000001&&base - 1 < 0.000001)
		return 1;
	if (base > -0.000001&&base < 0.000001)
		return 0;
	if (exponse > 0)
		return PowerPositiveExponent(base, exponse);
	if (exponse < 0)
	{
		ret = PowerPositiveExponent(base, -exponse);
		ret = 1.0 / ret;
		return ret;
	}
}
//�Ż���
//��nΪż����a^n=(a^(n/2))*(a^(n/2))
//��nΪ������a^n=(a^((n-1)/2))*(a^((n-1)/2))*a
double Power(double base, int exponse)
{
	if (exponse == 0)
		return 1;
	if (base - 1 > -0.000001&&base - 1 < 0.000001)
		return 1;
	if (base > -0.000001&&base < 0.000001)
		return 0;
	if (exponse == 1)
		return base;
	double ret = Power(base, exponse >> 1);
	ret *= ret;
	if (exponse & 0x1 == 1)
		ret *= base;
	return ret;
}
void Test1()
{
	cout << Power(2, 3) << endl;
	cout << Power(0, 3) << endl;
	cout << Power(2, 0) << endl;
	cout << Power(1, 100) << endl;
	cout << Power(2, -1) << endl;
	cout << Power(2, 4) << endl;
}

