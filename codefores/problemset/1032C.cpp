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

const int maxn=(int)1e5+10;

int a[maxn],ans[maxn];
int n;

void solve(){
    for(int i=1;i<=n;){
        int j=i;
        while(j<n&&a[j]<a[j+1]){
            j++;
        }
        if(i==j){
            while(j<n&&a[j]>a[j+1]){
                j++;
            }
            if(i==j){
                while(j<=n&&a[j]==a[i]){
                    j++;
                }
                if(j<=n&&a[j]>a[i]){
                    if((j-i)%2){
                        for(int k=0;k<(j-i);k++){
                            if(k%2==0){
                                ans[k+i]=1;
                            }
                            else{
                                ans[k+i]=2;
                            }
                        }
                    }
                    else{
                        for(int k=0;k<(j-i);k++){
                            if(k%2==0){
                                ans[k+i]=2;
                            }
                            else{
                                ans[k+i]=1;
                            }
                        }
                    }
                }
                else{
                    if((j-i)%2){
                        for(int k=0;k<(j-i);k++){
                            if(k%2==0){
                                ans[k+i]=5;
                            }
                            else{
                                ans[k+i]=4;
                            }
                        }
                    }
                    else{
                        for(int k=0;k<(j-i);k++){
                            if(k%2==0){
                                ans[k+i]=4;
                            }
                            else{
                                ans[k+i]=5;
                            }
                        }
                    }
                }
                i=j;
            }
            else{
                int cnt=ans[i-1]-1;
                if(cnt==0)
                    cnt=5;
                for(int k=i;k<=j;k++){
                    ans[k]=cnt--;
                }
                if(cnt<0){
                    cout<<"-1"<<'\n';
                    return ;
                }
                int k=j;
                while(k<=n&&a[k]==a[j]){
                    k++;
                }
                if(k<=n&&a[k]>a[j]){
                    if(ans[j]==1||ans[j]==2){
                        for(int l=0;l<(k-j-1);l++){
                            if(ans[j]==1){
                                if(l%2==0){
                                    ans[l+j+1]=2;
                                }
                                else{
                                    ans[l+j+1]=1;
                                }
                            }
                            else{
                                if(l%2==0){
                                    ans[l+j+1]=1;
                                }
                                else{
                                    ans[l+j+1]=2;
                                }
                            }
                        }
                    }
                    else{
                        if((k-j-1)%2==1){
                            for(int l=0;l<(k-j-1);l++){
                                if(l%2==0){
                                    ans[l+j+1]=1;
                                }
                                else{
                                    ans[l+j+1]=2;
                                }
                            }
                        }
                        else{
                            for(int l=0;l<(k-j-1);l++){
                                if(l%2==0){
                                    ans[l+j+1]=2;
                                }
                                else{
                                    ans[l+j+1]=1;
                                }
                            }
                        }
                    }
                }
                else{
                    for(int l=0;l<(k-j-1);l++){
                        if((k-j-1)%2==1){
                            if(l%2==0){
                                ans[l+j+1]=5;
                            }
                            else{
                                ans[l+j+1]=4;
                            }
                        }
                        else{
                            if(l%2==0){
                                ans[l+j+1]=4;
                            }
                            else{
                                ans[l+j+1]=5;
                            }
                        }
                    }
                }
                i=k;
            }
        }
        else{
            int cnt=ans[i-1];
            for(int k=i;k<=j;k++){
                ans[k]=++cnt;
            }
            if(cnt>5){
                cout<<"-1"<<'\n';
                return ;
            }
            int k=j;
            while(k<=n&&a[k]==a[j]){
                k++;
            }
            if(cnt>=3){
                if(k<=n&&a[k]>a[j]){
                    for(int l=0;l<(k-j-1);l++){
                        if((k-j-1)%2==1){
                            if(l%2==0){
                                ans[l+j+1]=1;
                            }
                            else{
                                ans[l+j+1]=2;
                            }
                        }
                        else{
                            if(l%2==0){
                                ans[l+j+1]=2;
                            }
                            else{
                                ans[l+j+1]=1;
                            }
                        }
                    }
                }
                else{
                    for(int l=0;l<(k-j-1);l++){
                        if((k-j-1)%2==1){
                            if(l%2==0){
                                ans[l+j+1]=5;
                            }
                            else{
                                ans[l+j+1]=4;
                            }
                        }
                        else{
                            if(l%2==0){
                                ans[l+j+1]=4;
                            }
                            else{
                                ans[l+j+1]=5;
                            }
                        }
                    }
                }
            }
            else{
                
                
                
                
            }
            i=k;
        }
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
}

int main(void){
    FC;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    solve();
    return 0;
}
