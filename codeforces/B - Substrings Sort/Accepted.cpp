/****************************************************************************************
*  @author: * kzvd4729                                       created: Jun/01/2018 20:50                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 30 ms                                           memory_used: 3400 KB                              
*  problem: https://codeforces.com/contest/988/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n;
string s[102];
bool cmp(string a,string b)
{
  if(a.size()!=b.size())return a.size()<b.size();
  else return a<b;
}
bool ok(int x,int y)
{
  string t=s[x];
  string p=s[y];
   t.push_back('#');
  for(int i=0;i<t.size();i++)
  {
    int k=i,f=0;
    for(int j=0;j<p.size();j++)
    {
      if(p[j]!=t[k++])f=1;
    }
    if(f==0)return true;
  }
  return false;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)
    cin>>s[i];
  sort(s+1,s+n+1,cmp);
   for(int i=2;i<=n;i++)
  {
    if(!ok(i,i-1))cout<<"NO"<<endl,exit(0);
  }
  cout<<"YES"<<endl;
  for(int i=1;i<=n;i++)
    cout<<s[i]<<endl;
  return 0;
}