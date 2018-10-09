#include <iostream>
using namespace std;

int main()
{
	int l, r, k, t, count = 0;
	cin >> l >> r >> k;
	if (l < r)
	{
		t = l;
		l = r;
		r = t;
	}
	for (int i = r; i < l+1; i++)
		if (i%k == 0)
			count++;
	cout << count << endl;
	return 0;
}
