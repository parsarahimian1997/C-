#include<iostream>
using namespace std;
int main()
{
	int i, n, a, b;
	cin >> n;
	for (int i = 0;i<n;i++)
	{
		cin >> a >> b;
		if (a >= b)
		{
			if (a % 2 == 0 && b % 2 == 0)
				cout << a + b << endl;
			else if (a % 2 != 0 && b % 2 != 0)
				cout << a + b - 1 << endl;
			else if (a % 2 != b % 2)
				cout << "No Number" << endl;
		}
		else
			cout << "No Number" << endl;
	}
	return 0;
}
