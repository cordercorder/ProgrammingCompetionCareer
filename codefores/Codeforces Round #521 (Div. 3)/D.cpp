#include<algorithm>
#include<iostream>
#include<limits.h>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<string>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<queue>
#include<stack>
#include<deque>
#include<ctime>
#include<set>
#include<map>
#include<list>

#define deb(x) cout<<"#---"<<#x<<"=="<<x<<endl
#define FC ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define FIN freopen("in.txt","r",stdin)
#define FOUT freopen("A.txt","w",stdout)

using namespace std;

const long double PI=acos(-1.0);  
const long double eps=1e-6;
const long long maxw=1e17+10;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const int maxn=2e5+10;

int n,k;
int s[maxn];
int num[maxn];

struct node{
    int num;
    int cnt;
};

node res[maxn];
int tot;
int ans[maxn],len;

bool cmp(const node &a,const node &b){
    return a.cnt>b.cnt;
}

bool check(int x){
    int sum=0;
    for(int i=1;i<=tot;i++){
        sum+=(res[i].cnt)/x;
    }
    return sum>=k;
}

void handle(){
    for(int i=1;i<=200000;i++){
        if(num[i]!=0){
            res[++tot].cnt=num[i];
            res[tot].num=i;
        }
    }
    sort(res+1,res+1+tot,cmp);
}

void solve(){
    handle();
    int l=1,r=n+1,mid;
    while(l<r){
        mid=(l+r)>>1;
        if(check(mid)){
            l=mid+1;
        }
        else{
            r=mid;
        }
    }
    if(check(l)==false)
        l--;
    //deb(l);
    len=0; 
    bool f=false;
    for(int i=1;i<=tot;i++){
        int tmp=res[i].cnt/l;
        for(int j=0;j<tmp;j++){
            ans[++len]=res[i].num;
            if(len==k){
                f=true;
                break;
            }
        }
        if(f)
            break;
    }
    for(int i=1;i<=k;i++){
        cout<<ans[i]<<" ";
    }
}

int main(void){
    FC;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        num[s[i]]++;
    }
    solve();
	return 0;
}
