/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/14/2019 17:14                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 155 ms                                          memory_used: 1000 KB                              
*  problem: https://codeforces.com/contest/1276/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    string s;cin>>s;int n=s.size();
    s.push_back('z');s.push_back('z');s.push_back('z');s.push_back('z');
    s.push_back('z');s.push_back('z');s.push_back('z');vector<int>ans;
    for(int i=0;i<n;i++)
    {
      if(s[i]=='t'&&s[i+1]=='w'&&s[i+2]=='o'&&s[i+3]=='n'&&s[i+4]=='e')
      {
        ans.push_back(i+2);i+=3;
      }
      else if(s[i]=='t'&&s[i+1]=='w'&&s[i+2]=='o')
      {
        ans.push_back(i+1);
      }
      else if(s[i]=='o'&&s[i+1]=='n'&&s[i+2]=='e')
      {
        ans.push_back(i+1);
      }
    }
    cout<<ans.size()<<endl;
    for(auto x:ans)cout<<x+1<<" ";
    cout<<endl;
  }
  return 0;
}