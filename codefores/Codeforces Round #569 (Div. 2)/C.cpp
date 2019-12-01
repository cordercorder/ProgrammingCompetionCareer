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

const int maxn=(int)1e5+10;

ll n,q,m;
ll a[maxn+maxn];
ll max_pos;
ll maxe[maxn],A[maxn],B[maxn];

void handle(){
    maxe[0]=-1;
    ll cnt=0;
    for(ll i=1;i<=max_pos;i++){
        if(a[i]>maxe[i-1]){
            A[i]=a[i];
            B[i]=a[i+1];
            a[i+n]=min(A[i],B[i]);
        }
        else{
            A[i]=maxe[i-1];
            B[i]=a[i+1];
            a[i+n]=min(A[i],B[i]);
        }
        maxe[i]=max(maxe[i-1],a[i]);
    }
//    for(int i=1;i<=max_pos+n;i++){
//        printf("%d ",a[i]);
//    }
//    puts("");
}

int main(void){
    scanf("%lld %lld",&n,&q);
    for(ll i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    max_pos=1;
    for(ll i=1;i<=n;i++){
        if(a[i]>a[max_pos]){
            max_pos=i;
        }
    }
    handle();
    while(q--){
        scanf("%lld",&m);
        if(m<=max_pos){
            printf("%lld %lld\n",A[m],B[m]);
        }
        else{
            printf("%lld %lld\n",a[max_pos],a[(m-max_pos)%(n-1ll)+max_pos+1ll]);
        }
    }
    return 0;
}
