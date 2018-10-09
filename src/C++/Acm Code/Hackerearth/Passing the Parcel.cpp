#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
	queue <int> a;
	int n;
	string s;
	scanf_s("%d", &n);
	cin >> s;
	for (int i = 1; i <= n; i++)
		a.push(i);
	while (true)
		for (int i = 0; i < s.size(); i++)
		{
			int f = a.front();
			a.pop();
			if (s[i] == 'a')
				a.push(f);
			if (a.size() == 1)
			{
				printf("%d\n", a.front());
				return 0;
			}
		}
}