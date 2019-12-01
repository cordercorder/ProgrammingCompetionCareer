#include<bits/stdc++.h>
//×¢ÊÍ 
//×¢ÊÍ 
//×¢ÊÍ 
//×¢ÊÍ 
//×¢ÊÍ 
//×¢ÊÍ 
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

const int maxn=(ll)1e5+10;

struct node{
    ll to;
    ll w;
    ll res;
    bool operator<(const node &a)const{
        return w>a.w;
    }
    node(){}
    node(ll _to,ll _w,ll _res):to(_to),w(_w),res(_res){}
};

ll D[maxn];
ll n,m,k; 
ll h[maxn];
vector<node> e[maxn];
bool isv[maxn];

void solve(){
    for(ll i=1;i<=n;i++){
        isv[i]=false;
        D[i]=maxw;
    }
    D[1]=0;
    priority_queue<node> q;
    q.push(node(1,D[1],k+h[1]));
    node now;
    ll u,v,w,res;
    while(!q.empty()){
        now=q.top();
//        deb(now.res);
//        deb(now.to);
//        deb(now.w);
        q.pop();
        u=now.to;
        if(isv[u])
            continue;
        isv[u]=true;
        for(ll i=0;i<(ll)e[u].size();i++){
            v=e[u][i].to;
            w=e[u][i].w;
            res=now.res;
            if(res<h[v]){
                w+=(h[v]-res)*(h[v]-res);
                if(D[v]>w+D[u]){
                    D[v]=w+D[u];
                    q.push(node(v,D[v],res));
                }
            }
            else{
                if(D[v]>w+D[u]){
                    D[v]=w+D[u];
                    q.push(node(v,D[v],res));
                }
            }
        }
    }
    cout<<D[n]<<'\n';
}

int main(void){
    FC;
    ll u,v,w;
    ll a,b,c,d; 
    cin>>n>>m>>k;
    for(ll i=1;i<=n;i++){
        cin>>h[i];
    }
    for(ll i=1;i<=m;i++){
        cin>>u>>v>>w;
        e[u].push_back(node(v,w,0ll));
        e[v].push_back(node(u,w,0ll));
    }
    solve();
    //×¢ÊÍ 
    return 0;
}
