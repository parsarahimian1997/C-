#include <iostream>
using namespace std;

int main()
{
	long long n;
	long *a;
	int k = 0, sum = 0, j, cs = 0;
	cin >> n;
	a = new long[n + 275];
	a[n] = '\0';
	for (j = 0; j < n; j++)
	{
		cin >> a[j];
		if (a[j] > 0)
			k = 7;
	}
	j = 0;
	if (k == 7)
		while (j < n)
		{
			sum += a[j];
			if (sum > cs)
				cs = sum;
			else if (sum < 0)
				sum = 0;
			j++;
		}
	cout << cs << endl;
	return 0;
}