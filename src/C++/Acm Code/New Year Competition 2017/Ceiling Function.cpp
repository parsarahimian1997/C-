#include <AP97.h>

bool Mosavi(vector<int>& i, vector<int>& j)
{
	if (i.size() != j.size())
		return false;
	if (i.size() <= 1)
		return true;
	vector<int> i_left, i_right, j_left, j_right;
	for (int z = 1; z < i.size(); z++)
	{
		if (i[z] < i[0])
			i_left.push_back(i[z]);
		else
			i_right.push_back(i[z]);
		if (j[z] < j[0])
			j_left.push_back(j[z]);
		else
			j_right.push_back(j[z]);
	}
	return Mosavi(i_left, j_left) && Mosavi(i_right, j_right);
}

int main()
{
	int n, k, j;
	scanf("%d %d", &n, &k);
	vector<vector<int>> a(n, vector<int>(k));
	int count = 0;
	for (int i = 0; i < n; i++)
		for (j = 0; j < k; j++)
			scanf("%d", &(a[i][j]));
	for (int i = 0; i < n; i++)
	{
		for (j = 0; j < i; j++)
			if (Mosavi(a[i], a[j]))
				break;
		if (j == i)
			count++;
	}
	printf("%d\n", count);
}