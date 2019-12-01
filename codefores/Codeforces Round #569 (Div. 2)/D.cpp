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

const int maxn=(int)1e6+10;

int n,m;
int Y[maxn];

void handle(int *num,int s,int ds){
    bool f=true;
    for(int i=0;i<m;i++){
        num[i+1]=s;
        if(f){
            s+=ds;
        }
        else{
            s-=ds;
        }
        f=!f;
        ds--;
    }
}

void solve(){
    int x=1;
    bool f=true;
    handle(Y,1,m-1);
    vector<pii> ans;
    int len=n/2;
    handle(Y,1,m-1);
    for(int i=0;i<len;i++){
        for(int j=1;j<=m;j++){
            if(f){
                ans.push_back(pii(x,Y[j]));
            }
            else{
                ans.push_back(pii(n-x+1,Y[j]));
            }
            f=!f;
        }
        for(int j=m;j>=1;j--){
            if(f){
                ans.push_back(pii(x,Y[j]));
            }
            else{
                ans.push_back(pii(n-x+1,Y[j]));
            }
            f=!f;
        }
        x++;
    }
    if(n%2==1){
        for(int i=1;i<=m;i++){
            ans.push_back(pii(x,Y[i]));
        }
    }
    for(pii e:ans){
        printf("%d %d\n",e.first,e.second);
    }
}

int main(void){
    scanf("%d %d",&n,&m);
    solve();
    return 0;
}
