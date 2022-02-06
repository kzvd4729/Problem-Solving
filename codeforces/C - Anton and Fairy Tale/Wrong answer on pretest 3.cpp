/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/15/2017 22:12                        
*  solution_verdict: Wrong answer on pretest 3               language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
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
         for(i=m-1;  ;i++)
        {
            s=(i*(i+1))/2;
            x=x-s+m;
            if(x>n)x=n;
            else if(x<=0)break;
         }
         cout<<i+1<<endl;
        }
     return 0;
}