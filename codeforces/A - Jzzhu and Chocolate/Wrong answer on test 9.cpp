/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/21/2017 23:01                        
*  solution_verdict: Wrong answer on test 9                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/449/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
long long int n,m,k,x,ans,ans1,ans2,ans3;
int main()
{
    cin>>n>>m>>k;
    if(k>n+m-2)
    {
        cout<<-1<<endl;
        return 0;
    }
    if(k<n)
    {
        x=n/(k+1);
        ans=x*m;
    }
    else
    {
        k=k-n+1;
        ans=m/(k+1);
    }
    if(k<m)
    {
        x=m/(k+1);
        ans2=x*n;
    }
    else
    {
        k=k-m+1;
        ans2=n/(k+1);
    }
    swap(n,m);
    if(k<n)
    {
        x=n/(k+1);
        ans1=x*m;
    }
    else
    {
        k=k-n+1;
        ans1=m/(k+1);
    }
    if(k<m)
    {
        x=m/(k+1);
        ans3=x*n;
    }
    else
    {
        k=k-m+1;
        ans3=n/(k+1);
    }
    cout<<max(ans2,max(ans3,max(ans,ans1)))<<endl;
        return 0;
}