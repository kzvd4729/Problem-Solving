/****************************************************************************************
*  @author: kzvd4729                                         created:                                          
*  solution_verdict: 100 points                              language: C++                                     
*  run_time: 83 ms                                           memory_used: 10236 KB                             
*  problem: 
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int n,t,x,r1,r2;
vector<int>adj1[N+2],adj2[N+2];
bool dfs(int nod1,int nod2)
{
  if(adj1[nod1].size()!=adj2[nod2].size())return false;
  if(adj1[nod1].size()==0&&adj2[nod2].size()==0)return true;
  if(adj1[nod1].size()==1&&adj2[nod2].size()==1)return dfs(adj1[nod1][0],adj2[nod2][0]);
  return (dfs(adj1[nod1][0],adj2[nod2][0])&&dfs(adj1[nod1][1],adj2[nod2][1]))||(dfs(adj1[nod1][0],adj2[nod2][1])&&dfs(adj1[nod1][1],adj2[nod2][0]));
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>t;
  while(t--)
  {
    for(int i=0;i<=N;i++)adj1[i].clear();
    for(int i=0;i<=N;i++)adj2[i].clear();
    cin>>n;
    for(int i=1;i<=n;i++)
    {
      cin>>x;
      if(x==0)r1=i;
      else adj1[x].push_back(i);
    }
    for(int i=1;i<=n;i++)
    {
      cin>>x;
      if(x==0)r2=i;
      else adj2[x].push_back(i);
    }
    if(dfs(r1,r2))cout<<1<<endl;
    else cout<<0<<endl;
  }
  return 0;
}