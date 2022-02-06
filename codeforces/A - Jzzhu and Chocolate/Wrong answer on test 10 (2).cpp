/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/21/2017 22:57                        
*  solution_verdict: Wrong answer on test 10                 language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/449/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
long long int n,m,k,x,ans;
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
        k=k-(n-1);
        ans=max(ans,m/(k+1));
    }
    if(k<m)
    {
        x=m/(k+1);
        ans=max(ans,x*n);
    }
    else
    {
        k=k-(m-1);
        ans=max(ans,n/(k+1));
    }
    cout<<ans<<endl;
        return 0;
}