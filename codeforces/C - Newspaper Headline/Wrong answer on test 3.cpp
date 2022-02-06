/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/22/2018 16:15                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 3300 KB                              
*  problem: https://codeforces.com/contest/92/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
string s,z;
vector<int>v[1000];
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>s>>z;
  for(int i=0;s[i];i++)
    v[int(s[i])].push_back(i);
  int now=-1,print=1;
  for(auto x:z)
  {
    vector<int>::iterator it;
    it=lower_bound(v[x].begin(),v[x].end(),now);
    if(it==v[x].end())
    {
      now=-1;
      print++;
      it=lower_bound(v[x].begin(),v[x].end(),now);
      if(it==v[x].end())cout<<-1<<endl,exit(0);
    }
    now=*it;
  }
  cout<<print<<endl;
  return 0;
}