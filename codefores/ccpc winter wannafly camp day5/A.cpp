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

const int maxn=(int)1e3+10;

int n,m;
vector<int> e[maxn],ans[maxn];
bool isv[maxn];
pii ret[maxn];

void solve(){
    queue<pii> q;
    q.push(pii(1,0));
    int v,u,depth=0;
    pii now,tmp;
    while(!q.empty()){
        now=q.front();
        ans[now.second].push_back(now.first);
        depth=max(depth,now.second);
        q.pop();
        u=now.first;
        isv[u]=true;
        for(int i=0;i<(int)e[u].size();i++){
            v=e[u][i];
            if(!isv[v]){
                tmp=pii(v,now.second+1);
                isv[v]=true;
                q.push(tmp);
            }
        }
    }
    int x,y;
    for(int i=0;i<=depth;i++){
        x=i+1;
        y=1;
        for(int j=0;j<(int)ans[i].size();j++){
            ret[ans[i][j]]=pii(x,y++);
        }        
    }
    for(int i=1;i<=n;i++){
        cout<<ret[i].first<<" "<<ret[i].second<<'\n';
    }
}

int main(void){
    FC;
    cin>>n>>m;
    int u,v;
    for(int i=1;i<=m;i++){
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    solve();
    return 0;
}
