#include <iostream>
#include <string>
using namespace std;

int main()
{
	long long n, q;;
	int p, h = 0, a = 0, c = 0, k = 0, e = 0, r = 0, t = 0;
	cin >> n;
	char *m = new char[n];
	string s;
	cin >> s;
	q = s.length();
	for (int i = 0; i < q; i++)
	{
		m[i] = s[i];
		if (m[i] == 'h')
			h++;
		else if (m[i] == 'a')
			a++;
		else if (m[i] == 'c')
			c++;
		else if (m[i] == 'k')
			k++;
		else if (m[i] == 'e')
			e++;
		else if (m[i] == 'r')
			r++;
		else if (m[i] == 't')
			t++;
	}
	for (p = 0; 1 ; p++)
	{
		t -= 1;
		h -= 2;
		a -= 2;
		k -= 1;
		e -= 2;
		r -= 2;
		c -= 1;
		if (h < 0 || t < 0 || a < 0 || k < 0 || e < 0 || r < 0 || c < 0)
			break;
	}
	cout << p << endl;
	return 0;
}