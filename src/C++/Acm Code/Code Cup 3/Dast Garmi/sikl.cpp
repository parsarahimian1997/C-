#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int t, k = 0, n = 0, s = 0, m, ma, kc = 0, nc = 0, sc = 0;
	string a, shir, key, nez;
	cin >> t >> a;
	shir = "2123";
	key = "331122";
	nez = "123";
	for (int i = 0; i < t; i++)
	{
		if (kc == 6)
			kc = 0;
		if (nc == 3)
			nc = 0;
		if (sc == 4)
			sc = 0;
		if (a[i] == shir[sc++])
			s++;
		if (a[i] == key[kc++])
			k++;
		if (a[i] == nez[nc++])
			n++;
	}
	m = max(s, k);
	ma = max(m, n);
	cout << ma << endl;
	if (k == ma)
		cout << "keyvoon" << endl;
	if (n == ma)
		cout << "nezam" << endl;
	if (s == ma)
		cout << "shir farhad" << endl;
	return 0;
}