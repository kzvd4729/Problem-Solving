/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/19/2018 22:40                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/935/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,x,cnt;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    for(long i=1;i<=n;i++)
    {
        x=n-i;
        if(x%i==0)
        {
            if(x/i)cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}