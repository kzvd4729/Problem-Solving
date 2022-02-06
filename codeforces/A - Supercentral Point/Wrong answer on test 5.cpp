/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/19/2018 15:10                        
*  solution_verdict: Wrong answer on test 5                  language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/165/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
int mxx[N+N+2],mxy[N+N+2],mnx[N+N+2],mny[N+N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;
  for(int i=0;i<=N+N;i++)
  {
    mny[i]=1e8,mnx[i]=1e8;
    mxy[i]=-1e8,mxx[i]=-1e8;
  }
  for(int i=1;i<=n;i++)
  {
    int x,y;cin>>x>>y;
    mxx[y+N]=max(mxx[y+N],x);
    mnx[y+N]=min(mnx[y+N],x);
    mxy[x+N]=max(mxy[x+N],y);
    mny[x+N]=min(mny[x+N],y);
  }
  //cout<<mxx[N+1]<<mnx[N+1]<<" "<<mxy[N+1]<<" "<<mny[N+1]<<endl;
  int ans=0;
  for(int i=-N;i<=N;i++)
  {
    for(int j=-N;j<=N;j++)
    {
      if(mxx[j+N]>i&&mxy[i+N]>j&&mnx[j+N]<i&&mny[i+N]<j)ans++;
    }
  }
  cout<<ans<<endl;
  return 0;
}