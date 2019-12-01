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

const int maxn=5010;

int a[maxn],n,k;
int dp[maxn][maxn];

void solve(){
    sort(a+1,a+1+n);
    int ans=0,pos;
    for(int i=1;i<=n;i++){
        pos=lower_bound(a+1,a+1+n,a[i]-5)-a;
        for(int j=1;j<=i;j++){
            dp[i][j]=max(max(dp[i-1][j],dp[i][j-1]),dp[pos-1][j-1]+i-pos+1);
        }
    }
    printf("%d\n",dp[n][k]);
}

int main(void){
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    solve();
    return 0;
}
