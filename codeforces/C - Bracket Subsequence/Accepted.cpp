/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/18/2018 01:40                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 1600 KB                              
*  problem: https://codeforces.com/contest/1023/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int vis[N+2];
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   int n,k;cin>>n>>k;
  string s;cin>>s;
   stack<int>st;
  for(int i=0;i<s.size();i++)
  {
    if(k==0)break;
    if(s[i]=='(')st.push(i);
    else
    {
      if(st.size()==0)continue;
      int tp=st.top();
      st.pop();vis[tp]=1;
      vis[i]=1;k-=2;
    }
  }
  for(int i=0;i<s.size();i++)
    if(vis[i])cout<<s[i];
  cout<<endl;
  return 0;
}