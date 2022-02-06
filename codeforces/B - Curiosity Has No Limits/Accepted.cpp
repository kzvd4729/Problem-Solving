/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/21/2018 14:35                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 78 ms                                           memory_used: 7600 KB                              
*  problem: https://codeforces.com/contest/1072/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int aa[N+2],bb[N+2],vis[N+2][4],n;
vector<int>ans;
void dfs(int st,int ls)
{
  if(st>n)
  {
    cout<<"YES"<<endl;
    for(auto x:ans)
      cout<<x<<" ";
    cout<<endl;
    exit(0);
  }
  if(vis[st][ls])return ;
  vis[st][ls]=1;
   for(int i=0;i<=3;i++)
  {
    if(((ls|i)==aa[st-1])&&((ls&i)==bb[st-1]))
    {
      ans.push_back(i);
      dfs(st+1,i);
      ans.pop_back();
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>n;
  for(int i=1;i<n;i++)
    cin>>aa[i];
  for(int i=1;i<n;i++)
    cin>>bb[i];
   ans.push_back(0);
  dfs(2,0);ans.pop_back();
   ans.push_back(1);
  dfs(2,1);ans.pop_back();
   ans.push_back(2);
  dfs(2,2);ans.pop_back();
   ans.push_back(3);
  dfs(2,3);ans.pop_back();
   cout<<"NO"<<endl;
   return 0;
}