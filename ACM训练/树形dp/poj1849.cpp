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

const int maxn=(int)1e5+10;

int n,m;
struct node{
    int to;
    int w;
    node(){}
    node(int _to,int _w):to(_to),w(_w){}
};
vector<node> e[maxn];
bool isv[maxn];
int dp[maxn][2];
int ans,sum;

void dfs(int u){
    isv[u]=true;
    int v,maxe1=0,maxe2=0;
    for(int i=0;i<(int)e[u].size();i++){
        v=e[u][i].to;
        if(!isv[v]){
            dfs(v);
            if(dp[v][0]+e[u][i].w>maxe1){
                maxe2=maxe1;
                maxe1=dp[v][0]+e[u][i].w;
            }
            else if(dp[v][0]+e[u][i].w>maxe2){
                maxe2=dp[v][0]+e[u][i].w;
            }
        }
    }
    dp[u][0]=maxe1;
    dp[u][1]=maxe2;
    ans=max(ans,maxe1+maxe2);
}

void solve(){
    for(int i=1;i<=n;i++){
        isv[i]=false;
    }
    dfs(1);
    ans=sum*2-ans;
    cout<<ans<<'\n';
}

int main(void){
    FC;
    cin>>n>>m;
    int u,v,w;
    sum=0;
    for(int i=1;i<n;i++){
        cin>>u>>v>>w;
        sum+=w;
        e[u].push_back(node(v,w));
        e[v].push_back(node(u,w));
    }
    solve();
    return 0;
}
