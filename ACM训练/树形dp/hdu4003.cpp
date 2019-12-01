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

const int maxn=(int)1e4+10;

int N,S,K;
vector<pii> e[maxn];
int dp[maxn][13];

void dfs(int u,int fa){
    for(int i=0;i<=K;i++){
        dp[u][i]=0;
    }
    int v;
    for(int i=0;i<(int)e[u].size();i++){
        v=e[u][i].first;
        if(v!=fa){
            dfs(v,u); 
            for(int j=K;j>=0;j--){
                dp[u][j]+=dp[v][0]+2*e[u][i].second;
                for(int k=1;k<=j;k++){
                    dp[u][j]=min(dp[u][j],dp[u][j-k]+dp[v][k]+k*e[u][i].second);
                }
            }
        }
    }
}

void solve(){
    dfs(S,0);
    printf("%d\n",dp[S][K]);
}

int main(void){
    int u,v,w;
    while(scanf("%d %d %d",&N,&S,&K)!=EOF){
        for(int i=1;i<N;i++){
            scanf("%d %d %d",&u,&v,&w);
            e[u].push_back(pii(v,w));
            e[v].push_back(pii(u,w));
        }
        solve();
        for(int i=1;i<=N;i++){
            if(!e[i].empty()){
                e[i].clear();
            }
        }
    }
    return 0;
}
