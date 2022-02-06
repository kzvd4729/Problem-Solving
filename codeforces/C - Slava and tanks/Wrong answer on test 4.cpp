/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/05/2017 22:03                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/877/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     long n;
    cin>>n;
    if(n==2)
    {
        cout<<3<<endl;
        cout<<2<<" "<<1<<" "<<2<<endl;
        return 0;
    }
    cout<<n*2-2<<endl;
    for(long i=2;i<=n;i++)
    {
        cout<<i<<" "<<i-1<<" ";
    }
    cout<<endl;
    return 0;
}