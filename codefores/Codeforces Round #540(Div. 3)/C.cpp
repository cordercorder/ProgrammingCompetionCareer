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

const int maxn=25;

int a[maxn][maxn];
int cnt[1005];

int n;
bool cmp(const int &a,const int &b){
    return cnt[a]<cnt[b];
}

int cal(int lim){
    vector<int> index;
    for(int i=1;i<=1000;i++){
        if(cnt[i]>=lim){
            index.push_back(i);
        }
    }
    if(index.empty()){
        return 0;
    }
    sort(index.begin(),index.end(),cmp);
    return index[0];
}

void print(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j==1){
                printf("%d",a[i][j]);
            }
            else{
                printf(" %d",a[i][j]);
            }
        }
        printf("\n");
    }
}

void solve(){
    int num;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j]==0&&a[i][n-j+1]==0&&a[n-i+1][j]==0&&a[n-i+1][n-j+1]==0){
                if(i==n-i+1){
                    if(j==n-j+1){
                        num=cal(1);
                        if(num==0){
                            puts("NO");
                            return ;
                        }
                        a[i][j]=num;
                        cnt[num]--;
                    }
                    else{
                        num=cal(2);
                        if(num==0){
                            puts("NO");
                            return ;
                        }
                        a[i][j]=num;
                        a[i][n-j+1]=num;
                        cnt[num]-=2;
                    }
                }
                else if(j==n-j+1){
                    if(i==n-i+1){
                        num=cal(1);
                        if(num==0){
                            puts("NO");
                            return ;
                        }
                        a[i][j]=num;
                        cnt[num]--;
                    }
                    else{
                        num=cal(2);
                        if(num==0){
                            puts("NO");
                            return ;
                        }
                        a[i][j]=num;
                        a[n-i+1][j]=num;
                        cnt[num]-=2;
                    }
                }
                else{
                    num=cal(4);
                    if(num==0){
                        puts("NO");
                        return ;
                    }
                    a[i][j]=num;
                    a[i][n-j+1]=num;
                    a[n-i+1][j]=num;
                    a[n-i+1][n-j+1]=num;
                    cnt[num]-=4;
                }
            }
        }
    }
    puts("YES");
    print();
}

int main(void){
    scanf("%d",&n);
    int len=n*n,tmp;
    for(int i=1;i<=len;i++){
        scanf("%d",&tmp);
        cnt[tmp]++;
    }
    solve();
    return 0;
}
