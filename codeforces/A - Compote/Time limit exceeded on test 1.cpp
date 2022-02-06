/****************************************************************************************
*  @author: kzvd4729#                                        created: May/03/2017 00:19                        
*  solution_verdict: Time limit exceeded on test 1           language: GNU C++14                               
*  run_time: 1000 ms                                         memory_used: 171400 KB                            
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
    main();
    return 0;
}