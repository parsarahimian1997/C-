#include <iostream>
using namespace std;

int main()
{


	int n, s, d, i, a, b;
	cin >> n;
	for (i = 1;i <= n;i++)
	{
		cin >> s >> d;
		a = (s + d) / 2;
		b = (s - d) / 2;
		if ((a * 2) != (s + d) || (b * 2) != (s - d) || s<d)
		{
			cout << "impossible" << endl;
		}
		else
		{
			cout << a << " " << b << endl;
		}
	}
	return 0;
}