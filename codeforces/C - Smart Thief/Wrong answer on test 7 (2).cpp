/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/30/2019 19:32                        
*  solution_verdict: Wrong answer on test 7                  language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 23400 KB                             
*  problem: https://codeforces.com/gym/102001/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
//..............................................................................
/*
de bruijn sequence: given an integer n and alphabet size k. there are total k^n
distinct string possible. find a string of length k^n+n-1(minimum length)
where every of those k^n string present as substring.
*/
//substring length n and alphabet 0 to k-1;
vector<string>v;
void generate(int n,int k,string s)
{
  if(n==0){v.push_back(s);return ;}
  for(int i=0;i<k;i++)
  {
    s.push_back((char)(i+'0'));
    generate(n-1,k,s);s.pop_back();
  }
}
map<string,int>mp;map<int,string>rv;
vector<int>adj[N+2];
int in[N+2],out[N+2];vector<int>cir;
bool eulerCircuit(int n,int start)
{
  for(int i=1;i<=n;i++)if(in[i]!=out[i])return false;
  stack<int>st;st.push(start);
  while(!st.empty())
  {
    int u=st.top();
    if(adj[u].size()==0){cir.push_back(u);st.pop();}
    else {st.push(adj[u].back());adj[u].pop_back();}
  }
  reverse(cir.begin(),cir.end());return true;
}
void solveEuler(int n)//adj graph is given
{
  for(int i=1;i<=n;i++){for(auto x:adj[i])out[i]++,in[x]++;}
  eulerCircuit(n,1);
}
string solve(int n,int k)
{
  string s;generate(n-1,k,s);
  for(int i=0;i<v.size();i++)
    mp[v[i]]=i+1,rv[i+1]=v[i];
  for(auto x:v)
  {
    string s=x;reverse(s.begin(),s.end());s.pop_back();
    reverse(s.begin(),s.end());
     int u=mp[x];
    for(int i=0;i<k;i++)
    {
      s.push_back((char)(i+'0'));
      adj[u].push_back(mp[s]);s.pop_back();
    }
  }
  //cout<<v.size()<<endl;
  solveEuler(v.size());string ret=rv[cir[0]];
  //cout<<cir.size()<<endl;
  for(int i=1;i<cir.size();i++)
    ret.push_back(rv[cir[i]][n-2]);
  return ret;
}
int ch[12];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,m,k;cin>>n>>m>>k;int ln=k+n-1;
   for(int i=0;i<m;i++)cin>>ch[i];
   if(n==1)
  {
    for(int i=0;i<k;i++)
      cout<<ch[i];
    cout<<endl,exit(0);
  }
   int f=0,pw=1;
  for(int i=1;i<=n;i++)
  {
    pw*=m;if(pw>200000){f=1;break;}
  }
  if(!f)
  {
    string s=solve(n,m);//cout<<s.size()<<endl;
    if(s.size()<ln)exit(0);
    for(int i=0;i<ln;i++)
      cout<<ch[s[i]-'0'];
    cout<<endl;
  }
  else
  {
    for(int i=0;i<ln;i++)
      cout<<ch[rand()%m];
    cout<<endl;
  }
  return 0;
}