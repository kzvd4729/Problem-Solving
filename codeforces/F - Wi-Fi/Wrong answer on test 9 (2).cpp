/****************************************************************************************
*  @author: * kzvd4729                                       created: Sep/21/2019 14:20                        
*  solution_verdict: Wrong answer on test 9                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1216/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;string s;cin>>s;s="#"+s;
   vector<int>v;
  for(int i=1;i<=n;i++)
    if(s[i]=='1')v.push_back(i);
   long ans=0,id=n;
  while(v.size())
  {
    int f=0,g;
    while(v.size())
    {
      int nm=v.back();
      if(nm+k>=id){f=1,g=nm;v.pop_back();}
      else
      {
        if(!f){g=nm;v.pop_back();}
        break;
      }
    }
    while(id>g+k)ans+=id--;
    ans+=g;id=g-k-1;
  }
  for(int i=1;i<=id;i++)ans+=i;
  cout<<ans<<endl;
  return 0;
}