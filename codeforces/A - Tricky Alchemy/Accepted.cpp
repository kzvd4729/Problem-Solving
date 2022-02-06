/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/16/2018 19:29                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/912/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long a,b,x,y,z,yl,bl;
int main()
{
    cin>>a>>b;
    cin>>x>>y>>z;
     yl=2*x+y;
    bl=3*z+y;
     ///cout<<yl<<" "<<bl<<endl;
     yl=yl<a?0:yl-a;
    bl=bl<b?0:bl-b;
     cout<<yl+bl<<endl;
     return 0;
}