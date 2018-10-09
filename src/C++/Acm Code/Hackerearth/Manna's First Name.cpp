#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s, s1, s2;
	int a, b, k;
	int t;
	scanf("%d", &t);
	while (t--)
	{
		a = b = 0;
		cin >> s;
		k = s.size();
		for (int i = 0; i < k - 3;)
		{
			s1 = s.substr(i, 7);
			s2 = s.substr(i, 4);
			if (s1 == "SUVOJIT")
			{
				b++;
				i += 7;
				continue;
			}
			else if (s2 == "SUVO")
			{
				i += 4;
				a++;
				continue;
			}
			i++;
		}
		printf("SUVO = %d, SUVOJIT = %d\n", a, b);
	}
	return 0;
}