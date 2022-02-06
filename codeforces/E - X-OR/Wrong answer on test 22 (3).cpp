/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/14/2020 13:39                        
*  solution_verdict: Wrong answer on test 22                 language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 4200 KB                              
*  problem: https://codeforces.com/contest/1364/problem/E
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<unordered_map>
#include<random>
#include<chrono>
#include<stack>
#include<deque>
#define long long long
using namespace std;
const int N=1e6;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int ans[N+2];vector<int>v;
void brut(int n)
{
  for(int i=0;i<n;i++)
  {
    for(int j=i+1;j<n;j++)
    {
      cout<<"? "<<v[i]<<" "<<v[j]<<endl;
      int x;cin>>x;
      for(int k=0;k<20;k++)
      {
        if((x&(1<<k))==0)
        {
          if((ans[v[i]]&(1<<k)))ans[v[i]]^=(1<<k);
          if((ans[v[j]]&(1<<k)))ans[v[j]]^=(1<<k);
        }
      }
    }
  }
}
vector<int>tk;
void take1(int n)
{
  int ad=(1<<20)-1;
  for(int i=0;i<n;i++)
  {
    if((ad&ans[v[i]])==0)
    {
      tk.push_back(v[i]);return ;
    }
  }
}
void take2(int n)
{
  for(int i=0;i<n;i++)
  {
    int ad=ans[v[i]];
    for(int j=i+1;j<n;j++)
    {
      if((ad&ans[v[j]])==0)
      {
        tk.push_back(v[i]);
        tk.push_back(v[j]);
        return ;
      }
    }
  }
}
void take3(int n)
{
  for(int i=0;i<n;i++)
  {
    for(int j=i+1;j<n;j++)
    {
      int ad=ans[v[i]]&ans[v[j]];
      for(int k=j+1;k<n;k++)
      {
        if((ad&ans[v[k]])==0)
        {
          tk.push_back(v[i]);
          tk.push_back(v[j]);
          tk.push_back(v[k]);
          return ;
        }
      }
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)v.push_back(i);
   shuffle(v.begin(),v.end(),rng);
  shuffle(v.begin(),v.end(),rng);
   for(int i=1;i<=n;i++)ans[i]=(1<<20)-1;
   if(n<=200)
  {
    brut(n);cout<<"!";
    for(int i=1;i<=n;i++)cout<<" "<<ans[i];
    cout<<endl;exit(0);
  }
  brut(16);
  for(int i=16;i<n;i++)
  {
    tk.clear();take1(i);
    if(tk.size()==0)take2(i);
    if(tk.size()==0)take3(i);
    assert(tk.size());
    for(auto x:tk)
    {
      cout<<"? "<<x<<" "<<v[i]<<endl;
      int z;cin>>z;
      for(int k=0;k<20;k++)
      {
        if((z&(1<<k))==0)
        {
          if((ans[v[i]]&(1<<k)))ans[v[i]]^=(1<<k);
        }
      }
    }
  }
  cout<<"!";
  for(int i=1;i<=n;i++)cout<<" "<<ans[i];
  cout<<endl;
  return 0;
}