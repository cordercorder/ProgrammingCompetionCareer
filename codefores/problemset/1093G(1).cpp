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
void err(long long a){
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

const ll maxn=(ll)2e5+10ll;

int n,k,q;
int a[maxn][6],b[35][maxn];
int cnt;
int len;
int T[2][35][maxn<<2];

void create(int id,int rt,int l,int r){
    if(l==r){
        T[0][id][rt]=b[id][l];
        T[1][id][rt]=b[id][l];
        return ;
    }
    int mid=(l+r)>>1;
    create(id,rt<<1,l,mid);
    create(id,rt<<1|1,mid+1,r);
    T[0][id][rt]=max(T[0][id][rt<<1],T[0][id][rt<<1|1]);
    T[1][id][rt]=min(T[1][id][rt<<1],T[1][id][rt<<1|1]);
}

void update(int id,int rt,int l,int r,int pos,int val){
    if(l==r){
        T[0][id][rt]=val;
        T[1][id][rt]=val;
        return ;
    }
    int mid=(l+r)>>1;
    if(pos<=mid){
        update(id,rt<<1,l,mid,pos,val);
    }
    else{
        update(id,rt<<1|1,mid+1,r,pos,val);
    }
    T[0][id][rt]=max(T[0][id][rt<<1],T[0][id][rt<<1|1]);
    T[1][id][rt]=min(T[1][id][rt<<1],T[1][id][rt<<1|1]);
}

int cal(int id,int rt,int l,int r,int L,int R,bool f){
    if(L==l&&R==r){
        if(f)
            return T[0][id][rt];
        return T[1][id][rt];
    }
    int mid=(l+r)>>1;
    if(R<=mid){
        return cal(id,rt<<1,l,mid,L,R,f);
    }
    else if(L>mid){
        return cal(id,rt<<1|1,mid+1,r,L,R,f);
    }
    else{
        if(f){
            return max(cal(id,rt<<1,l,mid,L,mid,f),cal(id,rt<<1|1,mid+1,r,mid+1,R,f));
        }
        else{
            return min(cal(id,rt<<1,l,mid,L,mid,f),cal(id,rt<<1|1,mid+1,r,mid+1,R,f));
        }
    }
}

int main(void){
    FC;
    int tmp,L,R,res[6],pos;
    cin>>n>>k;
    len=1<<k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            cin>>a[i][j];
        }
        for(int j=0;j<len;j++){
            int sum=0;
            for(int u=0;u<k;u++){
                if((j>>u)&1){
                    sum-=a[i][u+1];
                }
                else{
                    sum+=a[i][u+1];
                }
            }
            b[j+1][i]=sum;
        }
    }
    for(int i=1;i<=len;i++){
        create(i,1,1,n);
    }
    cin>>q;
    while(q--){
        cin>>tmp;
        if(tmp==1){
            cin>>pos;
            for(int i=1;i<=k;i++){
                cin>>res[i];
            }
            for(int i=0;i<len;i++){
                int sum=0;
                for(ll j=0;j<k;j++){
                    if((i>>j)&1){
                        sum-=res[j+1];
                    }
                    else{
                        sum+=res[j+1];
                    }
                }
                update(i+1,1,1,n,pos,sum);
            }
        }
        else{
            cin>>L>>R;
            int ans=-((int)1e9+10);
            for(int i=1;i<=len;i++){
//                ll tmp1=cal(i,1,1,n,L,R,true);
//                ll tmp2=cal(i,1,1,n,L,R,false);
//                deb(tmp1);
//                deb(tmp2);
                ans=max(ans,cal(i,1,1,n,L,R,true)-cal(i,1,1,n,L,R,false));
            }
            cout<<ans<<'\n';
        }
    }
    return 0;
}
