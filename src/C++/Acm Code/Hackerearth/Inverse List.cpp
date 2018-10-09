#include <iostream>
using namespace std;

int main()
{
	int p[100000 + 10];
	int a[100000 + 10];
	ios::sync_with_stdio(false);
	int n, t;
	scanf("%d", &t);
	while (t--) 
	{
		bool flag = true;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", p + i);
			a[p[i]] = i;              
		}
		for (int i = 1; i <= n; i++)
		{
			if (p[i] == a[i])
				continue;
			flag = false;
		}
		if (flag) 
			printf("inverse\n");
		else
			printf("not inverse\n");
	}
	return 0;
}