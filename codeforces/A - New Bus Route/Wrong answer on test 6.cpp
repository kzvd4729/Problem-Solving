/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/27/2017 20:56                        
*  solution_verdict: Wrong answer on test 6                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 4200 KB                              
*  problem: https://codeforces.com/contest/792/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
long long int a[300003];
int main()
{
    long long int n,i,j,mn,x,cnt;
    while(cin>>n)
    {
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        sort(a,a+n);
        x=9999999999999;
        cnt=0;
        for(i=0;i<n-1;i++)
        {
            mn=abs(a[i]-a[i+1]);
            if(mn<x)
            {
                x=mn;
                cnt=1;
            }
            else if(mn==x)
            {
                cnt++;
            }
         }
        cout<<mn<<" "<<cnt<<endl;
       }
      return 0;
}