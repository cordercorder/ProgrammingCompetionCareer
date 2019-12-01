#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>

using namespace std;
typedef long long ll;
const ll maxn=5e5+10;
const ll M=1e9+7;
ll n,a[maxn],ans;
int main()
{
    scanf("%lld",&n);
    for(int i=0;i<n;++i)scanf("%lld",a+i);
    ll ma=-M;
    bool f=true,f0=false;
    for(int i=0;i<n;++i){
        if(a[i]>=0)f=false;
        if(a[i]<=0)f0=true;
        ma=max(ma,a[i]);
    }
    if(f0){
        for(int i=0;i<n;++i){
            if(a[i]<0)ans-=a[i];
            else ans+=a[i];
        }
    }
    else {
        for(int i=0;i<n;++i){
            //if(f){ans=a[i];f=false;}
            if(a[i]>=0){
                ll te=0,mi=M,j;
                for(j=i;j<n&&a[j]>=0;++j){
                    te+=a[j];
                    mi=min(mi,a[j]);
                }
                ans+=te-mi*2;
                i=j-1;
            }
            else {
                ans-=a[i];
            }
        }
    }
    if(f)ans+=ma*2;
    if(n==1)ans=a[0];
    printf("%lld\n",ans);
    return 0;
}
