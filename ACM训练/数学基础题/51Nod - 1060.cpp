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
#include<set>
#include<map>

#define deb(x) cout<<"#---"<<#x<<"=="<<x<<endl
#define FC ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define FIN freopen("in.txt","r",stdin)
#define FOUT freopen("A.txt","w",stdout)

using namespace std;

const long double PI=acos(-1.0);  
const long double eps=1e-6;
const long long maxw=1e17+10;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const ll maxn=200;

ll t,n;
bool f[maxn+10];
vector<ll> pri;
ll ans,ret;

void pre_handle(){
    for(ll i=2;i<=maxn;i++){
        if(f[i]==false){
            pri.push_back(i);
            for(ll j=i*i;j<=maxn;j+=i){
                f[j]=true;
            }
        }
    }  
}

void dfs(ll pos,ll num,ll cnt,ll limit){
    if(cnt>ret||cnt==ret&&num<ans){
        ret=cnt;
        ans=num;
    }
    if(pos>(ll)pri.size())
        return ;
    ll tmp=num;
    for(ll i=1;i<=limit;i++){
        if(tmp<n/pri[pos]){
            tmp=tmp*pri[pos];
            dfs(pos+1,tmp,cnt*(i+1),i);
        }
    }
}

int main(void){
    pre_handle();
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&n);
        ret=0;
        ans=(ll)(1e18)+10LL;
        dfs(0,1,1,63);
        printf("%lld %lld\n",ans,ret);
    }
	return 0;
}
