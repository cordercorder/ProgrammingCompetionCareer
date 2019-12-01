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

ll a[maxn];
ll n,m;

bool check(ll x){
    if(x>n)
        return false;
    ll sum=0,cnt=0;
    ll i,k=1;
    for(i=1;i<=x;i++){
        sum+=a[i];
    }
    while(i<=n){
        sum+=max((ll)0,a[i]-k);
        cnt++;
        i++;
        if(cnt==x){
            k++;
            cnt=0;
        }
    }
    return sum>=m;
}

void solve(){
    sort(a+1,a+1+n,greater<ll>());
    ll l=1,r=n+1,mid;
    while(l<r){
        mid=(l+r)>>1;
        if(check(mid)){
            r=mid;
        }
        else{
            l=mid+1;
        }
    }
    if(l==n+1){
        puts("-1");
    }
    else{
        printf("%lld\n",l);
    }
}

int main(void){
    scanf("%lld %lld",&n,&m);
    for(ll i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    solve();
    return 0;
}
