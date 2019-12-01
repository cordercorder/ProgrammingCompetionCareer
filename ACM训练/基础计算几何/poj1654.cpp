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

const long double PI=acos(-1.0);  
const long double eps=1e-6;
const long long maxw=(long long)1e17+(long long)10;
 
typedef long long ll;
 
/*head------[@cordercorder]*/

const ll maxn=(ll)2e6+10;

ll t;
char s[maxn];

struct node{
    ll x;
    ll y;
    node operator-(node &a){
        node ans=*this;
        ans.x-=a.x;
        ans.y-=a.y;
        return ans;
    }
};
node now,pre,o;

//p0p1 cross p0p2
ll cross(node &p0,node &p1,node &p2){
    node tmp0=(p1-p0);
    node tmp1=(p2-p0);
    return tmp0.x*tmp1.y-tmp1.x*tmp0.y;
}

int main(void){
    scanf("%lld",&t);
    while(t--){
        scanf("%s",s);
        ll ans=0;
        now.x=0;
        now.y=0;
        pre=now;
        o=now;
        for(ll i=0;s[i]!='\0';i++){
            if(s[i]=='5')
                break;
            if(s[i]=='8'){
                now.y++;
            }
            else if(s[i]=='2'){
                now.y--;
            }
            else if(s[i]=='6'){
                now.x++;
            }
            else if(s[i]=='4'){
                now.x--;
            }
            else if(s[i]=='9'){
                now.x++;
                now.y++;
            }
            else if(s[i]=='7'){
                now.x--;
                now.y++;
            }
            else if(s[i]=='3'){
                now.x++;
                now.y--;
            }
            else if(s[i]=='1'){
                now.x--;
                now.y--;
            }
            ans+=cross(o,pre,now);
            pre=now;
        }
        if(ans<0){
            ans=-ans;
        }
        if(ans%2==0){
            printf("%lld\n",ans/2);
        }
        else{
            printf("%lld",ans/2);
            printf(".5\n");
        }
    }
    return 0;
}
