/****************************************************************************************
*  @author: kzvd4729#                                        created: May/11/2017 13:52                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/719/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,arr[100];
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    if(arr[n]==0)cout<<"UP"<<endl;
    else if(arr[n]==15)cout<<"DOWN"<<endl;
    else if(n==1)cout<<-1<<endl;
    else
    {
        if(arr[n]-arr[n-1]==1)cout<<"UP"<<endl;
        else cout<<"DOWN"<<endl;
    }
    return 0;
}