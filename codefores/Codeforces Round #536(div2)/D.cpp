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

const int maxn=(int)1e5+10;

int n,m;
vector<int> e[maxn];
vector<int> ans;
bool isv[maxn];

void bfs(){
    priority_queue<int,vector<int>,greater<int> >q;
    q.push(1);
    int now,v;
    while(!q.empty()){
        now=q.top();
        q.pop();
        if(isv[now])
            continue;
        isv[now]=true;
        ans.push_back(now);
        for(int i=0;i<(int)e[now].size();i++){
            v=e[now][i];
            if(!isv[v]){
                q.push(v);
            }
        }
    }
}

void solve(){
    bfs();
    for(auto i:ans){
        cout<<i<<" ";
    }
}

int main(void){
    FC;
    cin>>n>>m;
    int u,v;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    solve();
    return 0;
}
