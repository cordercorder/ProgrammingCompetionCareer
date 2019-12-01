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

const int maxn=(int)1e5+10;

int n;
int a[maxn],cnt,tot;

void print(){
    for(int i=1;i<=n;i++){
        if(i>1){
            printf(" ");
        }
        printf("%d",a[i]);
    }
    puts("");
}

void solve(){
    int cnt=0,min_pos=1;
    for(int i=1;i<=n;i++){
        if(a[i]>=0){
            a[i]=-a[i]-1;
        }
        if(a[i]<0){
            cnt++;
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i]<a[min_pos]){
            min_pos=i;
        }
    }
    if(cnt%2==1){
        a[min_pos]=-a[min_pos]-1;
    }
    print();
}

int main(void){
    
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    solve();
    return 0;
}
