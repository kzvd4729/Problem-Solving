/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/18/2019 22:04                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 200 KB                               
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
int dfs(string s)
{
  if(s.size()==1)
  {
    if(s[0]=='a'||s[0]=='e'||s[0]=='i'||s[0]=='o'||s[0]=='u')return 1;
    return 0;
  }
  int a=dfs(conL(s));
  int b=dfs(conR(s));
   if(a!=0&&b!=0)return 0;
  //if(a!=1&&b!=1)return 1;
  return 1;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    for(int i=0;i<26;i++)cin>>mt[i];
    string s;cin>>s;
    if(dfs(s))cout<<"Salah\n";else cout<<"Marzo\n";
  }
  return 0;
}