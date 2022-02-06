/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/29/2019 12:46                        
*  solution_verdict: Wrong answer on test 23                 language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/gym/102001/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string s;cin>>s;int one=0,zero=0;
  for(auto x:s)x=='1'?one++:zero++;
   char c='0';if(zero>=one)c='1';
    string p;
  for(int i=1;i<=s.size();i++)p.push_back(c);
  if(one==zero)
  {
    for(int i=0;i<s.size();i++)
      if(s[i]=='1'){p[i]='0';break;}
  }
  cout<<p<<endl;
    return 0;
}