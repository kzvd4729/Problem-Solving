/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/14/2020 13:17                        
*  solution_verdict: Time limit exceeded on test 7           language: GNU C++14                               
*  run_time: 1000 ms                                         memory_used: 3900 KB                              
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
vector<int>tk;int ok,f;
void dfs(int i,int l,int ad)
{
  if(i==ok)
  {
    if(l==0&&ad==0)f=1;
    return ;
  }
  dfs(i+1,l,ad);if(f)return ;
  if(l)
  {
    tk.push_back(v[i]);
    dfs(i+1,l-1,(ad&ans[v[i]]));
    if(f)return ;tk.pop_back();
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
  brut(17);
  for(int i=17;i<n;i++)
  {
    tk.clear(),ok=i,f=0;
    for(int j=1; ;j++)
    {
      dfs(0,j,(1<<20)-1);if(f)break;
    }
    for(auto x:tk)
    {
      cout<<"? "<<x<<" "<<i<<endl;
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