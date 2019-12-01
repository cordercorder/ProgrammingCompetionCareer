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

char s[maxn];
int n;
int res[maxn],sum[maxn];
int T[maxn<<2];

void create(int rt,int l,int r){
    if(l==r){
        T[rt]=sum[l];
        return ;
    }
    int mid=(l+r)>>1;
    create(rt<<1,l,mid);
    create(rt<<1|1,mid+1,r);
    T[rt]=min(T[rt<<1],T[rt<<1|1]);
}

int cal(int rt,int l,int r,int L,int R){
    if(l==L&&R==r){
        return T[rt];
    }
    int mid=(l+r)>>1;
    if(R<=mid){
        return cal(rt<<1,l,mid,L,R);
    }
    else if(L>mid){
        return cal(rt<<1|1,mid+1,r,L,R);
    }
    else{
        return min(cal(rt<<1,l,mid,L,mid),cal(rt<<1|1,mid+1,r,mid+1,R));
    }
}

void solve(){
    for(int i=1;i<=n;i++){
        if(s[i]=='('){
            res[i]=1;
        }
        else{
            res[i]=-1;
        }
        sum[i]=sum[i-1]+res[i];
        if(sum[i]<-2){
            cout<<"0"<<'\n';
            return ;
        }
    }
    int ans=0;
    create(1,1,n);
    if(sum[n]==2){
        for(int i=1;i<=n;i++){
            if(res[i]==1){
                if(cal(1,1,n,i,n)==2){
                    ans++;
//                    deb(i);
                }
            }
            if(sum[i]<0)
                break;
        }
        cout<<ans<<'\n';
    }
    else if(sum[n]==-2){
        for(int i=1;i<n;i++){
            if(res[i]==-1){
                if(cal(1,1,n,i,n)==-2){
                    ans++;
//                    deb(i);
                }
            }
            if(sum[i]<0)
                break;
        }
        cout<<ans<<'\n';
    }
    else{
        cout<<"0"<<'\n';
    }
}

int main(void){
    FC;
    cin>>n;
    cin>>(s+1);
    if(n&1){
        cout<<"0"<<'\n';
        return 0;
    }
    solve();
    return 0;
}
