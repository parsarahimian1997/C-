#include <iostream>

using namespace std;

int main()
{

	int t, x = 0, y = 0, i;

	cin >> t;

	for (i = 1;i <= t;i++)
	{
		cin >> x >> y;

		if (x == y)
		{
			if (x % 2 == 1)

			{
				cout << (x * 2) - 1 << endl;

			}
			else
			{
				cout << x * 2 << endl;

			}
		}


		else if (x - y == 2)
		{
			if (x % 2 == 0)
			{
				cout << x * 2 - 2 << endl;
			}
			else
			{
				cout << x * 2 - 3 << endl;
			}
		}
		else
		{
			cout << "No Number" << endl;
		}



	}

	return 0;

}