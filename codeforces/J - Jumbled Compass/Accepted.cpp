/****************************************************************************************
*  @author: JU_Quanta: tariqiitju, mh755628, kzvd4729#       created: Oct/09/2019 16:43                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/gym/101550/problem/J
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int a,b;cin>>a>>b;int cw,ccw;
   if(a<=b)cw=b-a;else cw=b+360-a;
   if(a>=b)ccw=a-b;else ccw=a+360-b;
   if(ccw<cw)cout<<-ccw<<endl;
  else cout<<cw<<endl;
   return 0;
}