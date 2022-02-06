/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/24/2019 20:58                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/1152/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
map<int,int>vis;
int _find(int x)
{
  int f=0;
  for(int i=21;i>=0;i--)
  {
    if((x&(1<<i)))f=1;
    else
    {
      if(f)return i;
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  for(int i=0;i<30;i++)
    vis[(1<<i)-1]=1;
  int x,f=0;cin>>x;
  if(vis[x])cout<<0<<endl,exit(0);
  vector<int>ans;
  for(int i=1;i<=40;i++)
  {
    if(i%2)
    {
      int c=_find(x);ans.push_back(c+1);
      x^=((1<<(c+1))-1);
    }
    else x++;
    if(vis[x])
    {
      f=1;cout<<i<<endl;
      break;
    }
  }
  if(!f)assert(0);
  for(auto x:ans)
    cout<<x<<" ";
  cout<<endl;
   return 0;
}