/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/01/2017 12:09                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 2000 KB                              
*  problem: https://codeforces.com/contest/492/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,ans,sum,now;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    for(long i=1; ;i++)
    {
        now+=i;
        sum+=now;
        if(sum>n)break;
        ans=i;
    }
    cout<<ans<<endl;
    return 0;
}
 