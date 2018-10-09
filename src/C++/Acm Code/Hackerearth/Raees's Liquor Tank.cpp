#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int n, a[1000 + 7], chap[1000 + 7], rast[1000 + 7], j = 1;
	long k = 0;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
		scanf_s("%d", a + i);
	a[n]=NULL;
	chap[0] = a[0];
	for (int i = 1; i < n; i++)
		chap[i] = max(chap[i - 1], a[i]);
	rast[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; i--)
		rast[i] = max(rast[i + 1], a[i]);
	for (int i = 0; i < n; i++)
		k += min(chap[i], rast[i]) - a[i];
	printf_s("%d\n", k);
	return 0;
}