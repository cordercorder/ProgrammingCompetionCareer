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

const int maxn=(int)1e5+10;

int n;
int num[30];
char s[maxn];
char ans[maxn];

int cal(int l,int r){
    string s1,s2;
    int sum=0;
    for(int i=l;i<=r;i++){
        for(int j=i;j<=r;j++){
            s1.clear();
            for(int k=i;k<=j;k++){
                s1+=ans[k];
            }
            s2=s1;
            reverse(s2.begin(),s2.end());
            if(s1==s2){
                sum++;
                cerr<<"s===="<<s1<<endl;
            }
        }
    }
    return sum;
}

void solve(){
    for(int i=1;i<=n;i++){
        num[(int)(s[i]-'a')]++;
    }
    int cnt=0;
    for(int i=0;i<26;i++){
        if(num[i]>0){
            for(int j=0;j<num[i];j++){
                ans[++cnt]=(char)(i+'a');
            }
        }
    }
    ans[cnt+1]='\n';
    cout<<ans+1<<'\n';
//    cerr<<cal(1,cnt);
}

int main(void){
    FC;
    cin>>n;
    cin>>(s+1);
    solve();
    return 0;
}
