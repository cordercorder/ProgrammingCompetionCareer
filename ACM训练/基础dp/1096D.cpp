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

const int maxn=(int)1e5+10;

char s[maxn];
int n;
int a[maxn];
ll dp[maxn][4];

void solve(){
    ll mine;
    for(int i=1;i<=n;i++){
        if(s[i]=='h'){
            dp[i][0]=dp[i-1][0]+(ll)a[i];
            dp[i][1]=dp[i-1][1];
            dp[i][2]=dp[i-1][2];
            dp[i][3]=dp[i-1][3];
        }
        else if(s[i]=='a'){
            dp[i][0]=dp[i-1][0];
            mine=min(dp[i-1][1]+(ll)a[i],dp[i-1][0]);
            dp[i][1]=mine;
            dp[i][2]=dp[i-1][2];
            dp[i][3]=dp[i-1][3];
        }
        else if(s[i]=='r'){
            dp[i][0]=dp[i-1][0];
            dp[i][1]=dp[i-1][1];
            mine=min(dp[i-1][1],dp[i-1][0]);
            mine=min(mine,dp[i-1][2]+(ll)a[i]);
            dp[i][2]=mine;
            dp[i][3]=dp[i-1][3];
        }
        else if(s[i]=='d'){
            dp[i][0]=dp[i-1][0];
            dp[i][1]=dp[i-1][1];
            dp[i][2]=dp[i-1][2];
            mine=min(dp[i-1][0],min(dp[i-1][1],dp[i-1][2]));
            mine=min(dp[i-1][3]+(ll)a[i],mine);
            dp[i][3]=mine;
        }
        else{
            for(int j=0;j<4;j++){
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<dp[n][3]<<'\n';
}

int main(void){
    FC;
    cin>>n;
    cin>>(s+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    solve();
    return 0;
}
