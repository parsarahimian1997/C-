#include <iostream>
#include <string>
using namespace std;

int main()
{
	long r = 0, a[26 + 7] = { 0 };
	string s;
	int n;
	scanf("%d", &n);
	cin >> s;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
			if (s[i] == s[j])
				for (int k = i + 1; k<j; k++)
					r += a[s[k] - 'a'];
		a[s[i] - 'a']++;
	}
	printf("%ld\n", r);
	return 0;
}