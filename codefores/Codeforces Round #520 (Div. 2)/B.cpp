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

const int maxn=1e6+10;

bool f[1010];
vector<int> pri;
int n;
vector<int> res;

void pre_handle(int x){
    for(int i=2;i<=x;i++){
        if(f[i]==false){
            pri.push_back((int)i);
            for(int j=i*i;j<=x;j+=i){
                f[j]=true;
            }
        }
    }
}

void solve(){
    int tmp=n;
    int sum=0,Max=0,Min=35;
    for(int i=0;i<(int)pri.size()&&(ll)pri[i]*pri[i]<=(ll)tmp;i++){
        sum=0;
        if(tmp%pri[i]==0){
            res.push_back(pri[i]);
            while(tmp%pri[i]==0){
                tmp/=pri[i];
                sum++;
            }
            Max=max(Max,sum);
            Min=min(Min,sum);
        }
        if(tmp==1)
            break;
    }
    if(tmp!=1){
        Max=max(Max,1);
        Min=min(Min,1);
        res.push_back(tmp);
    }
    ll ans1=1,ans2=0;
    for(int i=0;i<(int)res.size();i++){
        ans1=ans1*(ll)res[i];
    }
    ll res=1;
    while(res<Max){
        ans2++;
        res*=2LL;
    }
    if(res!=Max||Max!=Min){
        ans2++;
    }
    cout<<ans1<<" "<<ans2<<endl;
}

int main(void){
    pre_handle(1001);
    FC;
    cin>>n;
    if(n==1){
        puts("1 0");
        return 0;
    }
    solve();
	return 0;
}
