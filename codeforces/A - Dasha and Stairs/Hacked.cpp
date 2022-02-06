/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/31/2017 20:55                        
*  solution_verdict: Hacked                                  language: GNU C++11                               
*  run_time: 15 ms                                           memory_used: 2000 KB                              
*  problem: https://codeforces.com/contest/761/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int a,b;
    while(cin>>a>>b)
    {
        if(a+1==b||a==b||a-1==b)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
     }
    return 0;
}