/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/05/2019 22:01                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 78 ms                                           memory_used: 100 KB                               
*  problem: https://codeforces.com/contest/1132/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e3;
int lt[N+2],rt[N+2],cnt[N+2],qm[3][N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
  for(int i=1;i<=k;i++)
  {
    cin>>lt[i]>>rt[i];
    for(int j=lt[i];j<=rt[i];j++)
      cnt[j]++;
  }
  int sm=0;
  for(int i=1;i<=n;i++)
  {
    if(cnt[i])sm++;
    qm[1][i]=qm[1][i-1];qm[2][i]=qm[2][i-1];
    if(cnt[i]==1)qm[1][i]++;
    if(cnt[i]==2)qm[2][i]++;
  }
  int ans=0;
  for(int i=1;i<=k;i++)
  {
    for(int j=i+1;j<=k;j++)
    {
      int sum=sm;
      sum-=(qm[1][rt[i]]-qm[1][lt[i]-1]);
      sum-=(qm[1][rt[j]]-qm[1][lt[j]-1]);
       int a=max(lt[i],lt[j]);
      int b=min(rt[i],rt[j]);
       if(a<=b)
        sum-=(qm[2][b]-qm[2][a-1]);
      ans=max(ans,sum);
    }
  }
  cout<<ans<<endl;
  return 0;
}