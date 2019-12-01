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
void err(int a){
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

char s[500005];
int len;

void solve(){
    len=strlen(s+1);
    int l=-1,r=-1;
    int L=-1,R=-1;
    for(int i=1;i<=len;i++){
        if(s[i]=='['){
            l=i;
            break;
        }
    }
    if(l==-1){
        cout<<"-1"<<'\n';
        return ;
    }
    for(int i=len;i>=1;i--){
        if(s[i]==']'){
            r=i;
            break;
        }
    }
    if(r==-1){
        cout<<"-1"<<'\n';
        return ;
    }
    for(int i=l;i<=r;i++){
        if(s[i]==':'){
            L=i;
            break;
        }
    }
     for(int i=r;i>=l;i--){
        if(s[i]==':'){
            R=i;
            break;
        }
    }
    if(L==-1||R==-1||L==R){
        cout<<"-1"<<'\n';
        return ;
    }
    int sum=0;
    for(int i=L;i<=R;i++){
        if(s[i]=='|')
            sum++;
    }
    sum+=4;
    cout<<sum<<'\n';
}

int main(void){
    FC;
    cin>>(s+1);
    solve();
    return 0;
}
