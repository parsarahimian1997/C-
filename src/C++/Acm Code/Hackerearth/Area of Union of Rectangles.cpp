#include <iostream>
using namespace std;

int main()
{
	int t, area = 0, x1, x2, y1, y2;
	bool s[1000 + 7][1000 + 7] = { 1 };
	scanf_s("%d", &t);
	while (t--)
	{
		scanf_s("%d %d %d %d", &x1, &y1, &x2, &y2);
		for (int i = x1; i < x2; i++)
			for (int j = y1; j < y2; j++)
				s[i][j] = true;
	}
	for (int i = 0;i < 1000;i++)
		for (int j = 0;j < 1000;j++)
			if (s[i][j] == true)
				area++;
	printf_s("%d\n", area);
	return 0;
}