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

int n,k;
vector<pii> ans;
int sum;

void handle(){
    for(int i=1;i<=k;i++){
        for(int j=i+1;j<=k;j++){
            ans.push_back(pii(i,j));
            sum++;
            if(sum==n)
                return ;
            ans.push_back(pii(j,i));
            sum++;
            if(sum==n)
                return ;
        }
    }
}

void solve(){
    handle();
    if(sum!=n){
        puts("NO");
    }
    else{
        puts("YES");
        for(int i=0;i<n;i++){
            printf("%d %d\n",ans[i].first,ans[i].second);
        }
    }
}

int main(void){
    scanf("%d %d",&n,&k);
    solve();
    return 0;
}
