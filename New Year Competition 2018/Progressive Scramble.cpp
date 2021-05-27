#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <bits/stdc++.h>
using namespace std;

string s;
char a[21 + 7];
map<char, int>m;

void compute()
{
	for (char k = 'a'; k <= 'z'; k++)
		m[k] = k - 'a' + 1;
	a[0] = ' ';
	for (int i = 1; i <= 26; i++)
		a[i] = 'a' + i - 1;
}

void encrypts()
{
	int d[100 + 7], j = s.size();
	d[0] = m[s[0]];
	for (int i = 1; i < j; i++)
		d[i] = m[s[i]] + d[i - 1];
	for (int i = 0; i < j; i++)
		printf("%c", a[d[i] % 27]);
	printf("\n");
}

void decrypts()
{
	int j = s.size(), d[100 + 7];
	d[0] = m[s[0]];
	for (int i = 1; i < j; i++)
	{
		d[i] = m[s[i]] - m[s[i - 1]];
		d[i] = (d[i] + 27) % 27;
	}
	for (int i = 0; i < j; i++)
		printf("%c", a[d[i]]);
	printf("\n");
}

int main()
{
	int t;
	char x;
	cin >> t;
	compute();
	while (t--)
	{
		cin >> x;
		cin.ignore();
		getline(cin, s);
		if (x == 'e')
			encrypts();
		else
			decrypts();
	}
	return 0;
}