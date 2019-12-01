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

const int maxn=(int)1e6+10; 

int n,m;
int cnt[maxn];
int dp[2][3][3][3];

void solve(){
    for(int i=1;i<=m;i++){
        memset(dp[i%2],0,sizeof(dp[i%2]));
        for(int x=0;x<3;x++){
            for(int y=0;y<3;y++){
                for(int z=0;z<3;z++){
                    if((x+y+z)<=cnt[i]){
                        for(int k=0;k<3;k++){
                            dp[i%2][x][y][z]=max(dp[i%2][x][y][z],dp[(i-1)%2][k][x][y]+z+(cnt[i]-x-y-z)/3);
                        }
                    }
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<3&&i<=cnt[m];i++){
        ans=max(ans,dp[m%2][i][0][0]);
    }
    printf("%d\n",ans);
}

int main(void){
    int a;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a);
        cnt[a]++;
    }
    solve();
    return 0;
}
