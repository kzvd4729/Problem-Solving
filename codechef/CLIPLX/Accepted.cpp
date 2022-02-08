/****************************************************************************************
*  @author: kzvd4729                                         created: 26-02-2019 21:33:49                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 14.9M                                
*  problem: https://www.codechef.com/COLE2019/problems/CLIPLX
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int x,y;cin>>x>>y;
    for(int i=0;i<=y;i++)
    {
      if(i*2+y-i>=x)
      {
        cout<<i<<"\n";
        break;
      }
    }
  }
  return 0;
}