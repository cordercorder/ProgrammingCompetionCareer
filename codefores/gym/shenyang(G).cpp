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
void err(long long a){
    cerr<<a<<'\n';
    cerr<<"END OF DEBUG"<<'\n'<<'\n';
}

const long double PI=acos(-1.0);  
const long double eps=1e-6;
const long long maxw=(long long)1e17+(long long)10;

using ll=long long;
using ull=unsigned long long;
using pii=pair<ll,ll>; 

/*head------[@cordercorder]*/

const ll maxn=(ll)1e5+10ll;

ll n,m;
ll T,lastans;
ll isv[6005][6005];
set<pii> s;
vector<pii> res[10000010];

void pre_handle(){
    ll tmp;
    for(ll i=0;i<=6000ll;i++){
        for(ll j=0;j<=6000ll;j++){
            tmp=i*i+j*j;
            if(tmp<=10000000ll){
                res[tmp].push_back(pii(i,j));
            }
        }
    }
}

void solve(ll x,ll y,ll k,ll w){
    ll nx[2],ny[2];
    set<pii> tmp;
    for(auto &i:res[k]){
        nx[0]=x-i.first;
        nx[1]=x+i.first;
        ny[0]=y-i.second;
        ny[1]=y+i.second;
        for(ll j=0;j<=1;j++){
            for(ll u=0;u<=1;u++){
                if(nx[j]>=1&&nx[j]<=6000&&ny[u]>=1&&ny[u]<=6000&&isv[nx[j]][ny[u]]!=0){
                    tmp.insert(pii(nx[j],ny[u]));
                }
            }
        }
    }
    for(auto &i:tmp){
        isv[i.first][i.second]+=w;
    }
}

ll solve(ll x,ll y,ll k){
    ll nx[2],ny[2];
    ll ans=0ll;
    set<pii> tmp;
    for(auto &i:res[k]){
        nx[0]=x-i.first;
        nx[1]=x+i.first;
        ny[0]=y-i.second;
        ny[1]=y+i.second;
        for(ll j=0;j<=1;j++){
            for(ll u=0;u<=1;u++){
                if(nx[j]>=1&&nx[j]<=6000&&ny[u]>=1&&ny[u]<=6000&&isv[nx[j]][ny[u]]!=0){
                    tmp.insert(pii(nx[j],ny[u]));
                }
            }
        }
    }
    for(auto &i:tmp){
        ans+=isv[i.first][i.second];
    }
    return ans;
}

int main(void){
    FC;
    cin>>T;
    ll x,y,w,tmp,k;
    pre_handle();
    for(ll ca=1;ca<=T;ca++){
        cin>>n>>m;
        for(ll i=1;i<=n;i++){
            cin>>x>>y>>w;
            isv[x][y]=w;
            s.insert(pii(x,y));
        }
        cout<<"Case #"<<ca<<":"<<'\n';
        lastans=0ll;
        for(ll j=1;j<=m;j++){
            cin>>tmp;
            if(tmp==1ll){
                cin>>x>>y>>w;
                x=((x+lastans)%6000ll)+1ll;
                y=((y+lastans)%6000ll)+1ll;
                s.insert(pii(x,y));
                isv[x][y]=w;
            }
            else if(tmp==2ll){
                cin>>x>>y;
                x=((x+lastans)%6000ll)+1ll;
                y=((y+lastans)%6000ll)+1ll;
                s.erase(pii(x,y));
                isv[x][y]=0ll;
            }
            else if(tmp==3ll){
                cin>>x>>y>>k>>w;
                x=((x+lastans)%6000ll)+1ll;
                y=((y+lastans)%6000ll)+1ll;
                solve(x,y,k,w);
            }
            else{
                cin>>x>>y>>k;
                x=((x+lastans)%6000ll)+1ll;
                y=((y+lastans)%6000ll)+1ll; 
                lastans=solve(x,y,k);
                cout<<lastans<<'\n';
            }
        }
        for(auto &i:s){
            isv[i.first][i.second]=0ll;
        }
        s.clear();
    }
    return 0;
}
