#include <iostream>
using namespace std;

int main()
{
	int t, n;
	char a[50 + 7][50 + 7];
	cin >> t;
	while (t--)
	{
		bool h = 1, v = 1;
		cin >> n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> a[i][j];
		for (int i = 0; i < n / 2; i++)
			for (int j = 0; j < n; j++)
				if (a[i][j] != a[n - i - 1][j])
				{
					h = 0;
					break;
				}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n / 2; j++)
				if (a[i][j] != a[i][n - j - 1])
				{
					v = 0;
					break;
				}
		if (v == h)
		{
			if (v == 1)
				cout << "BOTH" << endl;
			else
				cout << "NO" << endl;
		}
		else
		{
			if (v == 1 && h == 0)
				cout << "VERTICAL" << endl;
			else
				cout << "HORIZONTAL" << endl;
		}
	}
	return 0;
}