#include <AP97.h>
using namespace std;

int main()
{
	int b[26];
	string s;
	int t;
	ll a = 0, d;
	scanf("%d", &t);
	cin >> s;
	int l = s.size();
	for (int i = 0; i < l; i++)
	{
		d = 0;
		for (int k = 97; k < 123; k++)
			b[k] = 0;
		for (int j = i; j < l; j++)
		{
			if (++b[s[j]] == 1)
				d++;
			if (d == t)
				a++;
		}
	}
	printf("%lld\n", a);
	return 0;
}