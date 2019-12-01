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

int n,k; 

void solve(){
    int x,y;
    y=n/2-1;
    if(k<=y){
        cout<<"-1"<<'\n';
    }
    else{
        x=k-y;
        cout<<x<<" "<<2*x;
        int lst=2*x;
        for(int i=2;i<n;i++){
            cout<<" "<<++lst;
        }
    }
}

int main(void){
    FC;
    cin>>n>>k;
    if(n==1){
        if(k==0){
            cout<<"1"<<'\n';
        }
        else{
            cout<<"-1"<<'\n';
        }
    }
    else{
        solve();
    }
    return 0;
}
