/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/12/2019 16:39                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 77 ms                                           memory_used: 3300 KB                              
*  problem: https://codeforces.com/contest/992/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
 ios_base::sync_with_stdio(0);cin.tie(0);
 int n;cin>>n;set<int>st;
 for(int i=1;i<=n;i++)
 {
  int x;cin>>x;
  if(x!=0)st.insert(x);
 }
 cout<<st.size()<<endl;
 return 0;
}