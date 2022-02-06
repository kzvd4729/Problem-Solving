/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/21/2017 22:56                        
*  solution_verdict: Wrong answer on test 11                 language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/449/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
long long int n,m,k,x,ans,ans1;
int main()
{
    cin>>n>>m>>k;
    if(k>n+m-2)
    {
        cout<<-1<<endl;
        return 0;
    }
    k++;
    if(n%k>m%k)swap(n,m);
    if(k<=n)
    {
        x=n/k;
        ans=x*m;
    }
    else
    {
        k=k-n;
        ans=m/k;
    }
    cout<<ans<<endl;
    return 0;
}