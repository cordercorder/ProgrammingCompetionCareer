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

const int maxn=(int)2e5+10;

int a[maxn];
int q,n;
int cnt[maxn];
bool isv[maxn],f[maxn];

void solve(){
    vector<ll> id;
    vector<ll> ls;
    for(int i=1;i<=n;i++){
        if(!isv[a[i]]){
            ls.push_back(cnt[a[i]]);
            isv[a[i]]=true;
        }
    }
    sort(ls.begin(),ls.end());
    ll now=ls.back();
    ll ans=now;
    for(ll i=(ll)ls.size()-2;i>=0&&now>0;i--){
        now--;
        now=min(now,ls[i]);
        ans+=now;
    }
    printf("%lld\n",ans);
}

int main(void){
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            cnt[a[i]]++;
        }
        solve();
        for(int i=1;i<=n;i++){
            cnt[a[i]]--;
            isv[a[i]]=false;
        }
    }
    return 0;
}
