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

const ll maxn=(ll)2e5+10ll;

ll n,m,k;
ll a[maxn];
pii res[maxn];

bool cmp(const pii &a,const pii &b){
    if(a.first>b.first)
        return true;
    else if(a.first==b.first&&a.second<b.second)
        return true;
    return false;
}

void solve(){
    ll ans=0;
    sort(res+1,res+1+n,cmp);
    vector<ll> index;
    ll len=k*m;
    for(ll i=1;i<=len;i++){
        ans+=res[i].first;
        index.push_back(res[i].second);
//        deb(res[i].second);
    }
    sort(index.begin(),index.end());
    cout<<ans<<'\n';
    for(ll i=m-1,cnt=0;cnt<k-1ll&&i<(ll)index.size();i+=m,cnt++){
        cout<<index[i]<<" ";
    }
}

int main(void){
    FC;
    cin>>n>>m>>k;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        res[i].first=a[i];
        res[i].second=i;
    }
    solve();
    return 0;
}
