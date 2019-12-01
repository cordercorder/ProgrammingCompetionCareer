#include<bits/stdc++.h> 

#define N 1123456

using namespace std;

int n,m;
int flag,sum,ave,ans,res,len,ans1,ans2;
int a[N],b[N];
long long eul[N];
void init()
{
     eul[1]=1;
     for(long long i=2;i<N;i++)
       eul[i]=i;
     for(long long i=2;i<N;i++)
        if(eul[i]==i)
           for(long long j=i;j<N;j+=i)
              eul[j]=eul[j]/i*(i-1);
}
int main()
{
    int i,j,k,kk,t,x,y,z;
    init();
    scanf("%d",&k);
    kk=0;
    while(k--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        long long res=0;
        for(i=2,j=0;j<n&&i<N;i++)
        {
            while(eul[i]>=a[j]&&j<n)
                res+=i,j++;
        }
        printf("Case %d: %lld Xukha\n",++kk,res);
    }
    return 0;
}
