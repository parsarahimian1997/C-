#include<iostream>
#include<cmath>
using namespace std;
int a[1000000 + 7];
int b[1000000 + 7];

int main()
{
	bool flag = false, flag1 = false;
	int x, y, j, k, s = 0, t = 0;
	scanf("%d %d %d", &x, &y, &j);
	for (int i = 0; i < j; i++)
		scanf("%d", a + i);
	scanf("%d", &k);
	for (int i = 0; i < k; i++)
		scanf("%d", b + i);
	for (int i = 1; i < 4000007; i++)
	{
		if (flag)
			x++;
		if (flag1)
			y++;
		if (i == a[s])
		{
			flag = !flag;
			if (s < j)
				s++;
		}
		if (i == b[t])
		{
			flag1 = !flag1;
			if (t < k)
				t++;
		}
		if (abs(x - y) <= 4)
		{
			printf("bumper tap at time %d\n", i);
			return 0;
		}
	}
	printf("safe and sound\n");
	return 0;
}