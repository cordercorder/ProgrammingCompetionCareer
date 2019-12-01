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
#include<set>
#include<map>
#include<list>

#define deb(x) cout<<"#---"<<#x<<"=="<<x<<endl
#define FC ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define FIN freopen("in.txt","r",stdin)
#define FOUT freopen("A.txt","w",stdout)

using namespace std;

const long double PI=acos(-1.0);  
const long double eps=1e-6;
const long long maxw=1e17+10;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const int maxn=1e5+10;

struct node{
    int to;
    int w;
};

vector<node> e[maxn];
int res[maxn],cnt[maxn];
int n;
int ans,num;

void dfs(int u,int f){
    res[u]=0;
    cnt[u]=1;
    int v,tmp;
    for(int i=0;i<(int)e[u].size();i++){
        v=e[u][i].to;
        if(v==f)
            continue;
        dfs(v,u);
        tmp=e[u][i].w+res[v];
        if(tmp+res[u]>ans){
            num=cnt[v]*cnt[u];
            ans=tmp+res[u];
        }
        else if(tmp+res[u]==ans){
            num+=cnt[v]*cnt[u];
        }
        if(res[u]<tmp){
            res[u]=tmp;
            cnt[u]=cnt[v];
        }
        else if(res[u]==tmp){
            cnt[u]+=cnt[v];
        }
        #ifdef debug
        deb(tmp);
        deb(res[u]);
        deb(cnt[u]);
        deb(res[v]);
        deb(cnt[v]);
        deb(num);
        deb(ans);
        puts("");
        #endif
    }
}

void solve(){
    ans=0;
    num=0;
    dfs(1,0);
    cout<<ans<<" "<<num<<'\n';
}

int main(void){
    int u,v,w;
    FC;
    while(cin>>n){
        for(int i=1;i<n;i++){
            cin>>u>>v>>w;
            e[u].push_back({v,w});
            e[v].push_back({u,w});
        }
        solve();
        for(int i=1;i<=n;i++){
            e[i].clear();
        }
    }
	return 0;
}
