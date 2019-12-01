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

const ll maxn=(ll)1e3+10ll;

struct node{
    ll a;
    ll b;
    node(){}
    node(ll _a,ll _b):a(_a),b(_b){}
};

node res[maxn];
ll n;
bool isv[maxn];

void solve(){
    ll tmp;
    ll ans=0,sum;
    vector<ll> ls;
    for(ll i=1;i<=n;i++){
        sum=0;
        for(ll j=1;j<=n;j++){
            tmp=res[j].b*i;
            sum+=tmp;
            ls.push_back(res[j].a-tmp);
        }
        nth_element(ls.begin(),ls.begin()+i,ls.end(),greater<ll>());
        for(ll j=0;j<i;j++){
            sum+=ls[j];
        }
        ans=max(sum,ans);
        ls.clear();
    }
    cout<<ans<<'\n';
}

int main(void){
    FC;
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>res[i].a>>res[i].b;
    }
    solve();
    return 0;
}
