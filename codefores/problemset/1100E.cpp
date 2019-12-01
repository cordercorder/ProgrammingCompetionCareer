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
using pii=pair<pair<int,int>,int>; 

/*head------[@cordercorder]*/

const int maxn=(int)1e5+10;

struct node{
    int to;
    int w;
};
vector<node> e[maxn],e_tmp[maxn];
pii res[maxn];
int n,m;
int in[maxn];
vector<int> index;
int ret[maxn];

bool check(int x){
    for(int i=1;i<=n;i++){
        in[i]=0;
        if(!e_tmp[i].empty()){
            e_tmp[i].clear();
        }
    }
    index.clear();
    for(int i=0;i<m;i++){
        if(res[i].second>x){
            e_tmp[res[i].first.first].push_back({res[i].first.second,res[i].second});
            in[res[i].first.second]++;
        }
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(in[i]==0){
            q.push(i);
            index.push_back(i);
        }
    }
    int sum=0;
    int now;
    while(!q.empty()){
        now=q.front();
        q.pop();
        sum++;
        for(int i=0;i<(int)e_tmp[now].size();i++){
            in[e_tmp[now][i].to]--;
            if(in[e_tmp[now][i].to]==0){
                q.push(e_tmp[now][i].to);
                index.push_back(e_tmp[now][i].to);
            }
        }
    }
    return sum==n;
}

void solve(){
    int l=0,r=(int)1e9+1,mid;
    while(l<r){
        mid=(l+r)>>1;
        if(check(mid)){
            r=mid;
        }
        else{
            l=mid+1;
        }
    }
    check(l);
    for(int i=0;i<(int)index.size();i++){
        ret[index[i]]=i+1;
    }
//    deb(index);
    vector<int> ans;
    for(int i=0;i<m;i++){
        if(ret[res[i].first.first]>ret[res[i].first.second]){
            ans.push_back(i+1);
        }
    }
    cout<<l<<" "<<(int)ans.size()<<'\n';
    for(auto i:ans){
        cout<<i<<" ";
    }
}

int main(void){
    FC;
    cin>>n>>m;
    int u,v,w;
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        res[i]=pii(pair<int,int>(u,v),w);
        e[u].push_back({v,w});
    }
    solve();
    return 0;
}
