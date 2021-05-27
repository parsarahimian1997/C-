#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	long r, p = 0;
	int h;
	string s;
	scanf("%d", &h);
	r = pow(2, h + 1) - 1;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 'R')
			p = (2 * p) + 2;
		else
			p = (2 * p) + 1;
	}
	printf("%ld\n", r - p);
	return 0;
}