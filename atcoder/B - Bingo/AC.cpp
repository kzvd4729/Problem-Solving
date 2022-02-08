/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-03-01 18:07:08                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 1 ms                                            memory_used: 256 KB                               
*  problem: https://atcoder.jp/contests/abc157/tasks/abc157_b
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int mt[5][5];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  for(int i=1;i<=3;i++)
  {
    for(int j=1;j<=3;j++)
      cin>>mt[i][j];
  }
  int q;cin>>q;
  while(q--)
  {
    int x;cin>>x;
    for(int i=1;i<=3;i++)
    {
      for(int j=1;j<=3;j++)
        if(mt[i][j]==x)mt[i][j]=-1;
    }
  }
  int f=0;
  for(int i=1;i<=3;i++)
  {
    if(mt[i][1]==-1&&mt[i][2]==-1&&mt[i][3]==-1)f=1;
    if(mt[1][i]==-1&&mt[2][i]==-1&&mt[3][i]==-1)f=1;
  }
  if(mt[3][1]==-1&&mt[2][2]==-1&&mt[1][3]==-1)f=1;
  if(mt[1][1]==-1&&mt[2][2]==-1&&mt[3][3]==-1)f=1;
  if(f)cout<<"Yes\n";else cout<<"No\n";
  return 0;
}