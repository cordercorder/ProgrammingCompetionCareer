#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;
#define lson l,(l+r)/2,rt<<1
#define rson (l+r)/2+1,r,rt<<1|1
#define dbg(x) cout<<#x<<" = "<< (x)<< endl
#define pb push_back
#define fi first
#define se second
#define ll long long
#define sz(x) (int)(x).size()
long long a[300010];
long long sum[300010];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        a[i+n]=a[i];
    }
    for(int i=1;i<=n*2;i++){
        sum[i]=sum[i-1]+a[i];
    }
    int s,f;
    cin>>s>>f;
    int d=f-s;
    long long mx=0;
    int res=0;
    for(int i=1;i<=n;i++){
        int l;
        if(i<=s){
            l=s-i+1;
        }else{
            l=s+n-i+1;
        }
        if(sum[l+d-1]-sum[l-1]>mx){
            mx=sum[l+d-1]-sum[l-1];
            res=i;
        }
    }
    cout<<res;
    return 0;
}
