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
#define FIN freopen("data.txt","r",stdin)
#define FOUT freopen("data.txt","w",stdout)

using namespace std;

const long double PI=acos(-1.0);
const long double eps=1e-6;
const int maxw=200000+10;

typedef long long ll;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const int maxn=2e5+10;

int n,q;
int a[maxn];
vector<int> pos[maxn];
int T[maxn<<2],add[maxn<<2],color[maxn<<2];
int ans[maxn];

void pre_handle(){
	for(int i=1;i<=n;i++){
		pos[a[i]].push_back(i);
	}
}

void create(int rt,int l,int r){
	if(l==r){
		if(a[l]==0){
			T[rt]=maxw;
		}
		else{
			T[rt]=a[l];
		}
		return ;
	}
	int mid=(l+r)>>1;
	create(rt<<1,l,mid);
	create(rt<<1|1,mid+1,r);
	T[rt]=min(T[rt<<1],T[rt<<1|1]);
}

void pushdown(int rt){
	if(add[rt]==0)
		return ;
	color[rt<<1]=add[rt];
	color[rt<<1|1]=add[rt];
	add[rt<<1]=add[rt];
	add[rt<<1|1]=add[rt];
	add[rt]=0;
}

void update(int rt,int l,int r,int L,int R,int val){
	if(l==L&&R==r){
		color[rt]=val;
		add[rt]=val;
		return ;
	}
	pushdown(rt);
	int mid=(l+r)>>1;
	if(R<=mid){
		update(rt<<1,l,mid,L,R,val);
	}
	else if(L>mid){
		update(rt<<1|1,mid+1,r,L,R,val);
	}
	else{
		update(rt<<1,l,mid,L,mid,val);
		update(rt<<1|1,mid+1,r,mid+1,R,val);
	}
	T[rt]=min(T[rt<<1],T[rt<<1|1]);
}

int query(int rt,int l,int r,int L,int R){
	if(L==l&&R==r){
		return T[rt];
	}
	pushdown(rt);
	int mid=(l+r)>>1;
	if(R<=mid){
		return query(rt<<1,l,mid,L,R); 
	}
	else if(L>mid){
		return query(rt<<1|1,mid+1,r,L,R);
	}
	else{
		return min(query(rt<<1,l,mid,L,mid),query(rt<<1|1,mid+1,r,mid+1,R));
	}
}

void cal(int rt,int l,int r){
	if(l==r){
		ans[l]=color[rt];
		return ;
	}
	pushdown(rt);
	int mid=(l+r)>>1;
	cal(rt<<1,l,mid);
	cal(rt<<1|1,mid+1,r);
}

void handle(){
	bool f;
	for(int i=1;i<=n;){
		int j=i;
		f=1;
		while(j<=n&&ans[j]==0){
			j++;
			f=0;
		}
		if(ans[i]==0&&j<=n){
			for(int k=i;k<j;k++){
				ans[k]=ans[j];
			}
		}
		if(f){
			i=j+1;
		}
		else{
			i=j;
		}
	}
	for(int i=n;i>=1;){
		int j=i;
		f=1;
		while(j>=1&&ans[j]==0){
			j--;
			f=0;
		}
		if(a[i]==0&&j>=1){
			for(int k=j+1;k<=i;k++){
				ans[k]=ans[j];
			}
		}
		if(f){
			i=j-1;
		}
		else{
			i=j;
		}
	}
}

void solve(){
	pre_handle();
	if(pos[q].empty()&&pos[0].empty()){
		cout<<"NO";
		return ;
	}
	if(pos[q].empty()){
		pos[q].push_back(pos[0].back());
		pos[0].pop_back();
	}
	create(1,1,n);
	int Min;
	for(int i=1;i<=q;i++){
		if(pos[i].empty())
			continue;
		Min=query(1,1,n,pos[i][0],pos[i].back());
		if(Min<i){
			cout<<"NO";
			return ;
		}
		update(1,1,n,pos[i][0],pos[i].back(),i);
	}
	cal(1,1,n);
	handle();
	cout<<"YES"<<'\n';
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<" ";
	}
}

int main(void){
	FC;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	solve();
	return 0;
}
