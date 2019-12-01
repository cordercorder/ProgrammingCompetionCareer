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
using pii=pair<int,string>; 

/*head------[@cordercorder]*/

const ll maxn=(ll)3e5+10ll;

ll a[maxn];
ll n;

void solve(){
    sort(a+1,a+1+n);
    ll len=n/2ll;
    ll ans=0ll;
    for(ll i=1;i<=len;i++){
        ans+=(a[i]+a[n-i+1])*(a[i]+a[n-i+1]);
    }
    cout<<ans<<'\n';
}

int main(void){
    FC;
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    solve();
    return 0;
}
