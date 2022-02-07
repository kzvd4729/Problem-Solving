/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-09-05 18:50:23                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 230                                             memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-524
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=16;
int vis[102],tc;
bool prime(int x)
{
  for(int i=2;i<x;i++)
    if(x%i==0)return false;
  return true;
}
int n;
void dfs(int st,int last,int msk,vector<int>v)
{
  if(st>n)
  {
    if(vis[last+1]==0)return ;
    for(int i=0;i<v.size();i++)
    {
      if(i)cout<<" ";
      cout<<v[i];
    }
    cout<<endl;
  }
  for(int i=2;i<=n;i++)
  {
    if(msk&(1<<i))continue;
    if(vis[last+i])
    {
      vector<int>tmp=v;
      tmp.push_back(i);
      dfs(st+1,i,msk|(1<<i),tmp);
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  for(int i=2;i<=100;i++)
    if(prime(i))vis[i]=1;
  int f=0;
  while(cin>>n)
  {
    if(f)cout<<endl;f=1;
    cout<<"Case "<<++tc<<":"<<endl;
    vector<int>v;v.push_back(1);
    dfs(2,1,(1<<1),v);
  }
  return 0;
}