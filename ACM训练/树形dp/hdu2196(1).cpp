#include<bits/stdc++.h>

using namespace std;

#define FC ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define FIN freopen("in.txt","r",stdin)
#define FOUT freopen("out.txt","w",stdout)
#define deb(x) cerr<<"DEBUG------"<<'\n';cerr<<#x<<"------>";err(x)

template<typename T>
void err(T a){
    cerr<<a<<'\n';
    cerr<<"END OF DEBUG"<<'\n'<<'\n';
}

const long double PI=acos(-1.0);  
const long double eps=1e-6;
const long long maxw=(long long)1e17+(long long)10;

using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

/*head------[@cordercorder]*/

const int maxn=1e4+10;

vector<pii> e[maxn];
int n;
int dp[maxn][3];
int from[maxn];

void dfs(int u,int fa){
    int v,w;
    dp[u][0]=0;
    dp[u][1]=0;
    dp[u][2]=0;
    for(int i=0;i<(int)e[u].size();i++){
        v=e[u][i].first;
        w=e[u][i].second;
        if(v!=fa){
            dfs(v,u);
            if(dp[v][0]+w>=dp[u][0]){
                dp[u][1]=dp[u][0];
                dp[u][0]=dp[v][0]+w;
                from[u]=v;
            }
            else if(dp[v][0]+w>dp[u][1]){
                dp[u][1]=dp[v][0]+w;
            }
        }
    }
}

void dfs2(int u,int fa){
    int v,w;
    for(int i=0;i<(int)e[u].size();i++){
        v=e[u][i].first;
        w=e[u][i].second;
        if(v!=fa){
            if(from[u]==v){
                dp[v][2]=max(dp[u][2],dp[u][1])+w;
            }
            else{
                dp[v][2]=max(dp[u][2],dp[u][0])+w;
            }
            dfs2(v,u);
        }
    }
}

void solve(){
    dfs(1,0);
    dfs2(1,0);
    for(int i=1;i<=n;i++){
        printf("%d\n",max(dp[i][0],dp[i][2]));
    }
}

int main(void){
    int u,w;
    while(scanf("%d",&n)!=EOF){
        for(int i=2;i<=n;i++){
            scanf("%d %d",&u,&w);
            e[i].push_back(pii(u,w));
            e[u].push_back(pii(i,w));
        }
        solve();
        for(int i=1;i<=n;i++){
            e[i].clear();
            from[i]=0;
        }
    }
    return 0;
}
