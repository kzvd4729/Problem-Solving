/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/18/2018 17:31                        
*  solution_verdict: Time limit exceeded on test 36          language: GNU C++14                               
*  run_time: 2000 ms                                         memory_used: 93000 KB                             
*  problem: https://codeforces.com/contest/732/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int soc[N+2],com[N+2],sck[N+2],c,u;
int n,m,vis[N+2],x;
map<int,vector<int> >mp;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    cin>>x;
    mp[x].push_back(i);
  }
  for(int i=1;i<=m;i++)
    cin>>soc[i];
  for(int p=0;p<=32;p++)
  {
    for(int i=1;i<=m;i++)
    {
      if(vis[i])continue;
      if(mp[soc[i]].size())
      {
        int x=mp[soc[i]].back();
        mp[soc[i]].pop_back();
        c++;
        u+=p;
        com[x]=i;
        sck[i]=p;
        vis[i]=1;
      }
      if(soc[i]==1)vis[i]=1;
      soc[i]=(soc[i]+1)/2;
    }
  }
  cout<<c<<" "<<u<<endl;
  for(int i=1;i<=m;i++)
    cout<<sck[i]<<" ";
  cout<<endl;
  for(int i=1;i<=n;i++)
    cout<<com[i]<<" ";
  cout<<endl;
  return 0;
}