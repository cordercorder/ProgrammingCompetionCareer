#include<bits/stdc++.h>

using namespace std;

#define FC ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define FIN freopen("in.txt","r",stdin)
#define FOUT freopen("out.txt","w",stdout)
#define deb(x) cerr<<"DEBUG------"<<'\n';cerr<<#x<<"------>";err(x)

template<typename T>
void err(T a){
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

int main(void){
    int l=1,r=1000000,mid;
    char s[10];
    while(l<r){
        mid=(l+r)>>1;
        printf("%d\n",mid);
        fflush(stdout);
        scanf("%s",s);
        if(s[0]=='<'){
            r=mid;
        }
        else{
            l=mid+1;
        }
    }
    printf("%d\n",l);
    fflush(stdout);
    scanf("%s",s);
    if(s[0]=='<'){
        l--;
        printf("! %d\n",l);
        fflush(stdout);
    }
    else{
        printf("! %d\n",l);
        fflush(stdout);
    }
    return 0;
}
