/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/22/2019 21:13                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1104/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string s;cin>>s;int f0=0,cnt=1;
  for(auto x:s)
  {
    if(x=='0')
    {
      if(!f0)
      {
        cout<<1<<" "<<4<<endl;
        f0=1;
      }
      else
      {
        cout<<3<<" "<<4<<endl;
        f0=0;
      }
    }
    else
    {
      cout<<cnt<<" "<<1<<endl;
      cnt++;if(cnt==5)cnt=1;
    }
  }
  return 0;
}