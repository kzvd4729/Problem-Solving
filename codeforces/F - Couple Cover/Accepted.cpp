/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/15/2019 18:32                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 935 ms                                          memory_used: 58700 KB                             
*  problem: https://codeforces.com/contest/691/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=3e6;
int aa[N+2],fr[N+2],qm[N+2];
long ans[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;fr[x]++;
  }
  int id=0;
  for(int i=1;i<=N;i++)if(fr[i])aa[++id]=i;
  for(int i=N;i>=1;i--)qm[i]=qm[i+1]+fr[i];
  for(int i=1;i<=id;i++)
  {
    ans[min(1LL*N,1LL*aa[i]*aa[i])]+=(1LL*fr[aa[i]]*(fr[aa[i]]-1))/2;
    for(int j=i+1;j<=id;j++)
    {
      if(1LL*aa[i]*aa[j]>1LL*N)
      {
        ans[N]+=(1LL*fr[aa[i]]*qm[aa[j]]);
        break;
      }
      ans[aa[i]*aa[j]]+=(1LL*fr[aa[i]]*fr[aa[j]]);
    }
  }
  for(int i=N;i>=1;i--)ans[i]+=ans[i+1];
  int q;cin>>q;
  while(q--)
  {
    int x;cin>>x;cout<<ans[x]*2LL<<"\n";
  }
  return 0;
}