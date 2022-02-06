/****************************************************************************************
*  @author: kzvd4729#                                        created: May/03/2017 00:20                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/746/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,ans=0,i;
    cin>>a>>b>>c;
    for(i=1;i<=a;i++)
    {
        if(2*i<=b&&4*i<=c)
        {
            ans=7*i;
        }
        else break;
    }
    cout<<ans<<endl;
    return 0;
}