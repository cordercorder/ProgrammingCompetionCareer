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
    int mine,maxe;
    for(int len=2;len<=n;len++){
        for(int l=1;l<=n-len+1;l++){
            int r=l+len-1;
            mine=(int)1e9+10;
            maxe=0;
            for(int i=l;i<r;i++){
                mine=min(mine,f[0][l][i]+f[0][i+1][r]+sum[r]-sum[l-1]);
                maxe=max(maxe,f[1][l][i]+f[1][i+1][r]+sum[r]-sum[l-1]);
            }
            f[0][l][r]=mine;
            f[1][l][r]=maxe;
        }
    }
    cout<<f[0][1][n]<<" "<<f[1][1][n]<<'\n';
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
