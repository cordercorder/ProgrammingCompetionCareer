#include<bits/stdc++.h>

using namespace std;

#define FC ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define FIN freopen("in.txt","r",stdin)
#define FOUT freopen("out.txt","w",stdout)
#define deb(x) cerr<<"DEBUG------"<<'\n';cerr<<#x<<"------>";err(x)

template<typename T>
void err(T a){
    for(auto i:a){
        cerr<<i<<" ";
    }
    cerr<<'\n'<<"END OF DEBUG"<<'\n'<<'\n';
}
void err(int a){
    cerr<<a<<'\n';
    cerr<<"END OF DEBUG"<<'\n'<<'\n';
}

const long double PI=acos(-1.0);  
const long double eps=1e-6;
const long long maxw=(long long)1e17+(long long)10;

using ll=long long;
using ull=unsigned long long;
using pii=pair<int,string>; 

/*head------[@cordercorder]*/

const int maxn=110;

int n;
int a[maxn];
int f[2][maxn][maxn];
int sum[maxn];

void solve(){
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    int mine,maxe,ret;
    for(int len=2;len<=n;len++){
        for(int l=1;l<=n;l++){
            int r=(l+len-2)%n+1;
            mine=(int)1e9+10;
            maxe=0;
            if(l<r){
                ret=sum[r]-sum[l-1];
            }
            else{
                ret=sum[r]+sum[n]-sum[l-1];
            }
            for(int i=l,cnt=0;cnt+1<len;i++,cnt++){
                mine=min(mine,f[0][l][(i-1)%n+1]+f[0][i%n+1][r]+ret);
                maxe=max(maxe,f[1][l][(i-1)%n+1]+f[1][i%n+1][r]+ret);
            }
            f[0][l][r]=mine;
            f[1][l][r]=maxe;
        }
    }
    mine=(int)1e9+10,maxe=0;
    for(int i=1;i<=n;i++){
        mine=min(mine,f[0][i][(i+n-2)%n+1]);
        maxe=max(maxe,f[1][i][(i+n-2)%n+1]);
    }
    cout<<mine<<" "<<maxe<<'\n';
}

int main(void){
    FC;
    while(cin>>n){
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        solve();
    }
    return 0;
}
