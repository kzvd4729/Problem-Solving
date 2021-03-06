/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/04/2020 19:23                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 44300 KB                             
*  problem: https://codeforces.com/contest/747/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
string s;
bool isNum(int l,int r)
{
  for(int i=l;i<=r;i++)
  {
    if(s[i]<'0'||s[i]>'9')return false;
  }
  return true;
}
int stToNum(int l,int r)
{
  int ret=0;
  for(int i=l;i<=r;i++)
  {
    ret=ret*10+s[i]-'0';
  }
  return ret;
}
string sub(int l,int r)
{
  string a;
  for(int i=l;i<=r;i++)a.push_back(s[i]);
  return a;
}
vector<string>lev[N+2];
int id,mx;
void print()
{
  cout<<mx<<"\n";
  for(int i=1;i<=mx;i++)
  {
    for(auto x:lev[i])cout<<x<<" ";
    cout<<"\n";
  }
  exit(0);
}
void dfs(int lv)
{
  mx=max(mx,lv);int i;
  for(i=id; ;i++)
  {
    if(i==s.size()||s[i]==',')break;
  }
  string a=sub(id,i-1);lev[lv].push_back(a);
  id=i+1;
  for(i=id; ;i++)
  {
    if(i==s.size()||s[i]==',')break;
  }
  if(i==s.size())print();
  int nm=stToNum(id,i-1);id=i+1;
  for(int i=1;i<=nm;i++)
    dfs(lv+1);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>s;while(true)dfs(1);
   return 0;
}