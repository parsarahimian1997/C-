#include <iostream>
using namespace std;

int main()
{
	int n, m=1;
	cin >> n;
	for (int i = 1; i < n + 1; i++)
		m *= i;
	cout << m << endl;
	return 0;
}