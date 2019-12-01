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

#define deb(x) cerr<<"#---"<<#x<<"=="<<x<<endl
#define FC ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define FIN freopen("in.txt","r",stdin)
#define FOUT freopen("out.txt","w",stdout)

using namespace std;

const long double PI=acos(-1.0);  
const long double eps=1e-6;
const long long maxw=(long long)1e17+(long long)10;

using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>; 

/*head------[@cordercorder]*/

const ll maxn=(ll)2e5+10ll;

ll n;
ll a[maxn];
ll Max;
map<ll,ll> ans;
vector<ll> res;

void solve(){
    ll tmp;
    map<ll,stack<ll>> st;
    for(ll i=1;i<=n;i++){
        if(a[i]==Max)
            continue;
        if(st[a[i]].empty()==false){
            tmp=st[a[i]].top();
            ans[tmp]=i;
            ans[i]=tmp;
            st[a[i]].pop();
        }
        else{
            st[a[i]].push(i);
        }
    }
    for(map<ll,stack<ll>>::iterator it=st.begin();it!=st.end();it++){
        if(it->second.empty()==false){
            cout<<"NO";
            return ;
        }
    }
    for(ll i=1;i<=n;i++){
        if(ans[i]!=0){
            res.push_back(ans[i]);
        }
    }
    if(res.empty()){
        cout<<"YES"<<endl;
        return ;
    }
    for(ll i=0;i<(ll)res.size();i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
    bool f;
    for(ll i=0;i<(ll)res.size();){
        ll j=i+1;
        f=false;
        while(j<(ll)res.size()&&res[j]<res[j-1]){
            j++;
            f=true;
        }
        if(f){
            if((j-i)&1ll){
                cout<<"NO";
                return ;
            }
            i=j;
        }
        else{
            cout<<"NO";
            return ;
        }
    }
    cout<<"YES";
}

int main(void){
    FC;
    cin>>n;
    Max=0;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        Max=max(Max,a[i]);
    }
    solve();
    return 0;
}
