#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	long long *b = new long long[n];
	long long c = 1;
	int d = pow(10, 9) + 7;
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
		c = (c*b[i]) % d;
	}
	cout << c << endl;
	return 0;
}