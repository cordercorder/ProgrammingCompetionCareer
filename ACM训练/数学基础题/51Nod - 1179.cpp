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

const int maxn=5e4+10;

int s[maxn];
int n;
int num[1000000+1000];

void handle(int x){
    for(int i=1;i*i<=x;i++){
        if(x%i==0){
            num[i]++;
            if(x/i!=i){
                num[x/i]++;
            }
        }
    }
}

int main(void){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&s[i]);
        handle(s[i]);
    }
    int ans=1;
    for(int i=1;i<=1000000;i++){
        if(num[i]>=2){
            ans=max(ans,i);
        }
    }
    printf("%d\n",ans);
	return 0;
}
