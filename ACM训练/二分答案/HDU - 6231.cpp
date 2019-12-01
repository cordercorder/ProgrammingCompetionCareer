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

const int maxn=1e5+10;

ll t;
ll a[maxn],n,m,k;
ll Min,Max;

bool check(ll x){
    ll sum=0,ans=0;
    ll i,j;
    for(i=1;i<=n;i++){
        if(a[i]>=x){
            sum++;
        }
        if(sum==k){
            break;
        }
    }
    if(sum<k)
        return 0;
    j=i;
    i=1;
    while(j<=n){
        if(sum>=k){
            ans+=(n-j+1); 
        }
        if(sum<k){
            j++;
            if(j<=n&&a[j]>=x){
                sum++;
            }
        }
        else{
            if(a[i]>=x){
                sum--;
            }
            i++;
        }
    }
    return ans>=m;
}

void solve(){
    ll l=Min,r=Max,mid;
    while(l<r){
        mid=(l+r)>>1;
        if(check(mid)){
            l=mid+1;
        }
        else{
            r=mid;
        }
    }
    if(!check(l))
        l--;
    cout<<l<<'\n';
}

int main(void){
	FC;
    cin>>t;
    while(t--){
        cin>>n>>k>>m;
    	Min=(ll)(1e9+10);
    	Max=0;
    	for(ll i=1;i<=n;i++){
    	    cin>>a[i];
    	    Max=max(Max,a[i]);
    	    Min=min(Min,a[i]);
        }
    	solve();
    }
	return 0;
}
