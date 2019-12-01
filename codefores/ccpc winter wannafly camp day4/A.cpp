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

ll n,m;
pii a[2][maxn];
ll cnt;

ll cal(const pii &a,const pii &b){
    return abs(a.first-b.first)+abs(a.second-b.second);
}

void solve(){
    ll tmp1,tmp2,ans=0;
    for(ll i=1;i<n;i++){
        tmp1=cal(a[0][i],a[0][i+1])+cal(a[1][i],a[1][i+1]);
        tmp2=cal(a[0][i],a[1][i+1])+cal(a[1][i],a[0][i+1]);
        ans+=min(tmp1,tmp2);
    }
    ans+=cal(a[0][n],a[1][n]);
    cout<<ans<<'\n';    
}

int main(void){
    FC;
    cin>>n>>m;
    ll x,y;
    cnt=0;
    for(int i=1;i<=2*n;i++){
        cin>>x>>y;
        if(i&1){
            a[0][++cnt]=pii(x,y);
        }
        else{
            a[1][cnt]=pii(x,y);
        }
    }
    solve();
    return 0;
}
