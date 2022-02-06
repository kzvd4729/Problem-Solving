/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/13/2018 10:27                        
*  solution_verdict: Wrong answer on test 6                  language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 6500 KB                              
*  problem: https://codeforces.com/contest/189/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=2e5;
long n,a[N+2],b[N+2],ans,po[N+2];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
     cin>>n;
    for(long i=1; i<=n; i++)cin>>a[i];
    for(long i=1; i<=n; i++)
    {
        cin>>b[i];
        po[b[i]]=i;
    }
    for(long i=1;i<=n;i++)ans=max(ans,po[a[i]]-i);
    cout<<ans<<endl;
    return 0;
}