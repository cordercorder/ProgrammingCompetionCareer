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

const int maxn=(int)2e5+10;

int n,k,q;
int a[maxn][6];
int cnt;
int len;
int T1[maxn<<2][35],T2[maxn<<2][35];
int res[6];

template<typename T>
void _read(T &ret){
	char ch=getchar();
	bool f=0;
    ret=0;
    while(ch<'0'||ch>'9'){
    	if(ch=='-'){
    		f=1;
		}
    	ch=getchar();
	}
    while(ch>='0'&&ch<='9'){
    	ret=ret*10+(ch-'0');
    	ch=getchar();
	}
    if(f)
    	ret=-ret;
}

template<typename T>
void print(T ret){
	if(ret<0){
		putchar('-');
		ret=-ret;
	}
	if(ret>9){
		print(ret/10);
	}
	putchar(ret%10+'0');
}

void create(int rt,int l,int r){
    if(l==r){
        for(int i=0;i<len;i++){
            int sum=0;
            for(int j=0;j<k;j++){
                if((i>>j)&1){
                    sum-=a[l][j+1];
                }
                else{
                    sum+=a[l][j+1];
                }
            }
            T1[rt][i]=sum;
            T2[rt][i]=sum;
        }
        return ;
    }
    int mid=(l+r)>>1;
    create(rt<<1,l,mid);
    create(rt<<1|1,mid+1,r);
    for(int i=0;i<len;i++){
        T1[rt][i]=max(T1[rt<<1][i],T1[rt<<1|1][i]);
        T2[rt][i]=min(T2[rt<<1][i],T2[rt<<1|1][i]);
    }
}

void update(int rt,int l,int r,int pos){
    if(l==r){
        for(int i=0;i<len;i++){
            int sum=0;
            for(int j=0;j<k;j++){
                if((i>>j)&1){
                    sum-=res[j+1];
                }
                else{
                    sum+=res[j+1];
                }
            }
            T1[rt][i]=sum;
            T2[rt][i]=sum;
        }
        return ;
    }
    int mid=(l+r)>>1;
    if(pos<=mid){
        update(rt<<1,l,mid,pos);
    }
    else{
        update(rt<<1|1,mid+1,r,pos);
    }
    for(int i=0;i<len;i++){
        T1[rt][i]=max(T1[rt<<1][i],T1[rt<<1|1][i]);
        T2[rt][i]=min(T2[rt<<1][i],T2[rt<<1|1][i]);
    }
}

int cal(int id,int rt,int l,int r,int L,int R,bool f){
    if(L==l&&R==r){
        if(f){
            return T1[rt][id];
        }
        return T2[rt][id];
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
    int tmp,L,R,pos;
    cin>>n>>k; 
    len=1<<k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            cin>>a[i][j];
        }
    }
    create(1,1,n);
    cin>>q;
    while(q--){
        cin>>tmp;
        if(tmp==1){
            cin>>pos;
            for(int i=1;i<=k;i++){
                cin>>res[i];
            }
            update(1,1,n,pos);
        }
        else{
            cin>>L>>R;
            int ans=-((int)1e9+10);
            for(int i=0;i<len;i++){
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
