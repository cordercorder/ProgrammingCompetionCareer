#include<algorithm>
#include<iostream>
#include<limits.h>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<string>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<queue>
#include<stack>
#include<deque>
#include<ctime>
#include<set>
#include<map>

#define deb(x) cout<<"#---"<<#x<<"=="<<x<<endl
#define FC ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define FIN freopen("in.txt","r",stdin)
#define FOUT freopen("out.txt","w",stdout)

using namespace std;

const long double PI=acos(-1.0);  
const long double eps=1e-6;
const long long maxw=1e17+10;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const int maxn=1e5+10;

char s[maxn],ch[15];
int m,len;
int L,R,pos;
ull base[maxn],seed=131;
ull res1[maxn],res2[maxn];
ull T[2][maxn<<2];

void pre_handle(){
	base[0]=1;
	len=strlen(s);
	for(int i=1;i<maxn;i++){
		base[i]=base[i-1]*seed;
	}
	for(int i=0;i<len;i++){
		res1[i+1]=base[i]*(ull)s[i];
	}
	int cnt=len;
	for(int i=len-1;i>=0;i--){
		res2[cnt--]=base[len-i-1]*(ull)s[i];
	}
}

void create(int rt,int l,int r){
	if(l==r){
		T[0][rt]=res1[l];
		T[1][rt]=res2[l];
		return ;
	}
	int mid=(l+r)>>1;
	create(rt<<1,l,mid);
	create(rt<<1|1,mid+1,r);
	T[0][rt]=T[0][rt<<1]+T[0][rt<<1|1];
	T[1][rt]=T[1][rt<<1]+T[1][rt<<1|1];
}

ull query(int id,int rt,int l,int r,int L,int R){
	if(l==L&&R==r){
		return T[id][rt];
	}
	int mid=(l+r)>>1;
	if(R<=mid){
		return query(id,rt<<1,l,mid,L,R);
	}
	else if(L>mid){
		return query(id,rt<<1|1,mid+1,r,L,R);
	}
	else{
		return query(id,rt<<1,l,mid,L,mid)+query(id,rt<<1|1,mid+1,r,mid+1,R);
	}
}

void update(int id,int rt,int l,int r,int pos,ull val){
	if(l==r){
		T[id][rt]=val;
		return ;
	}
	int mid=(l+r)>>1;
	if(pos<=mid){
		update(id,rt<<1,l,mid,pos,val);
	}
	else{
		update(id,rt<<1|1,mid+1,r,pos,val);
	}
	T[0][rt]=T[0][rt<<1]+T[0][rt<<1|1];
	T[1][rt]=T[1][rt<<1]+T[1][rt<<1|1];
}

int main(void){
	ull ans1,ans2,val;
	char tmp[100];
	scanf("%s",s);
	len=strlen(s);
	pre_handle();
	create(1,1,len);
	scanf("%d",&m);
	while(m--){
		scanf("%s",tmp);
		if(tmp[0]=='p'){
			scanf("%d %d",&L,&R);
			ans1=query(0,1,1,len,L,R);
			ans2=query(1,1,1,len,L,R);
			if(len-L-R+1>0){
				ans1=ans1*base[len-L-R+1];
				if(ans1==ans2){
					puts("Yes");
				}
				else{
					puts("No");
				}
			}
			else{
				ans2=ans2*base[L-1-len+R];
				if(ans1==ans2){
					puts("Yes");
				}
				else{
					puts("No");
				}
			}
		}
		else{
			scanf("%d %s",&pos,ch);
			val=base[pos-1]*(ull)ch[0];
			update(0,1,1,len,pos,val);
			val=base[len-pos]*(ull)ch[0];
			update(1,1,1,len,pos,val);
		}
	}
	return 0;
}
