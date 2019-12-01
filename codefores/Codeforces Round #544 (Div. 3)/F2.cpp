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

const int maxn=(int)2e5+10; 

pii E[maxn];
int cntE,cnte;
int n,m,D;
int pre[maxn];
int deg[maxn];
vector<int> id,ans;

int Find(int x){
    return pre[x]==-1?x:pre[x]=Find(pre[x]);
}

void solve(){
    if(deg[1]<D){
        puts("NO");
        return ;
    }
    for(int i=1;i<=n;i++){
        pre[i]=-1;
    }
    int u,v,nu,nv;
    for(int i=1;i<=m;i++){
        u=E[i].first;
        v=E[i].second;
        if((u!=1)&&(v!=1)){
            nu=Find(u);
            nv=Find(v);
            if(nu!=nv){
                pre[nu]=nv;
            }
        }
    }
    int sum=0;
    for(int i=1;i<=m;i++){
        u=E[i].first;
        v=E[i].second;
        if((u==1)||(v==1)){
            nu=Find(u);
            nv=Find(v);
            if(nu!=nv){
                pre[nu]=nv;
                ans.push_back(i);
                sum++;
            }
            else{
                id.push_back(i);
            }
        }
    }
    if(sum>D){
        puts("NO");
        return ;
    }
    for(int i=0;i<D-sum;i++){
        ans.push_back(id[i]);
    }
    for(int i=1;i<=n;i++){
        pre[i]=-1;
    }
    for(int i=0;i<(int)ans.size();i++){
        u=E[ans[i]].first;
        v=E[ans[i]].second;
        nu=Find(u);
        nv=Find(v);
        pre[nu]=nv;
    }
    for(int i=1;i<=m;i++){
        u=E[i].first;
        v=E[i].second;
        nu=Find(u);
        nv=Find(v);
        if((u!=1)&&(v!=1)){
            if(nu!=nv){
                pre[nu]=nv;
                ans.push_back(i);
            }
        }
    }
    puts("YES");
    for(auto v:ans){
        printf("%d %d\n",E[v].first,E[v].second);
    }
}

int main(void){
    int u,v;
    scanf("%d %d %d",&n,&m,&D);
    for(int i=1;i<=m;i++){
        scanf("%d %d",&u,&v);
        E[i]=pii(u,v);
        deg[u]++;
        deg[v]++;
    }
    solve();
    return 0;
}
