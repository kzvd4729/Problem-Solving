/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/16/2021 13:06                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 46 ms                                           memory_used: 31800 KB                             
*  problem: https://codeforces.com/contest/1511/problem/D
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
#include<sstream>
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<stack>
#include<deque>
#include<random>
#define long long long
using namespace std;
 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9,mod=1e9+7;
 vector<int>adj[N+2];
 int in[N+2],out[N+2];vector<int>cir;//circuit
bool eulerCircuit(int n,int start)
{
  for(int i=1;i<=n;i++)if(in[i]!=out[i])assert(0);
  stack<int>st;st.push(start);
  while(!st.empty())
  {
    int u=st.top();
    if(adj[u].size()==0)
    {
      cir.push_back(u);st.pop();
    }
    else
    {
      st.push(adj[u].back());adj[u].pop_back();
    }
  }
  reverse(cir.begin(),cir.end());
  return true;
}
void solve(int n)//adj graph is given
{
  for(int i=1;i<=n;i++)
  {
    for(auto x:adj[i])out[i]++,in[x]++;
  }
  eulerCircuit(n,1);
}
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
    int n,k;cin>>n>>k;
   if(k==1)
  {
    for(int i=1;i<=n;i++)cout<<'a';
      cout<<endl,exit(0);
  }
    for(int i=1;i<=k;i++)
  {
    for(int j=i+1;j<=k;j++)adj[i].push_back(j),adj[j].push_back(i);
  }
   solve(k);
  // for(auto x:cir)
  // {
  //   cout<<(char)(x+'a'-1);
  // }
  // cout<<endl;
   vector<int>vs(k+2,0);
  for(int i=(int)cir.size()-1;i>=0;i--)
  {
    if(vs[cir[i]])continue;
    cir.insert(cir.begin()+i,cir[i]);
    vs[cir[i]]=1;
  }
   string ans;
  for(auto x:cir)ans.push_back((char)(x+'a'-1));
   string tmp=ans;
  tmp.erase(tmp.begin());
   while((int)ans.size()<n)ans+=tmp;
   while((int)ans.size()>n)ans.pop_back();
  cout<<ans<<endl;
    return 0;
}