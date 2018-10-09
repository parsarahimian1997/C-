#include <iostream>
#include <stack>
using namespace std;

int main()
{
	long n, c, x;
	stack <long> s;
	scanf("%ld", &n);
	while (n--)
	{
		scanf("%ld", &x);
		if (x == 1)
		{
			if (!s.empty())
			{
				printf("%ld\n", s.top());
				s.pop();
			}
			else
				printf("No Food\n");
		}
		else
		{
			scanf("%ld", &c);
			s.push(c);
		}
	}
	return 0;
}