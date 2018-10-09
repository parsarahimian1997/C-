#include <iostream>
#include <string>
using namespace std;

int main()
{
	int k;
	string s;
	int t, n;
	cin >> t;
	while (t--)
	{
		k = 0;
		cin >> n;
		char *a = new char[n];
		cin >> s;
		for (int i = 0; i < n; i++)
			a[i] = s[i];
		for (int i = 0; i < n; i++)
		{
			if (a[i] >= 48 && a[i] <= 57)
			{
				while (a[i] >= 48 && a[i] <= 57)
					i++;
				k++;
			}
		}
		cout << k << endl;
	}
	return 0;
}