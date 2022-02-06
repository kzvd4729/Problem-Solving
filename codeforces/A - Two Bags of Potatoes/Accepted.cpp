/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/25/2017 01:50                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/239/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int y,k,n,x,z,i,j;
    while(cin>>y>>k>>n)
    {
         long int s=y;
        x=y%k;
        z=k-x;
        y=y+z;
         if(z==0)y=y+k;
         //cout<<y<<endl;
         long int f=0;
         for(i=y;i<=n;i=i+k)
        {
            cout<<i-s<<" ";
            f=1;
        }
        if(f==1)cout<<endl;
         if(f==0)cout<<-1<<endl;
      }
      return 0;
}