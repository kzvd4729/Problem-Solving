/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/17/2018 15:40                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 9700 KB                              
*  problem: https://codeforces.com/contest/637/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,x,mx,ans,cnt[1000004];
int main()
{
    cin>>n;
    for(long i=1;i<=n;i++)
    {
        cin>>x;
        cnt[x]++;
        if(cnt[x]>mx)
        {
            mx=cnt[x];
            ans=x;
        }
    }
    cout<<ans<<endl;
    return 0;
}