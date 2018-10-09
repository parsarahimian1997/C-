#include <iostream>
using namespace std;

int main()
{
	int t, a[100 + 7];
	scanf_s("%d", &t);
	int i = 0;
	while (t--)
	{
		scanf_s("%d", a + i);
		i++;
	}
	while (i>0)
	{
		printf_s("%d\n", a[i - 1]);
		i--;
	}
	return 0;
}
