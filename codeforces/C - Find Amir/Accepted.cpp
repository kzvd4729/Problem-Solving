/****************************************************************************************
*  @author: kzvd4729                                         created: May/04/2017 21:38                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/805/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n;
    cin>>n;
    if(n%2==0)cout<<(n/2)-1<<endl;
    else cout<<n/2<<endl;
    return 0;
}