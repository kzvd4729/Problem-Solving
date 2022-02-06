/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/20/2018 21:39                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/914/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long ans,x,z,n;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    ans=-9999999999999;
    for(int i=1; i<=n; i++)
    {
        cin>>x;
        if(x<0)
        {
            ans=max(ans,x);
        }
        else
        {
            z=sqrt(x);
            if(z*z!=x)ans=max(ans,x);
        }
    }
    cout<<ans<<endl;
    return 0;
}