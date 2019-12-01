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

const int maxn=110;

int n,m;
vector<int> e[maxn];
int bugs[maxn],brain[maxn];
int dp[maxn][maxn];

void dfs(int u,int fa){
    int ret=(bugs[u])/20;
    if(bugs[u]%20!=0){
        ret++;
    }
    for(int i=ret;i<=m;i++){
        dp[u][i]=brain[u];
    }
    int v;
    for(int i=0;i<(int)e[u].size();i++){
        v=e[u][i];
        if(v!=fa){
            dfs(v,u);
            for(int j=m;j>=ret;j--){
                for(int k=1;j-k>=ret;k++){
                    dp[u][j]=max(dp[u][j],dp[u][j-k]+dp[v][k]);
                }
            }
        }
    }
}

void solve(){
    dfs(1,0);
    printf("%d\n",dp[1][m]);
}

int main(void){
    while(scanf("%d %d",&n,&m)!=EOF){
        if(n==-1&&m==-1)
            break;
        for(int i=1;i<=n;i++){
            scanf("%d %d",&bugs[i],&brain[i]);
        }
        int u,v;
        for(int i=1;i<n;i++){
            scanf("%d %d",&u,&v);
            e[u].push_back(v);
            e[v].push_back(u);
        }
        if(m==0){
            puts("0");
        }
        else{
            solve();
        }
        for(int i=1;i<=n;i++){
            e[i].clear();
        }
        memset(dp,0,sizeof(dp));
    }
    return 0;
}
