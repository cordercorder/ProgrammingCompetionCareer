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

const ll maxn=(ll)1e5+10ll;

struct node{
    ll next;
    ll to;
    ll w;
    node(ll _to,ll _w):to(_to),w(_w){};
    node(){}
    bool operator<(const node &a)const{
        return w>a.w;
    }
}; 

ll n,m,q;
node e[maxn];
ll head[maxn];
ll tag[maxn];
ll cnt;

void Init_e(){
    cnt=0;
    memset(head,-1,sizeof(head)); 
}

void add(ll u,ll v,ll w){
    e[cnt].to=v;
    e[cnt].w=w;
    e[cnt].next=head[u];
    head[u]=cnt++;
}

priority_queue<node> Q;
ll D[maxn],d[maxn];
bool isv[maxn];
vector<ll> que[maxn];

void solve(){
    for(ll i=1;i<=n;i++){
        isv[i]=false;
        D[i]=maxw;
    }
    D[1]=0;
    Q.push(node(1,D[1]));
    node now;
    ll u,v,w;
    while(!Q.empty()){
        now=Q.top();
        Q.pop();
        u=now.to;
        if(isv[u])
            continue;
        isv[u]=true;
        for(ll i=head[u];i!=-1;i=e[i].next){
            v=e[i].to;
            w=e[i].w;
            if(D[u]+w<D[v]){
                D[v]=D[u]+w;
                Q.push(node(v,D[v]));
            }
        }
    }
    for(ll i=1;i<=n;i++){
        for(ll j=head[i];j!=-1;j=e[j].next){
            v=e[j].to;
            w=e[j].w; 
            e[j].w=D[i]-D[v]+w;
        }
    }
}

void handle(){
    for(ll i=0;i<=n;i++){
        d[i]=maxw;
        que[i].clear();
    }
    d[1]=0;
    que[0].push_back(1);
    ll now,u,v,w;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<(ll)que[i].size();j++){
            u=que[i][j];
            if(d[u]!=i)
                continue;
            for(ll k=head[u];k!=-1;k=e[k].next){
                v=e[k].to;
                w=e[k].w;
                if(d[v]>d[u]+w){
                    d[v]=d[u]+w;
                    if(d[v]<n){
                        que[d[v]].push_back(v);
                    }
                }
            }            
        }
    }
    for(ll i=1;i<=n;i++){
        if(d[i]<maxw){
            D[i]+=d[i];
        }
    }
    for(ll i=1;i<=n;i++){
        for(ll j=head[i];j!=-1;j=e[j].next){
            v=e[j].to;
            w=e[j].w;
            e[j].w=d[i]+w-d[v];
        }
    }
}

int main(void){
    FC;
    Init_e();
    ll u,v,w;
    cin>>n>>m>>q;
    for(ll i=1;i<=m;i++){
        cin>>u>>v>>w;
        add(u,v,w);
    }
    solve();
    ll c,l,tmp;
    while(q--){
        cin>>tmp;
        if(tmp==1){
            cin>>v;
            if(D[v]>=maxw){
                cout<<"-1"<<'\n';
            }
            else{
                cout<<D[v]<<'\n';
            }
        }
        else{
            cin>>c;
            for(ll i=0;i<c;i++){
                cin>>l;
                e[l-1].w++;
            }
            handle();
        }
    }
    return 0;
}
