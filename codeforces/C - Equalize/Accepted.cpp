/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/02/2018 21:08                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 3100 KB                              
*  problem: https://codeforces.com/contest/1037/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,ans=0;cin>>n;
  string a,b;cin>>a>>b;
  for(int i=0;i<a.size();i++)
  {
    if(a[i]==b[i])continue;
    if(i+1<a.size())
    {
      if(a[i+1]==b[i]&&a[i]==b[i+1])
      {
        ans++;
        swap(a[i],a[i+1]);
        continue;
      }
    }
    ans++;
  }
  cout<<ans<<endl;
  return 0;
}