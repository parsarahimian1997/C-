#include <iostream>
#include <string>
using namespace std;

int main()
{
	bool flag;
	int t;
	string s, s1;
	scanf("%d", &t);
	while (t--)
	{
		flag = false;
		cin >> s >> s1;
		for (int i = 0; i < s.size(); i++)
		{
			for (int j = 0; j < s1.size(); j++)
				if (s[i] == s1[j])
				{
					printf("YES\n");
					flag = true;
					break;
				}
			if (flag)
				break;
		}
		if (!flag)
			printf("NO\n");
	}
	return 0;
}