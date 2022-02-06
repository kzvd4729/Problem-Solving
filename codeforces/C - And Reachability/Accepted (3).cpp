/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/12/2019 09:30                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 670 ms                                          memory_used: 25800 KB                             
*  problem: https://codeforces.com/contest/1168/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=3e5;
const int B=19;
int aa[N+2],nx[N+2][B+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,q;cin>>n>>q;
  for(int i=1;i<=n;i++)cin>>aa[i];
  for(int j=0;j<=B;j++)nx[n+1][j]=n+1;
  for(int i=n;i>=1;i--)
  {
    for(int j=0;j<=B;j++)
    {
      nx[i][j]=nx[i+1][j];
      if(!(aa[i]&(1<<j)))continue;
      nx[i][j]=i;
    }
  }
  while(q--)
  {
    int x,y;cin>>x>>y;
    int id=x+1,f=0,now=aa[x];
    while(true)
    {
      if((now&aa[y])){f=1;break;}
      if(id>=y)break;
      int cmn=n+1,umn=n+1;
      for(int i=0;i<=B;i++)
      {
        if(now&(1<<i))cmn=min(cmn,nx[id][i]);
        else umn=min(umn,nx[id][i]);
      }
      if(cmn==umn&&cmn<y)now|=aa[cmn],id=cmn+1;
      else id=max(cmn,umn);
    }
    if(f)cout<<"Shi\n";
    else cout<<"Fou\n";
  }
  return 0;
}