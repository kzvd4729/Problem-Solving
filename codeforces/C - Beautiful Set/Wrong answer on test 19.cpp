/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/13/2018 15:10                        
*  solution_verdict: Wrong answer on test 19                 language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 195800 KB                            
*  problem: https://codeforces.com/contest/364/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2*5000*5000+2;
vector<int>v;
int vis[N+2];
int n;
void dfs(int x)
{
  if(x>2*5000*5000)return ;
  if(vis[x])return ;vis[x]=1;
  v.push_back(x);
  dfs(x*2);dfs(x*3);dfs(x*5);dfs(x*7);dfs(x*11);
}
void case1(void)
{
  for(int i=1;i<v.size();i++)
    if(v[i]%5&&v[i]%7&&v[i]%11)
    {
      if(!n)break;
      cout<<v[i]<<" ";
      n--;
    }
  cout<<endl;
}
void case2(void)
{
  for(int i=1;i<v.size();i++)
    if(v[i]%7&&v[i]%11)
    {
      if(!n)break;
      cout<<v[i]<<" ";
      n--;
    }
  cout<<endl;
}
void case3(void)
{
  for(int i=1;i<v.size();i++)
    if(v[i]%11)
    {
      if(!n)break;
      cout<<v[i]<<" ";
      n--;
    }
  cout<<endl;
}
void case4(void)
{
  for(int i=1;i<v.size();i++)
    if(v[i]%13)
    {
      if(!n)break;
      cout<<v[i]<<" ";
      n--;
    }
  cout<<endl;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  dfs(1);sort(v.begin(),v.end());
  cin>>n;
  if(n<=60)case1();
  else if(n<=400)case2();
  else if(n<=2000)case3();
  else case4();
  return 0;
}