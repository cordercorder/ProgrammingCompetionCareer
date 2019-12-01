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

int T;
int digit[15];
int n,m;
int dp[15][15];

void solve(){
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=m;i++){
        dp[1][i]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=1;k<=m;k++){
                if(abs(digit[j]-digit[k])<=2){
                    dp[i][j]+=dp[i-1][k];
                }
            }
        }
    }
    int ans=0;
    for(int i=1;i<=m;i++){
        ans+=dp[n][i];
    }
    cout<<ans<<'\n';
}

int main(void){
    FC;
    cin>>T;
    for(int ca=1;ca<=T;ca++){
        cin>>m>>n;
        for(int i=1;i<=m;i++){
            cin>>digit[i];
        }
        cout<<"Case "<<ca<<": ";
        solve();
    }
    return 0;
}
