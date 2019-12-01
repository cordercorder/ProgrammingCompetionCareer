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

const int maxn=(int)3e5+10;

int n,k;
int a[maxn];

void solve(){
    ll ans=a[n]-a[1],cnt=0;
    vector<int> ls;
    for(int i=2;i<=n;i++){
        ls.push_back(a[i-1]-a[i]);
    }
    sort(ls.begin(),ls.end());
//    for(int e:ls){
//        printf("%d ",e);
//    }
//    puts("");
    for(int i=1;i<k&&cnt<(int)ls.size();i++){
        ans+=(ll)(ls[cnt++]);
    }
    printf("%lld\n",ans);
    
}

int main(void){
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    solve();
    return 0;
}
