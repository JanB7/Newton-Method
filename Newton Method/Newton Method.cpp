#include "stdafx.h"
#include <cmath>
#include <math.h>
#include <iomanip>
#include <iostream>

#define F(x) (2700*log(250000/(250000-(3680*x)))) - (9.81*x) - 2000
#define FP(x) -(45126*x+9354375)/(4600*x-312500)

void newton(float x, float ε, float delta);

using namespace  std;

void main()
{
	const float eps = 1*pow(10,-6);
	const float delta = 0.01;
	
	
	newton(50, eps, delta);

	cout << endl << endl;

	newton(10, eps, delta);

	cin.ignore();
}


void newton(float x, const float ε, const float delta)
{
	const int nmax = 1000;

	float fx = F(x);
	float fp = FP(x);
	float d = fx / fp;

	cout << fixed << setprecision(6) << "0\tx = " << x << "\tf(x) = " << fx << endl << endl;
	cout << "Loop #\tx\t\tf(x)" << endl;

	for (int n = 0; n <= nmax; n++)
	{
		fp = FP(x);
		if(abs(fp) < delta)
		{
			cout << "small derivative";
			return;
		}
		d = fx / fp;
		x = x - d;
		fx = F(x);

		cout << n << "\t" << x << "\t" << fx << endl;

		if(abs(d) < ε)
		{
			cout << "Convergence at: " << x << endl;
			return;
		}		
	}
}