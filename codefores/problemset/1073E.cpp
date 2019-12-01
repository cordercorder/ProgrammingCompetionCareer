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

const ll mod=998244353ll;

ll l,r,k; 
ll dp[20][15][2];
ll d[20],cnt;
bool isv[15];

void handle(ll x){
    cnt=0;
    while(x){
        d[++cnt]=x%10;
        x/=10;
    }
}

ll dfs(ll pos,ll num,ll ret,bool f,bool ok,bool *isv){
    if(pos==0){
        return num;
    }
    if(!f&&dp[pos][ret][ok]!=-1){
        return dp[pos][ret][ok];
    }
    ll x;
    if(f){
        x=d[pos];
    }
    else{
        x=9ll;
    }
    ll tmp,nret,ans=0;
    for(ll i=0;i<=x;i++){
        tmp=num*10ll+i;
        if(ok||i!=0){
            if(!isv[i]){
                isv[i]=true;
                nret=ret+1;
            }
            else{
                nret=ret;
            }
            if(nret<=k)
                ans=(ans+dfs(pos-1,tmp,nret,f&&i==x,true,isv))%mod;
            if(nret==ret+1)
                isv[i]=false;
        }
        else{
            ans=(ans+dfs(pos-1,tmp,ret,f&&i==x,false,isv))%mod;
        }
    }
    if(!f){
        dp[pos][ret][ok]=ans;
    }
    return ans;
}

void solve(){
    handle(r);
    memset(dp,-1,sizeof(dp));
    ll ans1=dfs(cnt,0,0,true,false,isv);
    handle(l-1ll);
    ll ans2=dfs(cnt,0,0,true,false,isv);
    ll ans=(ans1-ans2+mod)%mod;
    printf("%lld\n",ans);
}

int main(void){    
    scanf("%lld %lld %lld",&l,&r,&k);
    solve();
    return 0;
}
