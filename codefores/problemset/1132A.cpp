#include<bits/stdc++.h>
#include<stdint.h>

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

ll cnt[5]; 

void solve(){
    ll mine=min(cnt[1],cnt[4]);
    if(mine!=0){
        cnt[3]=0;
    }
    mine=min(cnt[1],cnt[4]);
    cnt[1]-=mine;
    cnt[4]-=mine;
    if(cnt[1]!=0||cnt[3]!=0||cnt[4]!=0){
        puts("0");
    }
    else{
        puts("1");
    }
}

int main(void){
    for(ll i=1;i<=4;i++){
        scanf("%lld",&cnt[i]);
    }
    solve();    
    return 0;
}
