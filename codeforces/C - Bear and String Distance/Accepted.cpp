/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/20/2018 03:12                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 30 ms                                           memory_used: 400 KB                               
*  problem: https://codeforces.com/contest/628/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,k;
string s,ans;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>k;
  cin>>s;
  for(auto x:s)
  {
    int mx=-1,f=0;
    char tr='a';
    for(char i='a';i<='z';i++)
    {
      int tmp=abs(x-i);
      if(tmp==k)
      {
        ans.push_back(i);
        k=0;
        f=1;
        break;
      }
      if(tmp>mx)
      {
        mx=tmp;
        tr=i;
      }
    }
    if(f)continue;
    k-=mx;
    ans.push_back(tr);
  }
  if(k)cout<<-1<<endl;
  else cout<<ans<<endl;
  return 0;
}