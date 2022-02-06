/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/13/2019 15:29                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/1109/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string s;cin>>s;
   for(int i=1;i<s.size();i++)
  {
    string tmp=s.substr(i,s.size()-i);
    tmp+=s.substr(0,i);
    string mtp=tmp;reverse(tmp.begin(),tmp.end());
    if(tmp==mtp&&tmp!=s)cout<<1<<endl,exit(0);
  }
  for(int i=0;i<s.size();i++)
  {
    if(s.size()-1-i<=i)break;
    if(s.substr(0,i+1)!=s.substr(s.size()-1-i,i+1))
      cout<<2<<endl,exit(0);
  }
  cout<<"Impossible"<<endl;
  return 0;
}