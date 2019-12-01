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

string s;
stack<char> sta;

void solve(){
    int sum=0;
    for(int i=0;i<(int)s.length();i++){
        if(!sta.empty()&&sta.top()==s[i]){
            sta.pop();
            sum++;
        }
        else{
            sta.push(s[i]);
        }
    }
//    deb(sum);
    if(sum&1){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
}

int main(void){
    FC;
    cin>>s;
    solve();
    return 0;
}
