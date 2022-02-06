/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/04/2019 11:04                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 77 ms                                           memory_used: 7000 KB                              
*  problem: https://codeforces.com/contest/653/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int n,aa[N+2];vector<int>po;
bool ok(int a,int b,int c)
{
  if(b%2)
  {
    if(a>=1)
    {
      if(aa[a]<=aa[b])return false;
    }
    if(c<=n)
    {
      if(aa[c]<=aa[b])return false;
    }
  }
  else
  {
    if(a>=1)
    {
      if(aa[a]>=aa[b])return false;
    }
    if(c<=n)
    {
      if(aa[c]>=aa[b])return false;
    }
  }
  return true;
}
bool cal(void)
{
  /*for(int i=1;i<=n;i++)
    cout<<aa[i]<<" ";
  cout<<endl;*/
  for(auto x:po)
  {
    if(!ok(x-1,x,x+1))return false;
  }
  //cout<<"ok"<<endl;
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
        if(i<n)po.push_back(i+1);
      }
    }
    else
    {
      if(aa[i-1]>=aa[i])
      {
        po.push_back(i-1);
        po.push_back(i);
        if(i<n)po.push_back(i+1);
      }
    }
  }
  sort(po.begin(),po.end());po.erase(unique(po.begin(),po.end()),po.end());
  if(po.size()>20)cout<<0<<endl,exit(0);
  set<pair<int,int> >st;
  for(int ii=0;ii<po.size();ii++)
  {
    int i=po[ii];
    for(int j=1;j<=n;j++)
    {
      if(i==j)continue;
      swap(aa[i],aa[j]);
      po.push_back(i);po.push_back(j);
      if(cal())
      {
        st.insert({min(i,j),max(i,j)});
      }
      swap(aa[i],aa[j]);
      po.pop_back();po.pop_back();
    }
  }
  cout<<st.size()<<endl;
  return 0;
}