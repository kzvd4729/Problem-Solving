/****************************************************************************************
*  @author: kzvd4729                                         created: May/02/2017 08:21                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/144/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,mx,mn,arr[110],ans,j;
    cin>>n;
    mx=0;
    mn=100;
    ans=0;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
        if(arr[i]>mx)
        {
            mx=arr[i];
        }
        if(arr[i]<mn)mn=arr[i];
    }
    for(i=0;i<n;i++)
    {
        if(arr[i]==mx)
        {
            ans=ans+i;
            j=i;
            break;
        }
    }
        for(i=n-1;i>=0;i--)
    {
        if(arr[i]==mn)
        {
            ans=ans+n-1-i;
            break;
        }
    }
    if(i<j)ans--;
    cout<<ans<<endl;
    return 0;
}