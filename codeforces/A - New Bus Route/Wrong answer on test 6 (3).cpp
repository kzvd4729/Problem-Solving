/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/27/2017 21:31                        
*  solution_verdict: Wrong answer on test 6                  language: GNU C++14                               
*  run_time: 0 ms                                            memory_used: 4200 KB                              
*  problem: https://codeforces.com/contest/792/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
long long int a[300009];
int main()
{
    long long int n,i,j,mn,mx,cnt,x,y,xx,yy;
    while(cin>>n)
    {
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        sort(a,a+n);
        mx=9999999999999;
        for(i=0;i<n-1;i++)
        {
            mn=abs(a[i]-a[i+1]);
            if(mn<=mx)mx=mn;
         }
        xx=-99999999999;
        yy=99999999999;
        cnt=0;
        for(i=0;i<n-1;i++)
        {
            x=a[i];
            y=a[i+1];
            mn=abs(x-y);
            if(mn==mx)
            {
                if(x!=xx||y!=yy)cnt++;
                xx=x;
                yy=y;
            }
         }
         cout<<mn<<" "<<cnt<<endl;
       }
      return 0;
}