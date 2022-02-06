/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/12/2020 16:46                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/1299/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int aa[N+2],cnt[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;aa[i]=x;
    for(int j=0;j<31;j++)
    {
      if(x&(1<<j))cnt[j]++;
    }
  }
  int mx=0;
  for(int i=1;i<=n;i++)
  {
    int now=0,x=aa[i];
    for(int j=0;j<31;j++)
    {
      if((x&(1<<j))&&cnt[j]==1)
        now|=(1<<j);
    }
    if(now>mx)mx=now,swap(aa[1],aa[i]);
  }
  for(int i=1;i<=n;i++)
    cout<<aa[i]<<" ";
  cout<<endl;
    return 0;
}