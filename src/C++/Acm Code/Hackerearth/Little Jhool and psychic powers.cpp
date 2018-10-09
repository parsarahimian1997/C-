#include <iostream>
#include <string>

using namespace std;

int main()
{
	int flag0 = 0, flag1 = 0, b;
	string s;
	cin >> s;
	b = s.size();
	int c[100 + 25];
	for (int i = 0; i < b; i++)
		c[i] = s[i] - '0';
	c[b] = '\0';
	for (int i = 0; i < b; i++)
	{
		for (int j = i; j < i + 6; j++)
		{
			if (c[j] == 1)
				flag0++;
			else if (c[j] == 0)
				flag1++;
		}
		if (flag0 == 6 || flag1 == 6)
		break;
		flag0 = 0;
		flag1 = 0;
	}
	if (flag0 == 6 || flag1 == 6)
		cout << "Sorry, sorry!" << endl;
	else
		cout << "Good luck!" << endl;
	return 0;
}