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
using pii=pair<ll,ll>;

/*head------[@cordercorder]*/

const int maxn=(int)1e5+10;

int T;
int n,q;
int pre[maxn];
ll cntnode[maxn],cnte[maxn];
ll sum,k,tot;

struct cmp{
    bool operator()(const int &a,const int &b){
        if(cntnode[a]>cntnode[b])
            return true;
        else if(cntnode[a]==cntnode[b]&&a<b){
            return true;
        }
        return false;
    }
};

set<int,cmp> S;

int Find(int x){
    return pre[x]==-1?x:pre[x]=Find(pre[x]);
}

void pre_handle(){
    for(int i=1;i<=n;i++){
        pre[i]=-1;
        cntnode[i]=1;
        cnte[i]=0;
        S.insert(i);
    }
}

void Union(int u,int v){
    int nu=Find(u),nv=Find(v);
    ll s1,s2,s;
    if(nu!=nv){
        s1=(cntnode[nu]*(cntnode[nu]-1ll))/2ll-cnte[nu];
        s2=(cntnode[nv]*(cntnode[nv]-1ll))/2ll-cnte[nv];
        auto it=S.find(nu);
        S.erase(it);
        it=S.find(nv);
        S.erase(it);
        pre[nu]=nv;
        cntnode[nv]+=cntnode[nu];
        cnte[nv]+=cnte[nu];
        sum--;
        s=(cntnode[nv]*(cntnode[nv]-1ll))/2ll-cnte[nv]-1ll;
        S.insert(nv);
        tot+=(s-s1-s2);
    }
}

int cal(){
    int ans=0;
    ll res=k-tot,ret,tmp;
    multiset<int>::iterator it=S.begin();
    ret=*it;
    it++;
    for(;it!=S.end()&&res>0;it++){
        tmp=ret*(*it);
        res-=tmp;
        ret+=(*it);
        ans++;
    }
    return ans;
}

int main(void){
    int p;
    int a,b;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&n,&q);
        pre_handle();
        sum=n;
        while(q--){
            scanf("%d",&p);
            if(p==1){
                scanf("%d %d",&a,&b);
                Union(a,b);
            }
            else{
                scanf("%lld",&k);
                if(k>=(sum-1)){
                    printf("1 %lld\n",sum-cal());
                }
                else{
                    printf("%lld %lld\n",sum-k,sum-cal());
                }
            }
        }
        S.clear();
    }
    return 0;
}
