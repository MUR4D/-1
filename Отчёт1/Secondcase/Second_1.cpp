#include<iostream>
#include<math.h>
#include<Windows.h>
#include<iomanip>
using namespace std;

static const double eps = 0.00001;

//при альфа=1 выполняется.корень=1
//при альфа=-1 выполняется.корень=0.486
//при альфа=10 выполняется.корень=12.064
//при альфа=10 выполняется.корень=0.579

//условие Липшица не выполняется
double phi(double& x, double alpha = -1)
{
	return (x * x - alpha * log(x)) / alpha;
}





int main()
{
	double x0 = 0.5, x1 = phi(x0), d = 1;
	int k = 1;

	cout << "epsilon = " << eps << endl
		<< "x(0) = " << x0 << endl << "-------------------------------\n\n";

	while (d > eps)
	{
		x1 = phi(x0);
		d = abs(x1 - x0);
		x0 = x1;
		cout << "x" << "(" << k << ") = " << x1 << setw(10) << "| " << "x" << "(" << k << ") - x(" << (k - 1) << ") | = " << d << endl << endl;
		k++;
	}

	cout << x1;




	return 0;
}