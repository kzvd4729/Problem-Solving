/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/13/2018 17:18                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/950/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long l,r,a;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
     cin>>l>>r>>a;
    for(long i=1;i<=a;i++)
    {
      if(l<r)l++;
      else r++;
    }
    cout<<min(l,r)*2<<endl;
    return 0;
}