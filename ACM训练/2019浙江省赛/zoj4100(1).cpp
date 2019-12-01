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
using pii=pair<ll,ll>;

/*head------[@cordercorder]*/

const int maxn=(int)1e5+10;

int T;
int n,q;
int pre[maxn];
ll cntnode[maxn],cnte[maxn];
ll sum,k,tot;
ll seg[maxn<<2][3];//cntnode,cntedge,cnt
ll ret;

void create(ll rt,ll l,ll r){
    seg[rt][0]=0;
    seg[rt][1]=0;
    seg[rt][2]=0;
    if(l==r){
        if(l==1){
            seg[rt][0]=n;
            seg[rt][2]=n;
        }
        return ;
    }
    int mid=(l+r)>>1;
    create(rt<<1,l,mid);
    create(rt<<1|1,mid+1,r);
    for(int i=0;i<3;i++){
        seg[rt][i]=seg[rt<<1][i]+seg[rt<<1|1][i];
    }
}

int Find(int x){
    return pre[x]==-1?x:pre[x]=Find(pre[x]);
}

void pre_handle(){
    for(int i=1;i<=n;i++){
        pre[i]=-1;
        cntnode[i]=1;
        cnte[i]=0;
    }
}

void handle(ll rt,ll l,ll r,ll pos,bool f){
    if(l==r){
        if(f){
            seg[rt][0]+=l;
            seg[rt][1]+=l*(l-1ll)/2ll;
            seg[rt][2]++;
        }
        else{
            seg[rt][0]-=l;
            seg[rt][1]-=l*(l-1ll)/2ll;
            seg[rt][2]--;
        }
        return ;
    }
    ll mid=(l+r)>>1;
    if(pos<=mid){
        handle(rt<<1,l,mid,pos,f);
    }
    else{
        handle(rt<<1|1,mid+1,r,pos,f);
    }
    for(int i=0;i<3;i++){
        seg[rt][i]=seg[rt<<1][i]+seg[rt<<1|1][i];
    }
}

void Union(int u,int v){
    int nu=Find(u),nv=Find(v);
    ll s1,s2,s;
    if(nu!=nv){
        s1=(cntnode[nu]*(cntnode[nu]-1ll))/2ll-cnte[nu];
        s2=(cntnode[nv]*(cntnode[nv]-1ll))/2ll-cnte[nv];
        handle(1,1,n,cntnode[nu],false);
        handle(1,1,n,cntnode[nv],false);
        pre[nu]=nv;
        cntnode[nv]+=cntnode[nu];
        cnte[nv]+=(cnte[nu]+1);
        sum--;
        s=(cntnode[nv]*(cntnode[nv]-1ll))/2ll-cnte[nv];
        tot+=(s-s1-s2);
        handle(1,1,n,cntnode[nv],true);
    }
    else{
        tot--;
    }
}

ll cal(ll rt,ll l,ll r,ll node,ll edge,ll t){
    if(l==r){
        ll L=1,R=seg[rt][2],mid;
        ll X=l;
        while(L<R){
            mid=(L+R)>>1;
            if((mid*X+node)*(mid*X+node-1ll)/2ll-(edge+mid*X*(X-1ll)/2ll)<ret){
                L=mid+1;
            }
            else{
                R=mid;
            }
        }
//        deb(ret);
//        deb(l);
//        deb(R);
//        deb(node);
//        deb(edge);
//        deb(t);
        return t+R-1ll;
    }
    ll mid=(l+r)>>1;
    ll tmp=(node+seg[rt<<1|1][0])*(node+seg[rt<<1|1][0]-1ll)/2ll-(edge+seg[rt<<1|1][1]);
    if(tmp<ret){
        return cal(rt<<1,l,mid,node+seg[rt<<1|1][0],seg[rt<<1|1][1]+edge,t+seg[rt<<1|1][2]);
    }
    else{
        return cal(rt<<1|1,mid+1,r,node,edge,t);
    }
}

ll solve(){
    ret=k-tot;
    if(ret<=0){
        return 0;
    }
    ll ans=cal(1,1,n,0,0,0);
    return ans;
}

int main(void){
    int p;
    int a,b;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&n,&q);
        pre_handle();
        create(1,1,n);
        sum=n;
        tot=0;
        while(q--){
            scanf("%d",&p);
            if(p==1){
                scanf("%d %d",&a,&b);
                Union(a,b);
            }
            else{
                scanf("%lld",&k);
                if(k>=(sum-1ll)){
                    printf("1 %lld\n",sum-solve());
                }
                else{
                    printf("%lld %lld\n",sum-k,sum-solve());
                }
            }
//            deb(tot);
        }
    }
    return 0;
}
