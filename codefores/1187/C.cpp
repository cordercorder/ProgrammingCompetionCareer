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

int n,m;
int a[maxn];
vector<pii> p[2];
bool isv1[maxn],isv2[maxn];
int ans[maxn],f[maxn];

void print(){
    puts("YES"); 
    for(int i=1;i<=n;i++){
        if(i>1){
            printf(" ");
        }
        printf("%d",ans[i]);
    }
}

void solve(){
    for(int i=0;i<(int)p[0].size();i++){
        for(int j=p[0][i].first;j+1<=p[0][i].second;j++){
            f[j]=-1;
        }
    }
    for(int i=0;i<(int)p[1].size();i++){
        for(int j=p[1][i].first;j+1<=p[1][i].second;j++){
            f[j]=0;
        }
    }
    int sum=f[1],mine=0; 
    ans[1]=0;
    for(int i=2;i<=n;i++){
        ans[i]=sum;
        mine=min(mine,ans[i]);
        sum+=f[i];
    }
    mine=-mine+1;
    for(int i=1;i<=n;i++){
        ans[i]+=mine;
    }
    bool f;
    for(int i=0;i<(int)p[0].size();i++){
        f=false;
        for(int j=p[0][i].first;j+1<=p[0][i].second;j++){
            if(ans[j]>ans[j+1]){
                f=true;
                break;
            }
        }
        if(!f){
            puts("NO");
            return ;
        }
    }
    print();
}

int main(void){
    int t,l,r;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&t,&l,&r);
        p[t].push_back(pii(l,r));
    }
    solve();    
    return 0;
}
