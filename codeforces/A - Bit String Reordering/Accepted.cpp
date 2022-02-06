/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/17/2020 18:25                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 11800 KB                             
*  problem: https://codeforces.com/gym/100803/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int aa[N+2],bb[N+2],cc[N+2],n;
int cal()
{
  /*for(int i=1;i<=n;i++)
    cout<<bb[i]<<" ";
  cout<<endl;*/
  int cnt=0;
  for(int i=1;i<=n;i++)
  {
    if(aa[i]==0)cnt++;
    if(bb[i]==0)cnt--;
  }
  if(cnt!=0)return 1e9;
  int ret=0;
  for(int i=1;i<=n;i++)
  {
    int id;
    for(int j=i;j<=n;j++)
    {
      if(aa[j]==bb[i])
      {
        id=j;break;
      }
    }
    ret+=id-i;
    for(int j=id;j>i;j--)
      swap(aa[j],aa[j-1]);
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int m;cin>>n>>m;
  for(int i=1;i<=n;i++)cin>>aa[i],cc[i]=aa[i];
   int id=0,nw=0;
  for(int i=1;i<=m;i++)
  {
    int x;cin>>x;
    while(x--)bb[++id]=nw;
    nw^=1;
  }
  int ans=cal();
  for(int i=1;i<=n;i++)bb[i]^=1,aa[i]=cc[i];
  cout<<min(ans,cal())<<endl;
    return 0;
}