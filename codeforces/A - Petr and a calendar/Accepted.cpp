/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/23/2017 00:32                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 31 ms                                           memory_used: 2000 KB                              
*  problem: https://codeforces.com/contest/760/problem/A
****************************************************************************************/
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int m,d,month,day,ans,i;
    while(scanf("%d%d",&m,&d)==2)
    {
        if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)month=31;
        else if(m==2)month=28;
        else month=30;
        day=month-(8-d);
        ans=1;
        for(i=1;i<=7;i++)
        {
            ans=7*i;
            if(ans>=day)break;
        }
        printf("%d\n",i+1);
      }
     return 0;
}