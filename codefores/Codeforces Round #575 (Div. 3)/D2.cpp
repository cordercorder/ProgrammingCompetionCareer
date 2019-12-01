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

const int maxn=2e5+10;

int q;
int n,k;
char s[maxn];
char str[maxn][3];

void pre_handle(){
    str[1][0]='R';
    str[1][1]='G';
    str[1][2]='B';
    for(int i=2;i<=k;i++){
        for(int j=0;j<3;j++){
            if(str[i-1][j]=='R'){
                str[i][j]='G';
            }
            else if(str[i-1][j]=='G'){
                str[i][j]='B';
            }
            else{
                str[i][j]='R';
            }
        }
    }
}

void solve(){
    int ans=(int)1e6,sum[3]={0,0,0},sum_tmp[3];
    pre_handle();
    for(int j=0;j<3;j++){
        for(int i=1;i<=k;i++){
           if(s[i]!=str[i][j]){
               sum[j]++;
           }
        }
    }
    ans=min(sum[0],sum[1]);
    ans=min(ans,sum[2]);
    for(int i=k+1;i<=n;i++){
        for(int j=0;j<3;j++){
            sum_tmp[j]=sum[j];
        }
        for(int j=0;j<3;j++){
            sum[(j+1)%3]=sum_tmp[j]+(int)(str[k][(j+1)%3]!=s[i])-(int)(str[1][j]!=s[i-k]);
            ans=min(ans,sum[(j+1)%3]);
        }
    }
    printf("%d\n",ans);
}

int main(void){
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&k);
        scanf("%s",s+1);
        solve();
    }
    return 0;
}
