// Лабораторна робота № 5.4
#include <iostream>
#include <cmath>
using namespace std;
double P0()
{
	double P = 1;
	for (int i = 1; i <= 15; i++)
		P *= (pow(sin(i), 2) + pow(cos(1. / i), 2)) / pow(i, 2);
	return P;
}
double P1(const int i)
{
	if (i > 15)
		return 1;
	else
		return (pow(sin(i), 2) + pow(cos(1. / i), 2)) / (pow(i, 2.)) * P1(i + 1);
}
double P2(const int i)
{
	if (i < 1)
		return 1;
	else
		return (pow(sin(i), 2) + (pow(cos(1. / i), 2))) / (pow(i, 2)) * P2(i - 1);
}
double P3(const int i, double t)
{
	t = t * (pow(sin(i), 2) + (pow(cos(1. / i), 2))) / (pow(i, 2));
	if (i >= 15)
		return t;
	else
		return P3(i + 1, t);
}
double P4(const int i, double t)
{
	t = t * (pow(sin(i), 2) + (pow(cos(1. / i), 2))) / (pow(i, 2));
	if (i <= 1)
		return t;
	else
		return P4(i - 1, t);
}
int main()
{
	cout << "(iteration)   S0 = "	<< P0()		<< endl;
	cout << "(rec up ++)   S1 = "	<< P1(1)	<< endl;
	cout << "(rec up --)   S2 = "	<< P2(15)	<< endl;
	cout << "(rec down ++) S3 = "	<< P3(1,1)	<< endl;
	cout << "(rec down --) S4 = "	<< P4(15,1)	<< endl;
	return 0;
}
