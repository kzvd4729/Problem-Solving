/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/25/2018 23:46                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 3500 KB                              
*  problem: https://codeforces.com/contest/723/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int x,n,m,mn,cnt,ans[2002];
vector<int>v[2002];
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    cin>>x;
    ans[i]=x;
    if(x>m)v[0].push_back(i);
    else v[x].push_back(i);
  }
  mn=n/m;
  for(int i=1;i<=m;i++)
  {
    for(int j=v[i].size();j<mn;j++)
    {
      if(!v[0].size())break;
      x=v[0].back();
      v[0].pop_back();
      v[i].push_back(x);
      cnt++;
    }
  }
  priority_queue<pair<int,int> >pq;
  for(int i=1;i<=m;i++)pq.push({v[i].size(),i});
  for(int i=1;i<=m;i++)
  {
    for(int j=v[i].size();j<mn;j++)
    {
      pair<int,int>p=pq.top();
      pq.pop();
      pq.push({p.first-1,p.second});
      x=v[p.second].back();
      v[p.second].pop_back();
      v[i].push_back(x);
      cnt++;
    }
  }
  for(int i=1;i<=m;i++)for(auto x:v[i])ans[x]=i;
  cout<<mn<<" "<<cnt<<endl;
  for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
  cout<<endl;
  return 0;
}