#include <iostream>
using namespace std;
int main()
{
	int n, x, y, s = 0, d = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> x >> y;
		s = ((x + y) / 2);
		d = ((x - y) / 2);
		if ((s * 2) != (x + y) || (d * 2) != (x - y) || x < y)
		{
			cout << "impossible" << endl;
		}
		else
		{
			cout << s << " " << d << endl;
		}
	}
	return 0;
}