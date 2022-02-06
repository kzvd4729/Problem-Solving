/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/10/2019 20:12                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 202 ms                                          memory_used: 12000 KB                             
*  problem: https://codeforces.com/gym/102215/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int aa[N+2],ls[N+2],ans[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>aa[i];
   int rt=n+1;
  for(int i=n;i>=1;i--)
  {
    if(aa[i]<0)
    {
      if(ls[-aa[i]])rt=min(rt,ls[-aa[i]]);
    }
    else ls[aa[i]]=i;
    ans[i]=rt-i;
  }
  for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
    cout<<endl;
  return 0;
}