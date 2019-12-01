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

const ll maxn=(ll)1e5+10ll;

pii st,ed;
ll n;
char s[maxn];
ll dx[maxn],dy[maxn];

void pre_handle(){
    for(ll i=1;i<=n;i++){
        if(s[i]=='U'){
            dx[i]=dx[i-1];
            dy[i]=dy[i-1]+1ll;
        }
        else if(s[i]=='D'){
            dx[i]=dx[i-1];
            dy[i]=dy[i-1]-1ll;
        }
        else if(s[i]=='L'){
            dx[i]=dx[i-1]-1ll;
            dy[i]=dy[i-1];
        }
        else{
            dx[i]=dx[i-1]+1ll;
            dy[i]=dy[i-1];
        }
    }
}

bool check(ll x){
    ll ret=x/n;
    pii now;
    now.first=(st.first+ret*dx[n]);
    now.second=(st.second+ret*dy[n]);
    ll len=x-ret*n;
    now.first+=dx[len];
    now.second+=dy[len];
    ll res=abs(now.first-ed.first)+abs(now.second-ed.second);
    return x>=res;
}

void solve(){
    pre_handle();
    ll l=0,r=maxw,mid;
    while(l<r){
        mid=(l+r)>>1ll;
        if(check(mid)){
            r=mid;
        }
        else{
            l=mid+1;
        }
    }
    if(l==maxw){
        puts("-1");
    }
    else{
        printf("%lld\n",l);
    }
}

int main(void){
    scanf("%lld %lld",&st.first,&st.second);
    scanf("%lld %lld",&ed.first,&ed.second);
    scanf("%lld",&n);
    scanf("%s",s+1);
    solve();
    return 0;
}
