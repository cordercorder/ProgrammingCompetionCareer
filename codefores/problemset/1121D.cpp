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

const int maxn=(int)5e5+10;

int m,k,n,s;
int a[maxn],b[maxn];
int cnt[maxn],res[maxn];

void solve(){
    int tot=0,sum=0;
    vector<int> ans;
    for(int i=1;i<=500000;i++){
        if(cnt[i]){
            tot++;
        }
    }
    int l,r;
    for(l=1,r=1;l<=m;l++){
        while(r<=m&&sum<tot){
            if(cnt[a[r]]){
                res[a[r]]++;
                if(res[a[r]]==cnt[a[r]]){
                    sum++;
                }
            }
            r++;
        }
        if(sum<tot){
            puts("-1");
            return ;
        }
        int R=max(r-1,l+k-1);
        if((l-1)/k+(m-R)/k>=(n-1)&&R<=m){
            int len=R-l+1;
            for(int j=l;j<=R&&len>k;j++){
                if(cnt[a[j]]==0){
                    ans.push_back(j);
                    len--;;
                }
                else if(res[a[j]]>cnt[a[j]]){
                    res[a[j]]--;
                    ans.push_back(j);
                    len--;
                }
            }
            int num=(l-1)-(l-1)/k*k;
            for(int j=1;num>0;j++){
                ans.push_back(j);
                num--;
            }
            num=m-R-(m-R)/k*k;
            for(int j=m;num>0;j--){
                ans.push_back(j);
                num--;
            }
            if((int)ans.size()<=(m-n*k)){
                printf("%d\n",(int)ans.size());
                for(auto j:ans){
                    printf("%d ",j);
                }
                return ;
            }
            else{
                ans.clear();
            }
        }
        if(cnt[a[l]]){
            res[a[l]]--;
            if(res[a[l]]<cnt[a[l]]){
                sum--;
            }
        }
    }
    puts("-1");
}

int main(void){
    scanf("%d %d %d %d",&m,&k,&n,&s);
    for(int i=1;i<=m;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=s;i++){
        scanf("%d",&b[i]);
        cnt[b[i]]++;
    }
    solve();
    return 0;
}
