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

const ll maxn=(ll)2e5+10ll;

ll a[maxn],n,ret[maxn];

void solve(){
    ll cnt=0,r=1;
    ll pos;
    for(ll i=1;i<=n;i++){
        if(cnt>0){
            if(ret[cnt]>=a[i]){
                ret[++cnt]=a[i];
                ll j=cnt;
                pos=1ll;
                while(j-1>=r&&ret[j]<=ret[j-1]){
                    ret[j-1]=ret[j]-1;
                    ret[j-1]=max(0ll,ret[j-1]);
                    if(ret[j-1]==0ll){
                        pos=max(pos,j-1);
                    }
                    j--;
                }
                r=max(pos,r);
            }
            else{
                ret[++cnt]=a[i];
            }
        }
        else{
            ret[++cnt]=a[i];
        }
    }
    ll ans=0ll;
    for(ll i=1;i<=cnt;i++){
        ans+=ret[i];
    }
    printf("%lld\n",ans);
}

int main(void){
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    solve();
    return 0;
}
