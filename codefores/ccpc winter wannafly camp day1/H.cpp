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
void err(int a){
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

const int maxn=1e2+10;

int a[maxn];
int n,k;
int R[maxn],L[maxn];

void solve(){
    stack<int> s;
    int ans=0,Max,ret;
    int l,r;
    for(int u=0;u<k;u++){
        for(int i=1;i<=n;i++){
			while(!s.empty()&&a[s.top()]>=a[i])
				s.pop();
			if(s.empty())
				L[i]=0;
			else
				L[i]=s.top();
			s.push(i);
		}
		while(!s.empty()){
            s.pop();
        }
        for(int i=n;i>=1;i--){
    		while(!s.empty()&&a[s.top()]>=a[i])
    			s.pop();
    		if(s.empty())
    			R[i]=n+1;
    		else
    			R[i]=s.top();
    		s.push(i);
    	}
        while(!s.empty()){
            s.pop();
        }
//        for(int i=1;i<=n;i++){
//            cout<<R[i]<<" ";
//        }
//        cout<<'\n';
//        for(int i=1;i<=n;i++){
//            cout<<L[i]<<" ";
//        }
//        cout<<'\n';
        Max=-1;
        for(int i=1;i<=n;i++){
            if(a[i]*(R[i]-L[i]-1)>Max){
                Max=a[i]*(R[i]-L[i]-1);
                l=L[i];
                r=R[i];
                ret=a[i];
            }
            else if(a[i]*(R[i]-L[i]-1)==Max&&L[i]>=l&&R[i]<=r){
                l=L[i];
                r=R[i];
                ret=a[i];
            }            
        }
        ans+=Max;
        for(int i=l+1;i<r;i++){
            a[i]-=ret;
        }
//        for(int i=1;i<=n;i++){
//            cout<<a[i]<<" ";
//        }
//        cout<<'\n';
    }
	cout<<ans<<'\n';
}

int main(void){
    FC;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int kkoko;
    solve();
    //×¢ÊÍ
    //×¢ÊÍ
    //×¢ÊÍ
    //×¢ÊÍ
    //×¢ÊÍ 
    return 0;
}
