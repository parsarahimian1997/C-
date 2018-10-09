#include<iostream>
#include<string>

using namespace std;


int main()
{
	int flag = 0, t, count = 0;
	cin >> t;
	string s;
	for (int j = 0; j < t; j++)
	{
		cin >> s;
		long long a = s.size();
		char *b = new char[a + 25];
		for (int i = 0; i < a; i++)
			b[i] = s[i];
		b[a] = '\0';
		for (int i = 0; i < a; i++)
		{
			if (b[i] == 'B')
			{
				if (b[i - 1] == 'W' && b[i - 2] == 'W' && b[i + 1] == 'W' && b[i + 2] == 'W')
					flag += 4;
				if (flag > 0)
				{
					for (int k = i - 2; k < i + 3; k++)
						b[k] = 'z';
					count += flag;
					flag = 0;
				}
				else if (b[i - 1] == 'W' && b[i - 2] == 'W')
					flag += 2;
				if (flag > 0)
				{
					for (int k = i - 2; k < i + 1; k++)
						b[k] = 'z';
					count += flag;
					flag = 0;
				}
				else if (b[i + 1] == 'W' && b[i + 2] == 'W')
					flag += 2;
				if (flag > 0)
				{
					for (int k = i; k < i + 3; k++)
						b[k] = 'z';
					count += flag;
					flag = 0;
				}
				else if (b[i + 1] == 'W' && b[i - 1] == 'W')
					flag += 2;
				if (flag > 0)
				{
					for (int k = i - 1; k < i + 2; k++)
						b[k] = 'z';
					count += flag;
					flag = 0;
				}
				else if (b[i + 1] == 'W')
					flag++;
				if (flag > 0)
				{
					for (int k = i; k < i + 2; k++)
						b[k] = 'z';
					count += flag;
					flag = 0;
				}
				else if (b[i - 1] == 'W')
					flag++;
				if (flag > 0)
				{
					for (int k = i - 1; k < i + 1; k++)
						b[k] = 'z';
					count += flag;
					flag = 0;
				}
			}
		}
		cout << count << endl;
		flag = 0;
		count = 0;
	}
	return 0;
}