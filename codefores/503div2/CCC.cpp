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
using pii=pair<int,int>; 

/*head------[@cordercorder]*/

const ll maxn=(ll)3e3+10;
ll n,m;
vector<ll> res[maxn];

ll cal(ll x){
    ll need=x-(ll)res[1].size();
    ll pos,sum=0;
    vector<ll> ls;
    for(ll i=2;i<=m;i++){
        pos=(ll)res[i].size()-x+1ll;
        if(pos<0)
            pos=0;
        ll j;
        for(j=0;j<pos;j++){
            sum+=res[i][j];
            need--;
        }
        for(;j<(ll)res[i].size();j++){
            ls.push_back(res[i][j]);
        }
    }
    if(need>0){
        nth_element(ls.begin(),ls.begin()+need,ls.end());
        for(ll i=0;i<need;i++){
            sum+=ls[i]; 
        }
    }
    return sum;
}

void solve(){
    for(ll i=1;i<=m;i++){
        sort(res[i].begin(),res[i].end());
    }
    ll l=1,r=n,mid,ans;
    while(l<r){
        mid=(l+r)>>1;
        if(cal(mid)<=cal(mid+1ll)){
            r=mid;
        }
        else{
            l=mid+1ll;
        }
    }
    ans=cal(l); 
    cout<<ans<<'\n';
}

int main(void){
    FC;
    cin>>n>>m;
    ll p,c;
    for(ll i=1;i<=n;i++){
        cin>>p>>c;
        res[p].push_back(c);
    }
    solve();
    return 0;
}
