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

int a[maxn];
int n,k;
int st[110],ed[110],ret[110];
bool isv[110];
bool res[maxn];


void solve(){
    int l=1,d=0,sum=0;
    int ans=0;
    for(int t=0;sum<n;t++){
        for(int i=1;i<=k;i++){
            if(!isv[i]&&l<=n){
                st[i]=t;
                ed[i]=a[l]+t;
                ret[i]=l;
                isv[i]=true;
                l++;
            }
            else if(t==ed[i]){
                sum++;
                d=(int)((double)(100)*sum/n+(double)0.5);
                isv[i]=false;
            }
        }
        for(int i=1;i<=k;i++){
            if(!isv[i]&&l<=n){
                st[i]=t;
                ed[i]=a[l]+t;
                ret[i]=l;
                isv[i]=true;
                l++;
            }
        }
        for(int i=1;i<=k;i++){
            if(isv[i]){
                if((t-st[i]+1)==d){
                    res[ret[i]]=true;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(res[i]){
            ans++;
        }
    }
    printf("%d\n",ans);
}

int main(void){
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    solve();
    return 0;
}
