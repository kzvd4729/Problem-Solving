/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/18/2018 22:17                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/1079/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
int fr[N+2];set<int>st;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,k,mx=0;cin>>n>>k;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;fr[x]++;
    mx=max(mx,fr[x]);st.insert(x);
  }
  int ds=(mx+k-1)/k;
   //cout<<ds<<" "<<mx<<endl;
   cout<<ds*k*st.size()-n<<endl;
   return 0;
}