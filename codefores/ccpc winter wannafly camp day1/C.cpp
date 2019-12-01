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

const ll S=3ll;
const ll maxn=10000005;

ll t;
ll A,B;
ll prime[maxn];
bool vis[maxn];
ll cnt;
ll ans[2][2];

ll mult_mod(ll a,ll b,ll c){
    a%=c;
    b%=c;
    ll ret=0;
    ll tmp=a;
    while(b){
        if(b&1ll){
            ret+=tmp;
            if(ret>c)
                ret-=c;
        }
        tmp<<=1ll;
        if(tmp>c)
            tmp-=c;
        b>>=1ll;
    }
    return ret;
}

ll pow_mod(ll a,ll n,ll mod){
    ll ret=1;
    ll tmp=a%mod;
    while(n){
        if(n&1ll){
            ret=mult_mod(ret,tmp,mod);
        }
        tmp=mult_mod(tmp,tmp,mod);
        n>>=1ll;
    }
    return ret;
}

bool check(ll a,ll n,ll x,ll t){
    ll ret=pow_mod(a,x,n);
    ll last=ret;
    for(ll i=1;i<=t;i++){
        ret=mult_mod(ret,ret,n);
        if(ret==1&&last!=1&&last!=n-1)
            return true;
        last=ret;
    }
    if(ret!=1)
        return true;
    return false;
}

bool Miller_Rabin(ll n){
    if(n<2)
        return false;
    if(n==2)
        return true;
    if((n&1ll)==0)
        return false;
    ll x=n-1;
    ll t=0;
    while((x&1)==0){
        x>>=1;
        t++;
    }
    srand(time(NULL));
    for(ll i=0;i<S;i++){
        ll a=(ll)rand()%(n-1)+1ll;
        if(check(a,n,x,t))
            return false;
    }
    return true;
}

void Prime(ll x){
	cnt=0;
	memset(vis,0,sizeof(vis));
	for(ll i=2;i<x;i++){
		if(!vis[i])
			prime[cnt++]=i;
		for(ll j=0;j<cnt&&i*prime[j]<x;j++){
			vis[i*prime[j]]=1;
			if(i%prime[j]==0)
				break;
		}
	}
}

void solve(){
    for(ll i=0;i<cnt;i++){
        if(Miller_Rabin(A-prime[i])){
            ans[0][0]=prime[i];
            ans[0][1]=A-prime[i];
            break;
        }
    }
    ans[1][0]=2ll;
    ans[1][1]=B-2ll;
    if(ans[0][0]==ans[1][0]){
        swap(ans[0][0],ans[0][1]);
    }
    cout<<"2"<<'\n';
    cout<<ans[0][0]<<" "<<ans[1][0]<<'\n';
    cout<<ans[0][1]<<" "<<ans[1][1]<<'\n'; 
}

int main(void){
    FC;
//    clock_t st=clock();
    Prime(1000000ll);
//    clock_t ed=clock();
//    cerr<<(double)(ed-st)<<"ms"<<endl;
    cin>>t;
    while(t--){
        cin>>A>>B;
        if(A==B){
            if(A&1ll){
                ans[0][0]=A/2ll,ans[0][1]=A-ans[0][0];
                cout<<"2"<<'\n';
                cout<<ans[0][0]<<" "<<ans[0][1]<<'\n';
                cout<<ans[0][1]<<" "<<ans[0][0]<<'\n'; 
            }
            else{
                ans[0][0]=A/2ll-1ll,ans[0][1]=A-ans[0][0];
                cout<<"2"<<'\n';
                cout<<ans[0][0]<<" "<<ans[0][1]<<'\n';
                cout<<ans[0][1]<<" "<<ans[0][0]<<'\n'; 
            }
            continue;
        }
        solve();
    }
    return 0;
}
