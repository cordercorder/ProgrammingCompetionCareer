#include<bits/stdc++.h>
#include<stdint.h>

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

pii a[maxn];
int n,q;
int cnt[maxn],tag[maxn];
int sum[maxn];


void solve(){
    int ans=0,ret,res;
    for(int i=1;i<=q;i++){
        for(ll j=1;j<=q;j++){
            if(i!=j){
                tag[a[j].first]++;
                tag[a[j].second+1]--;
            }
        }
        for(int j=1;j<=n;j++){
            cnt[j]=cnt[j-1]+tag[j];
            sum[j]=0;
            tag[j]=0;
        }
        for(int j=1;j<=n;j++){
            if(cnt[j]==1){
                sum[j]=sum[j-1]+1;
            }
            else{
                sum[j]=sum[j-1];
            }
        }
        ret=(int)1e6;
        for(int j=1;j<=q;j++){
            if(i!=j){
                ret=min(ret,sum[a[j].second]-sum[a[j].first-1]);
            }
        }
        res=0;
        for(int j=1;j<=n;j++){
            if(cnt[j]>0){
                res++;
            }
        }
        ans=max(ans,res-ret);
    }
    printf("%d\n",ans);
}


int main(void){
    scanf("%d %d",&n,&q);
    for(int i=1;i<=q;i++){
        scanf("%d %d",&a[i].first,&a[i].second);
    }
    solve();
    return 0;
}
