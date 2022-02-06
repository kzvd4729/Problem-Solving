/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/05/2017 20:25                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/579/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,ans;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    while(n)
    {
        if(n%2==1)ans++;
        n=n/2;
    }
    cout<<ans<<endl;
    return 0;
}