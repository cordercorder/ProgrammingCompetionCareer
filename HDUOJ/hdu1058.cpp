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

ll n;
ll a[4]={2,3,5,7};
map<ll,bool> mp;
vector<ll> ans;

void dfs(ll ret){
    ll tmp;
    for(int i=0;i<4;i++){
        tmp=ret*a[i];
        if(tmp<=2000000000ll&&mp.count(tmp)==0){
            mp[tmp]=true;
            dfs(tmp);
        }
    }
}


int main(void){
    dfs(1ll);
    ans.push_back(1ll);
    for(auto x:mp){
        ans.push_back(x.first);
    }
    while(scanf("%lld",&n)!=EOF){
        if(n==0)
            break;
        if(n%10ll==1&&n%100ll!=11ll){
            printf("The %lldst humble number is %lld.\n",n,ans[n-1]);
        }
        else if(n%10ll==2&&n%100ll!=12ll){
            printf("The %lldnd humble number is %lld.\n",n,ans[n-1]);
        }
        else if(n%10ll==3&&n%100ll!=13ll){
            printf("The %lldrd humble number is %lld.\n",n,ans[n-1]);
        }
        else{
            printf("The %lldth humble number is %lld.\n",n,ans[n-1]);
        }
    }
    return 0;
}
