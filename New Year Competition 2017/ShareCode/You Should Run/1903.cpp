#include<iostream>
using namespace std;
int main()
{
	int n, i;
	while (cin >> n && n != -1)
	{
		int *s = new int[n], *t = new int[n], sum = 0;
		for (i = 0;i<n;i++)
			cin >> s[i] >> t[i];
		sum += s[0] * t[0];
		for (i = 1;i<n;i++)
			sum += s[i] * (t[i] - t[i - 1]);
		cout << sum << " miles" << endl;
	}
	return 0;
}