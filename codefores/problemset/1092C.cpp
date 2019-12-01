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
#define FIN freopen("in.txt","r",stdin)
#define FOUT freopen("out.txt","w",stdout)

using namespace std;

const long double PI=acos(-1.0);  
const long double eps=1e-6;
const long long maxw=1e17+10;

using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>; 

/*head------[@cordercorder]*/

const int maxn=100;

int n;
string s[maxn*2];
int len,tot;
string res[2];
int ans[maxn*2];
string ret;

int handle(int pos){
    for(int i=1;i<=len;i++){
        if(ans[i]!=0)
            continue;
        if((int)s[i].length()==(int)s[pos].length()){
            return i;
        }
    }
}

bool check_pre(int pos){
    for(int i=0;i<(int)s[pos].length();i++){
        if(s[pos][i]!=ret[i])
            return false;
    }
    return true;
}

bool check_suf(int pos){
    int i=(int)ret.length()-1;
    int j=(int)s[pos].length()-1;
    while(i>=0&&j>=0){
        if(ret[i]!=s[pos][j])
            return false;
        i--;
        j--;
    }
    return true;
}

bool solve(){
    int pos;
    for(int i=1;i<=len;i++){
        if(ans[i]==0){
            if(check_pre(i)){
                ans[i]=1;
                pos=handle(i);
                if(check_suf(pos))
                    ans[pos]=-1;
                else
                    return false;
            }
            else if(check_suf(i)){
                ans[i]=-1;
                pos=handle(i);
                if(check_pre(pos)){
                    ans[pos]=1;
                }
                else
                    return false;
            }
            else
                return false;
        }
    }
//    for(int i=1;i<=len;i++){
//        cout<<ans[i];
//    }
//    cout<<endl;
    for(int i=1;i<=len;i++){
        if(ans[i]==1){
            cout<<"P";
        }
        else{
            cout<<"S";
        }
    }
    cout<<endl;
    return true;
}

int main(void){
    FC;
    cin>>n;
    len=2*n-2;
    tot=0;
    for(int i=1;i<=len;i++){
        cin>>s[i];
        if((int)s[i].length()==n-1){
            res[tot++]=s[i];
        }
    }
    for(int i=1;i<(int)res[0].length();i++){
        if(res[0][i]!=res[1][i-1]){
            swap(res[0],res[1]);
            ret+=res[0][0];
            for(int j=1;j<(int)res[0].length();j++){
                ret+=res[0][j];
            }
            ret+=res[1].back();
//            deb(ret);
            solve();
            return 0;
        }
    }
    ret+=res[0][0];
    for(int i=1;i<(int)res[0].length();i++){
        ret+=res[0][i];
    }
    ret+=res[1].back();
//    deb(ret);
    while(!solve()){
        swap(res[0],res[1]);
//        deb(ret);
        ret.clear();
        ret+=res[0][0];
        for(int i=1;i<(int)res[0].length();i++){
            ret+=res[0][i];
        }
        ret+=res[1].back();
        memset(ans,0,sizeof(ans));
//        deb(ret); 
    }
    return 0;
}
