#include <iostream>		
using namespace std;

int main()
{
	char a[7 + 7][7 + 7];
	for (int i = 2; i < 9; i++)
		for (int j = 2; j < 9; j++)
			cin >> a[i][j];
	int count = 0;
	for (int i = 2; i < 9; i++)
		for (int j = 2; j < 9; j++)
			if (a[i][j] == '.')
			{
				if (a[i - 2][j] == 'o' && a[i - 1][j] == 'o')
					count++;
				if (a[i + 2][j] == 'o' && a[i + 1][j] == 'o')
					count++;
				if (a[i][j - 2] == 'o' && a[i][j - 1] == 'o')
					count++;
				if (a[i][j + 2] == 'o' && a[i][j + 1] == 'o')
					count++;
			}
	printf("%d\n", count);
	return 0;
}