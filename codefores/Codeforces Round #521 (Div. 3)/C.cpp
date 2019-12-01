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
#include<list>

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

const int maxn=2e5+10;

ll a[maxn];
ll n;
ll sum;
ll ans[maxn],cnt;

ll T[maxn<<2];

void create(ll rt,ll l,ll r){
    if(l==r){
        T[rt]=a[l];
        return ;
    }
    ll mid=(l+r)>>1;
    create(rt<<1,l,mid);
    create(rt<<1|1,mid+1,r);
    T[rt]=max(T[rt<<1],T[rt<<1|1]);
}

ll cal(ll rt,ll l,ll r,ll L,ll R){
    if(l==L&&R==r){
        return T[rt];
    }
    ll mid=(l+r)>>1;
    if(R<=mid){
        return cal(rt<<1,l,mid,L,R);
    }
    else if(L>mid){
        return cal(rt<<1|1,mid+1,r,L,R);
    }
    else{
        return max(cal(rt<<1,l,mid,L,mid),cal(rt<<1|1,mid+1,r,mid+1,R));
    }
}

void solve(){
    ll tmp;
    cnt=0;
    create(1,1,n);
    for(ll i=1;i<=n;i++){
        if(i==1){
            tmp=cal(1,1,n,i+1,n);
        }
        else if(i==n){
            tmp=cal(1,1,n,1,i-1);
        }
        else{
            tmp=max(cal(1,1,n,1,i-1),cal(1,1,n,i+1,n));
        }
        if(tmp==sum-a[i]-tmp){
            ans[++cnt]=i;
        }
    }
    cout<<cnt<<'\n';
    for(ll i=1;i<=cnt;i++){
        cout<<ans[i]<<" ";
    }
}

int main(void){
    FC;
    cin>>n;
    sum=0;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    solve();
	return 0;
}
