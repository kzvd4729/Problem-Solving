/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/19/2019 17:06                        
*  solution_verdict: Wrong answer on test 14                 language: GNU C++14                               
*  run_time: 140 ms                                          memory_used: 10500 KB                             
*  problem: https://codeforces.com/contest/1172/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int aa[N+2],bb[N+2],vis[N+2],vs[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;deque<int>dq;set<int>st;int cnt=0;
  for(int i=1;i<=n;i++)
  {
    cin>>aa[i];vis[aa[i]]=1;
    vs[aa[i]]=1;
    if(!aa[i])cnt++;
    else st.insert(aa[i]);
  }
  for(int i=1;i<=n;i++)
  {
    cin>>bb[i];dq.push_back(bb[i]);
  }
  int f=0;
  for(int i=1;i<=n;i++)
  {
    if(bb[i]==1)
    {
      for(int j=i+1;j<=n;j++)
        if(bb[j]!=bb[j-1]+1)f=1;
      break;
    }
  }
  int tar=1,ans=0,an=0,pt=1;
  if(!f)tar=bb[n]+1;
  int tr=tar;f=0;
  while(true)
  {
    if(tr>n){f=1;break;}
    if(vs[tr])tr++;
    else break;
    if(pt<=n)vs[bb[pt++]]=1;
    an++;
  }
  if(f)cout<<an<<endl,exit(0);
  tar=1;
  while(true)
  {
    if(vis[tar])tar++;
    else
    {
      if(cnt)dq.push_back(0),cnt--;
      else
      {
        dq.push_back(*st.rbegin()),st.erase(*st.rbegin());
        vis[*st.rbegin()]=0;
      }
    }
    if(tar>n){ans++;break;}
    vis[dq.front()]=1;
    if(dq.front())st.insert(dq.front());
    else cnt++;dq.pop_front();
    ans++;
  }
  cout<<ans<<endl;
  return 0;
}