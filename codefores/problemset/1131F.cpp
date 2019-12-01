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

const int maxn=150010;

list<int> ans[maxn];
int pre[maxn],n;

int Find(int x){
    return pre[x]==-1?x:pre[x]=Find(pre[x]);
}

void handle(int u,int v){
    int nu=Find(u);
    int nv=Find(v);
    if((int)ans[nu].size()<(int)ans[nv].size()){
        swap(nu,nv);
    }
    for(auto x:ans[nv]){
        ans[nu].push_back(x);
    }
    ans[nv].clear();
    pre[nv]=nu;
}

int main(void){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        pre[i]=-1;
        ans[i].push_back(i);
    }
    int u,v;
    for(int i=1;i<n;i++){
        scanf("%d %d",&u,&v);
        handle(u,v);
    }
    int index=Find(1);
    for(auto x:ans[index]){
        printf("%d ",x);
    }
    return 0;
}
