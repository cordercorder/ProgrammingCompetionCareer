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
using pii=pair<ll,ll>;

/*head------[@cordercorder]*/

const ll maxn=(ll)1e5+10ll;

struct node{
    ll l;
    ll r;
};

ll n,m;
ll a[maxn];
node seg[maxn];
ll T[2][maxn<<2],tag[maxn<<2];
vector<ll> add[maxn*10ll],sub[maxn*10ll];

void pushup(ll rt){
    T[0][rt]=max(T[0][rt<<1],T[0][rt<<1|1]);
    T[1][rt]=min(T[1][rt<<1],T[1][rt<<1|1]);
}

void create(ll rt,ll l,ll r){
    if(l==r){
        T[0][rt]=a[l];
        T[1][rt]=a[l];
        return ;
    }
    ll mid=(l+r)>>1;
    create(rt<<1,l,mid);
    create(rt<<1|1,mid+1,r);
    pushup(rt);
}

void pushdown(ll rt){
    if(tag[rt]){
        T[0][rt<<1]+=tag[rt];
        T[0][rt<<1|1]+=tag[rt];
        T[1][rt<<1]+=tag[rt];
        T[1][rt<<1|1]+=tag[rt];
        tag[rt<<1]+=tag[rt];
        tag[rt<<1|1]+=tag[rt];
        tag[rt]=0ll;
    }
}

void update(ll rt,ll l,ll r,ll L,ll R,ll val){
    if(l==L&&R==r){
        T[0][rt]+=val;
        T[1][rt]+=val;
        tag[rt]+=val;
        return ;
    }
    pushdown(rt);
    ll mid=(l+r)>>1;
    if(R<=mid){
        update(rt<<1,l,mid,L,R,val);
    }
    else if(L>mid){
        update(rt<<1|1,mid+1,r,L,R,val);
    }
    else{
        update(rt<<1,l,mid,L,mid,val);
        update(rt<<1|1,mid+1,r,mid+1,R,val);
    }
    pushup(rt);
}

ll cal(ll rt,ll l,ll r,ll L,ll R,bool f){
    if(l==L&&r==R){
        if(f)
            return T[0][rt];
        return T[1][rt];
    }
    pushdown(rt);
    ll mid=(l+r)>>1;
    if(R<=mid){
        return cal(rt<<1,l,mid,L,R,f);
    }
    else if(L>mid){
        return cal(rt<<1|1,mid+1,r,L,R,f);
    }
    else{
        if(f)
            return max(cal(rt<<1,l,mid,L,mid,f),cal(rt<<1|1,mid+1,r,mid+1,R,f));
        return min(cal(rt<<1,l,mid,L,mid,f),cal(rt<<1|1,mid+1,r,mid+1,R,f));
    }
}

void solve(){
    create(1,1,n);
    ll ans=-1,pos,tmp;
    for(ll i=1;i<=n;i++){
        for(auto &j:add[i-1]){
            update(1,1,n,seg[j].l,seg[j].r,1);
        }
        for(auto &j:sub[i]){
            update(1,1,n,seg[j].l,seg[j].r,-1);
        }
        tmp=cal(1,1,n,1,n,true)-cal(1,1,n,1,n,false);
        if(tmp>ans){
            ans=tmp;
            pos=i;
        }
    }
    vector<ll> index;
    for(ll i=1;i<=m;i++){
        if(seg[i].l<=pos&&seg[i].r>=pos){
            index.push_back(i);
        } 
    }
    cout<<ans<<'\n';
    cout<<(ll)index.size()<<'\n';
    for(auto &j:index){
        cout<<j<<" ";
    }
}

int main(void){
    FC;
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    for(ll i=1;i<=m;i++){
        cin>>seg[i].l>>seg[i].r;
        add[seg[i].r].push_back(i);
        sub[seg[i].l].push_back(i);
    }
    solve();
    return 0;
}
