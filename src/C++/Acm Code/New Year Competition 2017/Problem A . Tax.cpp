rce.cpp | submission id : 489007

#include <iostream>
using namespace std;

int main()
{
	long long c;
	while (cin >> c)
	{
		if (c == 0)
			return 0;
		else if (c <= 1000000)
			cout << c;
		else if (c <= 5000000 && c > 1000000)
		{
			c = c*.9;
			cout << c;
		}
		else
		{
			c = c*.8;
			cout << c;
		}
		cout << endl;
	}
	return 0;
}