#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
typedef std::pair<int, int> node;

std::vector<int> dp[101];
std::vector<node> len[101];

struct object{
	int price, rate, rn;
	node r[101];
};
object obj[101];


int iabs(int a)
{
	return a > 0 ? a : -a;
}

bool isin(int a, int m, int i, int j)
{
	return iabs(len[i][j].first - a) <= m && iabs(len[i][j].second - a) <= m;
}

int main()
{
	int M, N;
	scanf("%d%d", &M, &N);
	for (int i = 1; i <= N; ++i)
	{
		scanf("%d%d%d", &(obj[i].price), &(obj[i].rate), &(obj[i].rn));
		for (int j = 1; j <= obj[i].rn; ++j)
		{
			scanf("%d%d", &(obj[i].r[j].first), &(obj[i].r[j].second));
		}
	}
	for (int i = 1; i <= N; ++i)
	{
		//dp[i][0].first = obj[i].price;
		//dp[i][0].second = obj[i].rate;
		//len[i][0].first = len[i][0].second = obj[i].rate;
		//for (int j = 0; j <= obj[i].rn; ++j)
		//{
		//	len[i][j].first = len[i][j].second = obj[i].rate;
		//}
		dp[i].push_back(obj[i].price);
		len[i].push_back(std::make_pair(obj[i].rate, obj[i].rate));
	}
	for (int i = 1; i <= obj[N].rn; ++i)
	{
		dp[N].push_back(obj[N].r[i].second);
		len[N].push_back(std::make_pair(obj[N].rate, obj[N].rate));
		/*dp[N][i + 1].first = obj[N].r[i].second;
		dp[N][i + 1].second = obj[N].rate;
		len[N][i + 1].first = len[N][i + 1].second = obj[i].rate;*/
	}
	for (int i = N - 1; i >= 1; i--)
	{
		for (int j = 1; j <= obj[i].rn; ++j)
		{

			int di = obj[i].r[j].first;
			for (int k = 0; k < dp[di].size(); ++k)
			{
				//int fi = iabs(obj[i].rate - dp[di][k].second);
				if (isin(obj[i].rate,M,di,k)&&isin(obj[1].rate,M,di,k))
				{

					//min = obj[i].r[j].second + dp[di][k].first;
					///*rate = std::min(obj[i].rate, dp[di][k].second);*/
					//len[i][j + 1] = len[di][k];
					dp[i].push_back(dp[di][k] + obj[i].r[j].second);
					int a = len[di][k].first, b=len[di][k].second;
					if (obj[i].rate > len[di][k].second) b = obj[i].rate;
					if (obj[i].rate < len[di][k].first) a = obj[i].rate;
					len[i].push_back(std::make_pair(a, b));
				}

			}
		}
	}
	int m = 0x7fffffff;
	for (int i = 0; i < dp[1].size(); ++i)
	{
		if (dp[1][i] < m)
		{
			m = dp[1][i];
		}
	}
	printf("%d\n", m);
	return 0;
}
