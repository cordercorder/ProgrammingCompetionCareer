#include<algorithm>
#include<iostream>
#include<limits.h>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<string>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<queue>
#include<stack>
#include<deque>
#include<ctime>
#include<list>
#include<set>
#include<map>

using namespace std;

#define FC ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define FIN freopen("in.txt","r",stdin)
#define FOUT freopen("out.txt","w",stdout)
#define deb(x) cerr<<"DEBUG------"<<'\n';cerr<<#x<<"------>";err(x)

void err(int a){
    cerr<<a<<'\n';
    cerr<<"END OF DEBUG"<<'\n'<<'\n';
}

const long double PI=acos(-1.0);  
const long double eps=1e-6;
const long long maxw=(long long)1e17+(long long)10;

/*head------[@cordercorder]*/

const int maxn=6010;

int n;
vector<int> e[maxn];
int root,in[maxn];
int a[maxn];
int dp[maxn][2];

void dfs(int u){
    int v;
    for(int i=0;i<(int)e[u].size();i++){
        v=e[u][i];
        dfs(v);
        dp[u][0]+=(dp[v][1]);
        dp[u][1]+=max(dp[v][0],dp[v][1]);
    }
    dp[u][0]+=a[u];
}

void solve(){
    for(int i=1;i<=n;i++){
        if(in[i]==0){
            root=i;
            break;
        }
    }
    dfs(root);
    int ans=max(dp[root][0],dp[root][1]);
    cout<<ans<<'\n';
}

int main(void){
    FC;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int u,v;
    for(int i=1;i<n;i++){
        cin>>u>>v;
        e[v].push_back(u);
        in[u]++;
    }
    solve();
    return 0;
}
