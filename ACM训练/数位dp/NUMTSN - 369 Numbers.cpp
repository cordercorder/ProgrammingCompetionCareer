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

const int maxn=55;
const ll mod=1000000007ll;

int T;
char A[maxn],B[maxn];
int len;
ll dp[55][55][55][55];

ll dfs(char *s,int pos,int sum3,int sum6,int sum9,bool f){
    if(pos==0){
        return (ll)(sum3==sum6&&sum6==sum9&&sum3>0);
    }
    if(!f&&dp[pos][sum3][sum6][sum9]!=-1){
        return dp[pos][sum3][sum6][sum9];
    }
    ll x,ans=0ll;
    if(f){
        x=(int)(s[pos]-'0');
    }
    else{
        x=9;
    }
    for(int i=0;i<=x;i++){
        if(i==3){
            ans=(ans+dfs(s,pos-1,sum3+1,sum6,sum9,i==x&&f))%mod;
        }
        else if(i==6){
            ans=(ans+dfs(s,pos-1,sum3,sum6+1,sum9,i==x&&f))%mod;
        }
        else if(i==9){
            ans=(ans+dfs(s,pos-1,sum3,sum6,sum9+1,i==x&&f))%mod;
        }
        else{
            ans=(ans+dfs(s,pos-1,sum3,sum6,sum9,i==x&&f))%mod;
        }
    }
    if(!f){
        dp[pos][sum3][sum6][sum9]=ans;
    }
    return ans;
}

void solve(){
    len=strlen(A+1);
    reverse(A+1,A+1+len);
    ll ans1=dfs(A,len,0,0,0,true);
    int sum[3]={0,0,0};
    for(int i=1;i<=len;i++){
        if(A[i]=='3'){
            sum[0]++;
        }
        else if(A[i]=='6'){
            sum[1]++;
        }
        else if(A[i]=='9'){
            sum[2]++;
        }
    }
    if(sum[0]==sum[1]&&sum[1]==sum[2]&&sum[0]>0){
        ans1=(ans1-1ll+mod)%mod;
    }
    len=strlen(B+1);
    reverse(B+1,B+1+len);
    ll ans2=dfs(B,len,0,0,0,true);
    ll ans=(ans2-ans1+mod)%mod;
    cout<<ans<<'\n';
}

int main(void){
    FC;
    cin>>T;
    memset(dp,-1,sizeof(dp));
    while(T--){
        cin>>(A+1)>>(B+1);
        solve();
    }
    return 0;
}
