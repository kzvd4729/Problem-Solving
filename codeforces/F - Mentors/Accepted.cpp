/****************************************************************************************
*  @author: kzvd4729                                         created: May/14/2018 20:11                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 2199 ms                                         memory_used: 82800 KB                             
*  problem: https://codeforces.com/contest/978/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
const int rn=1e9;
int skl[N+2],cnt[N+2],n,m,u,v;
map<int,int>bit;
void upd(int idx)
{
  for( ;idx<=rn;idx+=idx&-idx)
    bit[idx]=bit[idx]+1;
}
int query(int idx)
{
  int sum=0;
  for( ;idx>0;idx-=idx&-idx)
    sum+=bit[idx];
  return sum;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    cin>>skl[i];
    upd(skl[i]);
  }
  while(m--)
  {
    cin>>u>>v;
    if(skl[u]>skl[v])cnt[u]++;
    if(skl[v]>skl[u])cnt[v]++;
  }
  for(int i=1;i<=n;i++)
    cout<<query(skl[i]-1)-cnt[i]<<" ";
  cout<<endl;
  return 0;
}