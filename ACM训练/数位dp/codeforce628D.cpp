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

const int maxn=(int)2e3+10;
const ll mod=(ll)1e9+7ll;

ll m,d;
char a[2][maxn];
ll len_s;
ll dp[maxn][maxn];
vector<ll> res;

ll solve(ll id,ll pos,ll mul,ll num,bool f){
    if(pos==len_s+1){
        return (ll)mul==0;
    }
    if(!f&&dp[pos][mul]!=-1)
        return dp[pos][mul];
    ll x;
    if(f){
        x=(ll)(a[id][pos]-'0');
    }
    else{
        x=9ll;
    }
    ll ans=0ll;
    for(ll i=0;i<=x;i++){
        if(pos%2ll==1ll){
            if(i!=d)
                ans=(ans+solve(id,pos+1,(mul*10ll+i)%m,num*10ll+i,i==x&&f))%mod;
            
        }
        else{
            if(i==d){
                ans=(ans+solve(id,pos+1,(mul*10ll+i)%m,num*10ll+i,i==x&&f))%mod;
            }
        }
    }
    if(!f)
        dp[pos][mul]=ans;
    return ans;
}

bool check(){
    ll sum=0;
    for(ll i=1;i<=len_s;i++){
        if(i%2ll==0&&(ll)(a[0][i]-'0')!=d)
            return false;
        else if(i%2ll==1ll&&(ll)(a[0][i]-'0')==d){
            return false;
        }
        sum=(sum*10ll+(ll)(a[0][i]-'0'));
    }
    return sum%m==0;
}

int main(void){
    FC;
    memset(dp,-1,sizeof(dp));
    cin>>m>>d;
    cin>>(a[0]+1)>>(a[1]+1);
    len_s=strlen(a[0]+1);
    ll ans1=solve(1ll,1ll,0ll,0ll,true);
    ll ans2=solve(0ll,1ll,0ll,0ll,true);
    ll ans=(ans1-ans2+mod)%mod;
    if(check()){
        ans=(ans+1+mod)%mod;
    }
    cout<<ans<<'\n';
    return 0;
}
