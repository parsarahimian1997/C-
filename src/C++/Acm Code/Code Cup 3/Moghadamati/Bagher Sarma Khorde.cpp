#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
	string s[7], s1, s2;
	int j = 0;
	for (int k = 0; k < 5; k++)
		cin >> s[k];
	for (int k = 0; k < 5; k++)
	{
		for (int i = 0; i <= s[k].size(); i++)
		{
			s1 = s[k].substr(i, 6);
			s2 = s[k].substr(i, 5);
			if (s1 == "MOLANA" || s2 == "HAFEZ")
			{
				j++;
				cout << k + 1 << " ";
				break;
			}
		}
		if (k == 4 && j == 0)
			cout << "NOT FOUND!";
	}
	cout << endl;
	return 0;
}