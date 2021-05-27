#include<iostream>
using namespace std;
#include<string>
int pc(char m)
{
	if (m == 'R')
		return 6;
	else if (m == 'L')
		return 4;
	else if (m == 'D' || m == 'T')
		return 3;
	else if (m == 'M' || m == 'N')
		return 5;
	else if (m == 'B' || m == 'F' || m == 'P' || m == 'V')
		return 1;
	else if (m == 'C' || m == 'G' || m == 'J' || m == 'K' || m == 'Q' || m == 'S' || m == 'X' || m == 'Z')
		return 2;
	else
		return 0;
}
int main()
{
	int i, b[20];
	string a;
	while (cin >> a) {
		b[0] = 0;
		for (i = 0;a[i] != '\0';i++)
			b[i] = pc(a[i]);
		if (b[0] != 0)
			cout << b[0];
		for (i = 1;a[i] != '\0';i++)
			if (b[i] != b[i - 1])
				if (b[i] != 0)
					cout << b[i];
		cout << endl;
	}
	return 0;
}