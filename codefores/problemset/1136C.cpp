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

const int maxn=510;

int a[maxn][maxn],b[maxn][maxn];
int n,m;
bool isv[maxn][maxn];

bool check(int x,int y){
    int nx=x,ny=y;
    while(nx>=1&&ny<=m){
        if(a[x][y]==b[nx][ny]&&!isv[nx][ny]){
            isv[nx][ny]=true;
            return true;
        }
        nx--;
        ny++;
    }
    nx=x;
    ny=y;
    while(nx<=n&&ny>=1){
        if(a[x][y]==b[nx][ny]&&!isv[nx][ny]){
            isv[nx][ny]=true;
            return true;
        }
        nx++;
        ny--;
    }
    return false;
}

void solve(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(!check(i,j)){
                puts("NO");
                return ;
            }
        }
    }
    puts("YES");
}

int main(void){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&b[i][j]);
        }
    }
    solve();
    return 0;
}
