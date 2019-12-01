#include<bits/stdc++.h>
 
using namespace std;
 
#define FC ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
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

const int maxn=(int)1e5+10;

int q,n;
int f[maxn][5];
pii res[maxn];
int x[maxn][2],y[maxn][2];

void solve(){
    int x0,y0,xx,yy;
    for(int i=1;i<=n;i++){
        x[i][0]=-(int)1e5;
        y[i][0]=-(int)1e5;
        x[i][1]=(int)1e5;
        y[i][1]=(int)1e5;
        for(int j=1;j<=4;j++){
            if(f[i][j]==0){
                if(j==1){
                    x[i][1]=res[i].first;
                }
                else if(j==2){
                    y[i][0]=res[i].second;
                }
                else if(j==3){
                    x[i][0]=res[i].first;
                }
                else{
                    y[i][1]=res[i].second;
                }
            }
        }
    }
    x0=x[1][0];
    y0=y[1][0];
    xx=x[1][1];
    yy=y[1][1];
    for(int i=2;i<=n;i++){
        if(x[i][0]>=x0&&x[i][0]<=xx){
            y0=min()
            
        }
        else if(x[i][1]>=x0&&x[i][1]<=xx){
            
        }
        else{
            puts("0");
            return ;
        }
    }
    
}

int main(void){
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d %d",&res[i].first,&res[i].second);
            for(int j=1;j<=4;j++){
                scanf("%d",f[i][j]);
            }
        }
        
    }
    
    return 0;
}
