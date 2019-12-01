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
#include<list>
#include<set>
#include<map>

#define deb(x) cout<<"#---"<<#x<<"=="<<x<<endl
#define FC ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define FIN freopen("in.txt","r",stdin)
#define FOUT freopen("out.txt","w",stdout)

using namespace std;

const long double PI=acos(-1.0);  
const long double eps=1e-6;
const long long maxw=1e17+10;

using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>; 

/*head------[@cordercorder]*/

const ll maxn=(ll)2e5+10ll;

ll n;
ll a[maxn],maxe;
stack<ll> sta;

void solve(){
    vector<ll> ls;
    ll ret;
    for(ll i=1;i<=n;i++){
        if(!sta.empty()&&sta.top()==a[i]){
            sta.pop();
            if(!sta.empty()&&sta.top()<a[i]){
                cout<<"NO"<<'\n';
                return ;
            }
        }
        else{
            sta.push(a[i]);
        }
    }
    if((ll)sta.size()>1){
        cout<<"NO"<<'\n';
        return ;
    }
    else if((ll)sta.size()==1ll&&sta.top()!=maxe){
        cout<<"NO"<<'\n';
        return ;
    }
    cout<<"YES"<<'\n';
}

int main(void){
    FC;
    cin>>n;
    maxe=0;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        maxe=max(maxe,a[i]);
    }
    solve();
    return 0;
}
