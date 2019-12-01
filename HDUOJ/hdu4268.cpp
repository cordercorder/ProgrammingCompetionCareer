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

const int maxn=(int)1e5+10;

int T;
int n;
pii A[maxn],B[maxn];

bool cmp(const pii &a,const pii &b){
    return a.first<b.first;
}

void solve(){
    sort(A+1,A+1+n,cmp);
    sort(B+1,B+1+n,cmp);
    multiset<int> s;
    int i,j,ans=0;
    for(i=1,j=1;i<=n;i++){
        while(j<=n&&A[i].first>=B[j].first){
            s.insert(B[j].second);
            j++;
        }
        if(!s.empty()){
            multiset<int>::iterator it=s.upper_bound(A[i].second);
            if(it!=s.begin()){
                it--;
                s.erase(it);
                ans++;
            }
        }
    }
    printf("%d\n",ans);
}

int main(void){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d %d",&A[i].first,&A[i].second);
        }
        for(int i=1;i<=n;i++){
            scanf("%d %d",&B[i].first,&B[i].second);
        }
        solve();
    }
    return 0;
}
