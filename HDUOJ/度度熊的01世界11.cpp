#include <iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#define siz 105
using namespace std;
const int maxn = 100;
typedef long long LL;
int n,m;
char S[maxn+5][maxn+5];
int cnt,vis[maxn+5][maxn+5];// cnt ��ͨ��ĸ���
int yes[maxn*maxn+5],is[maxn*maxn+5],hv[maxn*maxn+5][5];// yes �Ƿ���ﵽ�߽磬 is��ʾ��ͨ����1����0�� hv����Щ���ڡ�
int f[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
void dfs(int x,int y)
{
    vis[x][y] = 1;
    for(int i=0; i<4; i++)
    {
        int nx = x+f[i][0] ,ny=y+f[i][1];
        if(nx<1||ny<1||nx>n||ny>m) continue;
        if(S[nx][ny]!=S[x][y])
        {
            hv[cnt][S[nx][ny]-'0'] = 1;// ��cnt����ͨ���� S[nx][ny]���ڡ�
            continue;
        }
        if(vis[nx][ny]) continue;
        if(nx==1||nx==n||ny==1||ny==m) yes[cnt] = 1;//��cnt����ͨ���Ƿ񵽵ױ߽硣
        dfs(nx,ny);
    }
}
int ok()
{
    int cot = 0,tot=0;
    cnt = 0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++) if(!vis[i][j])
            {
                cnt++;
                if(S[i][j]=='1') cot++;
                is[cnt] = S[i][j]-'0';
                if(i==1||i==n||j==1||j==m) yes[cnt] = 1;//ע�� ����ȥ��x,y��Ҫ �жϡ�
                dfs(i,j);
            }
    }
    if(cot!=1) return -1;//1��ͨ�첻��һ����Ϊ-1
    for(int i=1; i<=cnt; i++)
    {
        if(is[i]==0)
        {
            if(!yes[i]&&hv[i][1]) tot++;
        }
    }
    if(tot==1) return 0;// ��1��Χ��0����ͨ��Ϊһ����Ϊ 0
    if(tot==0) return 1;// �������κ�0�ַ���ɵ���ͨ�鱻1����ȫ��Χ
    return -1;
}
int main()
{
    while(~scanf("%d %d",&n,&m))
    {
        for(int i=1; i<=n; i++)
        {
            scanf("%s",S[i]+1);
        }
        for(int i=1; i<=n*m; i++) yes[i] = 0;
        memset(hv,0,sizeof(hv));
        memset(vis,0,sizeof(vis));
        int ty = ok();
        printf("%d\n",ty);
    }
    return 0;
}
