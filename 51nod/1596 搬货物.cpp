# include<iostream>
# include<algorithm>
# include<cstring>
# include<string>
# include<cmath>
# include<queue>
# include<stack>
# include<set>
# include<vector>
# include<cstdio>
# include<cstdlib>
# include<map>
# include<deque>
# include<limits.h>
# include<ctime>

# define deb(x) cout<<"#---"<<#x<<"=="<<x<<endl

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn=1e6+10;

ll n;
priority_queue<ll,vector<ll>,greater<ll> > q;
ll res[maxn],cnt;

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

void solve(){
	ll now1,now2;
	cnt=0;
	while(!q.empty()){
		now1=q.top();
		q.pop();
		if(q.empty()){
			res[cnt++]=now1;
			break;
		}
		if(now1==q.top()){
			q.pop();
			q.push(now1+1);
		}
		else{
			res[cnt++]=now1;
		}
	}
	printf("%lld\n",cnt);
}

int main(void){
	ll tmp;
	while(scanf("%lld",&n)!=EOF){
		for(ll i=1;i<=n;i++){
			_read(tmp);
			q.push(tmp);
		}
		solve();
	}
	return 0;
}
