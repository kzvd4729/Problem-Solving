/****************************************************************************************
*  @author: * kzvd4729                                       created: Feb/04/2020 21:34                        
*  solution_verdict: Wrong answer on test 8                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 4100 KB                              
*  problem: https://codeforces.com/contest/1296/problem/E2
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int cl[N+2];
string s;
vector<char>find(char c)
{
  vector<char>v;
  for(int i=s.size()-1;i>=0;i--)
  {
    if(s[i]==c)
    {
      for(int j=0;j<i;j++)
        if(s[j]>s[i])v.push_back(s[j]);
      break;
    }
  }
  sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
  return v;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n>>s;vector<char>v;
  for(int i=0;i<n;i++)v.push_back(s[i]);
   sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
   int mx=0;
  for(int i=v.size()-1;i>=0;i--)
  {
    vector<char>u=find(v[i]);
    set<int>st;
    for(auto x:u)st.insert(cl[x-'a']);
     for(int f=1; ;f++)
    {
      if(st.find(f)!=st.end())continue;
      cl[v[i]-'a']=f;mx=max(mx,f);
      break;
    }
  }
  cout<<mx<<endl;
  for(int i=0;i<s.size();i++)
    cout<<cl[s[i]-'a']<<" ";
  cout<<endl;
   return 0;
}