/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/21/2017 23:12                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/449/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
long long int n,m,k,x,ans,kk;
int main()
{
    cin>>n>>m>>k;
    if(k>n+m-2)
    {
        cout<<-1<<endl;
        return 0;
    }
    kk=k;
    if(k<n)
    {
        ans=m*(n/(k+1));
    }
    else
    {
        k=k-(n-1);
        ans=max(ans,m/(k+1));
    }
    k=kk;
    if(k<m)
    {
        ans=max(ans,n*(m/(k+1)));
    }
    else
    {
        k=k-(m-1);
        ans=max(ans,n/(k+1));
    }
    cout<<ans<<endl;
    return 0;
}