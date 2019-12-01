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

int T;
int n,a[maxn];
bool isv[maxn],res[maxn];

void solve(){
    int ans=0,sum=0;
    for(int k=2;k<n;k++){
        if(a[k]>a[k-1]&&a[k]>a[k+1]){
            ans++;
            isv[k]=true;
        }
    }
    int ret=ans;
    for(int k=1;k<=n;k++){
        sum=ret;
        if(k-2>=1&&k+1<=n&&!(a[k-1]>a[k-2]&&a[k-1]>a[k+1])){
            if(isv[k-1]){
                sum--;
            }
        }
        if(k-1>=1&&k+2<=n&&!(a[k+1]>a[k-1]&&a[k+1]>a[k+2])){
            if(isv[k+1]){
                sum--;
            }
        }
        ans=min(ans,sum);
    }
    printf("%d\n",ans);
}

int main(void){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            isv[i]=false;
        }
        solve();
    }
    return 0;
}
