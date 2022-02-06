/****************************************************************************************
*  @author: * kzvd4729                                       created: May/06/2018 21:39                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 624 ms                                          memory_used: 23900 KB                             
*  problem: https://codeforces.com/contest/977/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5+2;
int n,arr[N],dp[N];
map<int,vector<int> >pos;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>arr[i];
    int x=arr[i];
    if(pos[x].size()==0)
      pos[x].push_back(0);
    pos[x].push_back(i);
  }
  for(int i=1;i<=n;i++)
    dp[i]=1;
   for(int i=2;i<=n;i++)
  {
    int x=arr[i];
    if(pos[x].size()>1)
    {
      int id=upper_bound(pos[x].begin(),pos[x].end(),i)-pos[x].begin();
      id--;
      id=pos[x][id];
      if(id>=1&&id<=n)
        dp[i]=max(dp[i],dp[id]);
    }
    x--;
    if(pos[x].size()>1)
    {
      int id=upper_bound(pos[x].begin(),pos[x].end(),i)-pos[x].begin();
      id--;
      id=pos[x][id];
      if(id>=1&&id<=n)
        dp[i]=max(dp[i],dp[id]+1);
    }
  }
  int mx=0,num;
  for(int i=1;i<=n;i++)
  {
    if(dp[i]>mx)
    {
      mx=dp[i];
      num=arr[i];
    }
  }
  vector<int>ans;
  cout<<mx<<endl;
  for(int i=n;i>=1;i--)
  {
    if(dp[i]==mx&&arr[i]==num)
    {
      ans.push_back(i);
      mx--;
      num--;
    }
  }
  reverse(ans.begin(),ans.end());
  for(auto x:ans)
    cout<<x<<" ";
  cout<<endl;
  return 0;
}