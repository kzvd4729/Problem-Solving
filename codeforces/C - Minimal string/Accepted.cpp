/****************************************************************************************
*  @author: kzvd4729                                         created: May/09/2019 18:08                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 10800 KB                             
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
    tmp.push_back(x);id++;
    while(tmp.size()>0)
    {
      int f=0,c=tmp.back()-'a';
      for(int i=0;i<c;i++)
        if(po[i][id])f=1;
      if(f)break;
      ans.push_back(tmp.back());tmp.pop_back();
    }
  }
  cout<<ans<<endl;
  return 0;
}