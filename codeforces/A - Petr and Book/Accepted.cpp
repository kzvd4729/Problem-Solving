/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/25/2017 01:50                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/139/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long int n,arr[10],sum,i,flag;
    while(cin>>n)
    {
        for(i=1;i<=7;i++)
        {
            cin>>arr[i];
        }
         flag=0;
         while(1)
        {
            for(i=1;i<=7;i++)
            {
                n=n-arr[i];
                 if(n<=0)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1)break;
        }
         cout<<i<<endl;
     }
     return 0;
}