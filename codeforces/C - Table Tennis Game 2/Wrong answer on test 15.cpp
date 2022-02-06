/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/10/2018 20:05                        
*  solution_verdict: Wrong answer on test 15                 language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/765/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long a,b,k;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
        cin>>k>>a>>b;
    long x=a/k+b/k;
    if(x==0)cout<<-1<<endl;
    else cout<<x<<endl;
    return 0;
}
 