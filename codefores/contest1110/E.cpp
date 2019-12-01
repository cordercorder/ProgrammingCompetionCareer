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

const ll maxn=(ll)1e5+10ll;

ll c[maxn],t[maxn];
ll n;

void solve(){
    ll l=1,r=n;
    while(l<=n&&c[l]==t[l]){
        l++;
    }
    while(r>=1&&c[r]==t[r]){
        r--;
    }
    if(l==1||r==n){
        cout<<"No"<<'\n';
        return ;
    }
    if(l>r){
        cout<<"Yes"<<'\n';
        return ;
    }
    vector<ll> a,b;
    for(ll i=2;i<=n;i++){
        a.push_back(c[i]-c[i-1]);
        b.push_back(t[i]-t[i-1]);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    for(ll i=0;i<n-1ll;i++){
        if(a[i]!=b[i]){
            cout<<"No"<<'\n';
            return ;
        }
    }
    cout<<"Yes"<<'\n';
}

int main(void){
    FC;
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>c[i];
    } 
    for(ll i=1;i<=n;i++){
        cin>>t[i];
    }
    solve();    
    return 0;
}
