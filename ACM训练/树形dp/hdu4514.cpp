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
using pii=pair<int,string>; 

/*head------[@cordercorder]*/

const int maxn=(int)1e5+5;

struct node{
    int to;
    int w;
};

vector<node> e[maxn];
int n,m;
int pre[maxn];
bool isv[maxn];
int maxe;
int id;

int Find(int x){
    return pre[x]==-1?x:pre[x]=Find(pre[x]);
}

void dfs1(int u,int sum){
    if(sum>maxe){
        maxe=sum;
        id=u;
    }
    isv[u]=true;
    int v;
    for(int i=0;i<(int)e[u].size();i++){
        v=e[u][i].to;
        if(!isv[v]){
            dfs1(v,sum+e[u][i].w);
        }
    }
}

void solve(){
    int ans=0;
    for(int i=1;i<=n;i++){
        if(!isv[i]){
            maxe=0;
            dfs1(i,0);
            for(int j=1;j<=n;j++){
                isv[j]=false;
            }
            maxe=0;
            dfs1(id,0);
            ans=max(maxe,ans);
        }
    }
    cout<<ans<<'\n';
}

int main(void){
    FC;
    int u,v,w;
    int nu,nv;
    bool f;
    while(cin>>n>>m){
        for(int i=1;i<=n;i++){
            pre[i]=-1;
            isv[i]=false;
        }
        f=false;
        for(int i=0;i<m;i++){
            cin>>u>>v>>w;
            if(f)
                continue;
            e[u].push_back({v,w});
            e[v].push_back({u,w});
            nu=Find(u);
            nv=Find(v);
            if(nu==nv){
                f=true;
            }
            else{
                pre[nu]=nv;
            }
        }
        if(f){
            cout<<"YES"<<'\n';
        }
        else{
            solve();
        }
        for(int i=1;i<=n;i++){
            if(!e[i].empty()){
                e[i].clear();
            }
        }
    }
    return 0;
}
