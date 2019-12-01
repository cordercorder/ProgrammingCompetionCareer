#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<queue>
#include<stack>
#include<set>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<deque>
#include<limits.h>
#include<bitset>
#include<ctime>

#define deb(x) cout<<"#---"<<#x<<"=="<<x<<endl

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn=1e5+10;

int n,m,cnt,root[maxn],a[maxn],x,y,k;
int len;

struct node{
	int l;
	int r;
	int sum;
}T[maxn*30];

vector<int> v;

void update(int l,int r,int &x,int y,int pos){
	T[++cnt]=T[y];
	T[cnt].sum++;
	x=cnt;
	if(l==r){
		return ;
	}
	int mid=(l+r)>>1;
	if(pos<=mid){
		update(l,mid,T[x].l,T[y].l,pos);
	}
	else{
		update(mid+1,r,T[x].r,T[y].r,pos);
	}
}

int query(int l,int r,int x,int y,int k){
	if(l==r){
		return l;
	}
	int mid=(l+r)>>1;
	int sum=T[T[y].l].sum-T[T[x].l].sum;
	if(sum>=k){
		return query(l,mid,T[x].l,T[y].l,k);
	}
	else{
		return query(mid+1,r,T[x].r,T[y].r,k-sum);
	}
}

int main(void){
	int pos;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		v.push_back(a[i]);
	}
	sort(v.begin(),v.end());
	len=unique(v.begin(),v.end())-v.begin();
	for(int i=1;i<=n;i++){
		pos=lower_bound(v.begin(),v.end(),a[i])-v.begin()+1;
		update(1,n,root[i],root[i-1],pos);
	} 
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&x,&y,&k);
		printf("%d\n",v[query(1,n,root[x-1],root[y],k)-1]);
	}
	return 0;
}
