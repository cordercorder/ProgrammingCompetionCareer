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

const ll maxn=2e5+10;

ll n;
ll a[maxn];
map<ll,ll> mp;
map<ll,ll>::iterator it;

ll res[maxn];
ll tot;

void solve(){
    ll tmp,pos,ans=0,ret;
    tot=0;
    for(it=mp.begin();it!=mp.end();it++){
        res[++tot]=it->second;
    }
    sort(res+1,res+1+tot);
    for(ll i=1;i<=res[tot];i++){
        tmp=i;
        ret=0;
        pos=1;
        while(true){
            pos=lower_bound(res+pos,res+1+tot,tmp)-res;
            if(pos==tot+1)
                break;
            ++pos;
            ret+=tmp;
            tmp=tmp*2ll;
        }
        ans=max(ans,ret);
        //deb(ret);
    }
    cout<<ans<<'\n';
}

int main(void){
    FC;
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        mp[a[i]]++;
    }
    solve();
	return 0;
}
