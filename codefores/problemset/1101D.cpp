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
using pii=pair<int,int>; 

/*head------[@cordercorder]*/

const int maxn=(int)2e5+10;

int n;
int a[maxn];
vector<int> e[maxn];
map<int,int> d[maxn];
int ans;
vector<int> res[maxn];

void pre_handle(){
    for(int i=2;i<=200000;i++){
        if(res[i].empty()){
            for(int j=i;j<=200000;j+=i){
                res[j].push_back(i);
            }
        }
    }
}

void dfs(int u,int f){
    int maxe;
    int maxe1=0,maxe2=0;
    for(auto i:res[a[u]]){
        d[u][i]=1;
        ans=max(ans,d[u][i]);
    }
    for(auto v:e[u]){
        if(v!=f){
            dfs(v,u);
            maxe=0;
            for(auto j:res[a[u]]){
                if(d[u].find(j)!=d[u].end()){
                    d[u][j]=max(d[u][j],d[v][j]+1);
                    ans=max(ans,d[u][j]);
                    maxe=max(maxe,d[v][j]+1);
                }
            }
            if(maxe>=maxe1){
                maxe2=maxe1;
                maxe1=maxe;
            }
            else if(maxe>maxe2){
                maxe2=maxe;
            }
            ans=max(ans,maxe1+maxe2-1);
        }
    }
}

void solve(){
    pre_handle();
    ans=0;
    dfs(1,0);
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
        e[u].push_back(v);
        e[v].push_back(u);
    }
    solve();
    return 0;
}
