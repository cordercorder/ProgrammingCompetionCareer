#include<bits/stdc++.h>
 
using namespace std;
 
#define FC ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
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

const ll maxn=(ll)2e5+10ll;

ll q;
ll n,k,a[maxn],sum[maxn];
vector<ll> ls;

void solve(){
    if((ll)ls.size()<k||((ll)ls.size()-k)%2==1){
        puts("NO");
        return ;
    }
    puts("YES");
    for(ll i=0;i+1<k;i++){
        printf("%lld ",ls[i]);
    }
    printf("%lld\n",n);
}

int main(void){
    scanf("%lld",&q);
    while(q--){
        scanf("%lld %lld",&n,&k);
        for(ll i=1;i<=n;i++){
            scanf("%lld",&a[i]);
            if(a[i]%2==1){
                ls.push_back(i);
            }
        }
        solve();
        ls.clear();
    }
    return 0;
}
