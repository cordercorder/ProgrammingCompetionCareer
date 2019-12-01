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

ll x,y;
char s[50];
char tmp[10];

void solve(){
    printf("? %lld %lld\n",0ll,1ll);
    fflush(stdout);
    scanf("%s",tmp);
    if(tmp[0]=='x'){
        printf("! %lld\n",1ll);
        fflush(stdout);
        return ;
    }
    ll ret=1ll;
    while(ret<(ll)1e9){
        printf("? %lld %lld\n",ret,ret*2ll);
        fflush(stdout);
        scanf("%s",tmp);
        if(tmp[0]=='x')
            break;
        ret<<=1ll;
    }
    ll l=ret,r=ret*2ll,mid;
    while(l<r){
        mid=(l+r+1ll)>>1;
        printf("? %lld %lld\n",l,mid);
        fflush(stdout);
        scanf("%s",tmp);
        if(tmp[0]=='x'){
            r=mid-1ll;
        }
        else{
            l=mid;
        }
    }
    printf("! %lld\n",l+1ll);
    fflush(stdout);
}

int main(void){
    while(scanf("%s",s)){
        if(s[0]=='s'){
            solve();
        }
        else if(s[0]=='m'){
            break;
        }
        else if(s[0]=='e'){
            break;
        }
    }
    return 0;
}
