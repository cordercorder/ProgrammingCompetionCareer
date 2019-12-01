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
using pii=pair<ll,ll>;
 
/*head------[@cordercorder]*/

const ll maxn=(ll)2e5+10ll;

ll q,n;
ll a[maxn],f[maxn],cnt[maxn][2],ret[maxn];
bool isv[maxn];

bool cmp(const pii &a,const pii &b){
    if(a.first>b.first){
        return true;
    }
    else if(a.first==b.first&&a.second>b.second){
        return true;
    }
    return false;
}

void solve(){
    vector<pii> ls;
    for(int i=1;i<=n;i++){
        if(!isv[a[i]]){
            ls.push_back(pii(cnt[a[i]][0]+cnt[a[i]][1],cnt[a[i]][1]));
            isv[a[i]]=true;
        }
    }
    sort(ls.begin(),ls.end(),cmp);
    ll now=ls[0].first;
    ll ans1=now,ans2=0,L=0,R=1;
    ret[0]=now;
    for(ll i=1;i<(ll)ls.size()&&now>0;i++,R=i){
        now--;
        now=min(now,ls[i].first);
        ans1+=now;
        ret[i]=now;
    }
    priority_queue<ll> Q;
    for(ll i=0;i<(ll)ls.size()&&i<R;i++){
        while(L<(ll)ls.size()&&ls[L].first>=ret[i]){
            Q.push(ls[L].second);
            L++;
        }
        ans2+=min(ret[i],Q.top());
        Q.pop();
    }
    printf("%lld %lld\n",ans1,ans2);
}

int main(void){
    scanf("%lld",&q);
    while(q--){
        scanf("%lld",&n);
        for(ll i=1;i<=n;i++){
            scanf("%lld %lld",&a[i],&f[i]);
            cnt[a[i]][f[i]]++;
        }
        solve();
        for(ll i=1;i<=n;i++){
            cnt[a[i]][f[i]]--;
            isv[a[i]]=false;
        }
    }
    return 0;
}
