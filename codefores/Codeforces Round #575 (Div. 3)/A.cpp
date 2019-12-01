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

ll q,a[3];

ll cal(ll x,ll y){
    for(ll i=0;i<3;i++){
        if(i!=x&&i!=y){
            return i;
        }
    }
}

void solve(){
    ll res1,res2,ans=0,tmp,ret;
    ll x1,x2;
    for(ll i=0;i<3;i++){
        for(ll j=i+1;j<3;j++){
            res1=a[i];
            res2=a[j];
            tmp=a[cal(i,j)];
            if(res1>res2){
                swap(res1,res2);
            }
            ret=abs(res2-res1);
            x1=(tmp+ret)/2;
            x2=x1-ret;
            res1+=x1;
            res2+=x2;
            ans=max(min(res1,res2),ans);
        }
    }
    printf("%lld\n",ans);
}

int main(void){
    scanf("%lld",&q);
    while(q--){
        for(ll i=0;i<3;i++){
            scanf("%lld",&a[i]);
        }
        solve();
    }
    return 0;
}
