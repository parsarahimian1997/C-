#include <iostream>
using namespace std;
long a[100000 + 7];

long binarySearch(long low, long high, long key)
{
	while (low <= high)
	{
		long mid = (low + high) / 2;
		if (a[mid]<key)
			low = mid + 1;
		else if (a[mid]>key)
			high = mid - 1;
		else
			return mid;
	}
	return key;
}

int main()
{
	long n, q, x;
	scanf("%ld", &n);
	for (long i = 1; i <= n; i++)
		scanf("%ld", a + i);
	scanf("%ld", &q);
	while (q--)
	{
		scanf("%ld", &x);
		cout << binarySearch(1, n, x) << endl;
	}
	return 0;
}