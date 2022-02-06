/****************************************************************************************
*  @author: * kzvd4729                                       created: May/06/2018 20:43                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 31 ms                                           memory_used: 3400 KB                              
*  problem: https://codeforces.com/contest/977/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,arr[102],f;
vector<int>adj[102],ans;
void dfs(int id,int vs[],int cnt)
{
  vs[id]=1;
  cnt++;
  if(cnt==n)
  {
    f=1;
    return ;
  }
  for(auto x:adj[id])
  {
    if(vs[x])continue;
    dfs(x,vs,cnt);
    if(f==1)
    {
      ans.push_back(x);
      return ;
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)
    cin>>arr[i];
   for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      if(i==j)continue;
      if((arr[j]%2==0&&(arr[j]/2)==arr[i])||(arr[i]%3==0&&arr[i]/3==arr[j]))
        adj[i].push_back(j);
    }
  }
  for(int i=1;i<=n;i++)
  {
    int vis[102];
    memset(vis,0,sizeof(vis));
    dfs(i,vis,0);
    if(f)
    {
      cout<<arr[i]<<" ";
      break;
    }
  }
  reverse(ans.begin(),ans.end());
  for(auto x:ans)
    cout<<arr[x]<<" ";
  cout<<endl;
  return 0;
}