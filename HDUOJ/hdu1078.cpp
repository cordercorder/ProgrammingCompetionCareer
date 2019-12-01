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

const int maxn=110;

int n,k;
int a[maxn][maxn];
int dp[maxn][maxn];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1}; 

void solve(){
    for(int i=0;i<=n;i++){
        for(int j=0;j<n;j++){
            dp[i][j]=0;
        }
    }
    queue<pii> q;
    q.push(pii(0,0));
    dp[0][0]=a[0][0];
    int nx,ny;
    pii now;
    int ans=0;
    while(!q.empty()){
        now=q.front();
        q.pop();
        ans=max(ans,dp[now.first][now.second]);
        for(int i=1;i<=k;i++){
            for(int j=0;j<4;j++){
                nx=now.first+dx[j]*i;
                ny=now.second+dy[j]*i;
                if(nx>=0&&nx<n&&ny>=0&&ny<n&&a[nx][ny]>a[now.first][now.second]&&dp[now.first][now.second]+a[nx][ny]>dp[nx][ny]){
                    dp[nx][ny]=dp[now.first][now.second]+a[nx][ny];
                    q.push(pii(nx,ny));
                }
            }
        }
    }
    cout<<ans<<'\n';
}

int main(void){
    FC;
    while(cin>>n>>k){
        if(n==-1&&k==-1)
            break;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];
            }
        }
        solve();
    }
    return 0;
}
