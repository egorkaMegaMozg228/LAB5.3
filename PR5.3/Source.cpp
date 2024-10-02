#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
double h(const double x);
int main()
{
	double rp, rk, z;
	int n;
	cout << "rp = "; cin >> rp;
	cout << "rk = "; cin >> rk;
	cout << "n = "; cin >> n;
	cout << fixed;
	cout << "---------------------------" << endl;
	cout << "|" << setw(6) << "r" << setw(7) << "|"
		<< setw(7) << "z" << "     |" << endl;
	cout << "---------------------------" << endl;
	double dg = (rk - rp) / n;
	double g = rp;
	while (g <= rk)
	{
		z = h(g + 1) + pow(h(g * g + 1), 2) + 1;
		cout << "|" << setw(6) << setprecision(2) << g
			<< setw(7) << "| " << setw(7) << setprecision(2) << z
			<< "     |" << endl;
		g += dg;
	}
	cout << "---------------------------" << endl;
	return 0;
}
double h(const double x)
{
	if (abs(x) >= 1 || x == 0)
		return (cos(x)+1)/exp(x);
	else
	{
		double S = 0;
		double Q = 0;
		int n = 0;
		double a = 1;
		S = a;
		do
		{
			n++;
			double R = (1. * x) / (n + 1);
			a *= R;
			Q += a;
		} while (n < 6);
		S = 1. / sin(x) / sin(x) * Q;
		return S;
	}
}
