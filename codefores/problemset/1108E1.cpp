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

const int maxn=3e2+10;

int a[maxn],sum[maxn],b[maxn];
int n,m; 
pii seg[maxn];
int Min;
vector<int> index;

int cal(int pos){
    sum[0]=0;
    for(int i=1;i<=n;i++){
        sum[i]=0;
        b[i]=a[i];
    }
    int ans=0,tmp;
    for(int i=1;i<=m;i++){
        if(seg[i].first<=pos&&seg[i].second>=pos){
            sum[seg[i].first]--;
            sum[seg[i].second+1]++;
            index.push_back(i);
        }
    }
    for(int i=1;i<=n;i++){
        sum[i]+=sum[i-1];
        b[i]+=sum[i];
    }
    ans=*max_element(b+1,b+1+n)-*min_element(b+1,b+1+n);
    index.clear();
    return ans;
}

void solve(){
    int ans=-1,tmp,pos;
    for(int i=1;i<=n;i++){
        tmp=cal(i);
        if(tmp>ans){
            ans=tmp;
            pos=i;
        }
    }
//    deb(pos);
    for(int i=1;i<=m;i++){
        if(seg[i].first<=pos&&seg[i].second>=pos){
            index.push_back(i);
        }
    }
    cout<<ans<<'\n';
    cout<<(int)index.size()<<'\n';
    for(auto &i:index){
        cout<<i<<" ";
    }
    cout<<'\n';
}

int main(void){
    FC;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>seg[i].first>>seg[i].second;
    }
    solve();
    return 0;
}
