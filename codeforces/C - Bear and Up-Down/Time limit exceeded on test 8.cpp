/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/04/2019 10:43                        
*  solution_verdict: Time limit exceeded on test 8           language: GNU C++14                               
*  run_time: 2000 ms                                         memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/653/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int n,aa[N+2];vector<int>po;
bool cal(void)
{
  for(int i=2;i<=n;i++)
  {
    if(i%2)
    {
      if(aa[i-1]<=aa[i])return false;
    }
    else
    {
      if(aa[i-1]>=aa[i])return false;
    }
  }
  return true;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(int i=1;i<=n;i++)
    cin>>aa[i];
  for(int i=2;i<=n;i++)
  {
    if(i%2)
    {
      if(aa[i-1]<=aa[i])
      {
        po.push_back(i-1);
        po.push_back(i);
        po.push_back(i+1);
      }
    }
    else
    {
      if(aa[i-1]>=aa[i])
      {
        po.push_back(i-1);
        po.push_back(i);
        po.push_back(i+1);
      }
    }
  }
  sort(po.begin(),po.end());po.erase(unique(po.begin(),po.end()),po.end());
  if(po.size()>50)cout<<0<<endl,exit(0);
  set<pair<int,int> >st;
  for(auto i:po)
  {
    for(int j=1;j<=n;j++)
    {
      if(i==j||i>n)continue;
      swap(aa[i],aa[j]);
      if(cal())
      {
        st.insert({min(i,j),max(i,j)});
      }
      swap(aa[i],aa[j]);
    }
  }
  cout<<st.size()<<endl;
  return 0;
}