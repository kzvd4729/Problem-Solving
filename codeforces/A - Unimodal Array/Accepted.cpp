/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/13/2017 21:26                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/831/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int n,i,f,arr[103],l,r,mid;
int main()
{
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cin>>arr[i];
    }
    if(n==1)
    {
        cout<<"YES"<<endl;
        return 0;
    }
    f=0;
    for(i=1; i<n; i++)
    {
        if(arr[i]==arr[i+1])
        {
            f=1;
            l=i;
            break;
        }
    }
    for(i=n; i>1; i--)
    {
        if(arr[i]==arr[i-1])
        {
            r=i;
            break;
        }
    }
    if(f==1)
    {
        for(i=l; i<r; i++)
        {
            if(arr[i]!=arr[i+1])
            {
                cout<<"NO"<<endl;
                return 0;
            }
        }
        for(i=1; i<l; i++)
        {
            if(arr[i]>arr[i+1])
            {
                cout<<"NO"<<endl;
                return 0;
            }
        }
         for(i=r; i<n; i++)
        {
            if(arr[i]<arr[i+1])
            {
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }
    f=0;
    for(i=1;i<n;i++)
    {
        if(arr[i]>arr[i+1])f=1;
    }
    if(f==0)
    {
        cout<<"YES"<<endl;
        return 0;
    }
    f=0;
    for(i=1;i<n;i++)
    {
        if(arr[i]<arr[i+1])f=1;
    }
    if(f==0)
    {
        cout<<"YES"<<endl;
        return 0;
    }
     for(i=1;i<n;i++)
    {
        if(arr[i]>arr[i+1])
        {
            mid=i;
            break;
        }
    }
    for(i=mid;i<n;i++)
    {
        if(arr[i]<arr[i+1])
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
     cout<<"YES"<<endl;
      return 0;
}