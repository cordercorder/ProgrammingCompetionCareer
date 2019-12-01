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

const int maxn=1010;

pii a[maxn];
int n,T;
map<int,bool> isv;

bool cmp(const pii &a,const pii &b){
    return a.second>b.second;
}

void solve(){
    int ans=0;
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++){
        int j;
        for(j=a[i].first;j>=1;j--){
            if(!isv[j]){
                isv[j]=true;
                break;
            }
        }
        if(j==0){
            ans+=a[i].second;
        }
    }
    isv.clear();
    printf("%d\n",ans);
}

int main(void){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i].first);
        }
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i].second);
        }
        solve();
    }
    return 0;
}
