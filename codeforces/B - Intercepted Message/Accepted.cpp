/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/13/2018 17:31                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 61 ms                                           memory_used: 3400 KB                              
*  problem: https://codeforces.com/contest/950/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e5;
long n,m,a[N+2],b[N+2];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
     cin>>n>>m;
    for(long i=1;i<=n;i++)cin>>a[i];
    for(long i=1;i<=m;i++)cin>>b[i];
    long p1=0,p2=0,s1=0,s2=0,ans=0;
    while(true)
    {
      if(s1<s2)s1+=a[++p1];
      else s2+=b[++p2];
      if(s1==s2)ans++;
      ///cout<<s1<<" "<<s2<<endl;
      if(p1==n&&p2==m)break;
    }
    cout<<ans<<endl;
    return 0;
}