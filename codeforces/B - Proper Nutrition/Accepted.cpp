/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/16/2017 23:02                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/898/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,a,b,c1,c2;
int main()
{
    cin>>n>>a>>b;
    for(long i=0;i<=n;i++)
    {
        c1=a*i;
        if(c1>n)break;
        c2=n-c1;
        if(c2%b==0)
        {
            cout<<"YES"<<endl;
            cout<<i<<" "<<c2/b<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}