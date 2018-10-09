#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	int a, b, t, n;
	bool j;
	while (scanf_s("%d %d", &a, &b) && (a != -1 && b != -1))
	{
		int count = 0, count1 = 0;
		vector <int> x(101, 0), y(101, 0), z(101, 0), k(101, 0);
		for (int i = 0; i < a; i++)
		{
			scanf_s("%d", &t);
			if (t % 2 != 0)
				z[t]++;
			else
				x[t] = 1;
		}
		for (int i = 0; i < b; i++)
		{
			scanf_s("%d", &n);
			if (n % 2 != 0)
				k[n]++;
			else
				y[n] = 1;
		}
		for (auto &e : z)
			if (e) count++;
		for (auto &e : k)
			if (e) count1++;
		if (count != count1)
			printf("N\n");
		else
		{
			j = true;
			for (int i = 0; i <= 100; i++)
				if (z[i] != k[i])
					j = false;
			if (!j)
				printf("N\n");
			else {
				for (int i = 0; i <= 100; i += 2)
					if (x[i])
					{
						if (y[i])
							continue;
						else if (k[(i - 2) / 2])
							continue;
						else
							j = false;
						break;
					}
				if (j == false)
					printf("N\n");
				else
				{
					for (int i = 0; i <= 100; i += 2)
						if (y[i])
						{
							if (x[i])
								continue;
							else if (z[(i - 2) / 2])
								continue;
							else
								j = false;
							break;
						}
					if (j)
						printf("Y\n");
					else
						printf("N\n");
				}
			}
		}
	}
	return 0;
}