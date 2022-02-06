/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/15/2017 23:14                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 15 ms                                           memory_used: 2000 KB                              
*  problem: https://codeforces.com/contest/755/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long int n,i,x,j,flag;
    while(scanf("%ld",&n)==1)
    {
        flag=0;
        for(i=1;i<=1000;i++)
        {
            x=(n*i)+1;
            for(j=2;j<=x/2;j++)
            {
                if(x%j==0)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1)break;
         }
        if(flag==1)printf("%ld\n",i);
      }
     return 0;
}