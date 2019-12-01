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

int a[maxn];
int n,k;
priority_queue<int> q;

void solve(){
    int now,cnt=0;
    while(!q.empty()&&cnt<k){
        now=q.top();
        q.pop();
        cnt++;
        now>>=1;
        if(now>0){
            q.push(now);
        }
    }
    ll sum=0;
    while(!q.empty()){
        now=q.top();
        q.pop();
        sum+=(ll)now;
    }
    cout<<sum<<'\n';
}

int main(void){
    FC;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        q.push(a[i]);
    }
    solve();
    return 0;
}
