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

ll T;
ll a[4],b[4];
ll cnt[6],ans[4][4];

bool deta(ll id,ll y){
    ll ret=a[id]*a[id]-4ll*(b[id]-y);
    if(ret<0ll)
        return false;
    ll tmp=sqrt(ret);
    cnt[id]=0ll;
    if(tmp*tmp==ret){
        ll x1=-a[id]+tmp;
        ll x2=-a[id]-tmp;
        if(x1%2ll==0ll){
            x1/=2ll;
            ans[id][cnt[id]++]=x1;
        }
        if(x2%2ll==0ll){
            x2/=2ll;
            ans[id][cnt[id]++]=x2;
        }
        if(cnt[id]>0ll)
            return true;
        return false;
    }
    return false;
}

void solve(){
    for(ll i=0;i<=1000ll;i++){
        if(deta(1ll,i)){
            if(deta(2ll,i)){
                cout<<ans[1][0]<<" "<<ans[2][0]<<" "<<"1"<<'\n';
                return ;
            }
            else if(deta(3ll,i)){
                cout<<ans[1][0]<<" "<<"1"<<" "<<ans[3][0]<<'\n';
                return ;
            }
        }
        else if(deta(2ll,i)){
            if(deta(1ll,i)){
                cout<<ans[1][0]<<" "<<ans[2][0]<<" "<<"1"<<'\n';
                return ;
            }
            else if(deta(3ll,i)){
                cout<<"1"<<" "<<ans[2][0]<<" "<<ans[3][0]<<'\n';
                return ;
            }
        }
        else if(deta(3ll,i)){
            if(deta(2ll,i)){
                cout<<"1"<<" "<<ans[2][0]<<" "<<ans[3][0]<<'\n';
                return ;
            }
            else if(deta(1ll,i)){
                cout<<ans[1][0]<<" "<<"1"<<" "<<ans[3][0]<<'\n';
                return ;
            }
        }
    }
}

int main(void){
    FC;
    cin>>T;
    while(T--){
        cin>>a[1]>>b[1]>>a[2]>>b[2]>>a[3]>>b[3];
        solve();
    }
    return 0;
}
