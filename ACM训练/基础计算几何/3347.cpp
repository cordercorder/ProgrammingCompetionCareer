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
#include<list>
#include<set>
#include<map>

using namespace std;
 
#define FC ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)

const long double PI=acos(-1.0);  
const double eps=1e-8;
const long long maxw=(long long)1e17+(long long)10;

/*head------[@cordercorder]*/

const int maxn=55;
const double X=sqrt(2.0);

struct node{
    double l;
    double r;
}p[maxn];
double L[maxn];
int n;

int sign(double x){
    if(x>eps){
        return 1;
    }
    else if(x<-eps){
        return -1;
    }
    return 0;
}

void solve(){
    vector<int> ans;
    for(int i=1;i<=n;i++){
        double l=p[i].l,r=p[i].r;//初始化的值要注意 
        for(int j=1;j<i;j++){
            if(sign(L[j]-L[i])>0)
                l=max(l,p[j].r);
        }
        for(int j=i+1;j<=n;j++){
            if(sign(L[j]-L[i])>0)
                r=min(r,p[j].l);
        }
        if(sign(l-r)>=0)
            continue;
        ans.push_back(i);
    }
    for(int i=0;i<(int)ans.size();i++){
        if(i>0){
            printf(" ");
        }
        printf("%d",ans[i]);
    }
    puts("");
}

int main(void){
    while(scanf("%d",&n)!=EOF){
        if(n==0){
            break;
        }
        for(int i=1;i<=n;i++){
            scanf("%lf",&L[i]);
            if(i==1){
                p[i].l=0;
                p[i].r=L[i]*X;
            }
            else{
                p[i].l=0;
                for(int j=1;j<i;j++){
                    p[i].l=max(p[i].l,p[j].r-abs(L[j]-L[i])/X);
                }
                p[i].r=p[i].l+L[i]*X;
            }
        }
        solve();
    }
    return 0;
}
