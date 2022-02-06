/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/15/2017 22:21                        
*  solution_verdict: Hacked                                  language: GNU C++14                               
*  run_time: 499 ms                                          memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/785/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,m,s,x,i;
    while(cin>>n>>m)
    {
        x=n;
         for(i=m;  ;i++)
        {
            x=x+m;
            if(x>=n)x=n;
            x=x-i;
            if(x<=0)break;
         }
         cout<<i<<endl;
      }
     return 0;
}