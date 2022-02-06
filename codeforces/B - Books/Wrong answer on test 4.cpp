/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/28/2017 19:00                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 2600 KB                              
*  problem: https://codeforces.com/contest/279/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,t,i,arr[100005],x,xx,lo,hi,mid;
    while(cin>>n>>t)
    {
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        arr[n]=999999999;
        for(i=1;i<=n;i++)
        {
            arr[i]=arr[i]+arr[i-1];
        }
        xx=0;
         for(i=0;i<n;i++)
        {
            lo=i;
            hi=n;
            while(lo<=hi)
            {
                mid=(lo+hi)/2;
                if(arr[mid]-arr[i]<=t&&arr[mid+1]-arr[i]>t)
                {
                    break;
                }
                if(arr[mid]-arr[i]<t)
                {
                    lo=mid+1;
                }
                else hi=mid-1;
             }
             x=(mid-i);
            if(x>xx)
            {
                xx=x;
            }
          }
        cout<<xx<<endl;
     }
     return 0;
}