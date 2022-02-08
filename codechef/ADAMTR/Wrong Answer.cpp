/****************************************************************************************
*  @author: kzvd4729                                         created: 20-01-2019 21:40:38                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.25 sec                                        memory_used: 22.9M                                
*  problem: https://www.codechef.com/COOK102A/problems/ADAMTR
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=(1<<10);
int aa[N+2][N+2],bb[N+2][N+2],n;
void transform(int x)
{
  for(int i=1;i<=n;i++)
    swap(aa[x][i],aa[i][x]);
}
bool ck(int x)
{
  for(int i=1;i<=n;i++)
    if(aa[x][i]!=bb[x][i])
      return false;
  return true;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    cin>>n;
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=n;j++)
      {
        cin>>aa[i][j];
      }
    }
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=n;j++)
      {
        cin>>bb[i][j];
      }
    }
    for(int i=1;i<=n;i++)
    {
      if(ck(i))continue;
      transform(i);
    }
    int ff=0;
    for(int i=1;i<=n;i++)
      if(!ck(i))ff=1;
    if(ff)cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
  }
  return 0;
}