/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/01/2019 13:50                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/1091/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
vector<int>divi(int n)
{
  set<int>st;int sq=sqrt(n+1);
  for(int i=1;i<=sq;i++)
  {
    if(n%i==0)
    {
      st.insert(i);
      st.insert(n/i);
    }
  }
  vector<int>v;
  for(auto x:st)v.push_back(x);
  return v;
}
long pass(int n,int k)
{
  long nn=n/k;
  long ret=k*(nn*(nn-1))/2+nn;
   return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;
  vector<int>v=divi(n);set<long>st;
  for(auto x:v)st.insert(pass(n,x));
  for(auto x:st)cout<<x<<" ";
    cout<<endl;
   return 0;
}