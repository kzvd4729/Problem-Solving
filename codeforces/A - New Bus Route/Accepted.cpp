/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/27/2017 21:45                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 436 ms                                          memory_used: 4200 KB                              
*  problem: https://codeforces.com/contest/792/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
long long int arr[300000];
int main()
{
    long long int n,i,j,x,mx,cnt;
    while(cin>>n)
    {
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        sort(arr,arr+n);
        mx=999999999999;
        cnt=0;
        for(i=0;i<n-1;i++)
        {
            x=abs(arr[i]-arr[i+1]);
            if(x<mx)mx=x;
        }
        for(i=0;i<n-1;i++)
        {
            x=abs(arr[i]-arr[i+1]);
            if(x==mx)cnt++;
        }
        cout<<mx<<" "<<cnt<<endl;
       }
      return 0;
}