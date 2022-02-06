/****************************************************************************************
*  @author: * kzvd4729                                       created: Feb/05/2021 22:00                        
*  solution_verdict: Wrong answer on pretest 3               language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 23500 KB                             
*  problem: https://codeforces.com/contest/1481/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9,mod=1e9+7;
 string s[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>s[i],s[i]="*"+s[i];
     if(n==2)
    {
      int now=1;
      if((s[1][2]==s[2][1])||(m%2))
      {
        cout<<"YES\n";
        for(int i=1;i<=m+1;i++)
        {
          cout<<now<<" ";
          if(now==1)now=2;else now=1;
        }
        cout<<'\n';
      }
      else cout<<"NO\n";
      continue;
    }
    cout<<"YES\n";int a=-1,b=-1;
    for(int i=1;i<=n;i++)
    {
      for(int j=i+1;j<=n;j++)
      {
        if(s[i][j]==s[j][i])a=i,b=j;
      }
    }
    if(a!=-1)
    {
      int now=a;
      for(int i=1;i<=m+1;i++)
      {
        cout<<now<<" ";
        if(now==a)now=b;else now=a;
      }
      cout<<'\n';
      continue;
    }
    a=1,b=2;
    if(m%2)
    {
      int now=a;
      for(int i=1;i<=m+1;i++)
      {
        cout<<now<<" ";
        if(now==a)now=b;else now=a;
      }
      cout<<'\n';
      continue; 
    }
    a=-1,b=-1;int md;
    for(int i=1;i<=n;i++)
    {
      int in=-1,ot=-1;
      for(int j=1;j<=n;j++)
      {
        if(s[j][i]=='a'){in=j;break;}
      }
      for(int j=1;j<=n;j++)
      {
        if(s[i][j]=='a'){ot=j;break;}
      }
      if(in!=-1&&ot!=-1){a=in,b=ot,md=i;break;}
    }
    if(a==-1)assert(0);
     cout<<a<<" ";int now=md;
    for(int i=1;i<=m/2;i++)
    {
      cout<<now<<" ";
      if(now==a)now=md;else now=a;
    }
    now=b;
    for(int i=1;i<=m/2;i++)
    {
      cout<<now<<" ";
      if(now==b)now=md;else now=b;
    }
    cout<<'\n';
   }
  return 0;
}