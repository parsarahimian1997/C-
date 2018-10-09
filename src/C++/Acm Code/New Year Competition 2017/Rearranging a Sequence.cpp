#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector <long> a;
	long n, m, j;
	while (scanf_s("%ld %ld", &n, &m))
	{
		for (long i = n; i >= 1; i--)
			a.push_back(i);
		for (long i = 1; i <= m; i++)
		{
			scanf_s("%ld", &j);
			a.erase(a.begin() + j);
			a.push_back(j);
		}
		for (long i = 0; i < n; i++)
		{
			if (a.back() != 0)
			{
				printf("%ld\n", a.back());
				a.pop_back();
			}
		}
	}
	return 0;
}