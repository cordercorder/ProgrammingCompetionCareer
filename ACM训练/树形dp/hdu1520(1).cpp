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

const int maxn=6010;
 
int a[maxn];
int n;
vector<int> e[maxn];
int in[maxn],root;
int dp[maxn][2];

void dfs(int u){
    int v;
    for(int i=0;i<(int)e[u].size();i++){
        v=e[u][i];
        dfs(v);
        dp[u][0]+=dp[v][1];
        dp[u][1]+=max(dp[v][0],dp[v][1]);
    }
    dp[u][0]+=a[u];
}

void solve(){
    for(int i=1;i<=n;i++){
        if(in[i]==0){
            root=i;
        }
    }
    dfs(root);
    printf("%d\n",max(dp[root][0],dp[root][1]));
}

int main(void){
    while(scanf("%d",&n)!=EOF){
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        int u,v;
        while(scanf("%d %d",&u,&v)){
            if(u==0&&v==0)
                break;
            e[v].push_back(u);
            in[u]++;
        }
        solve();
        for(int i=1;i<=n;i++){
            in[i]=0;
            e[i].clear();
            dp[i][0]=0;
            dp[i][1]=0;
        }
    }
    return 0;
}
