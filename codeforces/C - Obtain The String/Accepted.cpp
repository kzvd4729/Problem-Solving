/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/29/2020 21:02                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 1500 KB                              
*  problem: https://codeforces.com/contest/1295/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
vector<int>po[26+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    string s,t;cin>>s>>t;for(int i=0;i<26;i++)po[i].clear();
    int i=0;
    for(auto x:s)po[x-'a'].push_back(i++);
    int ans=1,pt=-1;
    for(int j=0;j<t.size();j++)
    {
      int c=t[j]-'a';
      int i=upper_bound(po[c].begin(),po[c].end(),pt)-po[c].begin();
       if(i<po[c].size())pt=po[c][i];
      else
      {
        ans++;pt=-1;j--;
      }
      if(ans>t.size())
      {
        ans=-1;break;
      }
    }
    cout<<ans<<"\n";
  }
  return 0;
}