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

const int maxn=(int)3e5+10;

int a[maxn];
int sum[maxn];
int n;
int cnt[10000010][2];

void solve(){
    ll ans=0;
    for(int i=0;i<=n;i++){
        ans+=(ll)(cnt[sum[i]][i%2]);
        cnt[sum[i]][i%2]++;
    }
    printf("%lld\n",ans);
}

int main(void){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        sum[i]=sum[i-1]^a[i];
    }
    solve();
    return 0;
}
