/*
POJ 3270  Cow Sorting
置换
每个循环进行判断  一个循环的花费有两种情况可能为最优
用循环内最小的花费牛 和其他牛 进行交换
或是用全局最小花费牛 先和本环内最小花费牛交换 然后一样
最后再交换回来就可以了
*/

#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
using namespace std;
const int MAXN=10010;
bool vis[MAXN];
struct Node
{
    int id;
    int num;
}node[MAXN];
bool cmp(Node a,Node b)
{
    return a.num < b.num;
}
int MIN;
int solve(int n)
{
    memset(vis,false,sizeof(vis));
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            vis[i]=true;
            int cnt=1;
            int sum=node[i].num;
            int m=node[i].num;
            int l=node[i].id;
            while(l!=i)
            {
                vis[l]=true;
                cnt++;
                sum+=node[l].num;
                if(m>node[l].num)m=node[l].num;
                l=node[l].id;
            }
            ans=ans+min(sum-m+m*(cnt-1),sum+m+(cnt+1)*MIN);
        }
    }
    return ans;
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        MIN=10000000;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&node[i].num);
            node[i].id=i;
            if(MIN>node[i].num)MIN=node[i].num;
        }
        sort(node+1,node+n+1,cmp);
        printf("%d\n",solve(n));
    }
    return 0;
}
