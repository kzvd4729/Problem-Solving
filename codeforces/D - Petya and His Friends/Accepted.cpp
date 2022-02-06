/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/24/2018 18:28                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 3300 KB                              
*  problem: https://codeforces.com/contest/66/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
string add(string a,string b)
{
  reverse(a.begin(),a.end());
  reverse(b.begin(),b.end());
  a.push_back('0');
  a.push_back('0');
  while(a.size()<b.size())a.push_back('0');
  while(b.size()<a.size())b.push_back('0');
  int c=0;
  string ret;
  for(int i=0;i<a.size();i++)
  {
    int x=a[i]+b[i]-'0'-'0'+c;
    c=x/10;
    x=x%10;
    ret.push_back(x+'0');
  }
  while(ret.back()=='0')ret.pop_back();
  reverse(ret.begin(),ret.end());
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   int n;
  cin>>n;
  vector<string>print;
   if(n==2)cout<<-1<<endl,exit(0);
  print.push_back("99");
  print.push_back("55");
  print.push_back("11115");
   int a;
  a=98;
  string ss="11115";
  while(a--)
    ss=add(ss,"11115");
  a=54;
  string org=ss;
  while(a--)
    ss=add(ss,org);
   print.push_back(ss);
   a=100;
  org=ss;
  while(a--)
  {
    ss=add(ss,org);
    print.push_back(ss);
  }
   for(int i=0;i<n;i++)cout<<print[i]<<endl;
   return 0;
}