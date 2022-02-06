/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/23/2017 22:57                        
*  solution_verdict: Wrong answer on test 49                 language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 2600 KB                              
*  problem: https://codeforces.com/contest/893/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,d,tr[100005],now,ans,f,hi;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n>>d;
    for(long i=1;i<=n;i++)
    {
        cin>>tr[i];
    }
    for(long i=1;i<=n;i++)
    {
        now+=tr[i];
        if(now>d)
        {
            hi=hi-(now-d);
            now=d;
        }
        if(hi<0)f=1;
        if(tr[i]==0&&now<0)
        {
            ans++;
            hi=d;
            now=d;
        }
    }
    if(f==1)cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}