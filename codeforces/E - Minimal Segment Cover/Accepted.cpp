/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/24/2019 23:23                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 436 ms                                          memory_used: 47000 KB                             
*  problem: https://codeforces.com/contest/1175/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e5,pas=20;
int aa[N+2],mx[N+2],nex[N+2][pas+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    int a,b;cin>>a>>b;
    aa[a]=max(aa[a],b);
  }
  mx[0]=aa[0];
  for(int i=1;i<=N;i++)
    mx[i]=max(mx[i-1],aa[i]);
  for(int i=N;i>=0;i--)
  {
    nex[i][0]=mx[i];
    for(int j=1;j<=pas;j++)
      nex[i][j]=max(nex[i][j-1],nex[nex[i][j-1]][j-1]);
  }
  while(m--)
  {
    int x,y,ans=1;cin>>x>>y;
    if(nex[x][pas]<y){cout<<-1<<" ";continue;}
    for(int j=pas;j>=0;j--)
    {
      if(nex[x][j]<y)
        ans+=(1<<j),x=nex[x][j];
    }
    cout<<ans<<" ";
  }
  return 0;
}