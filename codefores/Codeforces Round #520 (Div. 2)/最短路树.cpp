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
const long long maxw=1e16+10;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pii;
/*head------[@cordercorder]*/

const ll maxn=3e5+10;

struct node{
    ll to;
    ll w;
    ll id;
    bool operator<(const node &a)const{
        return w>a.w;
    }
};

ll n,m,k;
vector<node> e[maxn];
priority_queue<node> q;
ll D[maxn];
bool isv[maxn];
ll f[maxn];
ll id;
vector<ll> ans;

void solve(){
    for(ll i=1;i<=n;i++){
        D[i]=maxw;
        isv[i]=false;
    }
    q.push({1,D[1],0});
    D[1]=0;
    node now;
    ll u,v,w;
    while(!q.empty()){
        now=q.top();
        q.pop();
        u=now.to;
        if(isv[u])
            continue;
        f[u]=now.id;
        isv[u]=true;
        for(ll i=0;i<(ll)e[u].size();i++){
            v=e[u][i].to;
            w=e[u][i].w;
            if(D[v]>D[u]+w){
                D[v]=D[u]+w;
                q.push({v,D[v],u});
            }
        }
    }
    for(ll i=1;i<=n;i++){
        isv[i]=false;
    }
    queue<ll> qq;
    qq.push(1);
    while(!qq.empty()){
        u=qq.front();
        qq.pop();
        for(ll i=0;i<(ll)e[u].size();i++){
            if(f[e[u][i].to]==u&&isv[e[u][i].to]==false){
                ans.push_back(e[u][i].id);
                qq.push(e[u][i].to);
                isv[e[u][i].to]=true;
            }
        }
    }
    cout<<min((ll)ans.size(),k)<<endl;
    for(ll i=0;i<(ll)ans.size()&&i<k;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int main(void){
    ll u,v,w;
    cin>>n>>m>>k;
    for(ll i=1;i<=m;i++){
        cin>>u>>v>>w;
        e[u].push_back({v,w,i});
        e[v].push_back({u,w,i});
    }
    solve();
	return 0;
}
