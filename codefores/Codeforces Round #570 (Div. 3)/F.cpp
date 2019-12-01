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

char s[maxn];
ll n,k;

void solve(){
    vector<vector<int>> lst(n,vector<int>(26,-1));
    vector<vector<int>> dp(n,vector<int>(26,-1)); 
    for(int i=0;i<n;i++){
        for(int j=0;j<26;j++){
            if(i>0){
                lst[i][j]=lst[i-1][j];
            }
            
        }
        lst[i][s[i]-'a']=i;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<26;j++){
            printf("%d ",lst[i][j]);
        }
        puts("");
    }
    puts("");
    for(int i=0;i<n;i++){
        for(int j=0;j<26;j++){
            if((int)(s[i]-'a')==j){
                dp[i][j]=i;
            }
            else{
                if(i>0)
                    dp[i][j]=dp[i-1][j];f
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<26;j++){
            printf("%d ",dp[i][j]);
        }
        puts("");
    }
    puts("");
    
}

int main(void){
    scanf("%lld %lld",&n,&k);
    scanf("%s",s);
    solve();
    
    
        
    return 0;
}
