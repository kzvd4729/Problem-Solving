/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/23/2017 21:15                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/893/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,m1,m2,x,f;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     m1=1;
    m2=2;
    cin>>n;
    for(long i=1; i<=n; i++)
    {
        cin>>x;
        if(x!=m1&&x!=m2)f=1;
        if(x==m1)
        {
            for(long j=1; j<=3; j++)
            {
                if(j!=m1&&j!=m2)
                {
                    m2=j;
                    break;
                }
            }
        }
        else if(x==m2)
        {
            for(long j=1; j<=3; j++)
            {
                if(j!=m1&&j!=m2)
                {
                    m1=j;
                    break;
                }
            }
        }
    }
    if(f)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
     return 0;
}