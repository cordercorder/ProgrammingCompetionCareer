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

const int maxn=(int)2e5+10;

int T;
int n;
int ans[maxn];

struct node{
    int l;
    int r;
    int id;
    bool operator<(const node &a)const{
        if(l<a.l)
            return true;
        else if(l==a.l&&r<a.r)
            return true;
        return false;
    }
}res[maxn];

void solve(){
    sort(res+1,res+1+n);
    int R=0;
    for(int i=1;i<n;i++){
        R=max(R,res[i].r);
        if(R<res[i+1].l){
            for(int j=1;j<=i;j++){
                ans[res[j].id]=1;
            }
            for(int j=i+1;j<=n;j++){
                ans[res[j].id]=2;
            }
            for(int j=1;j<=n;j++){
                cout<<ans[j]<<" ";
            }
            cout<<'\n';
            return ;
        }
    }
    cout<<"-1"<<'\n';
}

int main(void){
    FC;
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>res[i].l>>res[i].r;
            res[i].id=i;
            ans[i]=0;
        }
        solve();
    }
    return 0;
}
