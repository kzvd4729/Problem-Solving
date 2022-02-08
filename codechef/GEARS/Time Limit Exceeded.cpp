/****************************************************************************************
*  @author: kzvd4729                                         created: 15-07-2018 23:56:03                      
*  solution_verdict: Time Limit Exceeded                     language: C++14                                   
*  run_time: 0.25 sec                                        memory_used: 16.8M                                
*  problem: https://www.codechef.com/JULY18A/problems/GEARS
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int arr[N+2],ty,n,m,u,v;
int bip[N+2],sz[N+2];
pair<int,int>parent[N+2];
pair<int,int>union_find(int node)
{
  if(node!=parent[node].first)
  {
    int parity=parent[node].second;
    parent[node]=union_find(parent[node].first);
    parent[node].second^=parity;
  }
  return parent[node];
}
void add_edge(int a,int b)
{
  pair<int,int>pa=union_find(a);
  pair<int,int>pb=union_find(b);
  a=pa.first;
  b=pb.first;
  if(a==b)
  {
    if(pa.second==pb.second)
      bip[a]=0,bip[b]=0;
    return ;
  }
  if(sz[a]<sz[b])swap(a,b);
  parent[b]={a,pa.second^pb.second^1};
  bip[a]&=bip[b];
  bip[b]&=bip[a];
  sz[a]+=sz[b];
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m;
  for(int i=1;i<=n;i++)
    cin>>arr[i];
  for(int i=1;i<=n;i++)
    parent[i]={i,0},bip[i]=1;
  while(m--)
  {
    cin>>ty>>u>>v;
    if(ty==1)
      arr[u]=v;
    else if(ty==2)
      add_edge(u,v);
    else
    {
      int x;
      cin>>x;
      pair<int,int>pa=union_find(u);
      pair<int,int>pb=union_find(v);
      if(!bip[pa.first]||!bip[pb.first])
        cout<<0<<endl;
      else if(pa.first!=pb.first)
        cout<<0<<endl;
      else
      {
        long tmp=arr[u]*x;
        long gcd=__gcd(tmp,arr[v]*1LL);
        if(pa.second==pb.second)cout<<tmp/gcd<<"/"<<arr[v]/gcd<<endl;
        else cout<<-(tmp/gcd)<<"/"<<arr[v]/gcd<<endl;
      }
    }
  }
  return 0;
}