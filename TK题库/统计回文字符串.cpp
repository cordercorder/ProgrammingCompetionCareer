#include <iostream>
#include <string>

using namespace std;

int main()
{
    int i, j, len, flag, count;
    string str;
    while(1)
    {
        cin>>str;
        len = str.length( );
        count = 0;
        for(i = 0; i < len; ++i)
        {
            for(j = i; j < len; ++j)
            {
                flag = 1;
                for(int k = 0; k < (j - i + 1)/2; ++k)
                {
                	cout<<"i="<<i<<" j="<<j<<" k="<<k<<endl;
                	cout<<"j-i+1="<<j-i+1<<" j-k="<<j-k<<endl<<endl;
                    if(str[i] != str[j - k])
                        flag = 0;
                }
                if(flag)
                    count++;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}

