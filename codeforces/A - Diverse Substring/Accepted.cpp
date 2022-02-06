/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/25/2018 20:39                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1073/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;string s;cin>>s;
  for(int i=0;i<n-1;i++)
  {
    if(s[i]!=s[i+1])
    {
      cout<<"YES"<<endl;
      cout<<s[i]<<s[i+1]<<endl;
      exit(0);
    }
  }
  cout<<"NO"<<endl;
  return 0;
}