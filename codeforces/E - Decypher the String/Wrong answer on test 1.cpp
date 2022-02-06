/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/16/2020 20:08                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1117/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e4;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string s,a,b,c,d,e,f;cin>>s;int n=s.size();
  int ml=26*26;char in='a';
  while(a.size()<n)
  {
    for(int i=0;i<ml;i++)
    {
      if(a.size()==n)break;
      a.push_back(in);
    }
    in++;if(in>'z')in='a';
  }
   ml=26;in='a';
  while(b.size()<n)
  {
    for(int i=0;i<ml;i++)
    {
      if(b.size()==n)break;
      b.push_back(in);
    }
    in++;if(in>'z')in='a';
  }
   ml=1;in='a';
  while(c.size()<n)
  {
    for(int i=0;i<ml;i++)
    {
      if(c.size()==n)break;
      c.push_back(in);
    }
    in++;if(in>'z')in='a';
  }
  map<vector<int>,int>mp;
  for(int i=0;i<n;i++)
    mp[{a[i],b[i],c[i]}]=i;
   cout<<"? "<<a<<endl;cin>>d;
  cout<<"? "<<b<<endl;cin>>e;
  cout<<"? "<<c<<endl;cin>>f;
   cout<<"! ";
  for(int i=0;i<n;i++)cout<<s[mp[{d[i],e[i],f[i]}]];cout<<endl;
   return 0;
}