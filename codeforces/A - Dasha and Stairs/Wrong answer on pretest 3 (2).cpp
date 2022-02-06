/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/31/2017 20:50                        
*  solution_verdict: Wrong answer on pretest 3               language: GNU C++11                               
*  run_time: 15 ms                                           memory_used: 2000 KB                              
*  problem: https://codeforces.com/contest/761/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    while(cin>>a>>b)
    {
        if(a+1==b||a==b)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
     }
    return 0;
}