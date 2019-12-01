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

const int maxn=(int)2e5+10;

int n;
vector<int> e[maxn];
set<int> ret[maxn];
int sum[maxn];
bool isv[maxn];
int cnt[maxn];

void dfs1(int u,bool f){
    isv[u]=true;
    int v;
    for(int i=0;i<(int)e[u].size();i++){
        v=e[u][i];
        if(!isv[v]){
            if(ret[u].find(v)==ret[u].end()){
                dfs1(v,true);
            }
            else{
                dfs1(v,false);
            }
            sum[u]+=sum[v];
            cnt[u]+=cnt[v];
        }
    }
    if(f){
        sum[u]++;
    }
    cnt[u]++;
}

void dfs2(int u){
    isv[u]=true;
    int v;
    for(int i=0;i<(int)e[u].size();i++){
        v=e[u][i];
        if(!isv[v]){
            sum[v]=sum[u];
            if(ret[u].find(v)==ret[u].end()){
                sum[v]--;
            }
            else{
                sum[v]++;
            }
            dfs2(v);
        }
    }
}

void solve(){
    dfs1(1,false);
    memset(isv,false,sizeof(isv));
    dfs2(1);
    int mine=(int)1e9+10;
    for(int i=1;i<=n;i++){
        mine=min(mine,sum[i]);
//        deb(sum[i]);
    }
    cout<<mine<<'\n';
    for(int i=1;i<=n;i++){
        if(mine==sum[i]){
            cout<<i<<" ";
        }
    }
}

int main(void){
    FC;
    cin>>n;
    int u,v;
    for(int i=1;i<n;i++){
        cin>>u>>v;
        ret[u].insert(v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    solve();
    return 0;
}
