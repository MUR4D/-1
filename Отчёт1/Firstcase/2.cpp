#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;

static const  double eps = 0.001;

//условие Липшица  выполняется при любых альфа =10 
// if alpha=1 result=1 
//elif alpha=-1 no result 
//elif alpha=0.1 result=0.369 
//elif alpha=10 result=7.28

//не сходится при альфа=0.1
//не сходится при альфа=1
//за 7 итераций при 10

double phi(double x,double alpha=10)
{
	return (-alpha*(log(x)/x))+alpha;
}

int main()
{
	double x0 = 7.9,x1=phi(x0),d=1;
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