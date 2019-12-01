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

#define deb(x) cout<<"#---"<<#x<<"=="<<x<<endl
#define FC ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define FIN freopen("1.in","r",stdin)
#define FOUT freopen("duipai1.out","w",stdout)

using namespace std;

const long double PI=acos(-1.0);  
const long double eps=1e-6;
const long long maxw=1e17+10;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const int maxn=1555;

int n,m;
int a[maxn],tmp[maxn],b[maxn];
int ans;

void handle(int l,int r){
    reverse(b+l,b+r+1);
}

void Union(int st1,int ed1,int st2,int ed2){
    int i=st1,j=st2,cnt=st1;
    while(i<=ed1&&j<=ed2){
        if(b[i]<=b[j]){
            tmp[cnt++]=b[i++]; 
        }
        else{
            ans+=(ed1-i+1);
            tmp[cnt++]=b[j++];
        }
    }
    while(i<=ed1){
        tmp[cnt++]=b[i++];
    }
    while(j<=ed2){
        tmp[cnt++]=b[j++];
    }
    for(int k=st1;k<=ed2;k++){
        b[k]=tmp[k];
    }
}

void solve(int l,int r){
    int mid;
    if(l<r){
        mid=(l+r)>>1;
        solve(l,mid);
        solve(mid+1,r);
        Union(l,mid,mid+1,r);
    }
}

int main(void){
    int l,r;
    bool f;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&b[i]);
    }
    scanf("%d",&m);
    solve(1,n);
    if(ans%2==1){
        f=true;
    }
    else{
        f=false;
    }
    while(m--){
        scanf("%d %d",&l,&r);
        int len=r-l+1;
        if(len*(len-1)/2%2==1){
            f=!f;
        }
        if(f){
            puts("odd");
        }
        else{
            puts("even");
        }
    }
    return 0;
}
