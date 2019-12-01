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

const int maxn=1e4+10;

int n;
pii res[maxn];

int cal_r(const pii &a,const pii &b){
    int l,r,mid;
    int ret=min(b.first,b.second)-max(a.first,a.second)+1;
    l=0,r=ret;
    int mine=max(a.first,a.second);
    while(l<r){
        mid=(l+r)>>1;
        if((mine+mid)>=a.first&&(mine+mid)>=a.second&&(mine+mid)<=b.first&&(mine+mid)<=b.second){
            l=mid+1;
        }
        else{
            r=mid;
        }
    }
    if(!((mine+l)>=a.first&&(mine+l)>=a.second&&(mine+l)<=b.first&&(mine+l)<=b.second))
        l--;
    if(l==-1){
        return -1;
    }
    return mine+l;
}

int cal_l(const pii &a,const pii &b){
    int l,r,mid;
    int ret=min(b.first,b.second)-max(a.first,a.second)+1;
    l=0,r=ret;
    int mine=max(a.first,a.second);
    while(l<r){
        mid=(l+r)>>1;
        if((mine+mid)>=a.first&&(mine+mid)>=a.second&&(mine+mid)<=b.first&&(mine+mid)<=b.second){
            r=mid;
        }
        else{
            l=mid+1;
        }
    }
    if(l==ret)
        return -1;
    return l+mine;
}

void solve(){
    int ans=0;
    int l,r,mid,R=0;
    res[0]=pii(0,0);
    for(int i=1;i<=n;i++){
        l=cal_l(res[i-1],res[i]);
        r=cal_r(res[i-1],res[i]);
//        deb(l);
//        deb(r);
        if(l!=-1&&r!=-1&&r>=R){
            ans+=(r-max(l,R)+1);
            R=r+1;
        }
    }
    printf("%d\n",ans);
}

int main(void){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&res[i].first,&res[i].second);
    }
    solve();
    return 0;
}
