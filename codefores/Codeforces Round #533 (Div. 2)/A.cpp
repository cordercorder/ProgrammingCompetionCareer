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

const int maxn=1e3+10;
 
int a[maxn];
int n;

void solve(){
    int ans=(int)1e9+10,sum,x;
    for(int t=1;t<=101;t++){
        sum=0;
        for(int i=1;i<=n;i++){
            if(t-1<=a[i]&&a[i]<=t+1)
                continue;
            sum+=(min(abs(a[i]-t+1),abs(a[i]-t-1)));
        }
        if(ans>sum){
            ans=sum;
            x=t;
        }
//        cout<<"t==="<<t<<"sum=="<<sum<<endl;
    }
    cout<<x<<" "<<ans<<'\n'; 
}

int main(void){
    FC;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    } 
    solve();
    return 0;
}
