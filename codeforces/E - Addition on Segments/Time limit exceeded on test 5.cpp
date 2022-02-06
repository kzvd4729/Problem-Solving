/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/17/2020 20:15                        
*  solution_verdict: Time limit exceeded on test 5           language: GNU C++14                               
*  run_time: 2000 ms                                         memory_used: 12300 KB                             
*  problem: https://codeforces.com/contest/981/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e4;
bitset<N+2>bt[N+2];
int aa[N+2];
bitset<N+2>doIT(int id)
{
  bitset<N+2>rt;rt[0]=1;
  for(int i=1;i<=N;i++)
    if(bt[id][i])rt|=(rt<<i);
  //cout<<rt<<endl;
  return rt;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,q;cin>>n>>q;
  for(int i=1;i<=q;i++)
  {
    int l,r,x;cin>>l>>r>>x;
    for(int j=l;j<=r;j++)bt[j][x]=1;
  }
  for(int i=1;i<=n;i++)aa[i]=i;
  sort(aa+1,aa+n+1,[](int a,int b){
    return bt[a].count()>bt[b].count();
  });
  bitset<N+2>f;
  for(int i=1;i<=n;i++)f|=doIT(aa[i]);
   int cnt=0;
  for(int i=1;i<=n;i++)if(f[i])cnt++;
  cout<<cnt<<endl;
  for(int i=1;i<=n;i++)if(f[i])cout<<i<<" ";cout<<endl;
   return 0;
}