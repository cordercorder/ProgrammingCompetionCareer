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

const int maxn=5010;

vector<pii> ret[maxn];
int n,m;
int cnt[maxn];
int index[maxn];

bool cmp(const pii &a,const pii &b){
    int len1=a.second-a.first;
    int len2=b.second-b.first;
    if(len1<0){
        len1+=n;
    }
    if(len2<0){
        len2+=n;
    }
    return len1>len2;
}

int cal(int st,int ed){
    int ans=ed-st;
    if(ans<0)
        ans+=n;
    return ans;
}

void solve(){
    int tot=0;
    for(int i=1;i<=n;i++){
        if(!ret[i].empty()){
            sort(ret[i].begin(),ret[i].end(),cmp);
            index[tot++]=i;
        }
    }
    int ans,sum;
    for(int st=1;st<=n;st++){
        ans=0;
        for(int i=0;i<tot;i++){
            sum=cal(st,index[i])+n*((int)ret[index[i]].size()-1)+cal(index[i],ret[index[i]].back().second);
            ans=max(ans,sum);
        }
        printf("%d ",ans);
    }
}

int main(void){
    int a,b;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d %d",&a,&b);
        ret[a].push_back(pii(a,b));
    }
    solve();
    return 0;
}
