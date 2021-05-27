#include <iostream>
using namespace std;
int main()
{
	int n, i, sa = 0, sb = 0, j = 0;
	int *a, *b;
	cin >> n;
	while (n != 0)
	{
		sa = 0, sb = 0;
		b = new int[n];a = new int[n];
		for (i = 0;i<n;i++)
			cin >> a[i];
		for (i = 0;i<n;i++)
			cin >> b[i];
		for (i = 0;i<n;i++)
		{
			if (a[i]>b[i])
			{
				if ((a[i] - b[i])>1)
					sa += a[i];
				else if ((a[i] - b[i]) == 1)
				{
					if (a[i] == 2 && b[i] == 1)
						sb += 6;
					else
						sb += a[i] + b[i];
				}
			}
			if (b[i]>a[i])
			{
				if ((b[i] - a[i])>1)
					sb += b[i];
				else if ((b[i] - a[i]) == 1)
				{
					if (b[i] == 2 && a[i] == 1)
						sa += 6;
					else
						sa += a[i] + b[i];
				}
			}
		}
		if (j>0) {
			cout << endl;
			cout << "A has " << sa << " points. B has " << sb << " points." << endl;
		}
		else
			cout << "A has " << sa << " points. B has " << sb << " points." << endl;
		j++;
		cin >> n;
	}
	return 0;

}