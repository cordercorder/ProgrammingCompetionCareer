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
using pii=pair<int,int>; 

/*head------[@cordercorder]*/

const ll maxn=(ll)1e5+10ll;

struct node{
    ll a;
    ll b;
    node(){}
    node(ll _a,ll _b):a(_a),b(_b){}
};

node res[maxn];
ll n;

ll cal(ll x){
    ll sum=0ll,tmp;
    vector<ll> ls;
    for(ll i=1;i<=n;i++){
        tmp=res[i].b*x;
        sum+=tmp;
        ls.push_back(res[i].a-tmp);
    }
    nth_element(ls.begin(),ls.begin()+x,ls.end(),greater<ll>());
    for(ll i=0;i<x;i++){
        sum+=ls[i];
    }
    return sum;
}

void solve(){
    ll l=1ll,r=n+1ll,mid;
    while(l<r){
        mid=(l+r)>>1ll;
        if(cal(mid)<cal(mid+1ll)){
            l=mid+1ll;
        }
        else{
            r=mid;
        }
    }
    cout<<cal(l)<<'\n';
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
