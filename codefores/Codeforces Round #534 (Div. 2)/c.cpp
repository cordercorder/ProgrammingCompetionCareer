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
int a[6][6];

void handle(){
    int sum;
    for(int i=1;i<=4;i++){
        sum=0;
        for(int j=1;j<=4;j++){
            sum+=a[i][j];
        }
        if(sum==4){
            for(int j=1;j<=4;j++){
                a[i][j]=0;
            }
        }
    }
}

void cal1(int &x,int &y){
    for(int j=1;j<=4;j++){
        if(a[1][j]==0&&a[2][j]==0){
            a[1][j]=1;
            a[2][j]=1;
            x=1;
            y=j;
            return ;
        }
    }
}

void cal2(int &x,int &y){
    for(int i=3;i<=4;i++){
        for(int j=1;j<=3;j++){
            if(a[i][j]==0&&a[i][j+1]==0){
                a[i][j]=1;
                a[i][j+1]=1;
                x=i;
                y=j;
                return ;
            }
        }
    }
}

void solve(){
    int x,y;
    vector<pii> ans;
    for(int i=0;i<(int)s.length();i++){
        if(s[i]=='0'){
            cal1(x,y);
        }
        else{
            cal2(x,y);
        }
        handle();
        ans.push_back(pii(x,y));
    }
    for(int i=0;i<(int)ans.size();i++){
        cout<<ans[i].first<<" "<<ans[i].second<<'\n'; 
    }   
}

int main(void){
    FC;
    cin>>s;
    solve();
    return 0;
}
