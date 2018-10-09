#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	long long n;
	scanf_s("%lld", &n);
	vector <long long>a(n);
	while (n--)
		scanf_s("%lld", &a[n]);
	sort(a.begin(), a.end());
	printf("%lld\n", a[0] + a[a.size() - 1]);
	system("pause");
	return 0;
}