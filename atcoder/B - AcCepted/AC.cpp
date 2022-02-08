/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-08-05 18:10:33                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 1 ms                                            memory_used: 256 KB                               
*  problem: https://atcoder.jp/contests/abc104/tasks/abc104_b
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
string s;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>s;
  if(s[0]!='A')cout<<"WA"<<endl,exit(0);
   int cnt=0;
  for(int i=1;i<s.size();i++)
  {
    if(s[i]>='A'&&s[i]<='Z')cnt++;
  }
  if(cnt!=1)cout<<"WA"<<endl,exit(0);
  cnt=0;
  for(int i=2;i<s.size()-1;i++)
  {
    if(s[i]=='C')cnt++;
  }
  if(cnt!=1)cout<<"WA"<<endl,exit(0);
  cout<<"AC"<<endl;
  return 0;
}