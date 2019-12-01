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

const int maxn=15;

int N,M; 
int p[maxn];
int V[maxn][maxn],B[maxn][maxn];
int dp[15][(1<<11)+10],nxt[(1<<11)+10][(1<<11)+10],cnt[(1<<11)+10],bonus[15][(1<<11)+10];
int res[maxn];

void handle(){
    int len=(1<<11);
    for(int i=0;i<len;i++){
        for(int j=0;j<len;j++){
            if((i&j)==j){
                nxt[i][cnt[i]++]=j;
            }
        }
    }
}

void solve(){
    int len1=(1<<N),tot;
    for(int i=1;i<=M;i++){
        for(int j=0;j<len1;j++){
            bonus[i][j]=0;
            tot=0;
            for(int k=0;k<N;k++){
                if((j>>k)&1){
                    res[++tot]=(k+1);
                    bonus[i][j]+=V[k+1][i];
                    bonus[i][j]-=p[i];
                }
            }
            for(int k=1;k<=tot;k++){
                for(int u=k+1;u<=tot;u++){
                    bonus[i][j]+=B[res[k]][res[u]];
                }
            }
        }
    }
    for(int i=1;i<=M;i++){
        for(int j=0;j<len1;j++){
            dp[i][j]=-(int)(1e9);
        }
    }
    for(int i=0;i<len1;i++){
        dp[0][i]=0;
    }
    for(int i=1;i<=M;i++){
        for(int j=0;j<len1;j++){
            for(int k=0;k<cnt[j];k++){
                dp[i][nxt[j][k]]=max(dp[i][nxt[j][k]],dp[i-1][j]+bonus[i][nxt[j][k]]);
            }
        }
    }
    int ans=0;
    for(int i=0;i<len1;i++){
        ans=max(ans,dp[M][i]);
    }
    if(ans==0){
        puts("STAY HOME");
    }
    else{
        printf("%d\n",ans);
    }
}

int main(void){
    handle();
    while(scanf("%d %d",&N,&M)){
        if(N==0&&M==0)
            break;
        for(int i=1;i<=M;i++){
            scanf("%d",&p[i]);
        }
        for(int i=1;i<=N;i++){
            for(int j=1;j<=M;j++){
                scanf("%d",&V[i][j]);
            }
        }
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                scanf("%d",&B[i][j]);
            }
        }
        solve();
    }
    return 0;
}
