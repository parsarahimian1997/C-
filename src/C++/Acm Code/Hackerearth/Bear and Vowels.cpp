#include <iostream>
using namespace std;

int main()
{
	int t, f;
	bool flag;
	char c[300 + 7];
	long s, p;
	scanf("%ld", &t);
	while (t--)
	{
		flag = false;
		f = s = p = 0;
		scanf("%s", &c);
		for (int i = 0; c[i] != '\0'; i++)
		{
			if (c[i] == 'o' || c[i] == 'i' || c[i] == 'u' || c[i] == 'a' || c[i] == 'e' || c[i] == 'y')
			{
				s++;
				f = 0;
			}
			else
			{
				p++;
				f++;
				if (f == 3)
				{
					printf("hard\n");
					flag = true;
					break;
				}
			}
		}
		if (flag == false)
		{
			if (p>s)
				printf("hard\n");
			else
				printf("easy\n");
		}
	}
	return 0;
}