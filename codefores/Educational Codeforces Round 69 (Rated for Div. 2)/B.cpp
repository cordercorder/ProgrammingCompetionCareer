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

int n,a[maxn];

void solve(){
    int maxe=1;
    for(int i=1;i<=n;i++){
        if(a[maxe]<a[i]){
            maxe=i;
        }
    }
    for(int i=1;i<=n;i++){
        if(i!=maxe&&a[i]==a[maxe]){
            puts("NO");
            return ;
        }
    }
    int l=maxe,r=maxe;
    while(l-1>=1&&a[l-1]<a[l]){
        l--;
    }
    while(r+1<=n&&a[r+1]<a[r]){
        r++;
    }
    if(l==1&&r==n){
        puts("YES");
    }
    else{
        puts("NO");
    }
}


int main(void){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    solve();
    return 0;
}
