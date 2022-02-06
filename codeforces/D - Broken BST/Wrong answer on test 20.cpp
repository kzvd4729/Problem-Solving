/****************************************************************************************
*  @author: kzvd4729                                         created: May/09/2019 18:45                        
*  solution_verdict: Wrong answer on test 20                 language: GNU C++14                               
*  run_time: 124 ms                                          memory_used: 4500 KB                              
*  problem: https://codeforces.com/contest/797/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int nd[N+2],lt[N+2],rt[N+2],cnt;
void dfs(int node,int lo,int hi)
{
  if(nd[node]>=lo&&nd[node]<=hi)cnt++;
  if(lt[node]!=-1)
    dfs(lt[node],lo,min(hi,nd[node]-1));
  if(rt[node]!=-1)
    dfs(rt[node],max(lo,nd[node]),hi);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;set<int>st;
  for(int i=1;i<=n;i++)st.insert(i);
  for(int i=1;i<=n;i++)
  {
    cin>>nd[i]>>lt[i]>>rt[i];
    if(st.find(lt[i])!=st.end())st.erase(lt[i]);
    if(st.find(rt[i])!=st.end())st.erase(rt[i]);
  }
  int root=*st.begin();
  dfs(root,0,1e9);cout<<n-cnt<<endl;
  return 0;
}