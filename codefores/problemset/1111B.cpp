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

ll a[maxn];
ll n,k,m;
ll sum[maxn];

void solve(){
    sort(a+1,a+1+n);
    double ANS;
    if(m>=(n-1ll)){
        ANS=(double)(a[n]+min(m-n+1ll,k));
    }
    ll f=0;
    for(ll i=1;i<=n;i++){
        if(a[i]+1ll==a[n])
            f++;
    }
    ll x;
    if(f>m){
        x=1ll;
    }
    else{
        x=0ll;
    }
    ll cnt=0;
    ll i,ret=0;
    double ans=0;
    for(i=1;i<=n;i++){
        if(a[i]+x<a[n]){
            cnt++;
            if(cnt==m){
                i++;
                break;
            }
        }
        else{
            break;
        }
    }
    ll tot=i;
    for(;cnt<m;cnt++){
        if(sum[tot]<k){
            sum[tot]++;
            a[tot]++;
            if(sum[tot]==k){
                tot++;
                if(tot==(n+1ll))
                    break;
            }
        }
    }
    for(ll j=i;j<=n;j++){
        ans+=a[j];
        ret++;
    }
    tot=i-1;
    while(cnt<m){
        if(tot>=1&&sum[tot]<k){
            sum[tot]++;
            a[tot]++;
            if(sum[tot]==k){
                tot--;
                if(tot==0ll)
                    break;
            }
        }
        cnt++;
    }
    for(ll j=i-1;j>tot;j--){
        if((ans+(double)a[j])/double(ret+1)>ans/(double)ret){
            ans+=(double)a[j];
            ret++;
        }
        else
            break;
    }    
    ans/=(double)ret;
    ans=max(ans,ANS);
    printf("%.12lf\n",ans);
}

int main(void){
    scanf("%lld %lld %lld",&n,&k,&m);
    for(ll i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    solve();
    return 0;
}
