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

const int maxn=1e2+10;

int a[maxn];
int n,k;
bool b[maxn];

int handle(int x){
    int pos=x,p,sum1=0,sum2=0;
    p=pos;
    for(int i=1;i<=n;i++){
        b[i]=true;
    }
    while(p<=n&&p>=1){
        b[p]=false;
        p-=k;
    }
    p=pos;
    while(p>=1&&p<=n){
        b[p]=false;
        p+=k;
    }
    for(int i=1;i<=n;i++){
        if(b[i]){
            if(a[i]==1){
                sum1++;
            }
            else{
                sum2++;
            }
        }
    }
    return abs(sum1-sum2);
}

void solve(){
    int ans=0;
    for(int b=1;b<=n;b++){
        ans=max(handle(b),ans);
    }
    cout<<ans<<'\n';
}

int main(void){
    FC;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    solve();
    return 0;
}
