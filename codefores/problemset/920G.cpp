#include<bits/stdc++.h>

using namespace std;

#define FC ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define FIN freopen("in.txt","r",stdin)
#define FOUT freopen("out.txt","w",stdout)
#define deb(x) cerr<<"DEBUG------"<<'\n';cerr<<#x<<"------>";err(x)

template<typename T>
void err(T a){
    for(auto i:a){
        cerr<<i<<" ";
    }
    cerr<<'\n'<<"END OF DEBUG"<<'\n'<<'\n';
}
void err(long long a){
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

const int maxn=1100;

int t;
int x,p,k;

bool isv[maxn];
vector<int> pre,fac;

void pre_handle(){
    for(int i=2;i<=1000;i++){
        if(!isv[i]){
            pre.push_back(i);
            for(int j=i*i;j<=1000;j+=i){
                isv[j]=true;
            }
        }
    }
}

void handle(int x){
    fac.clear();
    for(int i=0;i<(ll)pre.size()&&pre[i]*pre[i]<=x;i++){
        if(x%pre[i]==0){
            fac.push_back(pre[i]);
            while(x%pre[i]==0){
                x/=pre[i];
            }
        }
        if(x==1)
            break;
    }
    if(x!=1){
        fac.push_back(x);
    }
}

int cal(int x){
    int len=(1<<(ll)fac.size());
    int ret,sum,ans=0;
    for(int i=1;i<len;i++){
        sum=0;
        ret=1;
        for(int j=0;j<(ll)fac.size();j++){
            if((i>>j)&1){
                ret*=fac[j];
                sum++;
            }
        }
        if(sum&1){
            ans+=x/ret;
        }
        else{
            ans-=x/ret;
        }
    }
    ans=x-ans;
    return ans;
}

void solve(){
    handle(p);
    int ret=cal(x)+k;
    int l=x,r=(int)1e8+1,mid;
    while(l<r){
        mid=(l+r)>>1;
        if(cal(mid)>=ret){
            r=mid;
        }
        else{
            l=mid+1;
        }
    }
    cout<<l<<'\n';
}

int main(void){
    FC;
    cin>>t;
    pre_handle();
    while(t--){
        cin>>x>>p>>k;
        solve();
    }
    return 0;
}
