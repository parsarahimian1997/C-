#include<iostream>
using namespace std;
int main()
{
	int n, i = 1;
	while (cin >> n && n != 0)
	{
		i = 1;
		while (n != 1)
		{
			if (n % 2 != 0)
				n = 3 * n + 1;
			else
				n /= 2;
			i++;
		}
		cout << i << endl;
	}
	return 0;
}

