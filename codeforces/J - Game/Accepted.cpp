/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/18/2019 22:49                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/gym/100814/problem/J
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
string mt[26];
string conL(string &s)
{
  string r;int n=s.size();
  for(int i=0;i+1<n;i+=2)
    r.push_back(mt[s[i]-'a'][s[i+1]-'a']);
  if(n%2)r.push_back(s[n-1]);
  return r;
}
string conR(string &s)
{
  string r;int n=s.size();
  for(int i=n-1;i-1>=0;i-=2)
    r.push_back(mt[s[i]-'a'][s[i-1]-'a']);
  if(n%2)r.push_back(s[0]);
  reverse(r.begin(),r.end());
  return r;
}
int dfs(string s,int f)
{
  if(s.size()==2)
  {
    string a=conL(s),b=conR(s);bool u=0,v=0;
    if(a[0]=='a'||a[0]=='e'||a[0]=='i'||a[0]=='o'||a[0]=='u')u=1;
    if(b[0]=='a'||b[0]=='e'||b[0]=='i'||b[0]=='o'||b[0]=='u')v=1;
    if(!f)return u|v;else return u&v;
  }
  int a=dfs(conL(s),f^1);
  int b=dfs(conR(s),f^1);
   if(!f)return a|b;else return a&b;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    for(int i=0;i<26;i++)cin>>mt[i];
    string s;cin>>s;
    if(s.size()==1)
    {
      int f=0;
      if(s[0]=='a'||s[0]=='e'||s[0]=='i'||s[0]=='o'||s[0]=='u')f=1;
      if(f)cout<<"Salah\n";else cout<<"Marzo\n";
      continue;
    }
    if(dfs(s,0))cout<<"Salah\n";else cout<<"Marzo\n";
  }
  return 0;
}