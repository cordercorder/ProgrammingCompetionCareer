#include<algorithm>
#include<iostream>
#include<limits.h>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<string>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<queue>
#include<stack>
#include<deque>
#include<ctime>
#include<list>
#include<set>
#include<map>

#define deb(x) cout<<"#---"<<#x<<"=="<<x<<endl
#define FC ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define FIN freopen("in.txt","r",stdin)
#define FOUT freopen("out.txt","w",stdout)

using namespace std;

const long double PI=acos(-1.0);  
const long double eps=1e-6;
const long long maxw=1e17+10;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const int maxn=1e5+10;
const ll mod=1e9+7ll; 

int a[maxn];
vector<int> res[1000010];
int n;
int dp[1000010];

void pre_handle(int x){
    for(int i=1;i<=x;i++){
        for(int j=i;j<=x;j+=i){
            res[j].push_back(i);
        }
    }
}

void solve(){
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=(int)res[a[i]].size()-1;j>=0;j--){
            ll tmp=res[a[i]][j];
            dp[tmp]=(dp[tmp]+dp[tmp-1])%mod;
        }
    }
    ll ans=0;
    for(ll i=1;i<=n;i++){
        ans=(ans+dp[i])%mod;
    }
    printf("%lld\n",ans);
}

int main(void){
    clock_t st=clock();
    pre_handle(1000000);
    clock_t ed=clock();
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    solve();
    return 0;
}
