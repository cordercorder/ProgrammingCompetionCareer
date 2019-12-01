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

const int maxn=2e5+10;

int n,m;
int a[maxn];
vector<int> pos;
set<int> s;
int tmp[maxn];
ll ret;

void Merge(vector<int> &num,int st1,int ed1,int st2,int ed2){
	int i=st1,j=st2,cnt=st1;
	while(i<=ed1&&j<=ed2){
		if(num[i]<num[j]){
			tmp[cnt++]=num[i++];
			ret+=(ed2-j+1);
		}
		else{
			tmp[cnt++]=num[j++];
		}
	}
	while(i<=ed1){
		tmp[cnt++]=num[i++];
	}
	while(j<=ed2){
		tmp[cnt++]=num[j++];
	}
	for(i=st1;i<cnt;i++){
		num[i]=tmp[i];
	}
}

void m_sort(vector<int> &num,int l,int r){
	int mid;
	if(l<r){
		mid=(l+r)>>1;
		m_sort(num,l,mid);
		m_sort(num,mid+1,r);
		Merge(num,l,mid,mid+1,r);
	}
}

ll handle(int x){
	vector<int>sum(maxn,0);
	vector<int>res(maxn,0);	
	vector<int>num;
	num.push_back(sum[0]);
	for(int i=1;i<=n;i++){
		if(a[i]<x){
			res[i]--;
		}
		else{
			res[i]++;
		}
		sum[i]=sum[i-1]+res[i];
		num.push_back(sum[i]);
	}
	ret=0;
	m_sort(num,0,(int)num.size()-1);
	return ret;
}

void solve(){
	ll ans=handle(m)-handle(m+1);
	printf("%lld\n",ans);
}

int main(void){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	solve();
	return 0;
}
