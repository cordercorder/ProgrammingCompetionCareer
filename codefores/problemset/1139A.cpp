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

ll n;
char s[65010];
ll ans;

int main(void){
    scanf("%lld",&n);
    scanf("%s",s+1);
    for(ll i=1;i<=n;i++){
        if((ll)(s[i]-'0')%2ll==0ll){
            ans+=i;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
