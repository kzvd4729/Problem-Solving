/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/20/2018 19:05                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 233 ms                                          memory_used: 13400 KB                             
*  problem: https://codeforces.com/contest/45/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int aa[N+2],n;set<pair<int,pair<int,int> > >st;
int lt[N+2],rt[N+2],vis[N+2];
int _find_lt(int x)
{
  if(x==lt[x])return x;
  return lt[x]=_find_lt(lt[x]);
}
int _find_rt(int x)
{
  if(x==rt[x])return x;
  return rt[x]=_find_rt(rt[x]);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;string s;cin>>s;s="#"+s;
  for(int i=1;i<=n;i++)cin>>aa[i];
  for(int i=0;i<=n+1;i++)rt[i]=lt[i]=i;
  for(int i=1;i<n;i++)
  {
    if(s[i]!=s[i+1])
      st.insert({abs(aa[i]-aa[i+1]),{i,i+1}});
  }
  vector<pair<int,int> >ans;
  while(st.size())
  {
    pair<int,pair<int,int> >p=*st.begin();st.erase(p);
     int a=p.second.first,b=p.second.second;
    if(!vis[a]&&!vis[b])
    {
      ans.push_back(p.second);
      vis[a]=vis[b]=1;
       rt[b]=_find_rt(b+1);rt[a]=_find_rt(a+1);
      lt[a]=_find_lt(a-1);lt[b]=_find_lt(b-1);
       if(lt[a]>=1&&rt[b]<=n&&s[lt[a]]!=s[rt[b]])
        st.insert({abs(aa[lt[a]]-aa[rt[b]]),{lt[a],rt[b]}});
    }
  }
  cout<<ans.size()<<endl;
  for(auto x:ans)
    cout<<x.first<<" "<<x.second<<"\n";
  return 0;
}