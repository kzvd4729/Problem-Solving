/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/22/2017 15:14                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 15 ms                                           memory_used: 2100 KB                              
*  problem: https://codeforces.com/contest/559/problem/A
****************************************************************************************/
#include<iostream>
using namespace std;
int main()
{
    long long int a1,a2,a3,a4,a5,a6,base,ans,j,i;
    while(cin>>a1>>a2>>a3>>a4>>a5>>a6)
    {
         ans=(((a1+a2+a3)*(a1+a2+a3))-(a1*a1)-(a3*a3)-(a5*a5));
        cout<<ans<<endl;
    }
      return 0;
}