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

int T,cnt;
char s[110]; 
char ans[110];

bool check(int i){
    if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='y'){
        return true;
    }
    return false;
}

int main(void){
    scanf("%d",&T);
    while(T--){
        scanf("%s",s+1);
        cnt=0;
        ans[++cnt]=s[1];
        for(int i=2;s[i]!='\0';i++){
            if(!check(i)){
                ans[++cnt]=s[i];
            }
        }
        ans[cnt+1]='\0';
        puts(ans+1);
    }
    return 0;
}
