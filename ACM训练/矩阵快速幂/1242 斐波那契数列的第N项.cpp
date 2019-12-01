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

ll n;
const ll mod=1e9+9;

struct Matrix{
    ll m[2][2];
    Matrix(ll a,ll b,ll c,ll d){
        m[0][0]=a;
        m[0][1]=b;
        m[1][0]=c;
        m[1][1]=d;
    }
    Matrix(){} 
};

Matrix mul(Matrix a,Matrix b){
    Matrix ans(0,0,0,0);
    for(ll i=0;i<2;i++){
        for(ll j=0;j<2;j++){
            for(ll k=0;k<2;k++){
                ans.m[i][j]=(ans.m[i][j]+a.m[i][k]*b.m[k][j])%mod;
            }
        }
    }
    return ans;
}

Matrix q_mod(Matrix a,ll b){
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
    Matrix ret(1,1,1,0);
    ret=q_mod(ret,n-1);
    cout<<ret.m[0][0]<<'\n';
}

int main(void){
    FC;
    cin>>n;
    solve();
	return 0;
}
