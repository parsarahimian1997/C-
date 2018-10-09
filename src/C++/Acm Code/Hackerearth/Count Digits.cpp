#include <iostream>
#include <string>
using namespace std;

int main()
{
	int r, b[10] = { 0 };
	string s;
	getline(cin >> ws, s);
	int a = s.size();
	int *c = new int[a];
	for (int i = 0; i < a; i++)
	{
		c[i] = s[i] - '0';
		switch (c[i])
		{
		case 0: b[0]++; break;
		case 1: b[1]++; break;
		case 2: b[2]++; break;
		case 3: b[3]++; break;
		case 4: b[4]++; break;
		case 5: b[5]++; break;
		case 6: b[6]++; break;
		case 7: b[7]++; break;
		case 8: b[8]++; break;
		case 9: b[9]++; break;
		}
	}
	for (int i = 0;i < 10;i++)
		cout << i << " " << b[i] << endl;
	return 0;
}