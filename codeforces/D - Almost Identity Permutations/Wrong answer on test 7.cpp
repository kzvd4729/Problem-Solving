/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/11/2017 23:57                        
*  solution_verdict: Wrong answer on test 7                  language: GNU C++14                               
*  run_time: 0 ms                                            memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/888/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,k;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n>>k;
    long cnt=0;
    if(k==4)
    {
        for(long i=1;i<=n;i++)
        {
            for(long j=i+1;j<=n;j++)
            {
                for(long k=j+1;k<=n;k++)
                {
                    cnt+=(n-k);
                }
            }
        }
        cout<<(15*cnt)+1<<endl;
    }
    else if(k==3)
    {
        for(long i=1;i<=n;i++)
        {
            for(long j=i+1;j<=n;j++)
            {
                for(long k=j+1;k<=n;k++)
                {
                    cnt++;
                }
            }
        }
        cout<<(3*cnt)+1<<endl;
    }
    else if(k==2)
    {
        for(long i=1;i<=n;i++)
        {
            for(long j=i+1;j<=n;j++)
            {
                cnt++;
            }
        }
        cout<<cnt+1<<endl;
    }
    else cout<<1<<endl;
     return 0;
}