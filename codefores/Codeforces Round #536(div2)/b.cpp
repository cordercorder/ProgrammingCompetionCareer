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
const long long maxw=(long long)1e8+(long long)10;

using ll=long long;
using ull=unsigned long long;
using pii=pair<ll,ll>; 

/*head------[@cordercorder]*/

const ll maxn=(ll)1e5+10ll;

ll n,m;
ll a[maxn],c[maxn];
ll t[maxn],d[maxn];
ll T[2][maxn<<2];
ll num;

void create(ll rt,ll l,ll r){
    if(l==r){
        T[0][rt]=a[l];
        T[1][rt]=c[l];
        return ;
    }
    ll mid=(l+r)>>1;
    create(rt<<1,l,mid);
    create(rt<<1|1,mid+1,r);
    T[0][rt]=min(T[0][rt<<1],T[0][rt<<1|1]);
    T[1][rt]=min(T[1][rt<<1],T[1][rt<<1|1]);
}

ll query(ll rt,ll l,ll r){
    if(l==r){
        num=T[0][rt];
        return l;
    }
    ll mid=(l+r)>>1;
    if(T[1][rt<<1]<=T[1][rt<<1|1]){
        return query(rt<<1,l,mid);
    }
    else{
        return query(rt<<1|1,mid+1,r);
    }
}

ll query(ll rt,ll l,ll r,ll pos){
    if(l==r){
        return T[0][rt];
    }
    ll mid=(l+r)>>1;
    if(pos<=mid){
        query(rt<<1,l,mid,pos);
    }
    else{
        query(rt<<1|1,mid+1,r,pos);
    }
}

void update(ll rt,ll l,ll r,ll pos,ll val){
    if(l==r){
        T[0][rt]-=val;
        if(T[0][rt]==0){
            T[1][rt]=maxw;
        }
        return ;
    }
    ll mid=(l+r)>>1;
    if(pos<=mid){
        update(rt<<1,l,mid,pos,val);
    }
    else{
        update(rt<<1|1,mid+1,r,pos,val);
    }
    T[0][rt]=min(T[0][rt<<1],T[0][rt<<1|1]);
    T[1][rt]=min(T[1][rt<<1],T[1][rt<<1|1]);
}

void print(ll rt,ll l,ll r){
    if(l==r){
        cout<<T[0][rt]<<"  ";
        return ;
    }
    ll mid=(l+r)>>1;
    print(rt<<1,l,mid);
    print(rt<<1|1,mid+1,r);
}

void solve(){
    ll ans,ret;
    create(1,1,n);
    bool f=false;;
    for(ll i=1;i<=m;i++){
        ans=0ll;
        if(!f){
            ret=query(1,1,n,t[i]);
//            deb(ret);
            if(ret>=d[i]){
                update(1,1,n,t[i],d[i]);
                ans+=c[t[i]]*d[i];
            }
            else{
                d[i]-=ret;
                ans+=ret*c[t[i]];
//                deb(c[t[i]]);
//                deb(ans);
                update(1,1,n,t[i],ret);
                while(d[i]>0){
                    ll index=query(1,1,n);
                    if(num==0){
                        f=true;
                        cout<<"0"<<'\n';
                        break;
                    }
                    if(d[i]>=num){
                        d[i]-=num;
                        update(1,1,n,index,num);
                        ans+=num*c[index];
                    }
                    else{
                        update(1,1,n,index,d[i]);
                        ans+=d[i]*c[index];
                        d[i]=0;
                    }
                }
            }
            if(!f){
                cout<<ans<<'\n';
            }
        }
        else{
            cout<<"0"<<'\n';
        }
    }
}

int main(void){
    FC;
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    for(ll i=1;i<=n;i++){
        cin>>c[i];
    }
    for(ll i=1;i<=m;i++){
        cin>>t[i]>>d[i];
    }
    solve();
    return 0;
}
