/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/08/2017 11:28                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 30 ms                                           memory_used: 2000 KB                              
*  problem: https://codeforces.com/contest/4/problem/A
****************************************************************************************/
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    long long int n,m,a,b,c;
    while(cin>>n)
    {
        if(n==1)cout<<"NO"<<endl;
        else if(n==2)cout<<"NO"<<endl;
        else
        {
            if(n%2==1)cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
          }
      }
     return 0;
}