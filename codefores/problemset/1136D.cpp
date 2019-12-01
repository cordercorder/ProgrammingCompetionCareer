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

const int maxn=(int)3e5+10;

int p[maxn];
int n,m;
vector<int> e[maxn];

void solve(){
    for(int i=1;i<=n;i++){
        sort(e[i].begin(),e[i].end());
    }
    int ret=n,ans=0;
    for(int i=n-1;i>=1;i--){
        int j;
        for(j=i+1;j<=ret;j++){
            if(!binary_search(e[p[i]].begin(),e[p[i]].end(),p[j]))
                break;
        }
        if(j==ret+1){
            int num=p[i];
            for(int k=i+1;k<=ret;k++){
                p[k-1]=p[k];
            }
            p[ret]=num;
            ret--;
            ans++;
        }
    }
    printf("%d\n",ans);
}

int main(void){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&p[i]);
    }
    int u,v;
    for(int i=1;i<=m;i++){
        scanf("%d %d",&u,&v);
        e[u].push_back(v);
    }
    solve();
    return 0;
}
