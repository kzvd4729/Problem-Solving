/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/14/2019 19:52                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 6400 KB                              
*  problem: https://codeforces.com/contest/1209/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
const int inf=1e9;
int mn[10],mx[10],vis[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,print=0;cin>>n;string s;cin>>s;
    for(int i=0;i<10;i++)mn[i]=inf,mx[i]=0;
    for(int i=0;i<s.size();i++)
    {
      int x=s[i]-'0';
      mn[x]=min(mn[x],i);mx[x]=max(mx[x],i);
    }
    for(int i=0;i<10;i++)
    {
      int rt=-1,f=0;int ra=n+1,rb;
      for(int j=0;j<=i;j++)
      {
        if(mn[j]==inf)continue;
        if(mn[j]<=rt)f=1;
        rt=mx[j];
      }
      rb=rt;
      rt=-1;
      for(int j=i+2;j<10;j++)
      {
        if(mn[j]==inf)continue;
        if(mn[j]<=rt)f=1;
        if(ra==n+1)ra=mn[j];
        rt=mx[j];
      }
      if(!f)
      {
        for(int j=0;j<n;j++)vis[j]=0;
        for(int j=0;j<n;j++)
        {
          if(s[j]-'0'<=i)vis[j]=1;
          if(s[j]-'0'>=i+2)vis[j]=2;
        }
        for(int j=n-1;j>=0;j--)
        {
          if(vis[j]==1)break;
          if(vis[j]==0)vis[j]=1;
        }
        for(int j=0;j<n;j++)
          if(vis[j]==0)vis[j]=2;
         vector<int>v;
        for(int i=0;i<n;i++)
          if(vis[i]==1)v.push_back(s[i]-'0');
        for(int i=0;i<n;i++)
          if(vis[i]==2)v.push_back(s[i]-'0');
        int ng=0;
        for(int i=1;i<v.size();i++)
        {
          if(v[i]<v[i-1])ng=1;
        }
        if(ng)continue;
        for(int j=0;j<n;j++)
          cout<<vis[j];
        cout<<"\n";
        print=1;
        break;
      }
    }
    if(!print)cout<<"-"<<"\n";
  }
  return 0;
}