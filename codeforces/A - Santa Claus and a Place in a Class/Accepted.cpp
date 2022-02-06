/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/06/2019 12:03                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/752/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,m,k;cin>>n>>m>>k;
   int prln=m+m;
   int ln=(k+prln-1)/prln;
   k-=(prln*(ln-1));
   int ds=(k+1)/2;
   cout<<ln<<" "<<ds<<" ";
   if(k%2)cout<<"L"<<endl;
  else cout<<"R"<<endl;
     return 0;
}