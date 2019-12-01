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

const int maxn=(int)2e5+10;

vector<int> e[maxn];
int n;
ll dp[maxn],ans;
int sum[maxn];

void dfs1(int u,int fa){
    int v;
    sum[u]=1;
    for(int i=0;i<(int)e[u].size();i++){
        v=e[u][i];
        if(v!=fa){
            dfs1(v,u);
            sum[u]+=sum[v]; 
        }
    }
    dp[1]+=sum[u];
}

void dfs2(int u,int fa){
    int v;
    for(int i=0;i<(int)e[u].size();i++){
        v=e[u][i];
        if(v!=fa){
            dp[v]=max(dp[v],dp[u]-2*sum[v]+n);//dp[u]-sum[v]+n-sum[v]
            ans=max(ans,dp[v]);
            dfs2(v,u);
        }
    }
}

void solve(){
    dfs1(1,0);
    ans=dp[1];
    dfs2(1,0);
    printf("%lld\n",ans);
}

int main(void){
    int u,v;
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        scanf("%d %d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    solve();
    return 0;
}
