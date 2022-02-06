/****************************************************************************************
*  @author: * kzvd4729                                       created: Feb/19/2019 21:03                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1118/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
int fr[N+2],mt[N+2][N+2];
int _find(int vl)
{
  for(int i=1;i<=N;i++)
  {
    if(fr[i]>=vl)
    {
      fr[i]-=vl;return i;
    }
  }
  return -1;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n*n;i++)
  {
    int x;cin>>x;fr[x]++;
  }
  memset(mt,-1,sizeof(mt));
  if(n%2==0)
  {
    for(int i=1;i<=n/2;i++)
    {
      for(int j=1;j<=n/2;j++)
      {
        int x=_find(4);
        if(x==-1)cout<<"NO"<<endl,exit(0);
        mt[i][j]=x;mt[n-i+1][j]=x;
        mt[i][n-j+1]=x;mt[n-i+1][n-j+1]=x;
      }
    }
  }
  else
  {
    for(int i=1;i<=n/2;i++)
    {
      for(int j=1;j<=n/2;j++)
      {
        int x=_find(4);
        if(x==-1)cout<<"NO"<<endl,exit(0);
        mt[i][j]=x;mt[n-i+1][j]=x;
        mt[i][n-j+1]=x;mt[n-i+1][n-j+1]=x;
      }
    }
    int md=n/2+1;
    for(int i=1;i<=n/2;i++)
    {
      int x=_find(2);
      if(x==-1)cout<<"NO"<<endl,exit(0);
      mt[i][md]=x;mt[n-i+1][md]=x;
    }
    for(int j=1;j<=n/2;j++)
    {
      int x=_find(2);
      if(x==-1)cout<<"NO"<<endl,exit(0);
      mt[md][j]=x;mt[md][n-j+1]=x;
    }
    int x=_find(1);
    if(x==-1)cout<<"NO"<<endl,exit(0);
    mt[md][md]=x;
  }
  cout<<"YES"<<endl;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      cout<<mt[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}