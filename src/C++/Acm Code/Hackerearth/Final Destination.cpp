#include <iostream>
#include <string>

using namespace std;

int main()
{
	long x = 0, y = 0;
	string s;
	cin >> s;
	int l = s.length();
	char *a = new char[l];
	a[l] = '\0';
	for (int i = 0; i < l; i++)
		a[i] = s[i];
	for (int i = 0; i < l; i++)
	{
		if (a[i] == 'U')
			y++;
		else if (a[i] == 'D')
			y--;
		else if (a[i] == 'L')
			x--;
		else if (a[i] == 'R')
			x++;
	}
	cout << x << " " << y << endl;
	return 0;
}