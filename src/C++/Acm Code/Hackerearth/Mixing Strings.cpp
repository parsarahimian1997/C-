#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int n, i, j, k, si, b, d, count, sum = 1000000000 + 7;
	string s[10 + 7];
	scanf_s("%d", &n);
	vector<int>a;
	for (i = 0; i < n; i++)
	{
		a.push_back(i);
		cin >> s[i];
	}
	do 
	{                                              
		si = s[a[0]].size();
		for (i = 0; i < n - 1; i++) 
		{
			d = 1000000000 + 7;
			for ( j = 0; j < s[a[i]].size(); j++) 
			{
				count = 0;
				b = j;
				for (k = 0; k < s[a[i + 1]].size() && b < s[a[i]].size(); k++, b++) 
				{
					if (s[a[i]][b] == s[a[i + 1]][k]) 
						count++;                         
					else 
					{
						count = 0;                                                                    
						break;
					}
				}

				if (b != s[a[i]].size()) 
					count = 0;
				d = min(d, (int)s[a[i + 1]].size() - count);                  
			}
			si += d;                                                                     
		}
		sum = min(sum, si);                                                                 
	} while (next_permutation(a.begin(), a.end()));
	printf("%d\n", sum);
	system("pause");
	return 0;
}