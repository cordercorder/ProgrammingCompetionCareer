#include<cstdio>
#include<algorithm>
using namespace std;
#define ls (rt<<1)
#define rs (rt<<1|1)
#define mid ((l+r)>>1)
 
#define maxn 222222
int ma[maxn<<2],a[maxn],m,n,k;
void up(int rt){
    ma[rt]=max(ma[ls],ma[rs]);
}
void build(int rt,int l,int r){
    if(l==r){
        ma[rt]=a[l];
        return;
    }
    build(ls,l,mid);
    build(rs,mid+1,r);
    up(rt);
}
int query(int rt,int l,int r,int L,int R){
    if(L<=l&&r<=R){
        return ma[rt];
    }
    int ans=0;
    if(L<=mid)ans=max(ans,query(ls,l,mid,L,R));
    if(mid<R)ans=max(ans,query(rs,mid+1,r,L,R));
    return ans;
}
int scan()
{
    int res=0,ch;
    while(!((ch= getchar())>='0'&&ch<='9')){
        if(ch==EOF)return 1<<30;
    }
    res=ch-'0';
    while((ch=getchar())>='0'&&ch<='9')
        res=res*10+(ch-'0');
    return res;
}
int judge(int size){
    int d=n/size,now,li=d*size,ans=0;
    for(int i=1;i<=li;i+=d){
        now=query(1,1,n,i,i+d-1);
        ans+=now;
    }
    return ans>k;
}
int main(){
    while(~scanf("%d%d",&n,&k)){
        if(n==-1&&k==-1)break;
        int tot=0,ma=0,mi=0;
        for(int i=1;i<=n;++i){
            a[i]=scan();tot+=a[i];ma=max(a[i],ma);
            mi=min(mi,a[i]);
        }
        
        if(tot<k){
            printf("-1\n");continue;
        }
        if(ma>k){
            printf("1\n");continue;
        }
        build(1,1,n);
        ma=(ma==0)?1:ma;
        mi=(mi==0)?1:mi;
        int l=1,r=n,ans=-1;
        r=min((k/mi+1),n),l=k/ma;
        if(l==0)l++;
        while(l<=r){
            if(judge(mid)){
                ans=mid;
                r=mid-1;
            }else l=mid+1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
