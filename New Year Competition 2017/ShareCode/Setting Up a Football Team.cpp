#include <iostream>
using namespace std;

int main()
{
	int a, w, s;
	while (cin >> a >> w >> s)
	{
		if (a == 0 && w == 0 && s == 0)
		{
			return 0;
		}
		else
		{
			if (a > 36 || w < 60 || s < 200)
			{
				cout << "No Position" << endl;
			}
			else if (a < 26)
			{
				if (w > 80)
				{
					if (s > 500)
					{
						cout << "Mid-feild" << " " << "Forward " << "Defense" << endl;
					}
					else if (s > 300)
					{
						cout << "Forward" << " " << "Defense" << " " << endl;
					}
					else if (s > 200)
					{
						cout << "Forward" << endl;
					}
				}
				else if (w > 70)
				{
					if (s > 500)
					{
						cout << "Mid-feild" << " " << "Forward" << endl;
					}
					else if (s > 200)
					{
						cout << "Forward" << endl;
					}
				}
				else if (w > 60)
				{
					cout << "Forward" << endl;
				}
			}
			else if (a < 30)
			{
				if (w > 80)
				{
					if (s > 500)
					{
						cout << "Mid-field" << " " << "Defense" << endl;
					}
					if (s > 300)
					{
						cout << "Defense" << endl;
					}
					else if (w > 70 && s > 500)
					{
						cout << "Mid-feild" << endl;
					}
				}
			}
			else if (a < 36 && w > 80 && s > 300)
			{
				cout << "Defense" << endl;
			}
		}
	}
		return 0;
	}