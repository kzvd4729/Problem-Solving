/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/06/2018 19:12                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 278 ms                                          memory_used: 20400 KB                             
*  problem: https://codeforces.com/contest/195/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
string ss[N+2],rl[N+2];
string pro(string s)
{
  string ret;
  for(auto x:s)
  {
    if(x!=' ')ret.push_back(x);
  }
  return ret;
}
void print(string s)
{
  int f=0;string xx;
  for(auto x:s)
  {
    if(x=='"'&&f)break;
    if(f)xx.push_back(x);
    if(x=='"')f=1;
  }
  cout<<xx<<endl,exit(0);
}
bool match(string s1,string s2)
{
  int f=0;string xx;
  for(auto x:s1)
  {
    if(x==')')break;
    if(f)xx.push_back(x);
    if(x=='(')f=1;
  }
  f=0; string yy;
  for(auto x:s2)
  {
    if(x==',')break;
    if(f)yy.push_back(x);
    if(x=='(')f=1;
  }
  if(xx==yy)return true;
  return false;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;cin.ignore();
   int id=0;
  for(int i=1;i<=n;i++)
  {
    string s;getline(cin,s);
    string tmp=pro(s);
    if(tmp.size()==0)continue;
    ++id;
    rl[id]=s;ss[id]=tmp;
  }
  n=id;
   stack<string>st;
  for(int i=1;i<=n;i++)
  {
    if(ss[i][0]=='t')
      st.push(ss[i]);
    else
    {
      if(st.size()==0)continue;
      string tmp=st.top();
      if(tmp[0]=='t'&&tmp[1]=='r')st.pop();
      else
      {
        if(match(tmp,ss[i]))
          print(rl[i]);
      }
    }
  }
  cout<<"Unhandled Exception"<<endl;
  return 0;
}