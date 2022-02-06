/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/30/2018 15:10                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 3300 KB                              
*  problem: https://codeforces.com/contest/402/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,p,cnt,t;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>t;
  while(t--)
  {
    cin>>n>>p;
    cnt=2*n+p;
    for(int k=1;k<=n;k++)
    {
      for(int i=1;i<=n;i++)
      {
        if(i+k>n||!cnt)break;
        cout<<i<<" "<<i+k<<endl;
        cnt--;
      }
      if(!cnt)break;
    }
  }
  return 0;
}