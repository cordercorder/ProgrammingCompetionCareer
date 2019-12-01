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

const int maxn=(int)1e5+10;

int ans[maxn];
int n;
pii a[maxn];
vector<int> pos;

void solve(){
    sort(a+1,a+1+n);
    int sum;
    for(int i=1;i<=n;){
        int j=i+1;
        sum=1;
        while(j<=n&&a[j].second>a[j-1].second){
            j++;
            sum++;
        }
        pos.push_back(i);
        i=j;
    }
    int cnt=0;
    for(int i=(int)pos.size()-1;i>=0;i--){
        ans[pos[i]]=++cnt;
    }
    for(int i=1;i<=n;i++){
        if(ans[i]==0){
            ans[i]=++cnt;
        }
    }
    for(int i=1;i<=n;i++){
        if(i==1){
            cout<<ans[i];
        }
        else{
            cout<<" "<<ans[i];
        }
    }
    cout<<'\n';
}

int main(void){
    FC;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].first;
        a[i].second=i;
    }
    solve();
    return 0;
}
