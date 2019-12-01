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

vector<int> e[maxn];
int n,m;
bool isv[maxn];
int cnt;
set<int> nonisv;

void bfs(int u){
    queue<int> q;
    q.push(u);
    isv[u]=true;
    int now;
    nonisv.erase(u);
    while(!q.empty()){
        now=q.front();
        cnt++;
        q.pop();
        for(int i=0;i+1<(int)e[now].size();){
            int j=i;
            while(j+1<(int)e[now].size()&&e[now][j]+1==e[now][j+1]){
                j++;
            }
            if(i==j){
                auto it=nonisv.lower_bound(e[now][i]+1);
                for(;it!=nonisv.end()&&(*it)<e[now][i+1];){
                    int k=(*it);
                    if(!isv[k]){
                        q.push(k);
                        isv[k]=true;
                        nonisv.erase(it++);
                    }
                    else{
                        it++;
                    }
                }
                i=j+1;
            }
            else{
                i=j;
            }
        }
    }
}

void solve(){
    vector<int> ans;
    for(int i=1;i<=n;i++){
        e[i].push_back(0);
        e[i].push_back(n+1);
        sort(e[i].begin(),e[i].end());
        nonisv.insert(i);
    }
    for(int i=1;i<=n;i++){
        if(!isv[i]){
            cnt=0;
            bfs(i);
            ans.push_back(cnt);
        }
    }
    sort(ans.begin(),ans.end());
    cout<<(int)ans.size()<<'\n';
    for(auto i:ans){
        cout<<i<<" ";
    }
}

int main(void){
    FC;
    cin>>n>>m;
    int u,v;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    solve(); 
    return 0;
}
