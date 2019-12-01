#include<bits/stdc++.h>

using namespace std;

#define FC ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define FIN freopen("in.txt","r",stdin)
#define FOUT freopen("out.txt","w",stdout)
#define deb(x) cerr<<"DEBUG------"<<'\n';cerr<<#x<<"------>";err(x)

template<typename T>
void err(T a){
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

int n,m;
int deg[maxn];
vector<pii> e[maxn];
bool isv[maxn];
vector<int> ans;
pii E[maxn];

void solve(){
    int ret=1;
    for(int i=1;i<=n;i++){
        if(deg[ret]<deg[i]){
            ret=i;
        }
    }
    queue<int> q;
    q.push(ret);
    isv[ret]=true;
    int now,u;
    while(!q.empty()){
        now=q.front();
        q.pop();
        for(int i=0;i<(int)e[now].size();i++){
            u=e[now][i].first;
            if(!isv[u]){
                q.push(u);
                ans.push_back(e[now][i].second);
                isv[u]=true;
            }
        }
    }
    for(int i=0;i<(int)ans.size();i++){
        printf("%d %d\n",E[ans[i]].first,E[ans[i]].second);
    }
}

int main(void){
    int u,v;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d %d",&u,&v);
        e[u].push_back(pii(v,i));
        e[v].push_back(pii(u,i));
        E[i]=pii(u,v);
        deg[u]++;
        deg[v]++;
    }
    solve();
    return 0;
}
