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

ll t;
ll a,b,k;
ll cnt1,cnt2;
ll ans;

int main(void){
    FC;
    cin>>t;
    while(t--){
        cin>>a>>b>>k;
        cnt1=k/2LL+k%2LL;
        cnt2=k/2;
        ans=cnt1*a-cnt2*b;
        cout<<ans<<'\n';
    }
	return 0;
}
