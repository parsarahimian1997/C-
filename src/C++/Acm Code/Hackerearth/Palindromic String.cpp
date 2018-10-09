#include <iostream>
#include <string>
using namespace std;

int main()
{
	string a;
	int p;
	cin >> a;
	p = a.size();
	for (int i = 0; i < (p / 2) + 1; i++)
		if (a[i] != a[p - i - 1])
		{
			cout << "NO" << endl;
			return 0;
		}
	cout << "YES" << endl;
	return 0;
}
