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

const int maxn=(int)2e5+10ll;

int n,m;
int degree[maxn];
bool isv[maxn];
bool f;
vector<int> e[maxn];
int sum;

void dfs(int u,int steps){
    isv[u]=true;
    if(steps>=3){
        f=false;
    }
    int v;
    for(int i=0;i<(int)e[u].size();i++){
        v=e[u][i];
        if(!isv[v]){
            dfs(v,steps+1);
        }
    }
}

void dfs2(int u,int steps){
    isv[u]=true;
    if(steps>=2){
        sum++;
    }
    int v;
    for(int i=0;i<(int)e[u].size();i++){
        v=e[u][i];
        if(!isv[v]){
            dfs2(v,steps+1);
        }
    }
}

void solve(){
    if(m>n-1){
        cout<<"No"<<'\n';
        return;
    }
    for(int i=1;i<=n;i++){
        if(degree[i]==0){
            cout<<"No"<<'\n';
            return;
        }
    }
    f=true;
    for(int i=1;i<=n;i++){
        if(!isv[i]){
            dfs(i,0);
            if(f==false){
                cout<<"No"<<'\n';
                return ;
            }
        }
    }
    memset(isv,false,sizeof(isv));
    for(int i=1;i<=n;i++){
        if(!isv[i]){
            sum=0;
            dfs2(i,0);
            if(sum>=1&&degree[i]>1){
                cout<<"No"<<'\n';
                return ;
            }
        }
    }
    cout<<"Yes"<<'\n';
}

int main(void){
    FC;
    cin>>n>>m;
    int u,v;
    for(int i=1;i<=m;i++){
        cin>>u>>v;
        degree[u]++;
        degree[v]++;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    solve();
    return 0;
}
