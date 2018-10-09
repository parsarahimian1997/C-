#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>
using namespace std;
long b[10000000 + 7] = { 0 };

int main()
{
	string s;
	cin >> s;
	long count, j = 0, k, ma = 0;
	k = stoi(s);
	sort(s.begin(), s.end());
	do {
		b[j] *= 10;
		b[j++] += stoi(s);
	} while (next_permutation(s.begin(), s.end()));
	for (long i = 0; i < j; i++)
		if (b[i] == k)
		{
			cout << b[i + 1] << endl;
			return 0;
		}
	cout << 0 << endl;
	return 0;
}