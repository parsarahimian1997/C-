#include <iostream>
#include <string>
using namespace std;

int main()
{
	int t, n, k, sum;
	char b;
	cin >> t;
	while (t--)
	{
		cin >> n >> k;
		string s[10000];
		for (int i = 0; i < n; i++)
			cin >> s[i];
		for (int i = 0; i < k; i++)
		{
			long a = 1000000000;
			for (int j = 'a'; j <= 'z'; j++)
			{
				sum = 0;
				for (int z = 0; z < n; z++)
					sum += abs(s[z][i] - j);
				if (sum < a)
				{
					a = sum;
					b = j;
				}
			}
			cout << b;
		}
		cout << endl;
	}
	return 0;
}