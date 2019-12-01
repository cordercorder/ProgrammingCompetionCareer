#include<algorithm>
#include<iostream>
#include<limits.h>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<string>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<queue>
#include<stack>
#include<deque>
#include<ctime>
#include<set>
#include<map>

#define deb(x) cout<<"#---"<<#x<<"=="<<x<<endl
#define FC ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define FIN freopen("in.txt","r",stdin)
#define FOUT freopen("A.txt","w",stdout)

using namespace std;

const long double PI=acos(-1.0);  
const long double eps=1e-6;
const long long maxw=1e17+10;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const int mod=7;

int a,b,n;

struct Matrix{
    int m[2][2];
    Matrix(int a,int b,int c,int d){
        m[0][0]=a;
        m[0][1]=b;
        m[1][0]=c;
        m[1][1]=d;
    }
    Matrix(){}
};

Matrix mul(Matrix a,Matrix b){
    Matrix ans(0,0,0,0);
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                ans.m[i][j]=(ans.m[i][j]+a.m[i][k]*b.m[k][j])%mod;
            }
        }
    }
    return ans;
}

Matrix q_mod(Matrix a,int b){
    Matrix ans(1,0,0,1);
    while(b){
        if(b&1){
            ans=mul(ans,a);
        }
        b>>=1;
        a=mul(a,a);
    }
    return ans;
}

void solve(){
    Matrix ans(a,b,1,0);
    ans=q_mod(ans,n-2);
    ans.m[0][0]=(ans.m[0][0]+ans.m[0][1]+mod)%mod;
    cout<<ans.m[0][0]<<'\n';
}

int main(void){
    FC;
    cin>>a>>b>>n;
    if(n==1||n==2){
        cout<<"1"<<'\n';
        return 0;
    }
    solve();
	return 0;
}
