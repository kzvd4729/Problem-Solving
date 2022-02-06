/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/03/2018 19:13                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/701/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
pair<int,int>p[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
    cin>>p[i].first,p[i].second=i;
  sort(p+1,p+n+1);
  for(int i=1;i<=n/2;i++)
    cout<<p[i].second<<" "<<p[n-i+1].second<<endl;
   return 0;
}