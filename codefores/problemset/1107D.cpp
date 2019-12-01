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

const int maxn=5500;

int a[maxn][maxn],sum[maxn][maxn];
int n;
char s[maxn/4];
int len;
vector<int> fac;

int cal(char ch){
    if((ch>='0'&&ch<='9'))
        return (int)(ch-'0');
    else
        return (int)(ch-'A')+10;
}

void handle(int id){
    int cnt=0,num,sum;
    for(int i=1;i<=len;i++){
        num=cal(s[i]);
        sum=0;
        while(num){
            sum++;
            a[id][++cnt]=num%2;
            num>>=1;
        }
        while(sum<4){
            a[id][++cnt]=0;
            sum++;
        }
        reverse(a[id]+cnt-3,a[id]+cnt+1);
    }
}

void get_fac(int x){
    for(int i=1;i*i<=x;i++){
        if(x%i==0){
            fac.push_back(i);
            if(i!=x/i){
                fac.push_back(x/i);
            }
        }
    }
    sort(fac.begin(),fac.end());
}

bool check(int x){
    for(int i=1;i<=n-x+1;i+=x){
        for(int j=1;j<=n-x+1;j+=x){
            int L=i+x-1,R=j+x-1;
            int tmp=sum[L][R]-sum[L][j-1]-sum[i-1][R]+sum[i-1][j-1];
            if(tmp==0||tmp==x*x)
                continue;
            else
                return false;   
        }
    }
    return true;
}

void solve(){
    get_fac(n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            sum[i][j]=sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]+a[i][j];
        }
    }
    for(int i=(int)fac.size()-1;i>=0;i--){
        int x=fac[i];
        if(check(x)){
            cout<<x<<'\n';
            return ;
        }
    }
}

int main(void){
    FC;
    cin>>n;
    len=n/4;
    for(int i=1;i<=n;i++){
        cin>>(s+1);
        handle(i);
    }
    solve();
    return 0;
}
