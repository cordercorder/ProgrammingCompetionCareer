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

ll q;
ll k,n,a,b;

void solve(){
    if(k%a==0&&(k/a-1)==n){
        puts("-1");
        return ;
    }
    int ans1=k/a;
    k=k%a;
    if(k%b==0&&(k/b-1)==n-)
    
    
    if((k-k*ans1)==a){
        puts("-1");
        return ;
    }
    k=k%a;
    int ans2=k/b;
    if((k-b*ans2)==b){
        puts("-1");
        return ;
    }
    int ans=ans1+ans2;
    if(k==0){
        ans--;
    }
    printf("%lld\n",ans);
}

int main(void){
    
    scanf("%lld",&q);
    while(q--){
        scanf("%lld %lld %lld %lld",&k,&n,&a,&b);
        solve();
    }
    
    return 0;
}
