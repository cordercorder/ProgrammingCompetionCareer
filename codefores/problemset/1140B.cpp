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

int t,n;
char s[110];

void solve(){
    int ans=n+1;
    for(int i=1;i<=n;i++){
        if(s[i]=='>'){
            ans=min(ans,i-1);
        }
        else{
            ans=min(ans,n-i);
        }
    }
    printf("%d\n",ans);
}

int main(void){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        scanf("%s",s+1);
        solve();
    }
    return 0;
}
