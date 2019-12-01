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

const ll maxn=(ll)3e5+10ll;

ll a[maxn],n,m;
ll T[maxn<<2],MAX[maxn<<2];
ll res[1000010];

void create(ll rt,ll l,ll r){
    if(l==r){
        T[rt]=a[l];
        MAX[rt]=a[l];
        return ;
    }
    ll mid=(l+r)>>1;
    create(rt<<1,l,mid);
    create(rt<<1|1,mid+1,r);
    T[rt]=T[rt<<1]+T[rt<<1|1];
    MAX[rt]=max(MAX[rt<<1],MAX[rt<<1|1]);
}

ll pre_handle(){
    for(ll i=1;i<=1000000;i++){
        for(ll j=i;j<=1000000;j+=i){
            res[j]++;
        }
    }
}

void update(ll rt,ll l,ll r,ll L,ll R){
    if(MAX[rt]<=2)
        return ;
    if(l==r){
        T[rt]=res[T[rt]];
        MAX[rt]=T[rt];
        return ;
    }
    ll mid=(l+r)>>1;
    if(R<=mid){
        update(rt<<1,l,mid,L,R);
    }
    else if(L>mid){
        update(rt<<1|1,mid+1,r,L,R);
    }
    else{
        update(rt<<1,l,mid,L,mid);
        update(rt<<1|1,mid+1,r,mid+1,R);
    }
    T[rt]=T[rt<<1]+T[rt<<1|1];
    MAX[rt]=max(MAX[rt<<1],MAX[rt<<1|1]);
}

ll cal(ll rt,ll l,ll r,ll L,ll R){
    if(L==l&&R==r){
        return T[rt];
    }
    ll mid=(l+r)>>1;
    if(R<=mid){
        return cal(rt<<1,l,mid,L,R);
    }
    else if(L>mid){
        return cal(rt<<1|1,mid+1,r,L,R);
    }
    else{
        return cal(rt<<1,l,mid,L,mid)+cal(rt<<1|1,mid+1,r,mid+1,R);
    }
}

int main(void){
    FC;
    pre_handle();
    cin>>n>>m;
    ll t,l,r;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    create(1,1,n);
    while(m--){
        cin>>t>>l>>r;
        if(t==1){
            update(1,1,n,l,r);
        }
        else{
            cout<<cal(1,1,n,l,r)<<'\n';
        }
    }
    return 0;
}
