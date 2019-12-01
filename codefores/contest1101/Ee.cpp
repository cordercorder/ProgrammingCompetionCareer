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

int n;
int x,y;
int h,w;
int max_x,max_y;

int main(void){
    FC;
    char str[5];
    cin>>n;
    while(n--){
        cin>>str;
        if(str[0]=='+'){
            cin>>x>>y;
            if(x>y){
                swap(x,y);
            }
            max_x=max(max_x,x);
            max_y=max(max_y,y);
        }
        else{
            cin>>h>>w;
            if(h>w){
                swap(h,w);
            }
            if(h>=max_x&&w>=max_y){
                cout<<"YES"<<'\n';
            }
            else{
                cout<<"NO"<<'\n';
            }
        }
    }
    return 0;
}
