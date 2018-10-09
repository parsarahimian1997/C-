#include <iostream>
using namespace std;
int main()
{
	int n, min = 10000, max = 0;
	int flag = 0;
	cin >> n;
	int *a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] <= min)
			min = a[i];
		if (a[i] >= max)
			max = a[i];
	}
	for (int i = min; i <= max; i++)
	{
		for (int j = 0; j < n; j++)
			if (a[j] == i)
			{
				flag++;
				j = 0;
				i++;
			}
	}
	if (flag >= (max - min))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}