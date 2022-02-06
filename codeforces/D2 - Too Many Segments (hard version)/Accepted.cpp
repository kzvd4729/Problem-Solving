/****************************************************************************************
*  @author: * kzvd4729                                       created: Oct/22/2019 21:29                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 233 ms                                          memory_used: 26000 KB                             
*  problem: https://codeforces.com/contest/1249/problem/D2
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int uu[N+2],vv[N+2],vis[N+2];
pair<int,int>pp[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
  for(int i=1;i<=n;i++)
  {
    cin>>uu[i]>>vv[i];
    pp[2*i]={uu[i],-i};pp[2*i-1]={vv[i],i};
  }
  sort(pp+1,pp+2*n+1);
   set<pair<int,int> >st;int cnt=0;vector<int>ans;
  for(int i=1;i<=2*n;i++)
  {
    int id=abs(pp[i].second);
    if(pp[i].second<0)
    {
      cnt++;st.insert({vv[id],id});
      if(cnt>k)
      {
        cnt--;
        pair<int,int>p=*st.rbegin();st.erase(p);
        vis[p.second]=1;ans.push_back(p.second);
      }
    }
    else
    {
      if(!vis[id])cnt--;
    }
  }
  cout<<ans.size()<<endl;sort(ans.begin(),ans.end());
  for(auto x:ans)
    cout<<x<<" ";
  cout<<endl;
  return 0;
}