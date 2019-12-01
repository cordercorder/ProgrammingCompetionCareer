#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 5;

int num[MAXN], awake[MAXN];
int extra, n, k, tot, count, maxextra;

int main()
{
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; ++i) scanf("%d", num + i);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", awake + i);
		if(awake[i])
		{
			tot += num[i];
		}
	}

	for(int i = 1; i <= k; ++i)
	{
		if(!awake[i]) extra += num[i];
	}
	maxextra = extra;
	for(int i = 1, j = k + 1; j <= n; ++i, ++j)
	{
		if(!awake[j])
		{
			extra += num[j];
		}
		if(!awake[i])
		{
			extra -= num[i];
		}
		maxextra = max(extra, maxextra);
	}
	cout << maxextra + tot;
}
