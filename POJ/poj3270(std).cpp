/*
POJ 3270  Cow Sorting
�û�
ÿ��ѭ�������ж�  һ��ѭ���Ļ����������������Ϊ����
��ѭ������С�Ļ���ţ ������ţ ���н���
������ȫ����С����ţ �Ⱥͱ�������С����ţ���� Ȼ��һ��
����ٽ��������Ϳ�����
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
