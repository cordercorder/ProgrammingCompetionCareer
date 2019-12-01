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

const int maxn=1550;

int n;
vector<int> e[maxn];
char s[1000];
int dp[maxn][2];

void cal_index(int &u,int &k){
    int len=strlen(s);
    u=0;
    k=0;
    int i;
    for(i=0;s[i]!=':';i++){
        u=u*10+(int)(s[i]-'0');
    }
    i+=2;
    for(;s[i]!=')';i++){
        k=k*10+(int)(s[i]-'0');
    }
}

void dfs(int u,int fa){
    int v;
    dp[u][0]=0;
    dp[u][1]=1;
    for(int i=0;i<(int)e[u].size();i++){
        v=e[u][i];
        if(v!=fa){
            dfs(v,u);
            dp[u][0]+=dp[v][1];
            dp[u][1]+=min(dp[v][0],dp[v][1]);
        }
    }
}

int main(void){
    while(scanf("%d",&n)!=EOF){
        int u,v,k;
        for(int i=0;i<n;i++){
            scanf("%s",s);
            cal_index(u,k);
            for(int j=0;j<k;j++){
                scanf("%d",&v);
                e[u].push_back(v);
                e[v].push_back(u);
            }
        }
        dfs(0,-1);
        printf("%d\n",min(dp[0][1],dp[0][0]));
        for(int i=0;i<n;i++){
            e[i].clear();
        }
    }
    return 0;
}
