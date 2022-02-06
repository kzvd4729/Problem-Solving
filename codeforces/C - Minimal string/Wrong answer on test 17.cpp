/****************************************************************************************
*  @author: kzvd4729                                         created: May/09/2019 17:47                        
*  solution_verdict: Wrong answer on test 17                 language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 10300 KB                             
*  problem: https://codeforces.com/contest/797/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int po[26][N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string a;cin>>a;
  for(int i=a.size()-1;i>=0;i--)
  {
    for(int j=0;j<26;j++)
      po[j][i]|=po[j][i+1];
    po[a[i]-'a'][i]=1;
  }
  string ans,tmp;int id=0;
  for(auto x:a)
  {
    if(tmp.size()==0)
    {
      tmp.push_back(x);continue;
    }
    while(tmp.size())
    {
      int f=0;
      for(int i=0;i<tmp.back()-'a';i++)
      {
        if(po[i][id])
        {
          f=1;break;
        }
      }
      if(f)break;
      ans.push_back(tmp.back());tmp.pop_back();
    }
    tmp.push_back(x);id++;
  }
  reverse(tmp.begin(),tmp.end());
  cout<<ans+tmp<<endl;
  return 0;
}