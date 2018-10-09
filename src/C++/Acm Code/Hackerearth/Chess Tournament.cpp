#include <iostream>
#include <cmath>
#include <queue>

int d[1077][1077];
using namespace std;

int main()
{
	queue <int> a;
	int n;
	cin >> n;
	int k = pow(2, n);
	for (int i = 1; i < k; i++)
		for (int j = 1; j <= i; j++)
			cin >> d[i + 1][j];
	for (int i = 1; i <= k; i++)
		a.push(i);
	while (a.size() != 1)
	{
		int b = a.front();
		a.pop();
		int c = a.front();
		a.pop();
		if (d[c][b] == 1)
			a.push(c);
		else
			a.push(b);
	}
	cout << a.front() << endl;
	return 0;
}