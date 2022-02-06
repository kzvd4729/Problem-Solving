/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/03/2018 19:54                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/540/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,ans=0;cin>>n;
  string a,b;cin>>a>>b;
  for(int i=0;i<n;i++)
  {
    int x=a[i]-'0',y=b[i]-'0';
    if(x>y)swap(x,y);
    ans+=min(y-x,9-y+x+1);
  }
  cout<<ans<<endl;
  return 0;
}