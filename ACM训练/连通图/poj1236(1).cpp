#include<algorithm>
#include<iostream>
#include<limits.h>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<string>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<queue>
#include<stack>
#include<deque>
#include<ctime>
#include<set>
#include<map>

#define deb(x) cout<<"#---"<<#x<<"=="<<x<<endl
#define FC ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define FIN freopen("in.txt","r",stdin)
#define FOUT freopen("A.txt","w",stdout)

using namespace std;

const long double PI=acos(-1.0);  
const long double eps=1e-6;
const long long maxw=1e17+10;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const int maxn=1e2+10;

int n;
vector<int> e[maxn];
int low[maxn],dfn[maxn],belong[maxn];
bool isv[maxn];
int cnt,tot;
stack<int> sta; 
int in[maxn],out[maxn];

void Tarjan(int u){
    int v;
    low[u]=dfn[u]=++cnt;
    isv[u]=true;
    sta.push(u);
    for(int i=0;i<(int)e[u].size();i++){
        v=e[u][i];
        if(!dfn[v]){
            Tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(isv[v]){
            low[u]=min(low[u],dfn[v]);
        }
    }
    if(low[u]==dfn[u]){
        tot++;
        while(1){
            v=sta.top();
            isv[v]=false;
            sta.pop();
            belong[v]=tot;
            if(v==u)
                break;
        }
    }
}

void solve(){
    memset(dfn,0,sizeof(dfn));
    memset(isv,false,sizeof(isv));
    memset(in,0,sizeof(in));
    memset(out,0,sizeof(out));
    cnt=0;
    tot=0;
    for(int i=1;i<=n;i++){
        if(!dfn[i]){
            Tarjan(i);
        }
    }
    if(tot==1){
        puts("1");
        puts("0");
        return ;
    }
    int v;
    for(int i=1;i<=n;i++){
        for(int j=0;j<(int)e[i].size();j++){
            v=e[i][j];
            if(belong[v]!=belong[i]){
                in[belong[v]]++;
                out[belong[i]]++;
            }
        }
    }
    int sum1=0,sum2=0;
    for(int i=1;i<=tot;i++){
        if(in[i]==0){
            sum1++;
        }
        if(out[i]==0){
            sum2++;
        }
    }
    printf("%d\n%d\n",sum1,max(sum1,sum2));
}

int main(void){
    int u;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        while(scanf("%d",&u)){
            if(u==0)
                break;
            e[i].push_back(u);
        }
    }
    solve();
	return 0;
}
