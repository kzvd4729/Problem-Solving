/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/27/2020 17:30                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/817/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
void no()
{
  cout<<"NO\n",exit(0);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int a,b,c,d;cin>>a>>b>>c>>d;
   int x,y;cin>>x>>y;
  int da=abs(a-c),db=abs(b-d);
   if(da%x||db%y)no();
   if((da/x)%2!=(db/y)%2)no();
  cout<<"YES\n";
    return 0;
}