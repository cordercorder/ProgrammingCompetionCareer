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

const int maxn=(int)2e5+10;

int n,k;
string s;

void solve(){
    int sum=0,ans=0,ret;
    for(char ch='a';ch<='z';ch++){
        ret=0;
        for(int i=0;i<n;){
            int j=i;
            sum=0;
            bool f=false;
            while(j<n&&s[j]==ch){
                sum++;
                j++;
                f=true;
                if(sum==k){
                    ret++;
                    break;
                }
            }
            if(f){
                i=j;
            }
            else{
                i=j+1;
            }
        }
        ans=max(ans,ret);
    }
    cout<<ans<<'\n';
}

int main(void){
    FC;
    cin>>n>>k;
    cin>>s;
    solve();
    return 0;
}
