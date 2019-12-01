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

int T;
int n,m;
vector<int> e[maxn]; 
bool isv[maxn];
int ans[maxn];
int pre[maxn];
vector<int> ls[maxn];

void pre_handle(){
    for(int i=1;i<=n;i++){
        pre[i]=-1;
        ls[i].push_back(i);
    }
}

int Find(int x){
    return pre[x]==-1?x:pre[x]=Find(pre[x]);
}

void Union(int x,int y){
    int nx=Find(x),ny=Find(y);
    if(nx!=ny){
        if((int)ls[nx].size()>(int)ls[ny].size()){
            swap(nx,ny);
        }
        for(int e:ls[nx]){
            ls[ny].push_back(e);
        }
        ls[nx].clear();
        pre[nx]=ny;
    }
}

void solve(){
    priority_queue<int,vector<int>,greater<int>> q;
    int now,cnt=0,sum=0;
    for(int i=1;i<=n;i++){
        if(pre[i]==-1){
            now=i;
            for(int e:ls[i]){
                now=min(now,e);
            }
            q.push(now);
            sum++;
            isv[now]=true;
        }
    }
    while(!q.empty()){
        now=q.top();
        ans[++cnt]=now;
        q.pop();
        for(int v:e[now]){
            if(!isv[v]){
                q.push(v);
                isv[v]=true;
            }
        }
    }
    printf("%d\n",sum);
    for(int i=1;i<=n;i++){
        if(i>1){
            printf(" ");
        }
        printf("%d",ans[i]);
    }
    puts("");
}

int main(void){
    int a,b;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&n,&m);
        pre_handle();
        for(int i=1;i<=m;i++){
            scanf("%d %d",&a,&b);
            e[a].push_back(b);
            e[b].push_back(a);
            Union(a,b);
        }
        solve();
        for(int i=1;i<=n;i++){
            if(!e[i].empty())
                e[i].clear();
            ls[i].clear();
            isv[i]=false;
        }
    }
    return 0;
}
