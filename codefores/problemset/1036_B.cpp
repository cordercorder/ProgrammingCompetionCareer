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

int n,k;

void solve(){
    int ans=0;
    int l=k,r=n-k+1;
    if(l==1||r==1){
        ans=6+(n-2)*3;
    }
    else if(l<r){
        ans=6+(l-2)*3+(r-1)*2+n-1;
    }
    else{
        ans=6+(r-2)*3+(l-1)*2+n-1;
    }
    printf("%d\n",ans);
}

int main(void){
    scanf("%d %d",&n,&k);
    solve();
    return 0;
}
