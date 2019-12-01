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

ll T;
ll a,b,c,d,k;

bool check[maxn];
ll prime[maxn],mu[maxn];
ll sum[maxn];

void Moblus(){
    mu[1]=1ll;
    ll tot=0;
    for(ll i=2;i<maxn;i++){
        if(!check[i]){
            prime[tot++]=i;
            mu[i]=-1;
        }
        for(ll j=0;j<tot;j++){
            if(i*prime[j]>maxn)
                break;
            check[i*prime[j]]=true;
            if(i%prime[j]==0){
                mu[i*prime[j]]=0;
                break;
            }
            else{
                mu[i*prime[j]]=-mu[i];
            }
        }
    }
    for(ll i=1;i<maxn;i++){
        sum[i]=sum[i-1]+mu[i];
    }
}

void solve(){
    b/=k;
    d/=k;
    ll N=min(b,d);
    ll ans1=0ll,ans2=0ll;
    for(ll l=1ll,r;l<=N;l=r+1ll){
        r=min(b/(b/l),d/(d/l));
        ans1+=(sum[r]-sum[l-1])*(b/l)*(d/l);
    }
    for(ll l=1ll,r;l<=N;l=r+1ll){
        r=N/(N/l);
        ans2+=(sum[r]-sum[l-1])*(N/l)*(N/l);
    }
    ans1=ans1-ans2/2ll;
    cout<<ans1<<'\n';
}

int main(void){
    FC;
    Moblus();
    cin>>T;
    for(ll ca=1ll;ca<=T;ca++){
        cin>>a>>b>>c>>d>>k;
        cout<<"Case "<<ca<<": ";
        if(k==0ll){
            cout<<"0"<<'\n';
            continue;
        }
        solve();
    }
    return 0;
}
