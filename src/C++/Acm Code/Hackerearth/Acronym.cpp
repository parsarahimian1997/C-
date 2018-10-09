#include <iostream>
#include <string>
using namespace std;

int main()
{
	int i, j, t, n, m, k = 0;
	string c, cn;
	cn = cn + '$';
	cin >> n;
	while (n--)
	{
		cin >> c;
		cn = cn + c;
		cn = cn + '$';
	}
	cin >> m;
	while (m--)
	{
		t = 0;
		cin >> c;
		for (i = 0; cn[i] != '\0'; i++)
		{
			while (cn[i] != '$')
				i++;
			if (cn[i + 1] == '\0')
				break;
			j = 0;
			if (cn[i + 1] == c[0])
			{
				while (cn[i + 1 + j] == c[j])
					j++;
				if (cn[i + 1 + j] == '$' && c[j] == '\0')
				{
					t = 1;
					break;
				}
			}
		}
		if (t == 0)
		{
			k++;
			if (k != 1)
				cout << ".";
			c[0] = c[0] - 32;
			cout << c[0];
		}
	}
	return 0;
}