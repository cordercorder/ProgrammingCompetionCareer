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

const ll maxn=(ll)3e5+10ll;

ll n,k;
pii a[maxn];

bool cmp(const pii &a,const pii &b){
    if(a.second>b.second)
        return true;
    else if(a.second==b.second&&a.first>b.first){
            return true;
    }
    return false;
}

void solve(){
    sort(a+1,a+1+n,cmp);
    priority_queue<ll,vector<ll>,greater<ll> > q;
    ll sum=0;
    ll ans=0ll;
    for(ll i=1;i<=n;i++){
        q.push(a[i].first);
        sum+=a[i].first;
        while((ll)q.size()>k){
            sum-=q.top();
            q.pop();
        }
        ans=max(ans,sum*a[i].second);
    }
    printf("%lld\n",ans);
}

int main(void){
    scanf("%lld %lld",&n,&k);
    for(ll i=1;i<=n;i++){
        scanf("%lld %lld",&a[i].first,&a[i].second);
    }
    solve();
    return 0;
}
