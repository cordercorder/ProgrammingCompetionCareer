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

int n,m,k;
int p[maxn];
vector<int> res[maxn];
int c[maxn];
bool isv[maxn];

bool cmp(const int &a,const int &b){
    return p[a]>p[b];
}

void solve(){
    for(int i=1;i<=m;i++){
        sort(res[i].begin(),res[i].end(),cmp);
    }
    for(int i=1;i<=m;i++){
        isv[res[i][0]]=true;
    }
    int ans=0;
    for(int i=1;i<=k;i++){
        if(!isv[c[i]]){
            ans++;
        }
    }
    printf("%d\n",ans);
}

int main(void){
    int s;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&p[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&s);
        res[s].push_back(i); 
    }
    for(int i=1;i<=k;i++){
        scanf("%d",&c[i]);
    }
    solve();
    return 0;
}
