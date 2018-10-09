#include <iostream>
using namespace std;

int main()
{
	bool flag = false;
	int a[4], b[4] = { 0 }, m;
	for (int i = 0; i < 4; i++)
		cin >> a[i];
	for (int j = 0; ; j++)
	{
		if (j == 4)
			j = 0;
		for (int i = 0; i < 4; i++)
			if (a[i] == 0)
			{
				flag = true;
				break;
			}
		if (flag)
			break;
		a[j]--;
		b[j]++;
		m=a[0];
		for (int k = 0; k < 4; k++)
			a[k] = a[k + 1];
		a[3] = m;
	}
	for (int i = 0; i < 4; i++)
		cout << b[i] << " ";
	cout << endl;
	return 0;
}