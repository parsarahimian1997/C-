#include <iostream>
#include <string>
using namespace std;
#define parsa(i,n) for (int i = 0; i < n; i++)

bool tik_tak_teo(string s)
{
	if (s == "xx." || s == "x.x" || s == ".xx")
		return 1;
	return 0;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		bool d = 0;
		char a[4][4];
		string s[4], s2;
		parsa(i, 4)
			cin >> s[i];
		parsa(i, 4)
			parsa(j, 4)
			a[i][j] = s[i][j];
		parsa(i, 4)
			if (tik_tak_teo(s[i].substr(0, 3)) || tik_tak_teo(s[i].substr(1, 3)))
			{
				d = 1;
				break;
			}
		parsa(j, 4)
		{
			parsa(i, 4)
				s2 += a[i][j];
			if (tik_tak_teo(s2.substr(0, 3)) || tik_tak_teo(s2.substr(1, 3)))
			{
				d = 1;
				break;
			}
			s2.clear();
		}
		s2.clear();
		parsa(i, 4)
			s2 += a[i][i];
		if (tik_tak_teo(s2.substr(0, 3)) || tik_tak_teo(s2.substr(1, 3)))
			d = 1;
		s2.clear();
		parsa(i, 4)
			s2 += a[i][3 - i];
		if (tik_tak_teo(s2.substr(0, 3)) || tik_tak_teo(s2.substr(1, 3)))
			d = 1;
		s2 = string(1, a[1][0]) + a[2][1] + a[3][2];
		if (tik_tak_teo(s2))
			d = 1;
		s2 = string(1, a[0][1]) + a[1][2] + a[2][3];
		if (tik_tak_teo(s2))
			d = 1;
		s2 = string(1, a[0][2]) + a[1][1] + a[2][0];
		if (tik_tak_teo(s2))
			d = 1;
		s2 = string(1, a[1][3]) + a[2][2] + a[3][1];
		if (tik_tak_teo(s2))
			d = 1;
		if (d == 1)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}