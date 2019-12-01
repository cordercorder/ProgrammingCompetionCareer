#include<bits/stdc++.h>
 
using namespace std;
 
#define FC ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define deb(x) cerr<<#x<<"------>"<<x<<endl

const long double PI=acos(-1.0);  
const long double eps=1e-6;
const long long maxw=(long long)1e17+(long long)10;

typedef long long ll;
typedef unsigned long long ull;

/*head------[@cordercorder]*/

const ll inf=(ll)2e18;

int T;
ll N;
vector<ll> rev;
map<ll,bool> isv;

void dfs(ll res){
    if(isv.find(res)!=isv.end()){
        return ;
    }
    isv[res]=true;
    if(res!=1){
        rev.push_back(res);
    }
    if(res<inf/(ll)2)
        dfs(res*(ll)2);
    if(res<inf/(ll)3)
        dfs(res*(ll)3);
    if(res<inf/(ll)5)
        dfs(res*(ll)5);
}

int main(void){
    dfs(1);
    sort(rev.begin(),rev.end());
    scanf("%d",&T);
    while(T--){
        scanf("%lld",&N);
        vector<ll>::iterator it=lower_bound(rev.begin(),rev.end(),N);
        if(it!=rev.end()){
            printf("%lld\n",(*it));
        }
    }
    return 0;
}
