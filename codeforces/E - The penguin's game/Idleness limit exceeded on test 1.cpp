/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/22/2020 15:53                        
*  solution_verdict: Idleness limit exceeded on test 1       language: GNU C++14                               
*  run_time: 0 ms                                            memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/835/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int x,y;
int ask(vector<vector<int> >v)
{
  cout<<"?";
  for(auto x:v)
  {
    for(auto z:x)cout<<" "<<z;
  }
  cout<<endl;
  int ret;cin>>ret;return ret;
}
int solve(vector<vector<int> >v)
{
  vector<int>a;
  for(auto x:v)
  {
    for(auto z:x)
      a.push_back(z);
  }
  while(true)
  {
    if(a.size()==1)return a[0];
    vector<int>ta,tb;
    cout<<"?";
    for(int i=0;i<a.size()/2;i++)
    {
      ta.push_back(a[i]);
      cout<<" "<<a[i];
    }
    cout<<endl;
    for(int i=a.size()/2;i<a.size();i++)
      tb.push_back(a[i]);
    int r;cin>>r;
     if(r==y||r==(x^y))a=ta;
    else a=tb;
  }
}
void go(vector<vector<int> >u,vector<vector<int> >v)
{
  int z;z=ask(u);
  if(z==y||z==(x^y))
  {
    int id=solve(u);
    int rt;vector<int>l;
    for(auto x:u)
      if(x[0]<=id&&x.back()>=id)rt=x.back();
    for(auto x:v)
      if(x[0]==rt+1)l=x;
    while(true)
    {
      if(l.size()==1)cout<<"! "<<id<<" "<<l[0]<<endl,exit(0);
      vector<int>ta,tb;
      cout<<"?";
      for(int i=0;i<l.size()/2;i++)
      {
        ta.push_back(l[i]);
        cout<<" "<<l[i];
      }
      cout<<endl;
      for(int i=l.size()/2;i<l.size();i++)
        tb.push_back(l[i]);
      int r;cin>>r;
       if(r==y||r==(x^y))l=ta;
      else l=tb;
    }
  }
  //cout<<"here"<<endl;
  vector<vector<int> >a,b;
  for(auto x:u)
  {
    vector<int>ta,tb;
    for(int i=0;i<x.size()/2;i++)
      ta.push_back(x[i]);
    for(int i=x.size()/2;i<x.size();i++)
      tb.push_back(x[i]);
    a.push_back(ta);b.push_back(tb);
  }
  for(auto x:v)
  {
    vector<int>ta,tb;
    for(int i=0;i<x.size()/2;i++)
      ta.push_back(x[i]);
    for(int i=x.size()/2;i<x.size();i++)
      tb.push_back(x[i]);
    a.push_back(ta);b.push_back(tb);
  }
  go(a,b);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n>>x>>y;
  vector<int>u,v;vector<vector<int> >a,b;
   for(int i=1;i<=n/2;i++)u.push_back(i);
  for(int i=n/2+1;i<=n;i++)v.push_back(i);
  a.push_back(u),b.push_back(v);
  go(a,b);
   return 0;
}