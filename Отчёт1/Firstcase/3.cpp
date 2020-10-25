#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;

static const  double eps = 0.0001;

//условие Липшица  выполняется при любых альфа =10 
// if alpha=1 result=1 
//elif alpha=-1 no result 
//elif alpha=0.1 result=0.369 
//elif alpha=10 result=7.28

//альфа=10 выполняется за 25 итераций.
//при альфа=0.1 за 9 итераций.
//при альфа=1 за 4 итерации.

double phi(double x, double alpha =1)
{
	return sqrt(x * alpha - alpha * log(x));
}

int main()
{
	double x0 = 0.9 , x1 = phi(x0), d = 1;
	int k = 1;
	cout << "epsilon1 = " << eps << endl
		<< "x(0) = " << x0 << endl << "-------------------------------\n\n";

	while (d > eps)
	{
		x1 = phi(x0);
		d = fabs(x1 - x0);
		x0 = x1;
		cout << "x" << "(" << k << ") = " << x1 << setw(10) << "| " << "x" << "(" << k << ") - x(" << (k - 1) << ") | = " << d << endl << endl;
		k++;
	}
	return 0;
}
//TRUE IF ALPHA=10