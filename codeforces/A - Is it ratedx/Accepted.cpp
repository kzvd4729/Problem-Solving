/****************************************************************************************
*  @author: kzvd4729                                         created: May/07/2017 22:02                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/807/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,a,b,f=0,g=0,arr[10004];
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a>>b;
        arr[i]=a;
        if(a!=b)f=1;
    }
    for(i=1;i<n;i++)
    {
        if(arr[i]<arr[i+1])
        {
            g=1;
        }
    }
    if(f==1)cout<<"rated"<<endl;
    else 
    {
        if(g==1)cout<<"unrated"<<endl;
        else cout<<"maybe"<<endl;
    }
    return 0;
}