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

const int maxn=210;

int n,m;
int b[maxn];
vector<int> e[maxn];
int index[maxn],cnt,dp[maxn][maxn];

void dfs(int u,int fa){
    int v,f=1;
    if(u!=0){
        for(int i=1;i<=m;i++){
            dp[u][i]=b[u];
        }
    }
    if(u==0)
        f=0;
    for(int i=0;i<(int)e[u].size();i++){
        v=e[u][i];
        if(v!=fa){
            dfs(v,u);
            for(int j=m;j>=1;j--){
                for(int k=1;k+f<=j;k++){
                    dp[u][j]=max(dp[u][j],dp[u][j-k]+dp[v][k]);
                }
            }
        }
    }
}

void solve(){
    for(int i=1;i<=cnt;i++){
        e[0].push_back(index[i]);
    }
    dfs(0,-1);
    printf("%d\n",dp[0][m]);
    for(int i=0;i<=n;i++){
        e[i].clear();
    }
    memset(dp,0,sizeof(dp));
}

int main(void){
    int a;
    while(scanf("%d %d",&n,&m)!=EOF){
        if(n==0&&m==0)
            break;
        cnt=0;
        for(int i=1;i<=n;i++){
            scanf("%d %d",&a,&b[i]);
            if(a!=0){
                e[a].push_back(i);
            }
            else{
                index[++cnt]=i;
            }
        }
        solve();
    }
    return 0;
}
