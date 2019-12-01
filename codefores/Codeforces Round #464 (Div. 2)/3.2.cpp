#include <cstdio>  
#include <iostream>  
#include <string.h>  
#include <string>   
#include <map>  
#include <queue>  
#include <deque>  
#include <vector>  
#include <set>  
#include <algorithm>  
#include <math.h>  
#include <cmath>  
#include <stack>  
#include <iomanip>  
#define mem0(a) memset(a,0,sizeof(a))  
#define meminf(a) memset(a,0x3f,sizeof(a))  
using namespace std;  
typedef long long ll;  
typedef long double ld;  
typedef double db;  
const int maxn=100005,inf=0x3f3f3f3f;    
const ll llinf=0x3f3f3f3f3f3f3f3f;     
const ld pi=acos(-1.0L);  
int a[maxn],sum[maxn];  
  
int main() {  
    int n,i,ans,mx,s,f;  
    scanf("%d",&n);  
    sum[0]=0;  
    for (i=1;i<=n;i++) {  
        scanf("%d",&a[i]);  
        sum[i]=sum[i-1]+a[i];  
    }  
    ans=1;mx=-1;  
    scanf("%d%d",&s,&f);  
    int l,r;  
    l=s;r=f-1;  
    for (i=1;i<=n;i++) {  
        int now=0;  
        if (l<=r) now=sum[r]-sum[l-1]; else now=sum[r]+sum[n]-sum[l-1];  
        if (now>mx) {  
            mx=now;ans=i;  
        }  
        l--;r--;  
        if (l==0) l+=n;  
        if (r==0) r+=n;  
    }  
    printf("%d\n",ans);  
    return 0;  
}  
