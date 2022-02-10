/****************************************************************************************
*  @author: kzvd4729                                         created:                                          
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 58 ms                                           memory_used: 1160 KB                              
*  problem: 
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,mat[303][303],tt,cnt[303],mx;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      cin>>mat[i][j];
    }
  }
  for(int k=1;k<=302;k++)
  {
    for(int i=1;i<=n;i++)
    {
      tt-=cnt[i];
      cnt[i]=0;
      for(int j=1;j<=n;j++)
      {
        cnt[j]+=mat[i][j];
        tt+=mat[i][j];
      }
      mx=max(mx,tt);
    }
  }
  cout<<mx<<endl;
  return 0;
}