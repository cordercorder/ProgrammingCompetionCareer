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

const int maxn=(int)1e5+10;

ll T;
ll n,m;
ll l[maxn],a[maxn],b[maxn],sum[maxn],id[maxn];
vector<ll> ls[maxn],res[maxn];

void solve(){
    ll cnt=0;
    ll u1=0,v1=1,u2=0,v2,tmp,maxe=0;
    for(ll i=1;i<=m;i++){
        if(!ls[i].empty()){
            id[++cnt]=i;
            sort(ls[i].begin(),ls[i].end(),greater<ll>());
            sum[0]=ls[i][0];
            maxe=max(maxe,(ll)ls[i].size());
            res[i].push_back(0);
            res[i].push_back(sum[0]);
            for(ll j=1;j<(int)ls[i].size();j++){
                sum[j]=sum[j-1]+ls[i][j];
                res[i].push_back(sum[j]);
            }
        }
    }
    for(ll i=1;i<=maxe;i++){
        u2=0;
        v2=i;
        for(ll j=1;j<=cnt;j++){
            if(l[id[j]]<=i){
                if(i<(ll)res[id[j]].size()){
                    u2+=res[id[j]][i];
                }
                else{
                    u2+=res[id[j]].back();
                }
            }
        }
        if(u1*v2<u2*v1){
            u1=u2;
            v1=v2;
        }
    }
    tmp=__gcd(u1,v1);
    u1/=tmp;
    v1/=tmp;
    printf("%lld/%lld\n",u1,v1);
    for(ll i=1;i<=cnt;i++){
        res[id[i]].clear();
        ls[id[i]].clear();
    }
}

int main(void){
    scanf("%lld",&T);
    while(T--){
        scanf("%lld %lld",&n,&m);
        for(ll i=1;i<=m;i++){
            scanf("%lld",&l[i]);
        }
        for(ll i=1;i<=n;i++){
            scanf("%lld %lld",&a[i],&b[i]);
            ls[b[i]].push_back(a[i]);
        }
        solve();
    }
    return 0;
}
