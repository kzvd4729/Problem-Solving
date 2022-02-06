/****************************************************************************************
*  @author: * kzvd4729                                       created: Jul/16/2018 20:47                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 100 KB                               
*  problem: https://codeforces.com/contest/1006/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,x,sum,k;
priority_queue<pair<int,int> >pq;
vector<pair<int,int>>ans;
bool cmp(pair<int,int>a,pair<int,int>b)
{
  return a.second<b.second;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>k;
  for(int i=1;i<=n;i++)
  {
    cin>>x;
    pq.push({x,i});
  }
  while(k--)
  {
    sum+=pq.top().first;
    ans.push_back(pq.top());
    pq.pop();
  }
  cout<<sum<<endl;
  sort(ans.begin(),ans.end(),cmp);
  int id=0;
  for(int i=0;i<ans.size();i++)
  {
    if(i==ans.size()-1)cout<<n-id<<" ";
    else cout<<ans[i].second-id<<" ";
    id=ans[i].second;
  }
  cout<<endl;
  return 0;
}