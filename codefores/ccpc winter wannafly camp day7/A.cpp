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
void err(long long a){
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

const int maxn=(ll)1e5+10ll;

int n;
int a[maxn];
vector<int> e[maxn];
int D[maxn];
bool isv[maxn];
int depth;
ll ans;

void dfs(int u,int depth){
    D[u]=depth;
    isv[u]=true;
    int v;
    for(int i=0;i<(int)e[u].size();i++){
        v=e[u][i];
        if(!isv[v]){
            dfs(v,depth+1ll); 
        }
    }
}

void solve(){
    ans=0ll;
    dfs(1,0);
    vector<ll> num;
    for(int i=1;i<=n;i++){
        if(a[i]==1){
            num.push_back(D[i]);
        }
    }
    ll min_e=(ll)1e6+10ll;
    for(auto &i:num){
        min_e=min(min_e,i);
    }
    ll SIZE=(ll)num.size();
    ans=(SIZE+min_e-1ll);
    cout<<ans<<'\n';
}

int main(void){
    FC;
    int u,v;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;i++){
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    solve();
    return 0;
}
