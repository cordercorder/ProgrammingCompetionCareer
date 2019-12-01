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

int T;
int A,B,K; 
int a[15],cnt;
int dp[15][105][105];

void handle(int x){
    cnt=0;
    while(x){
        a[++cnt]=x%10;
        x/=10;
    }
}

int solve(int pos,int sum,int digit,bool f){
    if(pos==0){
        return sum==0&&digit==0;
    }
    int x;
    if(!f&&dp[pos][sum][digit]!=-1)
        return dp[pos][sum][digit];
    if(f){
        x=a[pos];
    }
    else{
        x=9;
    }
    int ans=0;
    for(int i=0;i<=x;i++){
        ans+=solve(pos-1,(sum*10+i)%K,(digit+i)%K,i==x&&f);
    }
    if(!f)
        dp[pos][sum][digit]=ans;
    return ans;
}

int main(void){
    FC;
    cin>>T;
    for(int ca=1;ca<=T;ca++){
        cin>>A>>B>>K;
        memset(dp,-1,sizeof(dp));
        cout<<"Case "<<ca<<": ";
        if(K>=99){
            cout<<"0"<<'\n';
            continue;
        }
        handle(B);
        int ans1=solve(cnt,0,0,true);
        handle(A-1);
        int ans2=solve(cnt,0,0,true);
        cout<<ans1-ans2<<'\n';
    }
    return 0;
}
