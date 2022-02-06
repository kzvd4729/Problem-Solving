/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/05/2018 22:45                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/1004/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long inf=2e12;
long n,d,arr[102];
set<long>st;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>d;
  for(long i=1;i<=n;i++)
    cin>>arr[i];
  sort(arr+1,arr+n+1);
  arr[0]=-inf;
  arr[n+1]=inf;
  for(long i=1;i<=n;i++)
  {
    if(arr[i]-d>=arr[i-1]+d)
      st.insert(arr[i]-d);
    if(arr[i]+d<=arr[i+1]-d)
      st.insert(arr[i]+d);
  }
  cout<<st.size()<<endl;
  return 0;
}