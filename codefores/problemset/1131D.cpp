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

const int maxn=1010;

char s[maxn][maxn];
int n,m;
int pre[maxn+maxn];
int in[maxn+maxn];
int ans[maxn+maxn];
vector<int> index[maxn+maxn];
bool isv[maxn+maxn];
vector<int> e[maxn+maxn];

int Find(int x){
    return pre[x]==-1?x:pre[x]=Find(pre[x]);
}

void merge(int u,int v){
    int nu=Find(u);
    int nv=Find(v);
    if(nu==nv)
        return ;
    if((int)index[nv].size()<(int)index[nu].size()){
        swap(nu,nv);
    }
    for(auto x:index[nu]){
        index[nv].push_back(x);
    }
    index[nu].clear();
    in[nv]+=in[nu];
    in[nu]=0;
    pre[nu]=nv;
}

void solve(){
    for(int i=1;i<=n+m;i++){
        index[i].push_back(i);
        pre[i]=-1;
    }
    int u,v;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i][j]=='>'){
                u=Find(i);
                v=Find(n+j);
                if(u==v){
                    puts("No");
                    return ;
                }
                e[v].push_back(u);
                in[u]++;
            }
            else if(s[i][j]=='<'){
                u=Find(i);
                v=Find(n+j);
                if(u==v){
                    puts("No");
                    return ;
                }
                e[u].push_back(v);
                in[v]++;
            }
            else{
                merge(i,n+j);
            }
        }
    }
    queue<int> q;
    int cnt=0;
    for(int i=1;i<=n+m;i++){
        if(pre[i]==-1&&in[i]==0){
            for(auto x:index[i]){
                if(!isv[x]){
                    q.push(x);
                    isv[x]=true;
                    ans[x]=1;
                }
            }
        }
    }
    while(!q.empty()){
        u=q.front();
        q.pop();
        cnt++;
        for(int i=0;i<(int)e[u].size();i++){
            v=Find(e[u][i]);
            in[v]--;
            if(in[v]==0){
                for(auto x:index[v]){
                    if(!isv[x]){
                        isv[x]=true;
                        q.push(x);
                        ans[x]=ans[u]+1;
                    }
                }
            }
        }
    }
    if(cnt!=n+m){
        puts("No");
    }
    else{
        puts("Yes");
        for(int i=1;i<=n;i++){
            printf("%d ",ans[i]);
        }
        putchar('\n');
        for(int i=n+1;i<=n+m;i++){
            printf("%d ",ans[i]);
        }
    }
}

int main(void){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%s",s[i]+1);
    }
    solve();
    return 0;
}
