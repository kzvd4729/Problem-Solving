/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/12/2017 20:55                        
*  solution_verdict: Wrong answer on pretest 7               language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/839/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int n,k,arr[103],i,x;
int main()
{
    cin>>n>>k;
    for(i=1;i<=k;i++)
    {
        cin>>arr[i];
    }
    n=n*4;
    for(i=1;i<=k;i++)
    {
        x=arr[i]/2;
        if(arr[i]%2==1)x++;
        n=n-x;
    }
    if(n<0)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    return 0;
}