/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/26/2017 00:43                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/791/problem/A
****************************************************************************************/
#include<iostream>
using namespace std;
int main()
{
    long long int i,a,b;
    while(cin>>a>>b)
    {
        for(i=1; ;i++)
        {
            a=3*a;
            b=2*b;
            if(a>b)break;
        }
        cout<<i<<endl;
      }
      return 0;
}