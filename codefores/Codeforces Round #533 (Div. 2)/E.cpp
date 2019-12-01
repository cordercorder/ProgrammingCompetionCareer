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
using pii=pair<int,string>; 

/*head------[@cordercorder]*/

const int maxn=(int)1e5+10;

int n,m;
pii res[maxn];
set<string> s;
map<string,int> index;
bool e[50][50];
bool isv[50];
int S1[(1<<20)+100],S2[(1<<22)+100];

void solve(){
    int cnt=0,id;
    for(auto it:s){
        index[it]=cnt++;
    }
    vector<int> ret;
    for(int i=1;i<=n;){
        int j=i;
        while(j<=n&&res[j].first==2){
            id=index[res[j].second];
            if(!isv[id]){
                ret.push_back(id);
                isv[id]=true;
            }
            j++;
        }
        if(j!=i){
            for(int k=0;k<(int)ret.size();k++){
                for(int u=k+1;u<(int)ret.size();u++){
                    e[ret[k]][ret[u]]=true;
                    e[ret[u]][ret[k]]=true;
                }
            }
            ret.clear();
            memset(isv,false,sizeof(isv));
            i=j;
        }
        else{
            i=j+1;
        }
    }
    int len1=cnt/2,len2=cnt-len1,ans=0;
    for(int i=0;i<len1;i++){
        S1[1<<i]=1;
    }
    for(int i=0;i<(1<<len1);i++){
        for(int j=0;j<len1;j++){
            if(((~i)>>j)&1){
                bool f=true;
                for(int k=0;k<len1;k++){
                    if((i>>k)&1){
                        f&=!e[j][k];
                    }
                }
                S1[i|(1<<j)]=max(S1[i|(1<<j)],S1[i]+(int)f);
            }
        }
        ans=max(ans,S1[i]);
    }
    for(int i=0;i<len2;i++){
        S2[1<<i]=1;
    }
    for(int i=0;i<(1<<len2);i++){
        for(int j=0;j<len2;j++){
            if(((~i)>>j)&1){
                bool f=true;
                for(int k=0;k<len2;k++){
                    if((i>>k)&1){
                        f&=!e[len1+j][len1+k];
                    }
                }
                S2[i|(1<<j)]=max(S2[i|(1<<j)],S2[i]+(int)f);
            }
        }
        ans=max(ans,S2[i]);
    }
    for(int i=0;i<(1<<len1);i++){
        int bits=(1<<len2)-1;
        for(int j=0;j<len1;j++){
            if((i>>j)&1){
                for(int k=0;k<len2;k++){
                    if(e[j][len1+k]){
                        if((bits>>k)&1){
                            bits^=(1<<k);
                        }
                    }
                }
            }
        }
        ans=max(ans,S1[i]+S2[bits]);
    }
    cout<<ans<<'\n';
}

int main(void){
    FC;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>res[i].first;
        if(res[i].first==1){
            res[i].second="";
        }
        else{
            cin>>res[i].second;
            s.insert(res[i].second);
        }
    }
    solve();
    return 0;
}
