/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/19/2019 21:09                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1278/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int a,b;cin>>a>>b;int d=abs(a-b);
     int sm=0,cnt=0;
    for(int i=1; ;i++)
    {
      if(sm>=d)break;sm+=i;cnt++;
    }
    if((sm-d)%2==0)cout<<cnt<<endl;
    else if(cnt%2==0)cout<<cnt+1<<endl;
    else cout<<cnt+2<<endl;
  }
  return 0;
}