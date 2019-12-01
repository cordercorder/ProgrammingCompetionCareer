 
#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<string>
#include<vector>
#include<queue>
#include<list>
using namespace std;
#define ep 1e-9
#define oo 0x3f3f3f3f
typedef __int64 lld;
int dp[12][(1 << 10) + 1];
int nxt[1 << 11][1 << 11];
int cnt[1 << 11], val[11][1 << 11];
int cost[12], b[12][12], inte[12][12];
int n, m;
 
void GetStatus()
{
	for (int i = 0; i < (1 << 11); i++)
	for (int j = 0; j < (1 << 11);j++)
	if ((i&j) == j)
		nxt[i][cnt[i]++] = j;
}
 
int Dp()
{
	int ans = -oo, Status = 1 << n;
	memset(val, 0, sizeof val);
	for (int i = 0; i < m; i++)
	for (int st = 0; st <= Status; st++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!(st&(1 << j))) continue;
			for (int k = j - 1; k >= 0; k--)
			{
				if (!(st&(1 << k))) continue;
				val[i][st] += b[j][k];
			}
			val[i][st] += (inte[j][i] - cost[i]);
		}
	}
	for(int i=0;i<m;i++){
	    for(int j=0;j<(1<<n);j++){
	        printf("%d ",val[i][j]);
        }
        puts("");
    }
	
	memset(dp, -0x3f, sizeof dp);
	for (int i = 0; i <= Status; i++)
		dp[0][i] = val[0][i];
	for (int i = 1; i < m; i++)
	{
		for (int j = 0; j <= Status; j++)
		{
			for (int k = 0; k < cnt[j]; k++)
				dp[i][nxt[j][k]] = max(dp[i][nxt[j][k]], dp[i - 1][j] + val[i][nxt[j][k]]);
		}
	}
	for (int i = 0; i <= Status; i++)
		ans = max(ans, dp[m - 1][i]);
	return ans;
}
 
int main()
{
	GetStatus();
	while (scanf("%d %d", &n, &m) && (n || m))
	{
		for (int i = 0; i < m; i++)
			scanf("%d", &cost[i]);
		for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &inte[i][j]);
		for (int i = 0; i < n;i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &b[i][j]);
		int ans = Dp();
		if (ans <= 0)
			printf("STAY HOME\n");
		else
			printf("%d\n", ans);
	}
	return 0;
}
