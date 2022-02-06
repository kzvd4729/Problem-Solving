/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/17/2018 15:36                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1800 KB                              
*  problem: https://codeforces.com/contest/637/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,x,mx,ans;
int main()
{
    cin>>n;
    for(long i=1;i<=n;i++)
    {
        cin>>x;
        if(x>mx)
        {
            mx=x;
            ans=i;
        }
    }
    cout<<ans<<endl;
    return 0;
}