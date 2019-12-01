#include<bits/stdc++.h>

using namespace std;

#define FC ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define FIN freopen("in.txt","r",stdin)
#define FOUT freopen("out.txt","w",stdout)
#define deb(x) cerr<<"DEBUG------"<<'\n';cerr<<#x<<"------>";err(x)

template<typename T>
void err(T a){
    for(auto i:a){
        cerr<<i<<" ";
    }
    cerr<<'\n'<<"END OF DEBUG"<<'\n'<<'\n';
}
void err(int a){
    cerr<<a<<'\n';
    cerr<<"END OF DEBUG"<<'\n'<<'\n';
}

const long double PI=acos(-1.0);  
const long double eps=1e-6;
const long long maxw=(long long)1e17+(long long)10;

using ll=long long;
using ull=unsigned long long;
using pii=pair<int,string>; 

/*head------[@cordercorder]*/

const int maxn=(int)1e4+10;

struct node{
    int to;
    int w;
};

vector<node> e[maxn];
int n;
int dp[maxn][3];
int id[maxn];

void dfs(int u,int f){
    int v,w;
    for(int i=0;i<(int)e[u].size();i++){
        v=e[u][i].to;
        w=e[u][i].w;
        if(v!=f){
            dfs(v,u);
            if(dp[u][0]<dp[v][0]+w){
                id[u]=v;
                dp[u][1]=dp[u][0];
                dp[u][0]=dp[v][0]+w;
            }
            else if(dp[u][1]<dp[v][0]+w){
                dp[u][1]=dp[v][0]+w;
            }
        }
    }
}

void dfs2(int u,int f){
    int v,w;
    for(int i=0;i<(int)e[u].size();i++){
        v=e[u][i].to;
        w=e[u][i].w;
        if(v!=f){
            if(id[u]==v){
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
        cout<<max(dp[i][0],dp[i][2])<<'\n';
    }
}

int main(void){
    FC;
    int u,w;
    while(cin>>n){
        for(int i=2;i<=n;i++){
            cin>>u>>w;
            e[i].push_back({u,w});
            e[u].push_back({i,w});
        }
        solve();
        for(int i=1;i<=n;i++){
            for(int j=0;j<=2;j++){
                dp[i][j]=0;
            }
            e[i].clear();
            id[i]=0;
        }
    }
    return 0;
}
