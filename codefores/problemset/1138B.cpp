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

const int maxn=5010; 

char c[maxn],a[maxn];
int n;
int cnt[4];
int ans[4];
vector<int> index;
bool isv[maxn];

void print(){
    int tmp[4]={ans[0],ans[1],ans[2],ans[3]};
    for(int i=1;i<=n;i++){
        if(c[i]=='0'&&a[i]=='0'){
            if(tmp[0]>0){
                index.push_back(i);
                tmp[0]--;
            }
        }
        else if(c[i]=='0'&&a[i]=='1'){
            if(tmp[1]>0){
                index.push_back(i);
                tmp[1]--;
            }
        }
        else if(c[i]=='1'&&a[i]=='0'){
            if(tmp[2]>0){
                index.push_back(i);
                tmp[2]--;
            }
        }
        else{
            if(tmp[3]>0){
                index.push_back(i);
                tmp[3]--;
            }
        }
    }
    for(auto i:index){
        printf("%d ",i);
    }
}

void solve(){
    for(int i=1;i<=n;i++){
        if(c[i]=='0'&&a[i]=='0'){
            cnt[0]++;
        }
        else if(c[i]=='0'&&a[i]=='1'){
            cnt[1]++;
        }
        else if(c[i]=='1'&&a[i]=='0'){
            cnt[2]++;
        }
        else{
            cnt[3]++;
        }
    }
    int ret;
    bool f;
    for(int i=0;i<=cnt[0];i++){
        for(int j=0;j<=cnt[3];j++){
            ret=n/2-i-j;
            if(ret<=(cnt[1]+cnt[2])&&ret==(cnt[3]+cnt[1]-2*j)){
                ans[0]=i;
                ans[3]=j;
                f=false;
                for(int k=0;k<=cnt[1];k++){
                    if(ret>=k&&ret-k<=cnt[2]){
                        ans[1]=k;
                        ans[2]=ret-k;
                        f=true;
                        break;
                    }
                }
                if(f){
                    print();
                    return ;
                }
            }
        }
    }
    puts("-1");
}

int main(void){
    scanf("%d",&n);
    scanf("%s",c+1);
    scanf("%s",a+1);
    solve();
    return 0;
}
