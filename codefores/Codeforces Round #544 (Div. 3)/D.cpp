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

ll a[maxn],b[maxn],n;

map<long double,int> cnt;

void solve(){
    int ans=0,sum=0;
    long double ret;
    for(ll i=1;i<=n;i++){
        if(a[i]==0){
            if(b[i]==0)
                sum++;
        }
        else{
            ret=(long double)(-b[i])/(long double)a[i];
            cnt[ret]++;
        }
    }
    for(auto v:cnt){
        ans=max(ans,v.second);
    }
    ans+=sum;
    printf("%d\n",ans);
}

int main(void){
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(ll i=1;i<=n;i++){
        scanf("%lld",&b[i]);
    }
    solve();
    return 0;
}
