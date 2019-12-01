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

const ll mod=2520ll;

ll t;
ll l,r;
ll a[25];
ll len;
ll dp[21][50][2525];
ll index[2525];

ll lcm(ll a,ll b){
    return a/__gcd(a,b)*b;
}

void handle(ll x){
    ll cnt=0;
    while(x){
        a[++cnt]=x%10ll;
        x/=10ll;
    }
    len=cnt;
}

void pre_handle(){
    ll cnt=0;
    for(ll i=1;i*i<=2520;i++){
        if(mod%i==0){
            index[i]=cnt++;
            if(mod/i!=i){
                index[mod/i]=cnt++;
            }
        }
    }
}

ll solve(ll pos,ll num,ll res,bool f){
    if(pos==0){
        return res%num==0;
    }
    if(!f&&dp[pos][index[num]][res]!=-1){
        return dp[pos][index[num]][res];
    }
    ll x;
    if(f){
        x=a[pos];
    }
    else{
        x=9ll;
    }
    ll ans=0,tmp,res_tmp;
    for(ll i=0;i<=x;i++){
        res_tmp=(res*10+i)%mod;
        if(i==0){
            ans+=solve(pos-1,num,res_tmp,i==x&&f);
        }
        else{
            tmp=lcm(num,i);
            ans+=solve(pos-1,tmp,res_tmp,i==x&&f);
        }
    }
    if(!f)
        dp[pos][index[num]][res]=ans;
    return ans;
}

int main(void){
    FC;
    pre_handle();
    memset(dp,-1,sizeof(dp));
    cin>>t;
    while(t--){
        cin>>l>>r;
        handle(r);
        ll ans1=solve(len,1,0,true);
        handle(l-1);
        ll ans2=solve(len,1,0,true);
        cout<<ans1-ans2<<'\n';
    }    
    return 0;
}
