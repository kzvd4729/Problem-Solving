/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-05-14 20:18:28                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 6                                          memory_used (MB):                                 
*  problem: https://vjudge.net/problem/UVALive-5341
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define long long long int
long n,k,a,b,m,d,x;
vector<long>down;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin>>n>>k)
    {
        if(n==0&&k==0)break;
        x=n-k;
        if(x>=k)a=x,b=k;
        else a=k,b=x;
        for(long i=2;i<=b;i++)
        {
            down.push_back(i);
        }
        m=1,d=1;
        for(long i=a+1;i<=n;i++)
        {
            m=m*i;
            for(long j=0;j<down.size();j++)
            {
                if(m%down[j]==0)
                {
                    m=m/down[j];
                    down[j]=1;
                }
            }
        }
        for(long i=0;i<down.size();i++)
        {
            d=d*down[i];
        }
        cout<<n<<" things taken "<<k<<" at a time is "<<m/d<<" exactly."<<endl;
        down.clear();
    }
    return 0;
}