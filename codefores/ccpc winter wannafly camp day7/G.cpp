#include<bits/stdc++.h>

using namespace std;

#define FC ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define FIN freopen("in.txt","r",stdin)
#define FOUT freopen("out.txt","w",stdout)
#define deb(x) cerr<<"DEBUG------"<<'\n';cerr<<#x<<"------>";err(x)

template<typename T>
void err(T a){
    for(auto i:a){
        cerr<<i<<" ";
    }
    cerr<<'\n'<<"END OF DEBUG"<<'\n'<<'\n';
}
void err(int a){
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

int n,m;
int len[maxn];
int res[maxn][maxn];
set<int> s[maxn];
bool isv[maxn];
bool ans[maxn];

void solve(){
    int ans=10000,sum;
    for(int i=1;i<=n;i++){
        sum=0;
        memset(isv,false,sizeof(isv));
        isv[i]=true;
        for(int j=1;j<=m;j++){
            for(int k=1;k<=len[j];k++){
                if(isv[res[j][k]]){
                    for(int u=1;u<k;u++){
                        isv[res[j][u]]=true;
                    }
                }
            }
        }
        for(int j=1;j<=n;j++){
            if(isv[j]){
                sum++;
            }
        }
//        deb(sum);
        ans=min(ans,sum);
    }
    cout<<ans<<'\n';
}

int main(void){
    FC;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>len[i];
        for(int j=1;j<=len[i];j++){
            cin>>res[i][j];
        }
    }
    solve();
    return 0;
}
